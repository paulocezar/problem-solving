#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    
    
    int F, P, em, de, prog, minfreq, minfreq2;
    unsigned long int E, A, t, nc, nc2, min, min2;
    unsigned long int gasto[20][5000], edp[20][5000];
    
    while( 1 ){
     
           scanf("%d %d %lu %lu", &F, &P, &E, &A );
           
           if( F == 0 ) return 0;
           
           for( de = 0; de < P; de++ ){
                for( em = 0; em < F; em++ ){
                     scanf("%lu %lu", &t, &nc );
                     gasto[em][de] = t*nc; 
                }     
           }
           
           t = E * A;
           
           min = edp[0][0] = gasto[0][0];
           minfreq = 0;
           for( em = 1; em < F; em++ ){
                edp[em][0] = gasto[em][0] + t;
                if( edp[em][0] < min ) min = edp[em][0], minfreq = em;
           }
           
           for( prog = 1; prog < P; prog++ ){
                min2 = ULONG_MAX;
                for( em = 0; em < F; em++ ){
                     
                     if( em == minfreq ){
                         edp[em][prog] = edp[em][prog-1] + gasto[em][prog];
                     }
                     else{
                     
                          nc = edp[minfreq][prog-1] + gasto[em][prog] + t;
                          nc2 = edp[em][prog-1] + gasto[em][prog];
                          if( nc < nc2 ) edp[em][prog] = nc;
                          else edp[em][prog] = nc2;
                          
                     }
                     
                     if( edp[em][prog] < min2 ) min2 = edp[em][prog], minfreq2 = em;
    
                }
                min = min2;
                minfreq = minfreq2;
           }
           
           printf("%lu\n", min );
           
    }    

    return 0;    
}
