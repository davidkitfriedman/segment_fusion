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

#ifndef ABS_QUAL
#define ABS_QUAL

#include <time.h>
#include "image.h"
#include <cstdio>
#include "math.h"
#include <stdlib.h>

class abs_qual
{
 public:
  // state variables
  float old_sum;
  float old_mean;
  float new_sum;
  float new_mean;
  int below_count;
  float below_sum;
  int above_count;
  float above_sum;
  int n;

  image<float> *im;
  int h;
  int w;
  int winradius;

  abs_qual( image<float> *img, int wr);

  // the main abs algorithm
  image<float> *main();

  // find the abs quality for a particular point at location (r,c)
  float set(int r, int c );

  float var( int r, int c );

  // compute the absolute value quality using brute force
  image<float> *brute();

  float square_var( int r, int c );
  
  // compute the squared quality using brute force
  image<float> *square_brute();

  // compare performance of main algorithm and brute force
  void mainvsbrute();

  int floatcmp( float a, float b );

  // transition functions
  float transrow_delins ( int delrow, int insrow, int startcol, int endcol );
  float transrow_ins    ( int insrow, int startcol, int endcol );
  float transrow_del    ( int delrow, int startcol, int endcol );
  float transcol_delins ( int delcol, int inscol );
  float transcol_ins    ( int inscol );
  float transcol_del    ( int delcol );

};

#define decl_saves float saved_old_sum;\
                   float saved_old_mean;\
                   int saved_below_count;\
                   float saved_below_sum;\
                   int saved_above_count;\
                   float saved_above_sum;\
                   int saved_n

#define save_state saved_old_sum     = old_sum;\
                   saved_old_mean    = old_mean;\
                   saved_below_count = below_count;\
                   saved_below_sum   = below_sum;\
                   saved_above_count = above_count;\
                   saved_above_sum   = above_sum;\
                   saved_n           = n

#define get_state old_sum     = saved_old_sum;\
                  old_mean    = saved_old_mean;\
                  below_count = saved_below_count;\
                  below_sum   = saved_below_sum;\
                  above_count = saved_above_count;\
                  above_sum   = saved_above_sum;\
                  n           = saved_n

#endif
