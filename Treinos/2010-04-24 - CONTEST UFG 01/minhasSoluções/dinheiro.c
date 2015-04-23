#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10010

int parent[MAXN], rank[MAXN], pending[MAXN];

int find( int i ){    
  if( parent[i] == i ) return i;
  return parent[i] = find( parent[i] );
}

void link( int i, int j ){   
  if( rank[i] < rank[j] ) link( j, i );
  else if( i != j ){
    parent[j] = i;
    pending[i] += pending[j];
    if( rank[i] == rank[j] ) rank[i]++;
  }
}

int main(){
	
	int tests, i, n, m, x, y;
    char possible;  
	
	scanf( "%d", &tests );
	while( tests-- ){
		
		scanf( "%d %d", &n, &m );
		
		for( i = 0; i < n; i++ )
			 rank[i] = 0, parent[i] = i;
			 
		for( i = 0; i < n; i++ ) scanf( "%d", &pending[i] );
		
		while( m-- ){
			scanf( "%d %d", &x, &y );
			link( find(x), find(y) );
		}
		
		possible = 1, i = 0;
		while( possible && i < n ){
               possible =  !( parent[i] == i && pending[i] );
               i++;
        }
        
        if( possible )
        	puts("POSSIVEL");
        else  
            puts("IMPOSSIVEL");
        
	}
	return 0;
}
