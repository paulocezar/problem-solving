#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char appear[3050];
    int n, i, j, dif, last;
    char isJolly;
    
    while( scanf("%d", &n ) != EOF ){
           
           for( i = 1; i < n; i++ ) appear[i] = 0;
           
           if( n ){
           
               isJolly = 1;
               scanf("%d", &last );
           
               for( i = 1; i < n; i++ ){
                    scanf("%d", &j );
                    dif = last - j;
                    if( dif < 0 ) dif = -dif;
                    appear[dif] = 1;
                    last = j;                
               }
               
               for( i = 1; i < n; i++ )
                    if( appear[i]==0 ){ isJolly = 0; break; }
           
           } else isJolly = 0;
           
           if( isJolly )
               printf("Jolly\n");
           else
               printf("Not jolly\n");
           
    }   
    return 0;    
}
