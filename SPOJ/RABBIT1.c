#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t;
    int n, m;
    int a, b, c, d, pot;
    
    int f[4], p[4];
    
    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d %d", &n, &m );
           m = (1<<m) - 1;
    
           f[0] = 1; f[1] = 0;
           f[2] = 0; f[3] = 1;
           
           p[0] = 1; p[1] = 1;
           p[2] = 1; p[3] = 0;
           
           while( n ){
           
                  if( n&1 ){
                  
                      a = f[0]*p[0] + f[1]*p[2];
                      b = f[0]*p[1] + f[1]*p[3];
                      c = f[2]*p[0] + f[3]*p[2];
                      d = f[2]*p[1] + f[3]*p[3];
                      f[0] = a&m; f[1] = b&m; f[2] = c&m; f[3] = d&m;
                      
                  }
                  a = p[0]*p[0] + p[1]*p[2];
                  b = p[0]*p[1] + p[1]*p[3];
                  c = p[2]*p[0] + p[3]*p[2];
                  d = p[2]*p[1] + p[3]*p[3];
                  p[0] = a&m; p[1] = b&m; p[2] = c&m; p[3] = d&m;

                  n >>= 1;
                  
           }
           printf("%d\n", f[0] );
    
    }

    return 0;    
}
