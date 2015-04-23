#include <stdio.h>
#include <stdlib.h>

int main(){
 
 int X, Y, N;
 int V[100];
 int i, dif, total, objetivo, max, teste = 1;
 char consegue[10100];
  
 scanf("%d %d %d", &X, &Y, &N );
 while( X ){
        
        total = 0;
        
        for( i = 0; i < N; i++ ){
             scanf("%d", &V[i] );
             total += V[i];
        }
        
        dif = X - Y;
        
        if( dif < 0 ) dif *= -1;
        
        if( dif > total ){
            printf("Teste %d\nN\n\n", teste++ );
        } else if( ( total + X + Y ) % 2 ) {
            printf("Teste %d\nN\n\n", teste++ );
        } else {
            memset( consegue, 0, sizeof(consegue));   
            objetivo = (total+dif)/2;
            max = 0;
            consegue[0] = 1;               
        
            while( !consegue[objetivo] && N > 0  ){
                
                for( i = max; i >= 0; i-- )
                     if( consegue[i] == 1 ){
                         consegue[i+V[N-1]] = 1;
                         if( i+V[N-1] > max ) max = i+V[N-1];
                     } 
            
            N--;       
            }
            
            if( consegue[objetivo] )
                printf("Teste %d\nS\n\n", teste++ );
            else
                printf("Teste %d\nN\n\n", teste++ ); 
            
        }
        
                   
 scanf("%d %d %d", &X, &Y, &N );
 }
 
 return 0;    
    
}
