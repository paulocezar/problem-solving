#include <stdio.h>
#include <stdlib.h>

int main(){

    int bottle[9];
    char *out;
    int min, cbcg, cbgc, ccbg, ccgb, cgcb, cgbc;
    
    while( scanf("%d", &bottle[0] ) != EOF ){
           scanf("%d %d %d %d %d %d %d %d", &bottle[1], &bottle[2], &bottle[3], &bottle[4],
                                            &bottle[5], &bottle[6], &bottle[7], &bottle[8] );
                     
           cbcg = bottle[1] + bottle[2] + bottle[3] + bottle[4] + bottle[6] + bottle[8];
           cbgc = bottle[1] + bottle[2] + bottle[3] + bottle[5] + bottle[6] + bottle[7];
           ccbg = bottle[0] + bottle[1] + bottle[4] + bottle[5] + bottle[6] + bottle[8];
           ccgb = bottle[0] + bottle[1] + bottle[3] + bottle[5] + bottle[7] + bottle[8];
           cgcb = bottle[0] + bottle[2] + bottle[3] + bottle[4] + bottle[7] + bottle[8];
           cgbc = bottle[0] + bottle[2] + bottle[4] + bottle[5] + bottle[6] + bottle[7];
           
           min = cbcg;
           out = "BCG";
           
           if( cbgc < min ){ min = cbgc; out = "BGC"; }
           if( ccbg < min ){ min = ccbg; out = "CBG"; }
           if( ccgb < min ){ min = ccgb; out = "CGB"; }
           if( cgbc < min ){ min = cgbc; out = "GBC"; }
           if( cgcb < min ){ min = cgcb; out = "GCB"; }

           
           printf("%s %d\n", out, min );
                                            
                                                
    }
    
    return 0;
}

