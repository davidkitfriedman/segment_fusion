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

#include <misc.h>
#include <pnmfile.h>
#include <segment-image.h>
#include <time.h>

int main(int argc, char **argv) 
{
  if ( argc != 17 )
    {       
      fprintf(stderr, "%s input(ppm) output_intensity(ppm) output_texture(ppm) output_quality(ppm) output_fused(ppm) intensity_sigma intensity_thresh intensity_minsize texture_winlength texture_cellalg_or_kmeans texture_cellalg_epsilon texture_cellalg_thresh_pct_or_abs texture_cellalg_thresh_val texture_kmeans_numclusters quality_abs_or_squ quality_winradius\n", argv[0]);
      exit(0);
    }
  
  fprintf(stderr, "loading input image: %s\n", argv[1]);
  image<rgb> *input = loadPPM(argv[1]);

  // parse args
  float intensity_sigma  = atof( argv[6] );
  int intensity_thresh = atoi( argv[7] );
  int intensity_minsize = atoi( argv[8] );
  int texture_winlength = atoi( argv[9] );

  char *texture_cellalg_or_kmeans = argv[10];
  float texture_cellalg_epsilon = atof( argv[11] );
  char *texture_cellalg_thresh_pct_or_abs = argv[12];
  float texture_cellalg_thresh_val = atof(argv[13]);
  int texture_kmeans_numclusters = atoi(argv[14]);
  char *quality_abs_or_squ = argv[15];
  int quality_winradius    = atoi(argv[16]);

  int num_ccs; 
  time_t start,end,prev,curr;
  start = time(0);

  // segment intensity 
  prev = time(0);
  image<int> *seg_intensity = segment_image(input, intensity_sigma, intensity_thresh, intensity_minsize, &num_ccs );
  curr = time(0);
  printf("segment intensity: %g sec\n", difftime(curr,prev));
  image<rgb> *im_intensity  = seg_to_image( seg_intensity );
  savePPM(im_intensity , argv[2] );


  // segment texture 
  prev = time(0);
  image<int> *seg_texture   = segment_image_texture(input, texture_winlength, texture_kmeans_numclusters,texture_cellalg_or_kmeans, texture_cellalg_epsilon, texture_cellalg_thresh_pct_or_abs, texture_cellalg_thresh_val);
  curr = time(0);
  printf("segment texture: %g sec\n", difftime(curr,prev) );
  image<rgb> *im_texture    = seg_to_image( seg_texture   ); 
  savePPM(im_texture   , argv[3] );

  // compute quality 
  prev = time(0);
  image<float> *quality = compute_quality(input,quality_winradius,quality_abs_or_squ);
  image<rgb> *qual_image = qual_to_image(quality);
  curr = time(0);
  printf("compute quality: %g sec\n", difftime(curr,prev) );
  savePPM(qual_image     , argv[4] );
  
  // fuse intensity and texture segmentations 
  prev = time(0);
  image<rgb> *im_fused     = fuse_intensity_texture( input, seg_intensity, seg_texture, quality);
  curr = time(0);
  printf("fuse intensity and texture: %g sec\n", difftime(curr,prev) );
  savePPM(im_fused     ,  argv[5] );

  end = time(0);
  printf("total elapsed time: %g sec\n", difftime(end,start)); 

  return 0;
}

	
	
