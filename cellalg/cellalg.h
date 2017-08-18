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

#ifndef CELLALG_H
#define CELLALG_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#include <queue>
#include <ext/hash_map>
class Bool;
typedef __gnu_cxx::hash_map<int, Bool>  hash;


class tree_node;
class cell;
class dist_pt;
class dist_pt_compare;
class cell_compare;

class cellalg
{
 public:
  cellalg();
  cellalg(float e , int buck_size );

  // set the dimension, the number of points, and the 
  // array containing the points
  void set_params( int m, int n, float *points );
  
  // a table holding the distance between points and the distance between
  // points and cells for use by the cell algorithm
  float *disttab;

  // a table containing the distance between points (used by k_closest_brute)
  float *brutetab;

  int dmns;
  int cellcount;

  // the maximum number of points that fit into a single entry in the tree
  int bucket_size;

  // epsilon is a parameter of the algorithm eps is 
  // used for floating points comparisons
  float epsilon;
  float eps;

  tree_node *root;
  int npts; 
  float *pts;
  int print_index;


  void split_pts_helper( int *ptsx, int nptsx, tree_node *node );
  void split_pts();

  // find the k_closest points using the cell algorithm
  dist_pt *k_closest( int locx, int k );

  void brutetabinit();
  float brutetabdist( int pntx1, int pntx2 );

  // find the k_closest points using brute force
  dist_pt *k_closest_brute( int locx, int k );

  
  float dist( int pntx1, int pntx2, cell *cll );

  // find the closest point within cell cll to point loc
  float *closest_point( cell *cll, float *loc );

  void disttab_init();
  float dist_raw( float *pnt1, float *pnt2 );

  // get the cell corresponding to a given location (used by k_closest)
  cell *get_unmarked_cell( float *loc, tree_node *node, hash *marked );

  void parse_fouriers( char *filename ) ;
  void scale_pts();
  void print_pts(char *filename);

  // compare the performance of the brute force 
  // algorithm and the cell algorithm
  void brutevcell( char *filename );
    
  int numtkns( char *filename );
  int numlines( char *filename );
  int floatcmp(float a, float b);

  void fprint_arr( FILE *j, float *arr, int size );
  void print_arr( float *arr, int size );
  void print_pts( int *ptsx, int nptsx);
  void print_tree_helper( tree_node *curr );
  void print_tree( tree_node *root );

};




class cell
{
public:
  int *ptsx;
  int nptsx; 
  int ident;
  tree_node *tref;
  float dist; 
};

class tree_node
{
public:
  bool isacell;
  cell *cellent;
  int split_idx;
  float split_crit;
  float *mins; 
  float *maxs; 
  tree_node *left;
  tree_node *right; 
  int index;
};

class dist_pt
{
 public:
  int ptx;
  float dist;
};

class dist_pt_compare
{
 public:
  bool operator() ( dist_pt a, dist_pt b )
    {
      return !( a.dist < b.dist );
    }
};

class cell_compare
{
 public:
  bool operator () ( cell *a, cell *b)
    {
      return !( a->dist < b->dist );
    }
};

class Bool
{
 public:
  bool b;
  Bool ()
    {
      b = false;
    }
  Bool ( bool b1 )
    {
      b = b1;
    }
};


#endif
