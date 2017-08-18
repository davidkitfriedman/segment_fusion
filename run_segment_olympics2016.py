import os

filename = "images/olympics2016"

# for naming purposes: e.g. "__intensity_sigma2.0__texture_winlength16__quality_winradius5__"
# (or default being "_" )
ident="__intensity_thresh275__"
# not all changes from the default are necessarily recorded in the ident

input            = filename+".ppm"
output_intensity = filename+ident+"intensity.ppm"
output_texture   = filename+ident+"texture.ppm"
output_quality   = filename+ident+"quality.ppm"
output_fused     = filename+ident+"fused.ppm"

intensity_sigma   = "0.8"   # default 0.8
intensity_thresh  = "275"   # default 475
intensity_minsize = "20"    # default 20

texture_winlength                 = "8"       # default 8
texture_cellalg_or_kmeans         = "cellalg" # default cellalg
texture_cellalg_epsilon           = "50"      # default 50
texture_cellalg_thresh_pct_or_abs = "pct"     # default pct
texture_cellalg_thresh_val        = "0.99"    # default 0.99
texture_kmeans_numclusters        = "5"       # default 5

quality_abs_or_squ  = "abs"                   # default abs
quality_winradius   = "11"                    # default 3 

os.system("./segment_fusion"                   + " " +\
          input                                + " " +\
          output_intensity                     + " " +\
          output_texture                       + " " +\
          output_quality                       + " " +\
          output_fused                         + " " +\
          intensity_sigma                      + " " +\
          intensity_thresh                     + " " +\
          intensity_minsize                    + " " +\
          texture_winlength                    + " " +\
          texture_cellalg_or_kmeans            + " " +\
          texture_cellalg_epsilon              + " " +\
          texture_cellalg_thresh_pct_or_abs    + " " +\
          texture_cellalg_thresh_val           + " " +\
          texture_kmeans_numclusters           + " " +\
          quality_abs_or_squ                   + " " +\
          quality_winradius           )

