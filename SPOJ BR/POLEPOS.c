#include <stdio.h>
#include <stdlib.h>

int main(){
 
 int grid[1001];
 int n, num, i, pos, ganhou;
 int impossivel;
 
 scanf("%d", &n );
 while( n ){
	
    for( i = 1; i <= n; i++ )
         grid[i] = 0;
         
	impossivel = 0;
	
	for( i = 1; i <= n; i++ ){
	
		scanf("%d %d", &num, &ganhou );
		
		if( !impossivel ){
            
            pos = i + ganhou;
		
		    if( pos < 1 || pos > n )
      			impossivel = 1;
	        else if( grid[pos] ^ 0 )
		    	impossivel = 1;
		    else 
			     grid[pos] = num;
        }
			     
	}
	
	if( impossivel )
		printf("-1\n");
	else {
		for( i = 1; i <= n; i++ ){
			if( i ^ 1 )
				printf(" ");
			printf("%d", grid[i] );
        }
		printf("\n");
	}
	
 
 scanf("%d", &n );
 }

 return 0;
}
