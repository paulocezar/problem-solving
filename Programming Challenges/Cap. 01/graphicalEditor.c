#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char image[253][253];
int widht, height;
char c, oldColor;

void fRectangle(int xa, int ya, int xb, int yb ) {
	int i, j;
	
	for (i = ya; i <= yb; i++)
		for (j = xa; j <= xb; j++)
			image[i][j] = c;
	return;
}

void newImage(){
     int i, j;
     memset( image[0], 0, sizeof( char ) * (widht+2) );
     memset( image[height+1], 0, sizeof( char ) * (widht+2) );
     
     for( j = 1; j<=height; j++ )
          image[j][0] = image[j][widht+1] = 0;
     c = 'O';
     fRectangle( 1, 1, widht, height );
}

void prntImage(){
     char* p;
     int i;
     for(i = 1; i <= height; i++){
           p = &image[i][0];
           p++;
           printf("%s\n", p );
     }
}

void fColor( int x, int y ){
     if( image[y][x] == 0 ) return;
     image[y][x] = c;
     
     if( image[y-1][x] == oldColor ) fColor( x, y-1 );
     if( image[y][x-1] == oldColor ) fColor( x-1, y );
     if( image[y][x+1] == oldColor ) fColor( x+1, y );
     if( image[y+1][x] == oldColor ) fColor( x, y+1 );
     
}

int main(){

  char cmd;
  char name[13];
  int ax, x, y, z, k;

      while( scanf("%c", &cmd) != EOF ){
	   switch( cmd ){
               case 'I':
		                scanf("%d %d", &widht, &height );
		                newImage();
		                break;
               case 'C':
		                newImage();
		                break;
               case 'L':
		                scanf("%d %d %c", &x, &y, &c);
                        image[y][x] = c;
		                break;
	           case 'V':
		                scanf("%d %d %d %c", &x, &y, &z, &c);
		                if( z >= y )
		                    fRectangle( x, y, x, z );
                        else
                            fRectangle( x, z, x, y );
		                break;
	           case 'H':
		                scanf("%d %d %d %c", &x, &y, &z, &c);
		                if( x >= y )
		                    fRectangle( y, z, x, z );
                        else
                            fRectangle( x, z, y, z );
		                break;
	           case 'K':
		                scanf("%d %d %d %d %c", &x, &y, &z, &k, &c );
		                if ( x >= z ){
                             ax = x;
                             x = z;
                             z = ax;
                        }
				        if ( y >= k ) {
					       ax = y;
					       y = k;
					       k = ax;
				        }
		                fRectangle( x, y, z, k );
		                break;
	           case 'F':
		                scanf("%d %d %c", &x, &y, &c );
		                oldColor = image[y][x];
		                if( c != oldColor ) fColor( x, y );
		                break;
	           case 'S':
		                scanf("%s", &name);
		                printf("%s\n", name );
		                prntImage();
		                break;
	           case 'X':
		                return 0;
	           default:
		               break;
       }
	}

 return 0;
}
