#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <time.h>
#include <pnmfile.h>
#include <misc.h>
#include <abs_qual.h>

int main( int argc, char **argv)
{
  if ( argc != 4 )
    {
      printf("Usage: profile_abs_qual <filename> <winradius> <main|brute|square_brute>\n");
      exit(-1);
    }

  image<rgb> *temp = loadPPM( argv[1] );
  printf("loading input image: %s\n", argv[1]);
  image<float> *img = grayscale( temp );
  int winradius = atoi( argv[2] );
  image<float> *ret;
  abs_qual aq( img, winradius );
  time_t curr;
  time_t prev;

  if ( strncmp( argv[3], "main", 4) == 0 )
    {
      prev = time(0);
      ret = aq.main();
      curr = time(0);
      printf("aq.main() elapsed time: %g\n", difftime(curr,prev) );
    }
  else if ( strncmp( argv[3], "brute", 5) == 0 )
    {
      prev = time(0);
      ret = aq.brute();
      curr = time(0);
      printf("aq.brute() elapsed time: %g\n", difftime(curr,prev) );
    }
  else if ( strncmp( argv[3], "square_brute", 12) == 0 )
    {
      prev = time(0);
      ret = aq.square_brute();
      curr = time(0);
      printf("aq.square_brute() elapsed time: %g\n", difftime(curr,prev) );
    }

  delete temp;
  delete img;
  delete ret;
  return 0;
}
