#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define MAXP 100000

int primos[9593];
char primo[MAXP];
     
int nprimos;

void geraPrimos(){

     int i, j;
     
     for( i = 0; i < MAXP; i++ )
          primo[i] = i % 2;
     primo[1] = 0;
     primo[2] = 1;
     primos[0] = 2;
     nprimos = 1;     
     for( i = 3; i < MAXP; i++ ) if( primo[i] ){
          primos[nprimos++] = i;
          for( j = i+i; j < MAXP; j+=i ) primo[j] = 0;
     }

}

char concPrimo( char* s ){
     
     int value, i, j;
     char saux[10];
     
     if( s[0] == '0' ) return 0;
     sscanf( s, "%d", &value );
     
     if( primo[value] ) return 1;
     
     i = strlen( s ) - 1;
     while( i > 0 ){
            for( j = 0; j < i; j++ ) saux[j] = s[j];
            saux[i] = 0;
            
            if( concPrimo( saux ) && concPrimo( s + i  ) ) return 1;
            i--;
     }
     
     return 0;
}

int main(){
    
    int n;
    char x[10];
    
    geraPrimos();
    
    scanf("%d", &n ); getchar();
    while( n-- ){
           
           scanf("%[^\n]", &x ); getchar();
           
           if( concPrimo( x ) ) puts("sim");
           else puts("nao");
                  
    }
    
    return 0;    
}
