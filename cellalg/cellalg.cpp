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

#include "cellalg.h"

cellalg::cellalg()
{
  cellcount = 0;
  bucket_size = 10;
  epsilon = 50;
  eps = 1e-5;
  root = (tree_node *) malloc( sizeof( tree_node ) );
}

cellalg::cellalg( float e, int buck_size )
{
  cellcount = 0;
  bucket_size = buck_size;
  epsilon = e;
  eps = 1e-5;
  root = (tree_node *) malloc( sizeof( tree_node ) );
} 

void cellalg::set_params( int m, int n, float *points )
{
  npts = m;
  dmns = n; 
  disttab_init();
  if ( points != NULL )
    {
      pts = (float *) malloc( npts * dmns * sizeof(float) );
      memcpy( pts, points, npts*dmns*sizeof(float) );
    }
  scale_pts();
  split_pts();
  return;
}



// split the points into a tree structure
void cellalg::split_pts()
{
  cellcount = 0;
  root->index = 0;
  root->mins = (float *) malloc( dmns * sizeof(float));
  root->maxs = (float *) malloc( dmns * sizeof(float));
  for( register int i = 0 ; i < dmns ; i++ )
    {
      root->mins[i] = 0;
      root->maxs[i] = 100;
    }
  int *ptsx = (int *)malloc( npts * sizeof(int));
  for ( register int i = 0; i < npts ; i++ )
    {
      ptsx[i] = i;
    }
  split_pts_helper( ptsx, npts, root );
  return; 
}

/* split_pts_helper
*
*recursive function which splits the points into the different branches
*of the tree. The split criteria is the average of the minimum value
*and the maximum value in the dimension of largest difference. Everything
*smaller going to the left and everything larger going to the right
*
*ptsx - an array containing the index of each point
*nptsx - the number of points in ptsx
*node - the node of the tree in which to do the split
*
*/
void cellalg::split_pts_helper( int *ptsx, int nptsx, tree_node *node )
{
  float *min_dmns = (float *) malloc( dmns * sizeof(float) );
  float *max_dmns = (float *) malloc( dmns * sizeof(float) );

  // initialize min_dmns and max_dmns from the first point
  for ( register int i = 0; i < dmns; i++ )
    {
      min_dmns[i] = pts[ ptsx[0]*dmns + i ];
      max_dmns[i] = pts[ ptsx[0]*dmns + i ];
    }

  // for each dimension find the minimum entry and the maximum entry
  for ( register int i = 0; i < nptsx; i++ )
    {
      for ( register int j = 0; j < dmns ; j++ )
	{
	  float curr = pts[ ptsx[i]*dmns + j ];
	  if ( curr < min_dmns[j] )
	    {
	      min_dmns[j] = curr;
	    }
	  if ( curr > max_dmns[j] )
	    {
	      max_dmns[j] = curr;
	    }
	}
    }
  float split_val = -1;
  int split_idx = -1;
  for ( register int j = 0; j < dmns; j++ )
    {
      if ( max_dmns[j] - min_dmns[j] > split_val )
	{
	  split_val = max_dmns[j] - min_dmns[j];
	  split_idx = j;
	}
    }

  // the split criteria is the average of the minimum value and the 
  // maximum value in the dimension with the largest difference
  float split_crit = ( max_dmns[split_idx] + min_dmns[split_idx] ) / 2.0 ; 
  free(min_dmns); 
  free(max_dmns); 

  node->split_idx = split_idx;
  node->split_crit = split_crit;
  node->isacell    = false;
 
  float *left_child_mins = (float *) malloc(dmns*sizeof(float));
  float *left_child_maxs = (float *) malloc(dmns*sizeof(float));
  float *right_child_mins = (float *)malloc(dmns*sizeof(float));
  float *right_child_maxs = (float *)malloc(dmns*sizeof(float));
  
  memcpy( left_child_mins, node->mins, dmns*sizeof(float) );
  memcpy(right_child_mins, node->mins, dmns*sizeof(float) );
  memcpy( left_child_maxs, node->maxs, dmns*sizeof(float) );
  memcpy(right_child_maxs, node->maxs, dmns*sizeof(float) );

  left_child_maxs[ split_idx ]  = split_crit;
  right_child_mins[ split_idx ] = split_crit;

  free(node->mins); 
  free(node->maxs);

  tree_node *lc = (tree_node *) malloc( sizeof( tree_node ) );
  lc->mins  = left_child_mins; 
  lc->maxs  = left_child_maxs;
  lc->index = 2*node->index + 1;
  node->left = lc;

  tree_node *rc = (tree_node *) malloc( sizeof( tree_node ) );
  rc->mins = right_child_mins; 
  rc->maxs = right_child_maxs; 
  rc->index = 2*node->index + 2; 
  node->right = rc; 

  int *left_chld = (int *) malloc( nptsx * sizeof(int) );
  int nleft_chld = 0;
  int *right_chld = (int *) malloc( nptsx * sizeof(int) );
  int nright_chld = 0;
  
  // split the points using the split criteria
  for ( register int i = 0; i < nptsx ; i++ )
    {
      if ( pts[ ptsx[i]*dmns + split_idx ] <= split_crit )
	{
	  left_chld[ nleft_chld ] = ptsx[i];
	  nleft_chld = nleft_chld + 1;
	}
      else
	{
	  right_chld[ nright_chld ] = ptsx[i];
	  nright_chld = nright_chld + 1;
	}
    }
  free(ptsx);

  // this will occur, for example, if all the points have all the 
  // same values for all dimensions
  if ( nright_chld == 0 )
    {
      cell *cll = ( cell * ) malloc( sizeof(cell) );
      cll->ptsx = left_chld;
      cll->nptsx = nleft_chld; 
      cll->ident = cellcount; 
      cll->tref  = node;
      cellcount++;
      node->cellent = cll;
      node->isacell = true; 
      node->left = NULL;
      node->right = NULL;
      return; 
    }

  if ( nleft_chld == 0 )
    {
      cell *cll = ( cell * ) malloc( sizeof(cell) );
      cll->ptsx = right_chld; 
      cll->nptsx = nright_chld; 
      cll->ident = cellcount;
      cll->tref  = node;
      cellcount++;
      node->cellent = cll;
      node->isacell = true; 
      node->left  = NULL;
      node->right = NULL; 
      return; 
    }

  // create a left child
  if ( nleft_chld <= bucket_size )
    {
      cell *cll = ( cell * ) malloc( sizeof(cell) );
      cll->ptsx  = left_chld; 
      cll->nptsx = nleft_chld; 
      cll->ident = cellcount;
      cll->tref = lc;
      cellcount++;
      lc->cellent = cll; 
      lc->isacell = true; 
      lc->left = NULL;
      lc->right = NULL;
    }
  else
    {
      split_pts_helper( left_chld, nleft_chld, lc );
    }

  // create a right child
  if ( nright_chld <= bucket_size ) 
    {
      cell *cll = ( cell * ) malloc( sizeof(cell) );
      cll->ptsx = right_chld; 
      cll->nptsx = nright_chld; 
      cll->ident = cellcount; 
      cll->tref  = rc;
      cellcount++;
      rc->cellent = cll; 
      rc->isacell = true; 
      rc->left = NULL;
      rc->right = NULL;
    }
  else
    {
      split_pts_helper( right_chld, nright_chld, rc );
    }

  return;
}

  
void cellalg::brutetabinit()
{
  brutetab = (float *) malloc( npts * npts * sizeof(float) );
  for ( int i = 0; i < npts; i++ )
    {
      for ( int j = i; j < npts; j++ )
	{
	  brutetab[ i*npts + j ] = dist_raw( pts + i*dmns, pts + j*dmns );
	}
    }
  return;
}

float cellalg::brutetabdist( int pntx1, int pntx2 )
{
  if ( pntx1 < pntx2 )
    {
      return brutetab[ pntx1*npts + pntx2 ];
    }
  else
    {
      return brutetab[ pntx2*npts + pntx1 ];
    }
}

// find the k closest point to a given location locx using brute force
dist_pt *cellalg::k_closest_brute( int locx, int k )
{
  std::priority_queue<dist_pt, std::vector<dist_pt>, dist_pt_compare> pq;
  dist_pt *saved_result = ( dist_pt *) malloc( k * sizeof(dist_pt) );
  int len_saved_result = 0;
  for ( int i = 0; i < npts; i++ )
    {
      dist_pt dp; 
      dp.dist = brutetabdist( locx, i );
      dp.ptx = i;
      pq.push( dp );
    }
  while ( len_saved_result < k )
    {
      saved_result[ len_saved_result ] = pq.top();
      len_saved_result++;
      pq.pop();
    }

  return saved_result;
}

/* 
* k_closest
*
* Find the approximate k closest points to a given point.
*
* locx - the index of the point
* k - the number of closest neighbors to look for
*
*/
dist_pt *cellalg::k_closest( int locx, int k)
{
  // the point priority queue
  std::priority_queue < dist_pt, std::vector<dist_pt>, dist_pt_compare> pq;
  dist_pt *saved_result = ( dist_pt *) malloc( k * sizeof(dist_pt));

  // the cell priority queue
  std::priority_queue < cell *, std::vector< cell *>, cell_compare> enum_pq;

  // used to prevent re-adding cells to the cell priority queue that have 
  // already been added
  hash *marked = new hash;

  cell *first_cell = get_unmarked_cell(pts+dmns*locx,root,marked);
  (*marked)[ first_cell->ident ] = Bool( true );
  first_cell->dist = dist(locx,0,first_cell);
  enum_pq.push(first_cell);
  int len_saved_result = 0;
  while ( len_saved_result < k )
    {
      // if the cell priority queue is empty just add points from the 
      // point priority queue
      if ( enum_pq.empty() )
	{
	  dist_pt r;
	  r.ptx = -1;
	  r.dist = -1;
	  while ( len_saved_result < k )
	    {
	      if ( pq.empty() )
		{
		  saved_result[ len_saved_result ] = r;
		  len_saved_result++;
		}
	      else
		{
		  saved_result[ len_saved_result ] = pq.top();
		  pq.pop();
		  len_saved_result++;
		}
	    }
	  return saved_result;
	}

      // get the current cell from the top of the cell 
      // priority queue (the next closest cell)
      cell *curr_cell = enum_pq.top();
      enum_pq.pop();
      tree_node *curr_celltref = curr_cell->tref;

      // add all points from the current cell to 
      // the point priority queue
      for ( int i = 0; i < curr_cell->nptsx; i++ )
	{
	  dist_pt dp;
	  dp.dist = dist(locx, curr_cell->ptsx[i], NULL );
	  dp.ptx = curr_cell->ptsx[i];
	  pq.push( dp );
	}
      while ( 1 )
	{
	  dist_pt d = pq.top();
	  // continue to add points to the saved_result as
	  // long as those points are sufficiently close
	  if ( dist( locx, 0, curr_cell ) * ( 1 + epsilon ) > 
	       dist( locx, d.ptx, NULL ) )
	    {
	      saved_result[ len_saved_result ] = pq.top();
	      pq.pop();
	      len_saved_result++;
	      if ( len_saved_result >= k || pq.empty() )
		{
		  break;
		}
	    }
	  else
	    {
	      break;
	    }
	}
      if ( len_saved_result >= k )
	{
	  return saved_result; 
	}

      // find new cells to add to the cell priority queue by
      // going through the borders of the current cell
      float *current_loc = closest_point(curr_cell,pts+dmns*locx);

      // first go through the minimums
      for ( int d = 0; d < dmns; d++ )
	{
	  float old_coord = current_loc[d];
	  if ( curr_celltref->mins[d] - eps >= 0 )
	    {
	      current_loc[d] = curr_celltref->mins[d] - eps;
	    }
	  else
	    {
	      continue;
	    }
	  cell *cll = get_unmarked_cell(current_loc,root,marked);
	  if ( cll == NULL )
	    {
	      current_loc[d] = old_coord;
	      continue;
	    }
	  
	  Bool temp = (*marked)[cll->ident];
	  if ( !(temp.b == true ) )
	    {
	      cll->dist = dist( locx, 0, cll );
	      enum_pq.push( cll );
	      (*marked)[cll->ident] = Bool( true );
	    }
	  current_loc[d] = old_coord;
	}

      // second go through the maximums
      for ( int d = 0; d < dmns; d++ )
	{
	  float old_coord = current_loc[d];
	  if ( curr_celltref->maxs[d] + eps <= 100 )
	    {
	      current_loc[d] = curr_celltref->maxs[d] + eps;
	    }
	  else
	    {
	      continue;
	    }
	  cell *cll = get_unmarked_cell(current_loc,root,marked);
	  if ( cll == NULL )
	    {
	      current_loc[d] = old_coord;
	      continue;
	    }
	  
	  Bool temp = (*marked)[cll->ident];
	  if ( !(temp.b == true ) )
	    {
	      cll->dist = dist( locx, 0, cll );
	      enum_pq.push( cll );
	      (*marked)[cll->ident] = Bool( true );
	    }
	  current_loc[d] = old_coord;
	}
      free( current_loc );
    }
  delete marked;
  return saved_result;
}

/*
* dist
*
*find the distance between two points or the distance between a 
*point and a cell
*
*pntx1 - the index of the first point in the pts array
*
*pntx2 - the index of the second point in the pts array
*
*cll - the parameter holding a pointer to the cell when computing 
*the distance between a point and a cell or NULL if computing the
*distance between two points
*/
float cellalg::dist( int pntx1, int pntx2, cell *cll )
{
  // find the distance between two points
  if ( cll == NULL )
    {
      int ptx1;
      int ptx2;
      if ( pntx1 <= pntx2 )
	{
	  ptx1 = pntx1;
	  ptx2 = pntx2;
	}
      else
	{
	  ptx1 = pntx2;
	  ptx2 = pntx1;
	}
      if ( disttab[ ptx1*npts*2 + ptx2*2 + 0 ] != -1 )
	{
	  return disttab[ ptx1*npts*2 + ptx2*2 + 0 ];
	}
      else
	{
	  float curr = dist_raw( pts+ptx1*dmns, pts+ptx2*dmns );
	  disttab[ ptx1*npts*2 + ptx2*2 + 0 ] = curr;
	  return curr;
	}
    }

  // find the distance between a point and a cell
  else
    {
      int ptx1 = pntx1;

      // use the first point in each cell as an index
      int ptx2 = cll->ptsx[0]; 

      if ( disttab[ ptx1*npts*2 + ptx2*2 + 1 ] != -1 )
	{
	  return disttab[ ptx1*npts*2 + ptx2*2 + 1 ];
	}
      else
	{
	  // find the distance between point 1 and the closest point
	  // to point 1 within cell cll
	  float *clopt = closest_point( cll, pts+ptx1*dmns );
	  float curr = dist_raw( clopt, pts+ptx1*dmns );
	  disttab[ ptx1*npts*2+ptx2*2+1] = curr;
	  free( clopt );
	  return curr;
	}
    }
}


// find the closest point to loc within cell cll
float *cellalg::closest_point( cell *cll, float *loc )
{
  float *dist_arr = (float *) malloc( dmns * sizeof(float) );
  tree_node *celltref = cll->tref;
  float *mins = celltref->mins; 
  float *maxs = celltref->maxs;

  for (register int d = 0; d < dmns; d++ )
    {
      float curr = loc[d];
      if ( curr < mins[d] )
	{
	  dist_arr[d] = mins[d];
	}
      else if ( curr >= mins[d] && curr <= maxs[d] )
	{
	  dist_arr[d] = curr;
	}
      else
	{
	  dist_arr[d] = maxs[d];
	}
    }
  return dist_arr;
}


// the disttab contains distances between points and distances
// between points and cells
void cellalg::disttab_init()
{
  disttab = (float *) malloc( npts*npts*2*sizeof(float));
  for ( register int i = 0; i < npts * npts * 2; i++ )
    {
      disttab[i] = -1;
    }
  return;
}


// computes the sum of the absolute values of the differences in
// each dimension
float cellalg::dist_raw( float *pnt1, float *pnt2 )
{
  float tot = 0;
  for ( register int i = 0; i < dmns; i++ )
    {
      float curr = pnt2[i] - pnt1[i];
      if ( curr < 0 )
	{
	  curr = -curr;
	}
      tot = tot + curr;
    }
  return tot;
}


// recurse through the tree finding the cell corresponding to a given 
// location loc
cell *cellalg::get_unmarked_cell( float *loc, tree_node *node, hash *marked)
{
  if ( node->isacell )
    {
      Bool temp =  (*marked)[ node->cellent->ident ]; 
      if ( temp.b != true )
	{
	  return node->cellent;
	}
      else
	{
	  return NULL;
	}
    }

  if ( loc[ node->split_idx ] == node->split_crit )
    {
      cell *cll = get_unmarked_cell( loc, node->left, marked );
      if ( cll != NULL )
	{
	  return cll;
	}
      cll = get_unmarked_cell( loc, node->right, marked );
      if ( cll != NULL )
	{
	  return cll;
	}
      return NULL;
    }
  else if ( loc[ node->split_idx ] < node->split_crit )
    {
      return get_unmarked_cell( loc, node->left, marked );
    }
  else
    {
      return get_unmarked_cell( loc, node->right, marked );
    }
}




int cellalg::floatcmp( float a, float b )
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


int cellalg::numtkns( char *filename )
{
  FILE *file = fopen(filename, "r" );
  int i = 0;
  float curr; 
  while ( 1 ) 
    {
      fscanf( file, "%g", &curr );
      i++;
      int next = fgetc( file );
      if ( next == '\n' )
	{
	  break;
	}
    }
  fclose( file );
  return i;
}


int cellalg::numlines( char *filename )
{
  FILE *file = fopen( filename, "r" );
  int newlinecount = 0;
  while ( 1 ) 
    {
      int curr = fgetc( file );
      if ( curr == EOF )
	{
	  break;
	}
      else if ( curr == '\n' )
	{
	  newlinecount++;
	}
    }
  return newlinecount;
}


void cellalg::parse_fouriers( char *filename ) 
{
  FILE *file = fopen(filename, "r" );
  dmns = numtkns( filename );
  npts = numlines( filename );
  pts = ( float *) malloc( npts * dmns * sizeof(float) );
  int cnt = 0;
  for ( register int i = 0 ; i < npts; i++ ) 
    {
      for ( register int j = 0 ; j < dmns; j++ )
	{
	  fscanf( file, "%g", pts+cnt );
	  cnt++;
	}
    }
  fclose( file );
  return;
}

void cellalg::print_pts(char *filename)
{
  FILE *file = fopen(filename, "w");
  for ( int i = 0; i < npts; i++ )
    {
      for ( int j = 0; j < dmns; j++ )
	{
	  fprintf(file, "%g", pts[ i*dmns + j ] );
	  if ( j != dmns - 1 )
	    {
	      fprintf(file, " ");
	    }
	}
      fprintf(file, "\n");
    }
  fclose( file ); 
  return; 
}

// scale the fourier transforms by dividing by the first entry and 
// multiplying by 100. Also, remove the first entry
void cellalg::scale_pts()
{
  float *new_pnts = ( float *) malloc( npts*(dmns-1)*sizeof(float) );
  for ( register int i = 0; i < npts; i++ )
    {
      memcpy( new_pnts+i*(dmns-1), pts+(i*dmns)+1, (dmns-1)*sizeof(float));
    }

  for ( register int i = 0; i < npts; i++ )
    {
      // the maximum value is the first entry (the upper left corner of the 
      // two dimensional fourier transform)
      float max_value = pts[i*dmns];
      for ( register int j = 0; j <= dmns - 2; j++ )
	{
	  if ( max_value != 0 )
	    new_pnts[ i*(dmns - 1) + j ] = (new_pnts[ i *(dmns - 1) + j ] / max_value) * 100.0 ; 
	  else /* handle the case where all the points are (0, 0, 0) in the window */
	    new_pnts[ i*(dmns - 1) + j ] = 0; 
	}
    }
  memcpy( pts, new_pnts, npts*(dmns-1)*sizeof(float));
  dmns = dmns - 1; 
  free( new_pnts ) ; 
  return; 
}
void cellalg::fprint_arr( FILE *j, float *arr, int size )
{
  fprintf(j,"[");
  for ( int i = 0; i < size; i++ )
    {
      fprintf(j, "'%.2f'", arr[i] );
      if ( i != size - 1 )
	{
	  fprintf(j, ", ");
	}
    }
  fprintf(j,"]");
  return;
}


void cellalg::brutevcell( char *filename )
{
  float *brutesums = (float *) malloc( npts * sizeof(float) );
  int nbrutesums = 0;
  float *cellsums = (float  *) malloc( npts * sizeof(float) );
  int ncellsums = 0;
  
  time_t prev,curr;
  prev = time(0);
  
  brutetabinit();
  for ( int i = 0; i < npts; i++ )
    {
      dist_pt *sr = k_closest_brute(i, 5 );
      float currsum = 0;
      for ( int j = 0; j < 5; j++ )
	{
	  dist_pt d = sr[j];
	  currsum = currsum + d.dist; 
	}
      brutesums[ nbrutesums ] = currsum; 
      nbrutesums++;
      free( sr );
    }
  curr = time(0);
  printf("Brute elapsed time: %4g\n", difftime(curr,prev) );
  
  prev = time(0);

  //disttab_init();
  for ( int i = 0; i < npts; i++ )
    {
      dist_pt *sr = k_closest(i, 5 );
      float currsum = 0;
      for ( int j = 0; j < 5; j++ )
	{
	  dist_pt d = sr[j];
	  currsum = currsum + d.dist;
	}
      cellsums[ ncellsums ] = currsum ; 
      ncellsums++;
      free( sr );
    }
  curr = time(0);
  printf("Cell  elapsed time: %4g\n", difftime(curr,prev) );

  FILE *currfile = fopen( filename, "w" );
  int exact_count = 0;
  int five_percent_count = 0;
  int ten_percent_count = 0;
  int fifteen_percent_count = 0;
  int twenty_percent_count = 0;
  for ( int i = 0; i < npts; i++ )
    {
      float diff = cellsums[i] - brutesums[i];

      if ( floatcmp( diff, 0) == 0 )
	{
	  exact_count++;
	}
      if ( diff <= 0.05 * brutesums[i] )
	{
	  five_percent_count++;
	}
      if ( diff <= 0.10 * brutesums[i] )
	{
	  ten_percent_count++;
	}
      if ( diff <= 0.15 * brutesums[i] )
	{
	  fifteen_percent_count++;
	}
      if ( diff <= 0.20 * brutesums[i] )
	{
	  twenty_percent_count++;
	}
      fprintf( currfile, "Index:  %d\n", i );
      fprintf( currfile, "Point:  "); fprint_arr( currfile, pts+i*dmns, dmns );
      fprintf( currfile, "\n");
      fprintf( currfile, "Brute:  %.2f\n", brutesums[i] );
      fprintf( currfile, "Cell:   %.2f\n\n",  cellsums[i]  );
    }

  printf("Percent cell exact:      %5.2f   %7d/%-7d\n", (exact_count*100.0)/npts,exact_count, npts);
  printf("Percent cell within  5%%: %5.2f   %7d/%-7d\n", (five_percent_count*100.0)/npts,five_percent_count,npts);
  printf("Percent cell within 10%%: %5.2f   %7d/%-7d\n", (ten_percent_count*100.0)/npts,ten_percent_count,npts);
  printf("Percent cell within 15%%: %5.2f   %7d/%-7d\n", (fifteen_percent_count*100.0)/npts,fifteen_percent_count,npts);
  printf("Percent cell within 20%%: %5.2f   %7d/%-7d\n", (twenty_percent_count*100.0)/npts,twenty_percent_count,npts);

  fclose( currfile );
  return; 
}




void cellalg::print_arr( float *arr, int size )
{
  printf("[");
  for ( int i = 0; i < size; i++ )
    {
      printf("'%.2f'", arr[i] );
      if ( i != size - 1 )
	{
	  printf(", ");
	}
    }
  printf("]");
  return;
}
 

void cellalg::print_pts( int *ptsx, int nptsx)
{
  printf("[");
  for ( int i = 0; i < nptsx ; i++ )
    {
      print_arr( pts+ptsx[i]*dmns, dmns );
      if ( i != nptsx - 1 )
	{
	  printf(", ");
	}
    }
  printf("]");
  return;
}

void cellalg::print_tree_helper( tree_node *curr )
{
  printf("%d ", print_index );
  print_index++;
  if ( curr->isacell )
    {
      printf("cell: ");
      printf("mins: ");
      print_arr( curr->mins, dmns ); 
      printf(" ");
      printf("maxs: ");
      print_arr( curr->maxs, dmns );
      printf(" ");
      printf("points: ");
      print_pts( curr->cellent->ptsx, curr->cellent->nptsx);
      printf(" ");
      printf("ident: ");
      printf("%d\n", curr->cellent->ident);
    }
  else
    {
      printf("super-cell:");
      printf(" ");
      printf("split_idx: %d split_crit: %.2f mins: ", curr->split_idx , curr->split_crit );
      print_arr( curr->mins, dmns );
      printf(" maxs: ");
      print_arr( curr->maxs, dmns );
      printf("\n");
   }
  fflush( stdout );
  return; 
}


void cellalg::print_tree( tree_node *root )
{
  std::queue< tree_node *> q;
  print_index = 0;
  if ( root != NULL )
    {
      q.push( root );
    }
  while ( !q.empty() )
    {
      tree_node *curr = q.front();
      print_tree_helper( curr );
      if ( curr->left != NULL )
	{
	  q.push( curr->left );
	}
      if ( curr->right != NULL )
	{
	  q.push( curr->right );
	}
      q.pop();
    }
  return; 
}
