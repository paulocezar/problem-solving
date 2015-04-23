#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int t, n, press, rem;
    int i, j, nxt, _nxt;
    char word[110][110];
    char used[110];
    int order[110];
    char *curr;
    
    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d", &n ); getchar();
           for( i = 0; i < n; i++ ){
                used[i] = 0;
                scanf("%[^\n]", word[i] );  getchar();
           }
           
           press = strlen( word[0] );
           used[0] = 1;
           order[0] = 0;
           curr = word[0];
           rem = n-1;
           while( rem ){
                  _nxt = -1;
                  for( i = 0; i < n; i++ ) if( !used[i] ){
                       j = 0;
                       while( curr[j] && word[i][j] && curr[j]==word[i][j] ) j++;
                       if( j > _nxt ) nxt = i , _nxt = j;
                  }
                  order[n-(rem--)] = nxt;
                  curr = word[nxt];
                  used[nxt] = 1;
                  press += ( strlen( curr ) - _nxt );               
           }
           
           printf("%d\n", press );
           for( i = 0; i < n; i++ )
                puts( word[order[i]] );

    }    
    
    return 0;
}
