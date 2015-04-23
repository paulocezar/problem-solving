#include <stdio.h>
#include <stdlib.h>

int main(){
    
    double A, G, Ra, Rg;
    double Ca, Cg;
    
    scanf("%lf %lf %lf %lf", &A, &G, &Ra, &Rg );
    
    Ca = A / Ra;
    Cg = G / Rg;
    
    if( Ca < Cg )
        printf("A");
    else
        printf("G");
    
    return 0;
}
