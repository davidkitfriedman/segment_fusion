/*
Copyright (C) 2006 Pedro Felzenszwalb

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
*/

/*
Copyring (C) 2007 David Kit Friedman 

This file is part of segment_fusion.

segment_fusion is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

segment_fusion is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with segment_fusion.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SEGMENT_IMAGE
#define SEGMENT_IMAGE

#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <time.h>
#include <string.h>

#include <misc.h>
#include <filter.h>
#include <segment-graph.h>
#include <GCoptimization.h>
#include <cellalg.h>
#include <abs_qual.h>

// dissimilarity measure between pixels
static inline float diff(image<float> *r, image<float> *g, image<float> *b,
			 int x1, int y1, int x2, int y2) {
  return sqrt(square(imRef(r, x1, y1)-imRef(r, x2, y2)) +
	      square(imRef(g, x1, y1)-imRef(g, x2, y2)) +
	      square(imRef(b, x1, y1)-imRef(b, x2, y2)));
}

/*
 * Segment an image
 *
 * Returns a color image representing the segmentation.
 *
 * im: image to segment.
 * sigma: to smooth the image.
 * c: constant for treshold function.
 * min_size: minimum component size (enforced by post-processing stage).
 * num_ccs: number of connected components in the segmentation.
 */
image<rgb> *segment_image_torgb(image<rgb> *im, float sigma, float c, int min_size,
			  int *num_ccs) {
  int width = im->width();
  int height = im->height();

  image<float> *r = new image<float>(width, height);
  image<float> *g = new image<float>(width, height);
  image<float> *b = new image<float>(width, height);

  // smooth each color channel  
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      imRef(r, x, y) = imRef(im, x, y).r;
      imRef(g, x, y) = imRef(im, x, y).g;
      imRef(b, x, y) = imRef(im, x, y).b;
    }
  }
  image<float> *smooth_r = smooth(r, sigma);
  image<float> *smooth_g = smooth(g, sigma);
  image<float> *smooth_b = smooth(b, sigma);
  delete r;
  delete g;
  delete b;
 
  // build graph
  edge *edges = new edge[width*height*4];
  int num = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (x < width-1) {
	edges[num].a = y * width + x;
	edges[num].b = y * width + (x+1);
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y);
	num++;
      }

      if (y < height-1) {
	edges[num].a = y * width + x;
	edges[num].b = (y+1) * width + x;
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x, y+1);
	num++;
      }

      if ((x < width-1) && (y < height-1)) {
	edges[num].a = y * width + x;
	edges[num].b = (y+1) * width + (x+1);
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y+1);
	num++;
      }

      if ((x < width-1) && (y > 0)) {
	edges[num].a = y * width + x;
	edges[num].b = (y-1) * width + (x+1);
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y-1);
	num++;
      }
    }
  }
  delete smooth_r;
  delete smooth_g;
  delete smooth_b;

  // segment
  universe *u = segment_graph(width*height, num, edges, c);
  
  // post process small components
  for (int i = 0; i < num; i++) {
    int a = u->find(edges[i].a);
    int b = u->find(edges[i].b);
    if ((a != b) && ((u->size(a) < min_size) || (u->size(b) < min_size)))
      u->join(a, b);
  }
  delete [] edges;
  *num_ccs = u->num_sets();

  image<rgb> *output = new image<rgb>(width, height);

  // pick random colors for each component
  rgb *colors = new rgb[width*height];
  for (int i = 0; i < width*height; i++)
    colors[i] = random_rgb();
  
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int comp = u->find(y * width + x);
      imRef(output, x, y) = colors[comp];
    }
  }  

  delete [] colors;  
  delete u;

  return output;
}

/* 
*segment_image
*
*segment an image with a return value in which each pixel is set 
*to an integer corresponding to its segment 
*
*im    -- image to segment 
*sigma -- for smoothing
*c     -- threshold for graph segmentation algorithm 
*min_size -- minimum size for post processing 
*
*/
image<int> *segment_image(image<rgb> *im, float sigma, float c, int min_size,
			  int *num_ccs) 
{
  int width = im->width();
  int height = im->height();

  image<float> *r = new image<float>(width, height);
  image<float> *g = new image<float>(width, height);
  image<float> *b = new image<float>(width, height);

  // smooth each color channel  
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      imRef(r, x, y) = imRef(im, x, y).r;
      imRef(g, x, y) = imRef(im, x, y).g;
      imRef(b, x, y) = imRef(im, x, y).b;
    }
  }
  image<float> *smooth_r = smooth(r, sigma);
  image<float> *smooth_g = smooth(g, sigma);
  image<float> *smooth_b = smooth(b, sigma);
  delete r;
  delete g;
  delete b;
 
  // build graph
  edge *edges = new edge[width*height*4];
  int num = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (x < width-1) {
	edges[num].a = y * width + x;
	edges[num].b = y * width + (x+1);
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y);
	num++;
      }

      if (y < height-1) {
	edges[num].a = y * width + x;
	edges[num].b = (y+1) * width + x;
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x, y+1);
	num++;
      }

      if ((x < width-1) && (y < height-1)) {
	edges[num].a = y * width + x;
	edges[num].b = (y+1) * width + (x+1);
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y+1);
	num++;
      }

      if ((x < width-1) && (y > 0)) {
	edges[num].a = y * width + x;
	edges[num].b = (y-1) * width + (x+1);
	edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y-1);
	num++;
      }
    }
  }
  delete smooth_r;
  delete smooth_g;
  delete smooth_b;

  // segment
  universe *u = segment_graph(width*height, num, edges, c);
  
  // post process small components
  for (int i = 0; i < num; i++) 
    {
      int a = u->find(edges[i].a);
      int b = u->find(edges[i].b);
      if ((a != b) && ((u->size(a) < min_size) || (u->size(b) < min_size)))
	u->join(a, b);
    }
  delete [] edges;
  *num_ccs = u->num_sets();

  image<int> *output = new image<int>(width, height);
  hashInt hashtab; 
  int counter = 0;
  for (int y = 0; y < height; y++) 
    {
    for (int x = 0; x < width; x++) 
      {
	int comp = u->find(y * width + x);
	IntMark temp = hashtab[comp];
	if ( temp.i == -1 )
	  {
	    imRef(output, x, y) = counter;
	    hashtab[comp] = IntMark(counter);
	    counter++;
	  }
	else
	  {
	    imRef(output, x, y) = temp.i;
	  }
      }
    }  

  delete u;

  return output;
}



image<float> *compute_quality_crude(image<rgb> *im, int win_len);
image<float> *compute_quality(image<rgb> *im, int win_rad, char *quality_abs_or_squ);

/*
*quality_image
*
*return an image where each pixel is proportional to the quality of that pixel 
*within input. The quality being proportional to the variability within the 
*window as a measure of whether it is texture or not 
*
*input -- image to compute quality for 
*
*quality_winradius -- the window radius to use 
*
*quality_abs_or_squ -- whether to use the abs algorithm or the squared 
*algorithm 
*
*/

image<rgb> *quality_image( image<rgb> *input, int quality_winradius, char *quality_abs_or_squ )
{
  image<float> *qual = compute_quality( input, quality_winradius, quality_abs_or_squ );
  int w = qual->width();
  int h = qual->height();
  image<rgb> *ret = new image<rgb>(w, h);

  // find the maximum 
  float maximum = 0;
  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  if ( qual->access[i][j] > maximum )
	    {
	      maximum = qual->access[i][j];
	    }
	}
    }

  // set each entry equal to its value divided by the maximum 
  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  rgb curr;
	  curr.r = (unsigned char)(( qual->access[i][j] / maximum ) * 255);
	  curr.g = curr.r;
	  curr.b = curr.r;
	  ret->access[i][j] = curr;
	}
    }
  return ret;
}

/* 
*quality_image_threshold 
*
*return an image where each pixel is proportional to the quality of that pixel
*within input, and thresholded to be either 0%,25%,50%, or 75%
*
*input -- image to compute quality for
*
*quality_winradius -- the window radius to use
*
*quality_abs_or_squ -- whether to use the abs algorithm or the squared 
*algorithm
*
*/
image<rgb> *quality_image_threshold( image<rgb> *input, int quality_winradius, char *quality_abs_or_squ )
{
  image<float> *qual = compute_quality( input, quality_winradius, quality_abs_or_squ );
  int w = qual->width();
  int h = qual->height();
  image<rgb> *ret = new image<rgb>(w, h);
  rgb *colors = new rgb[ 4 ];

  for ( int i = 0; i < 4; i++ )
    {
      rgb curr;
      curr.r = (uchar)(i*( 255 / 4 ));
      curr.g = curr.r;
      curr.b = curr.r;
      colors[ i ] = curr;
    }

  float qual_max = maximum( qual );
  for ( int i=0; i < h; i++ )
    {
      for ( int j=0; j < w; j++ )
	{
	  int index = (int)( floor( (qual->access[i][j]/qual_max) * 4) );
	  if ( index == 4 )
	    {
	      index = 3;
	    }
	  ret->data[ i*w + j ] = colors[ index ];

	}
    }
  return ret;
}
/* 
*compute quality 
*
*compute quality where each pixel is set to a quality value based on a window 
*centered on itself 
*
*im -- image to compute quality for
*
*quality_winradius -- the window radius to use
*
*quality_abs_or_squ -- whether to use the abs algorithm or the squared 
*algorithm 
*/
image<float> *compute_quality(image<rgb> *im, int quality_winradius, char *quality_abs_or_squ) 
{
  image<float> *gim    = grayscale( im );
  abs_qual aq( gim, quality_winradius );
  image<float> *ret;
  if ( strncmp( quality_abs_or_squ, "squ", 3) == 0 )
    {
      ret = aq.square_brute();
    }
  else if ( strncmp(quality_abs_or_squ, "abs", 3) == 0 )
    {
      ret = aq.main();
    }
  delete gim;
  return ret;
}

/* 
*compute quality crude
*
*compute quality where all pixels within a window get the same quality 
*value. 
*
*im -- image to compute quality for 
*
*win_len -- the length of the window. Each window is winlen*winlen number 
*of pixels
*
*The excess pixels which do not fit into a window are not computed on so 
*the returned image will be smaller than or equal to im
*/
image<float> *compute_quality_crude(image<rgb> *im, int win_len) 
{

  int height = im->height();
  int width  = im->width();

  int winlen  = win_len;
  int winsize = winlen*winlen;
  
  int h_small = (int)floor( height / winlen );
  int w_small = (int)floor( width /  winlen );
  
  int h_  = (int)floor( height / winlen ) * winlen;
  int w_  = (int)floor( width  / winlen ) * winlen;

  image<float> *window = new image<float>( winlen, winlen ); 
  image<float> *gim    = grayscale( im );

  image<float> *temp  = new image<float>( w_small, h_small );
  image<float> *ret   = new image<float>( w_ , h_ );
  
  // for each window find the square root of the variance 
  for ( int i=0; i <= h_ - winlen; i=i+winlen )
    {
      for ( int j=0; j <= w_ - winlen; j=j+winlen )
	{
	  for ( int k=0; k <= winlen - 1; k++ )
	    {
	      memcpy( window->access[k] , gim->data + (i+k)*width + j, winlen * sizeof(float) );
	    }
	  temp->access[ i / winlen ][ j / winlen ] = sqrt( variance( window ) );
	}
    }

  delete gim;
  fflush(stdout);
  delete window;
  fflush(stdout);

  // expand the values stored in temp and put them into ret
  for ( int i=0; i <= h_ - winlen;  i=i+winlen )
    {
      for ( int j=0; j <= w_ - winlen; j=j+winlen )
	{
	  for ( int k=0; k <= winlen - 1; k++ )
	    {
	      for ( int l=0; l <= winlen - 1; l++ )
		{
		  ret->data[ (i+k)*w_ + j + l ] = temp->access[ i / winlen ][ j / winlen ];
		}
	    }
	}
    }

  delete temp;
  return ret; 
  
}

/* 
*fuse_intensity_texture
*
*Produce a fused segmentation from an intensity segmentation and a texture
*segmentation using the computed quality
*
*input - original input image
*seg_intensity - intensity segmentation 
*seg_texture - texture segmentation 
*quality - the computed quality 
*
*/
image<rgb> *fuse_intensity_texture(image<rgb> *input, image<int> *seg_intensity, image<int> *seg_texture, image<float> *quality)
{
  int width  = seg_texture->width();
  int height = seg_texture->height();

  int num_pixels = width*height; 
  int num_labels = 2;
  GCoptimization::EnergyTermType *datacost,*smoothcost,*vertWeights,*horizWeights;
  GCoptimization::EnergyType engS,engD,engT;
  GCoptimization *optimize = (GCoptimization *) new GCoptimization(width,height,num_labels,SET_ALL_AT_ONCE,SET_ALL_AT_ONCE);

  datacost     = (GCoptimization::EnergyTermType *) new GCoptimization::EnergyTermType[height*width*num_labels];
  smoothcost   = (GCoptimization::EnergyTermType *) new GCoptimization::EnergyTermType[num_labels*num_labels];
  vertWeights  = (GCoptimization::EnergyTermType *) new GCoptimization::EnergyTermType[height*width];
  horizWeights = (GCoptimization::EnergyTermType *) new GCoptimization::EnergyTermType[height*width];

  float large_quality = nth_largest(quality, (int)(quality->height()*quality->width()*(3.0/4.0))  );

  // set the datacost based on the computed quality 
  for ( int i = 0; i < height; i++ )
    {
      for ( int j = 0; j < width; j++ )
	{
	  datacost[ i*width*num_labels + j*num_labels + 0] = quality->access[i][j];
	  float temp = large_quality - quality->access[i][j];
	  if ( temp < 0 )
	    temp = 0;
	  datacost[ i*width*num_labels + j*num_labels + 1] = temp;
	}
    }
  
  // set a cost of 0.15 to transition between texture and intensity
  for ( int i = 0; i < num_labels; i++ )
    {
      for ( int j = 0; j < num_labels; j++ )
	{
	  if ( i != j )
	    {
	      smoothcost[i*num_labels+j] = 0.15;
	    }
	  else 
	    {
	      smoothcost[i*num_labels+j] = 0;
	    }
	}
    }
	
  for ( int i = 0; i < height; i++ )
    {
      for (int j = 0; j < width; j++ )
	{
	  if ( i != height - 1 ) 
	    {
	      vertWeights[i*width + j] = 1;
	    }
	}
    }


  for ( int i = 0; i < height; i++ )
    {
      for ( int j = 0; j < width; j++ )
	{
	  if ( j != width - 1 )
	    {
	      horizWeights[i*width + j] = 1;
	    }
	}
    }

  optimize->setData(datacost);
  optimize->setSmoothness(smoothcost,horizWeights,vertWeights);
  
  for ( int i = 0; i < height; i++ )
    {
      for ( int j = 0; j < width; j++ )
	{
	  optimize->setLabel(i*width+j,0);
	}
    }

  engT = optimize->expansion(); //run expansion algorithm to convergence

  image<int> *temp_fused = new image<int>(width, height );
  int offset = maximum( seg_intensity ) + 1;

  /*
  image<rgb> *texture_intensity = new image<rgb>(width, height );
  rgb black;
  black.r = (unsigned char) 0;
  black.g = (unsigned char) 0;
  black.b = (unsigned char) 0;
  rgb white;
  white.r = (unsigned char) 255;
  white.g = (unsigned char) 255;
  white.b = (unsigned char) 255;
  */

  for ( int i = 0; i < height; i++ )
    {
      for ( int j = 0; j < width; j++ )
	{
	  if ( optimize->whatLabel(i*width + j) == 0 )
	    {
	      //texture_intensity->access[i][j] = black;
	      temp_fused->access[i][j] = seg_intensity->access[i][j];
	    }
	  else
	    {
	      //texture_intensity->access[i][j] = white;
	      temp_fused->access[i][j] = offset + seg_texture->access[i][j];
	    }
	}
    }
  //savePPM( texture_intensity, "texture_intensity.ppm" );

  image<rgb> *ret = seg_to_image( temp_fused );  
  delete temp_fused;
  return ret;
  
}
/* segment_image_texture
*
*segment an image based on texture
*
*im - input image 
*
*texture_winlength - the window length; each fourier
*vector is texture_length*texture_length number of pixels
*
*texture_kmeans_numclusters - the number of clusters for the kmeans
*algorithm 
*
*texture_cellalg_or_kmeans - whether to use the cellalg
*algorithm or the kmeans algorithm 
*
*
*texture_cellalg_epsilon - the epsilon parameter of the cellalg algorithm. This 
*controls how accurate vs. how fast the cellalg algorithm finds the nearest
*neighbors 
*
*texture_cellalg_thresh_pct_or_abs - whether the threshold used for joining 
*points under cellalg is specified as a percentile rank of all edge weights 
*or as an absolute value 
*
*texture_cellalg_thresh_val - the value for the threshold used for joining 
*points (either a percentile rank, specified as a number
*between 0 and 1 or as an absolute value)
* */
image<int> *segment_image_texture(image<rgb> *im, int texture_winlength, int texture_kmeans_numclusters,char *texture_cellalg_or_kmeans, float texture_cellalg_epsilon, char *texture_cellalg_thresh_pct_or_abs, float texture_cellalg_thresh_val )
{
  time_t curr,prev;
  int height = im->height();
  int width  = im->width();

  int winlen  = texture_winlength;
  int winsize = winlen*winlen;
  
  int h_small = (int)floor( height / winlen );
  int w_small = (int)floor( width /  winlen );
  
  int h_  = (int)floor( height / winlen ) * winlen;
  int w_  = (int)floor( width  / winlen ) * winlen;


  int num_clusters = texture_kmeans_numclusters;

  float *vecs = new float[ h_small * w_small * winsize ];
  image<float> *window = new image<float>( winlen, winlen ); 
  image<float> *gim    = grayscale( im );
  image<int> *ret = new image<int>( w_ , h_ );


  // set up the vecs containing the computed fourier transforms for each window
  prev = time(0);
  int vecs_index = 0;
  float **angle_table = fourier_table( winlen ); 
  for ( int i=0; i <= h_ - winlen; i=i+winlen )
    {
      for ( int j=0; j <= w_ - winlen; j=j+winlen )
	{
	  for ( int k=0; k <= winlen - 1; k++ )
	    {
	      memcpy( window->access[k] , gim->data + (i+k)*width + j, winlen * sizeof(float) );
	    }

	  image<float> *temp_window = abs_fourier_2( window, angle_table );
	  memcpy( vecs + vecs_index, temp_window->data, winsize * sizeof( float )); 
	  vecs_index = vecs_index + winsize;
	  delete temp_window;
	}
    }
  delete gim;
  delete window;
  for ( int i = 0; i < winlen; i++ )
    {
	  free( angle_table[i] );
    }
  free( angle_table );

  /*
  FILE *fouriers_output = fopen("fouriers.txt", "w");
  for ( int i = 0; i < h_small*w_small; i++ )
    {
      for ( int j = 0; j < winsize; j++ )
	{
	  fprintf( fouriers_output, "%g" , vecs[i*winsize + j] );
	  if ( j != winsize - 1 )
	    {
	      fprintf(fouriers_output, " ");
	    }
	}
      fprintf( fouriers_output, "\n");
    }
  fflush(fouriers_output);
  fclose(fouriers_output);
  */


  curr = time(0);
  printf("segment texture: compute fourier transforms: %g sec\n", difftime(curr,prev));

  int *cluster_index;
  rgb *colors; 
  if ( strncmp( texture_cellalg_or_kmeans, "cellalg", 7) == 0 )
    {
      prev = time(0);
      int npts = h_small*w_small;
      int dmns = winsize; 
      cellalg ca( texture_cellalg_epsilon, 10 );
      ca.set_params( npts, dmns , vecs );
      int k = 5;
      edge *edges = new edge[ k*npts ];
      int num_edges = 0;

      // set up a table to keep track of edges that have already been formed
      int *reptable = (int *) malloc( (npts * npts) * sizeof(int) );
      for ( register int i = 0; i < npts; i++ )
	{
	  for ( register int j = 0; j < npts; j++ )
	    {
	      if ( i < j )
		{
		  reptable[i*npts + j] = -1;
		}
	      else
		{
		  continue;
		}
	    }
	}
      
      std::vector<float> pq;
      time_t prevtemp, currtemp ; 
      prevtemp = time(0);
      // set up the graph where each point is connected to its k closest 
      // neighbors as computed from cellalg
      
      if ( texture_cellalg_epsilon != 0 )
	{
	  for ( int i = 0; i < npts; i++ )
	    {
	      dist_pt *sr = ca.k_closest(i, k);
	      for ( int j = 0; j < k; j++ )
		{
		  dist_pt d = sr[j];
		  if ( d.ptx == -1 )
		    {
		      printf("d.ptx == -1\n");
		      exit(-1);
		    }
		  if ( i == d.ptx )
		    {
		      continue;
		    }
		  int first;
		  int second;
		  if ( i < d.ptx )
		    {
		      first = i;
		      second = d.ptx; 
		    }
		  else
		    {
		      first = d.ptx; 
		      second = i;
		    }
		  if ( reptable[ first*npts+second ] == -1 )
		    {
		      reptable[ first*npts+second] = 1;

		      edges[num_edges].a = first;
		      edges[num_edges].b = second;
		      edges[num_edges].w = d.dist;
		      pq.push_back( d.dist );
		      num_edges++;
		    }
		}
	      free( sr );
	    }
	}
      else
	{
	  ca.brutetabinit();
	  for ( int i = 0; i < npts; i++ )
	    {
	      dist_pt *sr = ca.k_closest_brute(i, k);
	      for ( int j = 0; j < k; j++ )
		{
		  dist_pt d = sr[j];
		  if ( d.ptx == -1 )
		    {
		      printf("d.ptx == -1\n");
		      exit(-1);
		    }
		  if ( i == d.ptx )
		    {
		      continue;
		    }
		  int first;
		  int second;
		  if ( i < d.ptx )
		    {
		      first = i;
		      second = d.ptx; 
		    }
		  else
		    {
		      first = d.ptx; 
		      second = i;
		    }
		  if ( reptable[ first*npts+second ] == -1 )
		    {
		      reptable[ first*npts+second] = 1;

		      edges[num_edges].a = first;
		      edges[num_edges].b = second;
		      edges[num_edges].w = d.dist;
		      pq.push_back( d.dist );
		      num_edges++;
		    }
		}
	      free( sr );
	    }
	}
      currtemp = time(0);
      printf("segment texture: create graph: %g sec\n", difftime(currtemp,prevtemp));
      free( reptable );
      universe *u;
      // use the computed graph to find the segmentation 
      if ( strncmp( texture_cellalg_thresh_pct_or_abs, "pct", 3 ) == 0 )
	{
	  int index = vlib_round( pq.size() * texture_cellalg_thresh_val );
	  std::vector<float>::iterator pqi = pq.begin() + index;
	  std::nth_element( pq.begin() , pqi , pq.end() );
	  u = segment_graph( npts, num_edges, edges, pq[index]);
	}
      else if ( strncmp( texture_cellalg_thresh_pct_or_abs, "abs", 3 ) == 0 )
	{
	  u = segment_graph( npts, num_edges, edges, texture_cellalg_thresh_val);
	}

      cluster_index = (int *) malloc( npts * sizeof(int) );
      for ( int i = 0; i < npts; i++ )
	{
	  cluster_index[ i ] = u->find( i );
	}
      int num_comps = u->num_sets();
      colors = (rgb *) malloc( num_comps * sizeof(rgb) );
      for ( int i = 0; i < num_comps; i++ )
	{
	  colors[i] = random_rgb();
	}
      curr = time(0);
      printf("segment texture: run graph algorithm: %g sec\n", difftime(curr,prev));
    }
  else if ( strncmp( texture_cellalg_or_kmeans, "kmeans", 6 ) == 0 )
    {
      prev = time(0);
      cluster_index = k_means( vecs, h_small*w_small, winsize, num_clusters);
      curr = time(0);
      printf("segment texture: compute k_means: %g sec\n", difftime(curr,prev));
      delete vecs;

      colors = ( rgb *) malloc( num_clusters * sizeof( rgb ) );
      for ( int i = 0; i < num_clusters; i++ )
	{
	  colors[ i ] = random_rgb();
	}
    }
  
  int clust_idx = 0;
  for ( int i=0; i <= h_ - winlen;  i=i+winlen )
    {
      for ( int j=0; j <= w_ - winlen; j=j+winlen )
	{
	  for ( int k=0; k <= winlen - 1; k++ )
	    {
	      for ( int l=0; l <= winlen - 1; l++ )
		{
		  ret->data[ (i+k)*w_ + j + l ] = cluster_index [ clust_idx ] ;
		}
	    }
	  clust_idx++;
	}
    }
  delete cluster_index;
  delete colors;

  return ret; 
}




#endif
