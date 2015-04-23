#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int pos[100001];
    int vet[100001];
    int n, i, cnt;
    
    while( 1 ){
           scanf("%d", &n );
           if( n == 0 ) break;
           cnt = 0;
           
           for( i = 1; i <= n; i++ ){
                scanf("%d", &vet[i] );
                pos[vet[i]] = i;
           }
           
           for( i = 1; i <= n; i++ )
                if( pos[i] != i ){
                    cnt++;
                    pos[vet[i]] = pos[i];
                    vet[pos[i]] = vet[i];
                }      
           
           if( cnt % 2 ) printf("Marcelo\n");
           else printf("Carlos\n");
    }
    
    return 0;    
}
