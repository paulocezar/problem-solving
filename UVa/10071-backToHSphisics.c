#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int v, t, r;
    
    while( scanf("%d %d", &v, &t ) == 2 ){
           r = 2*v*t;       
           printf("%d\n", r );
    }

    return 0;    
}
