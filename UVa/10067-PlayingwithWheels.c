#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3F3F3F3F

int main(){
    
    int a, b, c, d, s;
    int i, f, ini, fim, test, frst, lst;
    int viz[10][2];
    int min[10000];
    int fila[10000];
    char pode[10000];
    
    viz[0][0] = 9; viz[0][1] = 1;
    viz[1][0] = 0; viz[1][1] = 2;
    viz[2][0] = 1; viz[2][1] = 3;
    viz[3][0] = 2; viz[3][1] = 4;
    viz[4][0] = 3; viz[4][1] = 5;
    viz[5][0] = 4; viz[5][1] = 6;
    viz[6][0] = 5; viz[6][1] = 7;
    viz[7][0] = 6; viz[7][1] = 8;
    viz[8][0] = 7; viz[8][1] = 9;
    viz[9][0] = 8; viz[9][1] = 0;
    
    scanf("%d", &test );
    while( test-- ){
    
           scanf("%d %d %d %d", &a, &b, &c, &d );
           ini = d + 10*c + 100*b + 1000*a;
           scanf("%d %d %d %d", &a, &b, &c, &d );
           fim = d + 10*c + 100*b + 1000*a;
           
           for( i = 0; i < 10000; i++ ) pode[i] = 1, min[i] = INF;
           
           scanf("%d", &f );
           for( i = 0; i < f; i++ ){
                scanf("%d %d %d %d", &a, &b, &c, &d );
                s = d + 10*c + 100*b + 1000*a;
                pode[s] = 0;
           }
           
           min[ini] = 0;
           pode[ini] = 0;
           frst = lst = 0;
           fila[lst++] = ini;
           
           while( frst != lst ){
           
                  i = fila[frst++];
                  
                  
                  if( i == fim ) break;
                  f = i;
                  d = i % 10; i /= 10;
                  c = i % 10; i /= 10;
                  b = i % 10; i /= 10;
                  a = i;  
                  i = f;
                  
                  f = a;
                  a = viz[a][0];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
                  a = viz[f][1];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
                  a = f;
                  
                  f = b;
                  b = viz[b][0];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
                  b = viz[f][1];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
                  b = f;
                  
                  f = c;
                  c = viz[c][0];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
                  c = viz[f][1];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
                  c = f;
                  
                  f = d;
                  d = viz[d][0];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
                  d = viz[f][1];
                  s = d + 10*c + 100*b + 1000*a;
                  if( pode[s] ) { fila[lst++] = s; pode[s] = 0; min[s] = min[i] + 1; }
           
           }
           
           if( min[fim] == INF ) min[fim] = -1;
           printf("%d\n", min[fim] );
           
           
    }

    return 0;
}

