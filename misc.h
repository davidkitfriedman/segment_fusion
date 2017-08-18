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

/* random stuff */

#ifndef MISC_H
#define MISC_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <image.h> 
#include <queue>
#include <ext/hash_map>


#ifndef M_PI
#define M_PI 3.141592653589793
#endif

typedef unsigned char uchar;

typedef struct { uchar r, g, b; }  rgb;

typedef struct { double h, s, v; } hsv;

inline bool operator==(const rgb &a, const rgb &b) {
  return ((a.r == b.r) && (a.g == b.g) && (a.b == b.b));
}

template <class T>
inline T abs(const T &x) { return (x > 0 ? x : -x); };

template <class T>
inline int sign(const T &x) { return (x >= 0 ? 1 : -1); };

template <class T>
inline T square(const T &x) { return x*x; };

template <class T>
inline T bound(const T &x, const T &min, const T &max) {
  return (x < min ? min : (x > max ? max : x));
}

template <class T>
inline bool check_bound(const T &x, const T&min, const T &max) {
  return ((x < min) || (x > max));
}

inline int vlib_round(float x) { return (int)(x + 0.5F); }

inline int vlib_round(double x) { return (int)(x + 0.5); }

inline double gaussian(double val, double sigma) {
  return exp(-square(val/sigma)/2)/(sqrt(2*M_PI)*sigma);
}

class IntMark;
typedef __gnu_cxx::hash_map<int, IntMark> hashInt; 
class IntMark
{
 public:
  int i;
  IntMark()
    {
      i = -1;
    }
  IntMark( int a )
    {
      i = a;
    }
};



// random color
rgb random_rgb(){ 
  rgb c;
  double r;
  
  c.r = (uchar)random();
  c.g = (uchar)random();
  c.b = (uchar)random();

  return c;
}


unsigned char uchar_max(unsigned char a, unsigned char b, unsigned char c)
{
  uchar temp;
  if ( a > b )
    temp = a;
  else
    temp = b;

  if ( temp > c )
    return temp;
  else
    return c;
}


float nth_largest( image<float> *table, int n )
{
  int size = table->height() * table->width();
  float ret;
  float *temp_copy = new float[ size ]; 
  memcpy(temp_copy, table->data, size * sizeof(float) );

  std::nth_element(temp_copy,  temp_copy + n,  temp_copy + size );
  ret = temp_copy[n];
  delete temp_copy;
  return ret;
}




float mean( image<float> *table )
{
  float ret = 0;
  for( int i = 0; i < table->height(); i++ )
    {
      for( int j = 0; j < table->width(); j++)
	{
	  ret = ret + table->access[i][j];
	}
    } 
  ret = ret / ( table->height() * table->width() );
  return ret;
}


float variance( image<float> *table )
{
  int h = table->height();
  int w = table->width();
  float avg_val = mean( table );

  float sum = 0;
  for ( int i = 0; i < h; i++ )
    {
      for ( int j = 0; j < w; j++ )
	{
	  sum = sum +  ( table->access[i][j]   -  avg_val ) * ( table->access[i][j] - avg_val );
	}
    }
  return sum / (h*w - 1);
}


float std_dev( image<float> *table )
{
  float ret = 0;
  float avg = mean( table );
  for( int i = 0; i < table->height(); i++ )
    {
      for( int j = 0; j < table->width(); j++)
	{
	  ret = ret + ( table->access[i][j] - avg )*(table->access[i][j] - avg );
	}
    } 
  ret =   sqrt(  ret  /  ((table->height() * table->width()) - 1) );
  return ret;
}





template <class T>
void print_table ( image<T> *table, char *real_complex, char *grid_list, char *title )
{
  if ( strncmp( real_complex, "real", 4) == 0 )
    {
      if ( strncmp( grid_list, "grid", 4) == 0 )
	{
	  printf("Table: %s\n", title );
	  for ( int i = 0; i < table->height(); i++ )
	    {
	      for ( int j = 0; j < table->width(); j++ )
		{
		  printf("%g\t", table->access[i][j] );
		}
	      printf("\n");
	    }
	}
      else if ( strncmp( grid_list, "list", 4) == 0 )
	{
	  for(int i = 0; i < table->height(); i++)
	    {
	      for(int j = 0; j < table->width(); j++ )
		{
		  printf("%s[%d][%d] = %g\n", title, i, j, table->access[i][j]);
		}
	      printf("\n");
	    }
	}

    }
  else if ( strncmp( real_complex, "complex", 7) == 0 )
    {
      if ( strncmp( grid_list, "grid", 4) == 0 )
	{
	  printf("Table: %s\n", title );
	  for(int i = 0; i < table->height(); i++)
	    {
	      for(int j = 0; j < table->width(); j=j+2 )
		{
		  printf("%9.5g + %9.5gi\t", table->access[i][j], table->access[i][j+1] );
		}
	      printf("\n");
	    }
	}
      else if ( strncmp( grid_list, "list", 4) == 0 )
	{

	  for(int i = 0; i < table->height(); i++)
	    {
	      for(int j = 0; j < table->width(); j=j+2 )
		{
		  printf("%s[%d][%d] = %9.5g + %9.5gi\n", title, i, j / 2, table->access[i][j], table->access[i][j+1] );
		}
	      printf("\n");
	    }
	}

    }
}


template <class T>
T maximum( image<T> *table )
{
  T max = table->access[0][0];
  for( int i = 0; i < table->height(); i++ )
    {
      for( int j = 0; j < table->width(); j++)
	{
	  T curr = table->access[i][j];
	  if ( curr > max )
	    {
	      max = curr;
	    }
	}
    } 
  return max;
}

image<float> *grayscale( image<rgb> *op1 )
{

  image<float> *ret = new image<float>( op1->width(), op1->height() );

  for( int i = 0; i < op1->height(); i++ )
    {
      for( int j = 0; j < op1->width(); j++)
	{
	  rgb curr = op1->access[i][j];
	  ret->access[i][j]   = uchar_max(curr.r, curr.g, curr.b ) / 255.0;
	}
    } 
  return ret;
}


image<float> *get_nhood( image<float> *im, int row, int col, int win_rad )
{
  int h = im->height();
  int w = im->width();

  int startr,startc,endr,endc;


  if ( row - win_rad < 0 )
    {  
      startr = 0;
      endr   = row + win_rad; 
    }
  else if ( row + win_rad > h - 1 )
    {
      startr = row - win_rad;
      endr   = h - 1;
    }
  else 
    {
      startr = row - win_rad;
      endr   = row + win_rad;
    }
  

  if ( col - win_rad < 0 )
    {
      startc = 0;
      endc   = col + win_rad;
    }
  else if ( col + win_rad > w - 1 )
    {
      startc = col - win_rad;
      endc   = w - 1;
    }
  else 
    {
      startc = col - win_rad;
      endc   = col + win_rad;
    }

  image<float> *window = new image<float>( endc - startc + 1, endr - startr + 1 );
  int i,j,k,l;
  for ( i =startr,k=0; i <= endr; i++,k++ )
    {
      for ( j=startc,l=0; j <= endc; j++,l++ )
	{
	  window->access[k][l] = im->access[i][j];
	}
    }
  return window;
}


float **fourier_table( int n )
{
  float **angle_table = (float **) malloc( n * sizeof(float *) );
  for ( int i = 0; i < n; i++ )
    {
      angle_table[i] = (float *) malloc( n*2*sizeof(float));
    }
  
  for ( int i = 0; i < n ; i++ )
    {
      for ( int j = 0; j < n; j++ )
	{
	  angle_table[i][2*j  ] = cos( j * (i * (2 * M_PI)/n)   );
	  angle_table[i][2*j+1] = sin( j * (i * (2 * M_PI)/n)   );
	}
    }
  return angle_table;
}

// compute the absolute value of a two dimensional fourier transform
image<float> *abs_fourier_2 ( image<float> *win, float **angle_table )
{
  int n = win->width();

  image<float> *temp_first = new image<float>( 2*n, n );
  for ( int row = 0; row < n; row++ )
    {
      for ( int i = 0; i < n; i++ )
	{
	  float real_sum = 0;
	  float imag_sum = 0;
	  
	  for ( int j = 0; j < n; j++ )
	    {
	      real_sum = real_sum + win->access[row][j]*angle_table[i][2*j  ];
	      imag_sum = imag_sum + win->access[row][j]*angle_table[i][2*j+1];
	    }
	  temp_first->access[row][2*i  ] = real_sum;
	  temp_first->access[row][2*i+1] = imag_sum;
	}
    }

  image<float> *temp_second = new image<float>( 2*n, n );

  for ( int col = 0; col < n; col++ )
    {
      for ( int i = 0; i < n; i++ )
	{
	  float real_sum = 0;
	  float imag_sum = 0;

	  for ( int j = 0; j < n; j++ )
	    {
	      real_sum = real_sum + temp_first->access[j][2*col  ]*angle_table[i][2*j  ] -
                    		    temp_first->access[j][2*col+1]*angle_table[i][2*j+1];
	      imag_sum = imag_sum + temp_first->access[j][2*col  ]*angle_table[i][2*j+1] +
                         	    temp_first->access[j][2*col+1]*angle_table[i][2*j  ];
	    }
	  temp_second->access[i][2*col  ] = real_sum;
	  temp_second->access[i][2*col+1] = imag_sum;
	}
    }
  delete temp_first;

  image<float> *ret = new image<float>(n, n);
  for ( int row = 0; row < n; row++ )
    {
      for ( int col = 0; col < n; col++ )
	{
	  ret->access[row][col] = sqrt( temp_second->access[row][2*col  ] *
					temp_second->access[row][2*col  ] +
					temp_second->access[row][2*col+1] *
					temp_second->access[row][2*col+1] );
	}
    }
  delete temp_second;
  return ret;
}


float k_means_vector_diff( float *vecs, int i, float *cluster_centers, int j, int dms)
{

  float diff = 0;
  for ( int k = 0; k < dms; k++ )
    {
      diff += abs( vecs[ i*dms + k] - cluster_centers[ j*dms + k] ); 
    }
  return diff;
}

/* 
* k_means
*
* Run the k_means clustering algorithm
*
* vecs - the vectors to cluster
* num_points - the number of vectors
* dms - the size of each vector
* num_clusters - the number of clusters
*/
int *k_means( float *vecs, int num_points, int dms, int num_clusters)
{

  int num_iters = 5;
  float *best_cluster_centers = new float[ num_clusters * dms ];
  int *best_cluster_index     = new int  [ num_points ]; 
  float best_diff; 
  
    
  float *cluster_centers     = new float[ num_clusters * dms ];
  float *new_cluster_centers = new float[ num_clusters * dms ];
  int   *cluster_index       = new int  [ num_points ];
  int   *old_cluster_index   = new int  [ num_points ];
  int   *cluster_size        = new int  [ num_clusters ];

  for (int iter = 0; iter < num_iters; iter++ )
    {
      // set the original cluster centers to random points among the vectors
      for ( int k = 0; k < num_clusters; k++ )
	{
	  int rand_point =  vlib_round( ((rand() * 1.0)/RAND_MAX)*num_points ); 
	  memcpy( cluster_centers + k*dms, vecs + rand_point*dms, dms*sizeof(float) );
	}

      int k_means_cnt = 0;
      while ( 1 )
	{
	  /*("k means iteration: %d:%d\n", iter, k_means_cnt )*/;
	  

	  // for each point find the closest center to it
	  for ( int i = 0; i < num_points; i++ )
	    {
	      float min_diff;
	      int min_diff_index = -1;
	      
	      for ( int j = 0; j < num_clusters; j++ )
		{
		  float current_diff = k_means_vector_diff(vecs, i, cluster_centers, j, dms);
		  
		  if ( (j==0) || (current_diff < min_diff) )
		    {
		      min_diff = current_diff;
		      min_diff_index = j;
		    }
		}
	      cluster_index[i] = min_diff_index;
	    }

	  // find the new cluster centers 
	  memset(cluster_size, 0, num_clusters * sizeof(float) );
	  memset(new_cluster_centers, 0, num_clusters * dms * sizeof(float) );

	  for ( int i = 0; i < num_points; i++)
	    {
		int curr_index = cluster_index[i];
		cluster_size[curr_index]++;
	      
		for ( int j = 0; j < dms; j++ )
		  {
		    new_cluster_centers[curr_index*dms + j] += vecs[i*dms + j];
		  }
	    }

	  for ( int i = 0; i < num_clusters; i++ )
	    {
	      for ( int j = 0; j < dms; j++ )
		{
		  new_cluster_centers[i*dms + j] /= cluster_size[i];
		}
	    }


	  // break if none of the cluster centers have changed
	  if ( k_means_cnt != 0 )
	    {
	      int k_means_converged = 1;
	      for ( int i = 0; i < num_points; i++ )
		{
		  if (  old_cluster_index[i] != cluster_index[i]  )
		    {
		      k_means_converged = 0;
		      break;
		    }
		}

	      if ( k_means_converged )
		{
		  break;
		}
	    }

	  memcpy( old_cluster_index, cluster_index,     num_points   * sizeof(int) ); 
	  memcpy( cluster_centers, new_cluster_centers, num_clusters * dms * sizeof(float));
	  k_means_cnt++;
	}

      float diff = 0;
      for( int i = 0; i < num_points; i++ )
	{
	  diff += k_means_vector_diff( vecs, i, new_cluster_centers, cluster_index[i], dms);
	}

      // take the solution with the smallest difference
      if ( (iter == 0) ||  (diff < best_diff) )
	{
	  best_diff = diff; 
	  memcpy( best_cluster_centers, new_cluster_centers, num_clusters * dms * sizeof(float));
	  memcpy( best_cluster_index  , cluster_index,       num_points * sizeof(int));
	}
    }

  delete best_cluster_centers;
  delete cluster_size;
  delete cluster_centers;
  delete new_cluster_centers;
  delete cluster_index;
  delete old_cluster_index;
  delete cluster_size;

  return best_cluster_index;

}


// produce an rgb image where each independent segment
// gets a different random color
image<rgb> *seg_to_image( image<int> *img )
{
  int w = img->width();
  int h = img->height();
  int num_segs = maximum( img ) + 1;
  rgb *colors = new rgb[h*w];
  image<rgb> *ret = new image<rgb>( w, h );


  for ( int i = 0; i < w*h; i++ )
    {
      colors[i] = random_rgb();
    }

  for ( int i = 0; i < h; i++ )
    {
      for ( int j = 0; j < w; j++ )
	{
	  ret->access[i][j] = colors[ img->access[i][j] ];
	}
    }

  delete [] colors;
  return ret;
}

image<rgb> *qual_to_image( image<float> *qual)
{
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



#endif
