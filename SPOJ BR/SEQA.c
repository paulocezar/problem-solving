#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char appear[1001];
    int seq[31];    
    int d, i, j, max, casenum = 1;
    char isA;
    
    while( scanf("%d", &d ) != EOF ){
           memset( appear, 0, sizeof( appear ) );
           isA = 1;
           
           scanf("%d", &seq[0] ); max = seq[0]; appear[max] = 1;          
           for( i = 1; i < d; i++ ){
                  scanf("%d", &seq[i] );
                  if( isA ){
                      if( seq[i] < seq[i-1] ){ isA = 0; continue; }
                      if( appear[seq[i]] ){ isA = 0; continue; }
                      for( j = max; j > 0; j-- ){
                           if( appear[j] ){
                               if( j + seq[i] < 1001 ){
                                   appear[j + seq[i]] = 1;
                                   if( j + seq[i] > max ) max = j + seq[i];
                               }
                           }
                      }
                      appear[seq[i]] = 1;
                  }
           }
           
           printf("Case #%d:", casenum++ );
           for( i = 0; i < d; i++ )
                printf(" %d", seq[i] );
           printf("\n");
           
           if( isA )
               printf("This is an A-sequence.\n");
           else
               printf("This is not an A-sequence.\n");

           
    }    

    return 0;
}

