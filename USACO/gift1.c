/*
ID: knightp2
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXNP 11
#define NAMES 16

typedef struct {
        char name[NAMES];
        int ini;
        int alter;
} person;

int main () {
        
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    
    /*
     *  gi = indice of the friend who is givin money
     *  ri = indice of the friend who is receiving money
     *  ng = number of friends the amount is being divided
     *  ga = amount of money the perso gives to each friend
     */ 
    int np, a, b, i, j, gi, ri, ng, ga;
    person friends[MAXNP];
    char actual[NAMES];
    
    fscanf( fin, "%d", &np );
    
    for( i = 0; i < np; i++ ){
         fscanf( fin, "%s\n", friends[i].name );
         friends[i].ini = friends[i].alter = 0;     
    }

    for( i = 0; i < np; i++ ){
         
         fscanf( fin, "%s", actual );
         
         for( gi = 0; gi < np; gi++ ) if( strcmp( actual, friends[gi].name ) == 0 ) break;

         fscanf( fin, "%d %d\n", &friends[gi].ini, &ng );
         
         if( ng ) ga = friends[gi].ini / ng;
         else ga = 0;
         friends[gi].alter += ( friends[gi].ini - ( ga * ng ) );
         
         for( j = 0; j < ng; j++ ){
              fscanf( fin, "%s\n", actual );
              if( ga ){
                  for( ri = 0; ri < np; ri++ ) if( strcmp( actual, friends[ri].name ) == 0 ) break;        
                  friends[ri].alter += ga;
              }
         }    
    } 
    
    for( i = 0; i < np; i++ )
         fprintf( fout, "%s %d\n", friends[i].name, friends[i].alter - friends[i].ini );   
    

    return 0;
}

