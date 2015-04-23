#include <stdio.h>
#include <stdlib.h>

int main(){

int T, A, B, virouA = 0, virouB = 0, isA, cur, aux = 0;

	scanf("%d%*c%d%*c%d", &T, &A, &B);
	
    cur = B;
    aux = A;
    isA = 0;
    
    while( cur ^ T ){
           
        cur -= aux;
           
        if( cur < 0 ){
            
            cur *= -1;
            
            if( isA ){
                 virouA++;
                 aux = A; 
                 isA = 0;
            } else { 
                 virouB++;
                 aux = B;
                 isA = 1;
           }
           
        } else {
               
            isA  ? virouB++ : virouA++;
            
        }
    }
    
	printf("%d", isA == 1 ? ( virouA * A ) + A : ( virouB * B ) + B );

return 0;
}
