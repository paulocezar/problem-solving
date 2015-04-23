#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <utility>

#define MAXN 55
#define INF 60

using namespace std;

struct r_state{
       int xa, ya, xb, yb;
      public:
             bool operator <( const r_state &a ) const { return true; }
             bool operator >( const r_state &a ) const { return true; }
};

typedef pair< int, pair< int, r_state > > state;


int calc_h( r_state &a, r_state &b ){
    int dx, dy;
    dx = abs( a.xa - b.xa ) + abs( a.xb - b.xb );
    dy = abs( a.ya - b.ya ) + abs( a.yb - b.yb );
    
    return dx + dy;
}

char gridA[MAXN][MAXN];
char gridB[MAXN][MAXN];
int  dist[MAXN][MAXN][MAXN][MAXN];

int main(){

    int t, m, n;
    int i, j, k, l;
    int xa, ya, xb, yb, d, h;
    r_state ini, end;
    r_state u, v;
    
    /* linha 0 e coluna 0 dos grids A e B feita de buracos.. */
    for( i = 0; i < MAXN; i++ ) gridA[0][i] = gridB[0][i] = gridA[i][0] = gridB[i][0] = 'B';
    
    scanf("%d", &t );
    while( t-- ){
           scanf("%d %d", &m, &n ); getchar();
    
           /* le os grids e guarda as posicoes iniciais e finais dos robos. */
           for( i = 1; i <= m; i++ ){
                gridA[i][n+1] = 'B'; /* Buraco na ultima coluna */
                for( j = 1; j <= n; j++ ){
                     gridA[i][j] = getchar();
                     if( gridA[i][j] == 'R' ) ini.xa = i, ini.ya = j;
                     if( gridA[i][j] == 'F' ) end.xa = i, end.ya = j;
                }
                getchar();
           }
             
           for( i = 1; i <= m; i++ ){
                gridB[i][n+1] = 'B';
                for( j = 1; j <= n; j++ ){
                     gridB[i][j] = getchar();                     
                     if( gridB[i][j] == 'R' ) ini.xb = i, ini.yb = j;
                     if( gridB[i][j] == 'F' ) end.xb = i, end.yb = j;
                }
                getchar();
           }
   
           /* ultima linha dos grids = buraco */
           for( i = 0; i <= n+1; i++ ) gridA[m+1][i] = gridB[m+1][i] = 'B';
           
           /* menor nro. de movimentos ate cada estado = INF */
           for( i = 1; i <= m; i++ )
                for( j = 1; j <= n; j++ )
                     for( k = 1; k <= m; k++ )
                          for( l = 1; l <= n; l++ )
                               dist[i][j][k][l] = INF;
                
           /* estado inicial = 0 movimentos */
           dist[ini.xa][ini.ya][ini.xb][ini.yb] = 0;
           
           /* fila de prioridade minima, para os estados.. analisa primeiro o valor da
             heuristica, depois a distancia percorrida */
           priority_queue< state, vector< state >, greater< state > > q;
           q.push( state( 0, make_pair( 0, ini ) ) ); 
           
           while( !q.empty() ){
           
                  d = q.top().second.first;
                  u = q.top().second.second; q.pop();
                  
                  /* movimentos a partir dessa posicao nao precisam ser analisados
                    pois com a distancia atual vai usar mais de 50 movimentos */           
                  if( d > 49 ) continue;
                  if( d > dist[u.xa][u.ya][u.xb][u.yb] ) continue;
           
                  /* Para quando encontrar a primeira solução */
                  if( u.xa == end.xa && u.xb == end.xb && u.ya == end.ya && u.yb == end.yb ) break;
           
           /* UP */
                  xa = u.xa+1; ya = u.ya;
                  xb = u.xb+1; yb = u.yb;
                  /* se nenhum dos dois robos cai em buraco.. */
                  if( gridA[xa][ya] != 'B' && gridB[xb][yb] != 'B' ){
                      /* caso algum dos robos tenha 'escalado' uma parede faz 
                          faz ele ficar parado */ 
                      if( gridA[xa][ya] == '#' ) xa--;
                      if( gridB[xb][yb] == '#' ) xb--;
                      /* se o numero de movimentos ate esse estado era maior que o nro 
                         de movimentos atual + 1 */
                      if( d+1 < dist[xa][ya][xb][yb] ){
                          v.xa = xa; v.ya = ya;
                          v.xb = xb; v.yb = yb;
                          /* atualiza menor nro. de movimentos */
                          dist[xa][ya][xb][yb] = d+1;
                          /* Valor esperado - o nro. de passos ja percorrido importa mais 
                             que a distancia aproximada duas vezes, 
                             h = 2*nro de passos + ( somatorio distancia manhattan dos
                                                      dois robos ate suas posicoes finais. ) */
                          h = 2*(d+1) + calc_h( v, end );
                          q.push( state( h, make_pair( d+1, v ) ) );
                       }
                  }
          /* DOWN */        
                  xa = u.xa-1; ya = u.ya;
                  xb = u.xb-1; yb = u.yb;
                  if( gridA[xa][ya] != 'B' && gridB[xb][yb] != 'B' ){
                      if( gridA[xa][ya] == '#' ) xa++;
                      if( gridB[xb][yb] == '#' ) xb++;
                      if( d+1 < dist[xa][ya][xb][yb] ){
                          v.xa = xa; v.ya = ya;
                          v.xb = xb; v.yb = yb;
                          dist[xa][ya][xb][yb] = d+1;
                          h = 2*(d+1) + calc_h( v, end );
                          q.push( state( h, make_pair( d+1, v ) ) );
                      }
                  }
          /* RIGHT */
                  xa = u.xa; ya = u.ya+1;
                  xb = u.xb; yb = u.yb+1;
                  if( gridA[xa][ya] != 'B' && gridB[xb][yb] != 'B' ){
                      if( gridA[xa][ya] == '#' ) ya--;
                      if( gridB[xb][yb] == '#' ) yb--;
                      if( d+1 < dist[xa][ya][xb][yb] ){
                          v.xa = xa; v.ya = ya;
                          v.xb = xb; v.yb = yb;
                          dist[xa][ya][xb][yb] = d+1;
                          h = 2*(d+1) + calc_h( v, end );
                          q.push( state( h, make_pair( d+1, v ) ) );
                      }
                  }
          /* LEFT */        
                  xa = u.xa; ya = u.ya-1;
                  xb = u.xb; yb = u.yb-1;
                  if( gridA[xa][ya] != 'B' && gridB[xb][yb] != 'B' ){
                      if( gridA[xa][ya] == '#' ) ya++;
                      if( gridB[xb][yb] == '#' ) yb++;
                      if( d+1 < dist[xa][ya][xb][yb] ){
                          v.xa = xa; v.ya = ya;
                          v.xb = xb; v.yb = yb;
                          dist[xa][ya][xb][yb] = d+1;
                          h = 2*(d+1) + calc_h( v, end );
                          q.push( state( h, make_pair( d+1, v ) ) );
                      }
                  }
                                    
           }
           
           if( dist[end.xa][end.ya][end.xb][end.yb] > 50 ) printf( "impossivel\n" );
           else printf("%d\n", dist[end.xa][end.ya][end.xb][end.yb] ); 
           
    }

    return 0;    
}
