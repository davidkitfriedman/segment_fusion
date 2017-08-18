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

#include "abs_qual.h"

abs_qual::abs_qual( image<float> *img, int wr )
{
  im = img;
  winradius = wr;
  h = im->height();
  w = im->width();
}

float abs_qual::var(int r, int c )
{
  int sr = r - winradius; 
  int er = r + winradius;
  int sc = c - winradius;
  int ec = c + winradius;

  if ( sr < 0 )
    {
      sr = 0;
    }
  
  if ( er > h - 1 )
    {
      er = h - 1;
    }

  if ( sc < 0 )
    {
      sc = 0;
    }

  if ( ec > w - 1 )
    {
      ec = w - 1;
    }
  float sum = 0;
  for ( int i = sr; i <= er; i++ )
    {
      for ( int j = sc; j <= ec; j++ )
	{
	  sum = sum + im->access[i][j];
	}
    }
  int count = ( er - sr + 1 ) * ( ec - sc + 1 );
  float mean = sum / count; 
  sum = 0;
  for ( int i = sr; i <= er; i++ )
    {
      for ( int j = sc; j <= ec; j++ )
	{
	  float curr = im->access[i][j];
	  sum = sum + fabsf( mean - curr );
	}
    }
  return sum/count;
}


float abs_qual::square_var(int r, int c )
{
  int sr = r - winradius; 
  int er = r + winradius;
  int sc = c - winradius;
  int ec = c + winradius;

  if ( sr < 0 )
    {
      sr = 0;
    }
  
  if ( er > h - 1 )
    {
      er = h - 1;
    }

  if ( sc < 0 )
    {
      sc = 0;
    }

  if ( ec > w - 1 )
    {
      ec = w - 1;
    }
  float sum = 0;
  for ( int i = sr; i <= er; i++ )
    {
      for ( int j = sc; j <= ec; j++ )
	{
	  sum = sum + im->access[i][j];
	}
    }
  int count = ( er - sr + 1 ) * ( ec - sc + 1 );
  float mean = sum / count; 
  sum = 0;
  for ( int i = sr; i <= er; i++ )
    {
      for ( int j = sc; j <= ec; j++ )
	{
	  float curr = im->access[i][j];
	  sum = sum + (mean - curr)*(mean-curr);
	}
    }
  return sum/count;
}



int abs_qual::floatcmp( float a, float b )
{
  float diff = a - b;
  float floatcmpepsilon = 0.000050;
  if ( diff < -floatcmpepsilon )
    {
      return -1;
    }
  else if ( diff > floatcmpepsilon )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

image<float> *abs_qual::brute()
{
  image<float> *ret = new image<float>(w, h);
  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  ret->access[i][j] = var(i,j);
	}
    }
  return ret;
}


image<float> *abs_qual::square_brute()
{
  image<float> *ret = new image<float>(w, h);
  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  ret->access[i][j] = square_var(i,j);
	}
    }
  return ret;
}



void abs_qual::mainvsbrute()
{
  time_t prev,curr;

  prev = time(0);
  image<float> *retmain = main();
  curr = time(0);
  printf("main elapsed time: %g\n", difftime(curr,prev));

  prev = time(0);
  image<float> *retbrute = brute();
  curr = time(0);
  printf("brute elapsed time: %g\n", difftime(curr,prev));

  bool done = false;
  for ( int c = 0; c <= w - 1; c++ )
    {
      for ( int r = 0; r <= h - 1; r++ )
	{

	  if ( floatcmp( retbrute->access[r][c],retmain->access[r][c] ) == 0 )
	    {
	      continue;
	    }
	  else
	    {
	      // each line not near the top or bottom is 11 coordinates
	      int sr = r - 5 >= 0 ? r - 5 : 0;
	      int er = r + 5 <= h - 1 ? r + 5 : h - 1;
	      printf("brute[%d-%d,%d] =\n",sr,er,c);
	      for ( int i = sr; i <= er; i++ )
		{
		  if ( i == sr )
		    {
		      printf("[%f,\n", retbrute->access[i][c] );
		    }
		  else if ( i == er )
		    {
		      printf(" %f]\n",  retbrute->access[i][c]);
		    }
		  else
		    {
		      printf(" %f,\n",  retbrute->access[i][c]);
		    }
		}
	      printf("\n");

	      printf("main [%d-%d,%d] =\n",sr,er,c);
	      for ( int i = sr; i <= er; i++ )
		{
		  if ( i == sr )
		    {
		      printf("[%f,\n", retmain->access[i][c] );
		    }
		  else if ( i == er )
		    {
		      printf(" %f]\n", retmain->access[i][c] );
		    }
		  else
		    {
		      printf(" %f,\n", retmain->access[i][c] );
		    }
		}
	      done = true;
	      break;
	    }
	}
      if ( done )
	{
	  break;
	}
    }
  

}

float abs_qual::set( int r, int c )
{
  int sr = r - winradius;
  int er = r + winradius;
  int sc = c - winradius;
  int ec = c + winradius;

  if ( sr < 0 )
    {
      sr = 0;
    }

  if ( er > h - 1 )
    {
      er = h - 1;
    }

  if ( sc < 0 )
    {
      sc = 0;
    }

  if ( ec > w - 1 )
    {
      ec = w - 1;
    }

  n = ( er - sr + 1 ) * ( ec - sc + 1 );
  old_sum = 0;
  for ( int i = sr; i <= er; i++ )
    {
      for ( int j = sc; j <= ec; j++ )
	{
	  old_sum = old_sum + im->access[i][j];
	}
    }

  old_mean = old_sum / n;


  below_count = 0;
  below_sum = 0;
  above_count = 0;
  above_sum = 0;
  for ( int i = sr; i <= er; i++ )
    {
      float *currrow = im->access[i];
      for ( int j = sc; j <= ec; j++ )
	{
	  float curr = currrow[j];
	  if ( curr <= old_mean )
	    {
	      below_count++;
	      below_sum = below_sum + old_mean - curr;
	    }
	  else
	    {
	      above_count++;
	      above_sum = above_sum + curr - old_mean;
	    }
	}
    }
  return (below_sum + above_sum) / n;
}

image<float> *abs_qual::main()
{
  // go through all points and find the abs qual for each
  image<float> *ret = new image<float>( w, h );
  int r = 0;
  int c = 0;
  // find for the first point and set initial state
  ret->access[r][c] = set(r,c);
  decl_saves;

  // left edge
  save_state;
  for ( c = 0; c <= winradius; c++ )
    {
      for ( r = 1; r <= winradius; r++ )
	{
	  ret->access[r][c] = transrow_ins( r+winradius,0,c+winradius);
	}
      
      for ( r = winradius+1; r <= (h-1)-winradius; r++ )
	{
	  ret->access[r][c] = transrow_delins(r-winradius-1,r+winradius,0,c+winradius);
	}

      for ( r = (h-1)-winradius+1; r <= h - 1; r++ )
	{
	  ret->access[r][c] = transrow_del( r-winradius-1, 0, c+winradius);
	}
      get_state;

      if ( c != winradius )
	{
	  ret->access[0][c+1] = transcol_ins( c+1+winradius );
	  save_state;
	}
      else
	{
	  ret->access[0][c+1] = transcol_delins(0, c+1+winradius );
	}
    }

  // middle
  save_state;
  for ( c = winradius + 1; c <= (w-1)-winradius; c++ )
    {
      // top 
      for ( r = 1; r <= winradius; r++ )
	{
	  ret->access[r][c] = transrow_ins( r+winradius, c-winradius, c+winradius );
	}

      for ( r = winradius + 1; r <= (h-1)-winradius; r++ )
	{
	  ret->access[r][c] = transrow_delins( r-winradius-1, r+winradius, c-winradius, c+winradius );
	}

      for ( r = (h-1)-winradius+1; r <= h - 1; r++ )
	{
	  ret->access[r][c] = transrow_del( r-winradius-1, c-winradius, c+winradius );
	}
      get_state;
      if ( c != ( w-1 ) - winradius )
	{
	  ret->access[0][c+1] = transcol_delins( c+1-winradius-1, c+1+winradius);
	  save_state;
	}
      else
	{
	  ret->access[0][c+1] = transcol_del( c+1-winradius-1 );
	}
    }

  // right edge
  save_state;
  for ( c = (w-1)-winradius+1; c <= w-1; c++ )
    {
      for ( r = 1; r <= winradius; r++ )
	{
	  ret->access[r][c] = transrow_ins( r+winradius, c-winradius, w-1);
	}

      for ( r = winradius+1; r <= (h-1)-winradius ; r++ )
	{
	  ret->access[r][c] = transrow_delins( r-winradius-1, r+winradius, c-winradius, w-1);
	}

      for ( r = (h-1)-winradius+1; r <= h - 1; r++ )
	{
	  ret->access[r][c] = transrow_del( r-winradius-1, c-winradius, w-1);
	}

      if ( c != w-1 )
	{
	  get_state;
	  ret->access[0][c+1] = transcol_del( c+1-winradius-1);
	  save_state;
	}
    }
  return ret;
}


float abs_qual::transrow_delins( int delrow, int insrow, int startcol, int endcol )
{
  float *dels = im->access[delrow];
  float *adds = im->access[insrow];
  new_sum = old_sum;

  // Handle points to be deleted
  for ( int i = startcol; i <= endcol; i++ )
    {
      float curr = dels[i];
      new_sum = new_sum - curr + adds[i];
      if ( curr <= old_mean )
	{
	  below_count--;
	  below_sum = below_sum - ( old_mean - curr );
	}
      else
	{
	  above_count--;
	  above_sum = above_sum - ( curr - old_mean );
	}
    }
  new_mean = new_sum / n;

  // Handle retained points
  float meandiff = new_mean - old_mean;
  int transptscnt = 0;
  if ( meandiff > 0 )
    {
      for ( int i = delrow + 1; i <= insrow - 1; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = startcol; j <= endcol; j++ )
	    {
	      float curr = currrow[j];
	      if ( old_mean < curr && curr <= new_mean )
		{
		  above_count--;
		  below_sum = below_sum + ( new_mean - curr );
		  above_sum = above_sum - ( curr - old_mean );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      below_count = below_count + transptscnt;
    }
  else if ( meandiff < 0 )
    {
      for ( int i = delrow+1; i <= insrow - 1; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = startcol; j <= endcol; j++ )
	    {
	      float curr = currrow[j];
	      if ( new_mean < curr && curr <= old_mean )
		{
		  below_count--;
		  above_sum = above_sum + ( curr - new_mean );
		  below_sum = below_sum - ( old_mean - curr );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      above_count = above_count + transptscnt;
    }

  // Handle added points
  for ( int i = startcol; i <= endcol; i++ )
    {
      float curr = adds[i];
      if ( curr <= new_mean )
	{
	  below_count++;
	  below_sum = below_sum + ( new_mean - curr );
	}
      else
	{
	  above_count++;
	  above_sum = above_sum + ( curr - new_mean );
	}
    }
  old_mean = new_mean;
  old_sum  = new_sum; 
  return (below_sum + above_sum)/n;
}



float abs_qual::transrow_ins( int insrow, int startcol, int endcol )
{
  float *adds = im->access[insrow];
  new_sum = old_sum;
  for ( int i = startcol ; i <= endcol; i++ )
    {
      new_sum = new_sum + adds[i];
    }
  n = n + endcol - startcol + 1;
  new_mean = new_sum / n;

  float meandiff = new_mean - old_mean;
  int transptscnt = 0;
  if ( meandiff > 0 )
    {
      for ( int i = 0; i <= insrow - 1; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = startcol; j <= endcol; j++ )
	    {
	      float curr = currrow[j];
	      if ( old_mean < curr && curr <= new_mean )
		{
		  above_count--;
		  below_sum = below_sum + ( new_mean - curr );
		  above_sum = above_sum - ( curr - old_mean );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      below_count = below_count + transptscnt;
    }
  else if ( meandiff < 0 )
    {
      for ( int i = 0; i <= insrow - 1; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = startcol; j <= endcol; j++ )
	    {
	      float curr = currrow[j];
	      if ( new_mean < curr && curr <= old_mean )
		{
		  below_count--;
		  above_sum = above_sum + ( curr - new_mean );
		  below_sum = below_sum - ( old_mean - curr );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      above_count = above_count + transptscnt;
    }

  for ( int i = startcol; i <= endcol; i++ )
    {
      float curr = adds[i];
      if ( curr <= new_mean )
	{
	  below_count++;
	  below_sum = below_sum + ( new_mean - curr );
	}
      else
	{
	  above_count++;
	  above_sum = above_sum + ( curr - new_mean );
	}
    }
  old_mean = new_mean;
  old_sum  = new_sum;
  return (below_sum + above_sum)/n; 
}
	  
float abs_qual::transrow_del( int delrow, int startcol, int endcol )
{
  float *dels = im->access[delrow];
  new_sum = old_sum;
  for ( int i = startcol; i <= endcol; i++ )
    {
      float curr = dels[i];
      new_sum = new_sum - curr;
      if ( curr <= old_mean )
	{
	  below_count--;
	  below_sum = below_sum - ( old_mean - curr );
	}
      else
	{
	  above_count--;
	  above_sum = above_sum - ( curr - old_mean );
	}
    }
  n = n - ( endcol - startcol + 1 );
  new_mean = new_sum / n;
  
  float meandiff = new_mean - old_mean;
  int transptscnt = 0;
  if ( meandiff > 0 )
    {
      for ( int i = delrow+1; i <= h - 1; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = startcol; j <= endcol; j++ )
	    {
	      float curr = currrow[j];
	      if ( old_mean < curr && curr <= new_mean )
		{
		  above_count--;
		  below_sum = below_sum + ( new_mean - curr );
		  above_sum = above_sum - ( curr - old_mean );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      below_count = below_count + transptscnt;
    }
  else if ( meandiff < 0 )
    {
      for ( int i = delrow + 1; i <= h - 1; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = startcol; j <= endcol; j++ )
	    {
	      float curr = currrow[j];
	      if ( new_mean < curr && curr <= old_mean )
		{
		  below_count--;
		  above_sum = above_sum + ( curr - new_mean );
		  below_sum = below_sum - ( old_mean - curr );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      above_count = above_count + transptscnt;
    }
  old_mean = new_mean;
  old_sum  = new_sum;
  return (below_sum + above_sum)/n;
}


float abs_qual::transcol_delins( int delcol, int inscol )
{
  new_sum = old_sum; 
  for ( int i = 0; i <= winradius; i++ )
    {
      float curr = im->access[i][delcol];
      new_sum = new_sum - curr + im->access[i][inscol];
      if ( curr <= old_mean )
	{
	  below_count--;
	  below_sum = below_sum - ( old_mean - curr );
	}
      else
	{
	  above_count--;
	  above_sum = above_sum - ( curr - old_mean );
	}
    }
  new_mean = new_sum / n;
  
  float meandiff = new_mean - old_mean;
  int transptscnt = 0;
  if ( meandiff > 0 )
    {
      for ( int i = 0; i <= winradius; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = delcol+1; j <= inscol-1; j++ )
	    {
	      float curr = currrow[j];
	      if ( old_mean < curr && curr <= new_mean )
		{
		  above_count--;
		  below_sum = below_sum + ( new_mean - curr );
		  above_sum = above_sum - ( curr - old_mean );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      below_count = below_count + transptscnt;
    }
  else if ( meandiff < 0 )
    {
      for ( int i = 0; i <= winradius; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j=delcol+1; j <= inscol-1; j++ )
	    {
	      float curr = currrow[j];
	      if ( new_mean < curr && curr <= old_mean )
		{
		  below_count--;
		  above_sum = above_sum + ( curr - new_mean );
		  below_sum = below_sum - ( old_mean - curr );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      above_count = above_count + transptscnt;
    }

  for ( int i = 0 ; i <= winradius; i++ )
    {
      float curr = im->access[i][inscol];
      if ( curr <= new_mean )
	{
	  below_count++;
	  below_sum = below_sum + ( new_mean - curr );
	}
      else
	{
	  above_count++;
	  above_sum = above_sum + ( curr - new_mean );
	}
    }
  old_mean = new_mean;
  old_sum  = new_sum;
  return (below_sum + above_sum)/n; 
}
  

float abs_qual::transcol_ins( int inscol )
{
  new_sum = old_sum;
  for ( int i = 0; i <= winradius; i++ )
    {
      new_sum = new_sum + im->access[i][inscol];
    }
  n = n + winradius + 1;
  new_mean = new_sum / n;

  float meandiff = new_mean - old_mean;
  int transptscnt = 0;
  if ( meandiff > 0 )
    {
      for ( int i = 0; i <= winradius; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = 0; j <= inscol - 1; j++ )
	    {
	      float curr = currrow[j];
	      if ( old_mean < curr && curr <= new_mean )
		{
		  above_count--;
		  below_sum = below_sum + ( new_mean - curr );
		  above_sum = above_sum - ( curr - old_mean );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      below_count = below_count + transptscnt;
    }
  else if ( meandiff < 0 )
    {
      for ( int i = 0; i <= winradius; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = 0; j <= inscol - 1; j++ )
	    {
	      float curr = currrow[j];
	      if ( new_mean < curr && curr <= old_mean )
		{
		  below_count--;
		  above_sum = above_sum + ( curr - new_mean );
		  below_sum = below_sum - ( old_mean - curr );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      above_count = above_count + transptscnt;

    }

  for ( int i = 0; i <= winradius; i++ )
    {
      float curr = im->access[i][inscol];
      if ( curr <= new_mean )
	{
	  below_count++;
	  below_sum = below_sum + ( new_mean - curr );
	}
      else
	{
	  above_count++;
	  above_sum = above_sum + ( curr - new_mean );
	}
    }
  old_mean = new_mean;
  old_sum  = new_sum;
  return (below_sum + above_sum)/n;
}


float abs_qual::transcol_del( int delcol )
{
  new_sum = old_sum; 
  for ( int i = 0; i <= winradius; i++ )
    {
      float curr = im->access[i][delcol];
      new_sum = new_sum - curr;
      if ( curr <= old_mean )
	{
	  below_count--;
	  below_sum = below_sum - ( old_mean - curr );
	}
      else
	{
	  above_count--;
	  above_sum = above_sum - ( curr - old_mean );
	}
    }
  n = n - ( winradius + 1 );
  new_mean = new_sum / n;

  float meandiff = new_mean - old_mean;
  int transptscnt = 0;
  if ( meandiff > 0 )
    {
      for ( int i = 0; i <= winradius; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = delcol+1; j <= w-1; j++ )
	    {
	      float curr = currrow[j];
	      if ( old_mean < curr && curr <= new_mean )
		{
		  above_count--;
		  below_sum = below_sum + ( new_mean - curr );
		  above_sum = above_sum - ( curr - old_mean );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      below_count = below_count + transptscnt;
    }
  else if ( meandiff < 0 )
    {
      for ( int i = 0; i <= winradius; i++ )
	{
	  float *currrow = im->access[i];
	  for ( int j = delcol+1; j <= w-1; j++ )
	    {
	      float curr = currrow[j];
	      if ( new_mean < curr && curr <= old_mean )
		{
		  below_count--;
		  above_sum = above_sum + ( curr - new_mean );
		  below_sum = below_sum - ( old_mean - curr );
		  transptscnt++;
		}
	    }
	}
      below_sum = below_sum + meandiff*below_count;
      above_sum = above_sum - meandiff*above_count;
      above_count = above_count + transptscnt;
    }
  old_mean = new_mean;
  old_sum  = new_sum;
  return (above_sum + below_sum)/n;
}

