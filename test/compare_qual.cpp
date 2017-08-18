#include <cstdlib>
#include <time.h>
#include <image.h>
#include <pnmfile.h>
#include <misc.h>
#include <abs_qual.h>



image<rgb> *qual_image( image<float> *img );

int main( int argc, char **argv )
{
  if ( argc != 3 )
    {
      printf("Usage: compare_qual <filename> winradius\n");
      exit(-1);
    }

  time_t curr,prev;
  printf("loading input image: %s\n", argv[1]);
  image<rgb> *temp = loadPPM( argv[1] );
  image<float> *img = grayscale( temp );
  delete temp;
  int winradius = atoi( argv[2] );
  abs_qual aq( img, winradius );
  prev = time(0);
  image<float> *abs_qual_img = aq.main();
  curr = time(0);
  printf("aq.main() elapsed time: %g\n", difftime(curr,prev) );

  prev = time(0);
  image<float> *squ_qual_img = aq.square_brute();
  curr = time(0);
  printf("aq.square_brute() elapsed time: %g\n", difftime(curr,prev));

  image<rgb> *abs_bw = qual_image( abs_qual_img );
  image<rgb> *squ_bw = qual_image( squ_qual_img );
  savePPM( abs_bw, "abs_qual.ppm");
  savePPM( squ_bw, "squ_qual.ppm");
  delete img;
  delete abs_qual_img;
  delete squ_qual_img;
  delete abs_bw;
  delete squ_bw;
  return 0;
}

image<rgb> *qual_image( image<float> *img )
{
  int w = img->width();
  int h = img->height();
  image<rgb> *ret = new image<rgb>(w,h);
  float maximum = 0;
  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  if ( img->access[i][j] > maximum )
	    {
	      maximum = img->access[i][j];
	    }
	}
    }

  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  rgb curr;
	  curr.r = (unsigned char)(( img->access[i][j] / maximum ) * 255);
	  curr.g = curr.r;
	  curr.b = curr.r;
	  ret->access[i][j] = curr;
	}
    }
  return ret;
}
