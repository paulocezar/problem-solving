#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    
    
    int F, P, em, de, prog;
    unsigned long int E, A, t, nc;
    unsigned long int gasto[20][5000], edp[20][5000];
    
    while( 1 ){
     
           scanf("%d %d %lu %lu", &F, &P, &E, &A );
           
           if( F == 0 ) return 0;
           
           for( de = 0; de < P; de++ ){
                for( em = 0; em < F; em++ ){
                     scanf("%lu %lu", &t, &nc );
                     gasto[em][de] = t*nc;
                     edp[em][de] = ULONG_MAX;  
                }     
           }
           
           t = E * A;
           
           edp[0][0] = gasto[0][0];
           for( em = 1; em < F; em++ )
                edp[em][0] = gasto[em][0] + t;
                
           for( prog = 1; prog < P; prog++ ){
                for( em = 0; em < F; em++ ){
                     for( de = 0; de < F; de++ ){
                          
                          nc = edp[de][prog-1] + gasto[em][prog];
                          if( de != em ) nc += t;
                          
                          if( edp[em][prog] > nc )
                              edp[em][prog] = nc;
                               
                     }     
                }
           }
           
           nc = ULONG_MAX;
           for( em = 0; em < F; em++ )
                 if( edp[em][P-1] < nc ) nc = edp[em][P-1];
                 
           printf("%lu\n", nc );
           
    }    

    return 0;    
}
