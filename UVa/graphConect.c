#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char graph[32][32];
int comp[32];
int queue[32];
int ncomp;

int main(){
    
    int cases, i, j, nv, ini, end;
    char u, v, n, line[10];
    
    gets( line );
    sscanf( line, "%d", &cases );
    gets( line );
    
    while( cases-- ){
       
           gets( line );
           n = line[0];
           nv = n - 'A'+1;
           for( i = 0; i < nv; i++ )
                memset( graph[i], 0, sizeof( char ) * (nv+1) );
                   
           while( gets( line ) ){
                  
                  if( !line[0] || line[0] == '\n' ) break;
                  
                  graph[line[0]-'A'][line[1]-'A'] = graph[line[1]-'A'][line[0]-'A'] = 1;
                  
           }
           
           ncomp = 0;
           memset( comp, 0, sizeof( int ) * (nv+1) );
                      
           for( i = 0; i < nv; i++ ){
                if( comp[i] == 0 ){
                    comp[i] = ncomp++;
                    ini = end = 0;
                    queue[end++] = i;
                    while( ini != end ){
                           u = queue[ini++];
                           for( v = 0; v < nv; v++ )
                                if( graph[u][v] && comp[v] == 0 ) { comp[v] = ncomp; queue[end++] = v; }
                    }
                }
                  
           }
           
           printf("%d\n", ncomp );
     
           if( cases ) printf("\n");      
    }
    
    return 0;
}
