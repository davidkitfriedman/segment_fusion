#include <image.h>
#include <pnmfile.h>
#include <cstdlib>

int main( int argc, char **argv )
{
  if ( argc != 2 )
    {
      printf("Usage: enlarge <filename>\n");
      exit(-1);
    }
  printf("loading input image: %s\n", argv[1]);
  image<rgb> *orig = loadPPM( argv[1] );
  int w = orig->width();
  int h = orig->height();
  image<rgb> *enlarged = new image<rgb>( 2*w, 2*h );
  for ( int i = 0; i <= h - 1; i++ )
    {
      for ( int j = 0; j <= w - 1; j++ )
	{
	  rgb curr = orig->access[i][j];
	  enlarged->access[2*i]  [2*j  ] = curr;
	  enlarged->access[2*i]  [2*j+1] = curr;
	  enlarged->access[2*i+1][2*j  ] = curr;
	  enlarged->access[2*i+1][2*j+1] = curr;
	}
    }
  savePPM(enlarged, "enlarged.ppm" );
  delete orig;
  delete enlarged;
  return 0;
}
