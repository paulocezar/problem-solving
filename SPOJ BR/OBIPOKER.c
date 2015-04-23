#include <stdio.h>
#include <stdlib.h>

void insertionSort( int vetor[] ) {
  int i, j;
  int v;
 
  for (j = 1; j < 5; ++j) {
    v = vetor[j];
    i = j - 1;
    while (vetor[i] > v && i >= 0) {
      vetor[i+1] = vetor[i];
      --i;
    }
 
    vetor[i+1] = v;
  }
}

int getPontuacao( int cartas[] ){
            
    if( ( cartas[1] == cartas[0] + 1 ) && ( cartas[2] == cartas[1] + 1 ) 
        && ( cartas[3] == cartas[2] + 1 ) && (cartas[4] == cartas[3]+1) )
        return cartas[0] + 200;
        
    if( (( cartas[0] == cartas[1] ) && ( cartas[1] == cartas[2] ) 
        && ( cartas[2] == cartas[3] ))  || (( cartas[1] == cartas[2] ) && 
             ( cartas[2] == cartas[3] ) && ( cartas[3] == cartas[4] ))  )
        return cartas[3] + 180;
        
    if( (( cartas[0] == cartas[1] ) && ( cartas[1] == cartas[2] ) 
          && ( cartas[3] == cartas[4] ))  || 
			(( cartas[2] == cartas[3] ) && ( cartas[3] == cartas[4] ) 
          && ( cartas[0] == cartas[1] ))		  )
        return cartas[2] + 160;
		
	if( (( cartas[0] == cartas[1] ) && ( cartas[1] == cartas[2] ) ) ||
			(( cartas[1] == cartas[2] ) && ( cartas[2] == cartas[3] ) ) || 
				(( cartas[2] == cartas[3] ) && ( cartas[3] == cartas[4] ) ) )
        return cartas[2] + 140;
        
	if( cartas[1] == cartas[2] && cartas[3] == cartas[4] )
		return 2*cartas[1] + 3*cartas[3] + 20;
		
	if( cartas[0] == cartas[1] && cartas[3] == cartas[4] )
		return 2*cartas[0] + 3*cartas[3] + 20;
		
	if( cartas[0] == cartas[1] && cartas[2] == cartas[3] )
		return 2*cartas[0] + 3*cartas[2] + 20;
		
	if( ( cartas[0] == cartas[1] ) )
        return cartas[0];
		
	if( ( cartas[1] == cartas[2] ) )
        return cartas[1];
    
	if( ( cartas[2] == cartas[3] ) )
        return cartas[2];        
    
	if( ( cartas[3] == cartas[4] ) )
        return cartas[3];    
		
	return 0;
}

int main(){
    
    int cartas[5];
    int testes;
    int i;
    
    scanf("%d", &testes);
    for( i = 1; i <= testes; i++ ){
         scanf("%d %d %d %d %d", &cartas[0], &cartas[1], &cartas[2], &cartas[3], &cartas[4] );
    
         insertionSort( cartas );
         
         
         printf("Teste %d\n%d\n\n", i, getPontuacao( cartas ) );
    
    }
    
    return 0;
}
