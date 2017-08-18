#include <image.h>
#include <pnmfile.h>
#include <cstdlib>

int main( int argc, char **argv )
{
  if ( argc != 5 )
    {
      printf("Usage: count_color <filename> red green blue\n");
      exit(-1);
    }
  image<rgb> *orig = loadPPM( argv[1] );
  printf("loading input image: %s\n", argv[1]);
  int r = atoi(argv[2]);
  int g = atoi(argv[3]);
  int b = atoi(argv[4]);
  int w = orig->width();
  int h = orig->height();
  int count = 0;
  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  rgb curr = orig->access[i][j];
	  if ( curr.r == r && 
	       curr.g == g &&
	       curr.b == b )
	    {
	      count++;
	    }

	}
    }
  delete orig;
  printf("Count for (%d, %d, %d) is %d\n", r, g, b, count);
  return 0;
}
