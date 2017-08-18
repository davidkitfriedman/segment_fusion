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

#include <misc.h>
#include <pnmfile.h>
#include <cellalg.h>
#include <time.h>




void segment_image_texture(image<rgb> *im, int texture_winlength, int texture_kmeans_numclusters,char *texture_cellalg_or_kmeans, char *texture_cellalg_thresh_pct_or_abs, float texture_cellalg_thresh_val, float texture_cellalg_epsilon )
{
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

  if ( strncmp( texture_cellalg_or_kmeans, "cellalg", 7) == 0 )
    {
      char *filename = (char *) malloc( 256 * sizeof(char) );
      int npts = h_small*w_small;
      int dmns = winsize; 
      cellalg ca( texture_cellalg_epsilon, 10 );
      ca.set_params( npts, dmns , vecs );
      /* 25 characters and then the trailing null */
      strncpy( filename, "test_brutevcell_debug.txt", 26 );
      ca.brutevcell( filename );
    }
  
  return;

}

int main(int argc, char **argv) 
{
  if ( argc != 4 )
    {       
      fprintf(stderr, "%s input(ppm) texture_winlength texture_cellalg_epsilon\n", argv[0]);
      exit(0);
    }
  
  printf("loading input image: %s\n", argv[1]);
  image<rgb> *input = loadPPM(argv[1]);

  // parse args
  int texture_winlength = atoi( argv[2] );
  char *texture_cellalg_or_kmeans = (char *) malloc( 256 * sizeof(char));
  char *texture_cellalg_thresh_pct_or_abs = (char *) malloc( 256 * sizeof(char));
  float texture_cellalg_thresh_val = 0.75;
  int texture_kmeans_numclusters = 5;
  float texture_cellalg_epsilon = atof( argv[3] );

  strncpy( texture_cellalg_or_kmeans, "cellalg", 7);
  strncpy( texture_cellalg_thresh_pct_or_abs, "pct", 3);


  // segment texture 
  segment_image_texture(input, texture_winlength, texture_kmeans_numclusters,texture_cellalg_or_kmeans, texture_cellalg_thresh_pct_or_abs, texture_cellalg_thresh_val, texture_cellalg_epsilon);

  return 0;
}
