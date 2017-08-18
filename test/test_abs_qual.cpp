#include <pnmfile.h>
#include <misc.h>
#include <image.h>
#include <cstdlib>
#include <cstdio>
#include <abs_qual.h>

int main(int argc, char **argv )
{
  if ( argc != 3 )
    {
      printf("Usage: test_abs_qual <filename> <winradius>\n" );
      exit(-1);
    }
  int winradius = atoi( argv[2] );
  image<rgb> *temp = loadPPM( argv[1] );
  printf("loading input image: %s\n", argv[1]);
  image<float> *img = grayscale( temp );
  abs_qual aq( img, winradius );
  aq.mainvsbrute();
  return 0;
}
