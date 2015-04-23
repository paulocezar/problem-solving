#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define MAXN 1010
#define MAXS 20

typedef struct{
        char ncnt[MAXS];
        int ndig;
        double cred, deb;
        char tipo;
} conta;

conta contas[MAXN];

int comp( const void *a, const void *b ){
    int x = *(int*) a;
    int y = *(int*) b;
    return contas[x].ndig - contas[y].ndig;
}

int main(){
    
    int n;
    int i, j;
    int posconta[MAXN];
    char sconta[MAXS];
    char tipo;
    double credito, debito;
    int ini, fim;
    
    while( 1 ){
           
           scanf("%d", &n ); getchar();
           if( n == 0 ) return 0;
           
           for( i = 0; i < n; i++ ){
                scanf("%s %c", &sconta, &tipo );
                if( tipo == 'S' ) scanf("%lf %lf", &contas[i].cred, &contas[i].deb );
                else contas[i].cred = contas[i].deb = 0.0;
                
                posconta[i] = i;
                
                ini = 0;
                fim = strlen( sconta ) - 1;
                while( sconta[ini] == '0' ) ini++;
                while( sconta[fim] == '0' && fim >= 0 ) fim--;
                contas[i].tipo = tipo;
                strncpy(  contas[i].ncnt, sconta + ini, fim - ini + 1 );
                contas[i].ncnt[fim-ini+1] = 0;
                contas[i].ndig = fim - ini + 1;
                               
           }
           
           qsort( posconta, n, sizeof( int ), comp );
           
           for( i = n-1; i >= 0; i-- ) if( contas[posconta[i]].tipo == 'A' ){
                j = i+1;
                while( contas[posconta[j]].ndig == contas[posconta[i]].ndig && j < n ) j++;
                while( contas[posconta[j]].ndig == (contas[posconta[i]].ndig+1) && j < n ){
                      if( strncmp( contas[posconta[i]].ncnt, contas[posconta[j]].ncnt, contas[posconta[i]].ndig ) == 0 ){
                          contas[posconta[i]].cred += contas[posconta[j]].cred;
                          contas[posconta[i]].deb += contas[posconta[j]].deb;    
                      }
                     j++;
                }
           }
           
           for( i = 0; i < n; i++ )
                printf("%s %.2lf %.2lf\n", contas[i].ncnt, contas[i].cred, contas[i].deb );
           puts("");
    
    }
    
    return 0;    
}
