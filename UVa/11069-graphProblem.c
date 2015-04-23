#include <stdio.h>
#include <stdlib.h>

int main(){
    

    int f[77];
    int n;
    
    f[1] = 1;
    f[2] = 2;
    f[3] = 2;    
    
    for( n = 4; n < 77; n++ )
         f[n] = f[n-2] + f[n-3];
         
    while( scanf("%d", &n ) != EOF ) printf("%d\n", f[n] );
    
    return 0;
    
}
