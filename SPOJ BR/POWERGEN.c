/*
 *  Problema: Geracao de Energia
 *  Tecnica Utilizada:  DFS ( Modificado - Guloso )
 *
 *		  Uma busca de profundidade modificada para remover o maximo 
 *		de arestas possiveis, gerando assim o maximo de componentes.
 *		Quando chegamos numa folha verificamos se ela tem capacidade 
 *		suficiente para gerar uma nova companhia, caso tenha contamos que
 *		mais uma companhia foi criada, caso contrario agrupamos a capacidade
 *		dela com a capacidade do pai, que quando se tornar uma folha vai 
 *		caso tenha capacidade suficiente vai gerar uma nova companhia,
 *		que inclui o filhos que nao tiveram capacidade para gerar uma compania por si.
 *      
 *  Dificuldade: Medio
 *	Complexidade:
 *				O( V + E )
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10010
#define INF 0x3F3F3F3F

struct node{
        int val;
        struct node *prox;
};

typedef struct node node;
typedef node* list;

list graph[MAXN];
int x[MAXN], y[MAXN], p[MAXN];
int C, ans;

void dfs( int u, int pu ){
     list w;    
     for( w = graph[u]; w != NULL; w = w->prox )
          if( w->val != pu ) dfs( w->val, u );
     if( p[u] >= C ) ans++;
     else p[pu] += p[u];
}     

int main(){
    
    int n, i, j, minv, dist, min;
    list novo;
    
    while( 1 ){
    
           scanf("%d %d", &n, &C );
           if( n+C == 0 ) return 0;
           
           for( i = 1; i <= n; i++ ) graph[i] = NULL;
           
           scanf("%d %d %d", &x[1], &y[1], &p[1] );
           
           for( i = 2; i <= n; i++ ){
                scanf("%d %d %d", &x[i], &y[i], &p[i] );
                min = INF; 
                for( j = 1; j < i; j++ ){
                     dist = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                     if( dist < min ) min = dist, minv = j;
                }
                
                novo = (list) malloc(sizeof(node));
                novo->val = i;
                novo->prox = graph[minv];
                graph[minv] = novo;
                    
                novo = (list) malloc(sizeof(node));
                novo->val = minv;
                novo->prox = graph[i];
                graph[i] = novo;

           }
           
           ans = 0;
           dfs( 1, 0 );
           printf("%d\n", ans );
           
    }
    
    return 0;    
}
