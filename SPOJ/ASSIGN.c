#include <stdio.h>
#include <stdlib.h>

long long dp[1<<20];
int bitCount[1<<20];
int like[1<<20];

int main(){

    int t;
    int i, b, j, n, ok;
    
    bitCount[0] = 0;
    for( i = 1; i < 1<<20; i++ ) bitCount[i] = bitCount[i>>1] + (i&1);
    
    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d", &n );
           for( i = 0; i < n; i++ ){
                like[i] = 0;
                for( j = 0; j < n; j++ ){
                     scanf("%d", &b );
                     like[i] = (like[i]<<1) | b;
                }
           }
           
           /* dp[ MASK ] = maneiras de atribuir as materias disponiveis
                ( i-esima materia disponivel se i-esimo bit está inativo )
               para os bitCount[ MASK ] ultimos alunos.. */
               
           dp[(1<<n)-1] = 1ll; /* (BASE) se todas as materias foram usadas,
                                  uma unica possibilidade */
           
           for( i = (1<<n)-2; i >= 0; i-- ){
                
                dp[i] = 0ll;
                /* podem ser alocadas ao bitCount[i]-esimo aluno as materias 
                   disponiveis (~i) e que ele tem interesse ( like[bitCount[i]] ). */
                ok = ~i & like[bitCount[i]];
                
                while( ok ){
                       dp[i] += dp[ i | (ok & -(ok)) ];
                       ok -= ok & -ok;
                }
           
           }
           
           printf("%lld\n", dp[0] );
    
    }

    return 0;    
}
