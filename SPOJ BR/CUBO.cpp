#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <queue>

#define MAXN 22
#define MAXM 22

#define INF 0x4FFFFFFF

using namespace std;

int ex, ey;

struct state{
       int mx, my, bx, by, emp, tot;
};


int mine[MAXN][MAXM][MAXN][MAXN];
int minp[MAXN][MAXM][MAXN][MAXN];
char tab[MAXN][MAXM];
int R, C;


int main(){
    

    state ini, aux, end;

    int i, j, k, l, inst = 1;
    
    while( true ){
           scanf("%d %d", &R, &C );
           if( R+C == 0 ) return 0;
           
           for( i = 0; i < R; i++ ){
                scanf("%s", &tab[i] );
                for( j = 0; j < C; j++ ){
                     if( tab[i][j] == 'B' ) ini.bx = i, ini.by = j;
                     if( tab[i][j] == 'S' ) ini.mx = i, ini.my = j;
                     if( tab[i][j] == 'T' ) ex = i, ey = j;
                }
           }
           ini.emp = ini.tot = 0;
           
           for( i = 0; i < R; i++ )
                for( j = 0; j < C; j++ )
                     for( k = 0; k < R; k++ )
                          for( l = 0; l < C; l++ )
                               mine[i][j][k][l] = minp[i][j][k][l] = INF;
    
           queue< state > q;
           q.push( ini );
           mine[ini.mx][ini.my][ini.bx][ini.by] = minp[ini.mx][ini.my][ini.bx][ini.by] = 0;
           end.bx = -1; end.by = -1; end.emp = INF; end.tot = INF;
           
           while( !q.empty() ){
                  ini = q.front(); q.pop();
              
              //cout << endl;
              //for( i = 0; i < R; i++ ){
              //     for( j = 0; j < C; j++ )
              //         cout << tab[i][j] ;
              //    cout << endl;
             // } cout << endl;
              //cout << ini.bx << " " << ini.by << endl;
              
              if( ini.bx == ex && ini.by == ey  ){ 
                  //cout << "eq\n";
                  if( ini.emp < end.emp || (ini.emp==end.emp && ini.tot<end.tot) ){
                       end = ini;
                       //cout << "at\n";
                  }
                  continue;
              }
              
                  if( ini.mx+1 < R && tab[ini.mx+1][ini.my] != '#' ){
                      i = ini.mx+1;
                      j = ini.my;
                      if( i == ini.bx && j == ini.by ){
                          k = ini.bx+1;
                          l = ini.by;
                          if( k < R && tab[k][l] != '#' ){
                           if( ini.emp + 1 < mine[i][j][k][l] )
                           {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.bx = k, aux.by = l;
                               aux.emp++, aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                             //  cout << "com tot : " << ini.tot << " emp: " << ini.emp << " empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                           }
                          }    
                      } else {
                          k = ini.bx;
                          l = ini.by;
                          if(  ini.emp < mine[i][j][k][l] || ( ini.emp == mine[i][j][k][l] && ini.tot+1 < minp[i][j][k][l]  ) )
                          {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                             // cout << "com tot : " << ini.tot << " emp: " << ini.emp << " n empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                            
                          }
                      
                      }
                  }

                  if( ini.mx-1 >= 0 && tab[ini.mx-1][ini.my] != '#' ){
                      i = ini.mx-1;
                      j = ini.my;
                      if( i == ini.bx && j == ini.by ){
                          k = ini.bx-1;
                          l = ini.by;
                          if( k >= 0 && tab[k][l] != '#' ){
                           if(  ini.emp + 1 < mine[i][j][k][l] )
                           {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.bx = k, aux.by = l;
                               aux.emp++, aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                             // cout << "com tot : " << ini.tot << " emp: " << ini.emp << " empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                            
                           }
                          }    
                      } else {
                          k = ini.bx;
                          l = ini.by;
                          if(   ini.emp < mine[i][j][k][l] || ( ini.emp == mine[i][j][k][l] && ini.tot+1 < minp[i][j][k][l]  )  )
                          {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                            //cout << "com tot : " << ini.tot << " emp: " << ini.emp << " n empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                           
                          }
                      
                      }
                  }

                  if( ini.my+1 < C && tab[ini.mx][ini.my+1] != '#' ){
                      i = ini.mx;
                      j = ini.my+1;                      
                      if( j == ini.by  && i == ini.bx){
                          k = ini.bx;
                          l = ini.by+1;
                          //cout << "fica em " << i << " " << j << " e emp pra " << k << " " << l << endl;
                         // cout << tab[k][l] << endl;
                          if( l < C && tab[k][l] != '#' ){
                           //cout << "limite ok" << endl;
                           if(   ini.emp + 1 < mine[i][j][k][l]   )
                           {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.bx = k, aux.by = l;
                               aux.emp++, aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                              // cout << "com tot : " << ini.tot << " emp: " << ini.emp << " empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                           
                           }
                          }    
                      } else {
                          k = ini.bx;
                          l = ini.by;
                          if(   ini.emp < mine[i][j][k][l] || ( ini.emp == mine[i][j][k][l] && ini.tot+1 < minp[i][j][k][l]  )  )
                          {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                              // cout << "com tot : " << ini.tot << " emp: " << ini.emp << " n empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                            
                          }
                      
                      }
                  }

                  if( ini.my-1 >= 0 && tab[ini.mx][ini.my-1] != '#' ){
                      i = ini.mx;
                      j = ini.my-1;
                      if( j == ini.by && i == ini.bx ){

                          k = ini.bx;
                          l = ini.by-1;
                          if( l >= 0 && tab[k][l] != '#' ){
                           if(   ini.emp + 1 < mine[i][j][k][l] ) 
                           {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.bx = k, aux.by = l;
                               aux.emp++, aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                               //cout << "com tot : " << ini.tot << " emp: " << ini.emp << " empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                           
                           }
                          }    
                      } else {
                          k = ini.bx;
                          l = ini.by;
                          if(   ini.emp < mine[i][j][k][l] || ( ini.emp == mine[i][j][k][l] && ini.tot+1 < minp[i][j][k][l]  )  )
                          {
                               aux = ini;
                               aux.mx = i, aux.my = j;
                               aux.tot++;
                               mine[i][j][k][l] = aux.emp;
                               minp[i][j][k][l] = aux.tot;
                               q.push( aux );
                              //cout << "com tot : " << ini.tot << " emp: " << ini.emp << " n empurrou, ficout com tot> " << aux.tot << " e emp-> " << aux.emp << endl;
                              
                          }
                      
                      }
                  }
                  
                  
           }

           if( end.bx != ex || end.by != ey ) printf("Instancia %d\nImpossivel\n\n", inst++ );
           else printf("Instancia %d\n%d %d\n\n", inst++, end.tot, end.emp );
    
    }
    
    return 0;
}
