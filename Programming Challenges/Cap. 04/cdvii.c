#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXP 1001
#define MAXL 256

typedef struct{
        char license[21];
        char code[6];
        int month;
        int day;
        int hour;
        int min;
        int location;
} photo;

photo records[MAXP];
int fare[24];
int nrecords;

int comp( const void* a, const void* b ){
    photo* pa = (photo*)a;
    photo* pb = (photo*)b;
    int r =  strcmp( pa->license, pb->license);
    if( r ) return r;
    r  = pa->day - pb->day;
    if( r ) return r;
    r = pa->hour - pb->hour;
    if( r ) return r;
    r = pa->min - pb->min;
    if( r ) return r;
    return pa->location - pb->location;
}



void makeBills( ){
     
     int i;
     char paired;
     int cost;
     int fee;
     
     for( i = 0; i < nrecords; ) {
          char *actual = records[i].license;
          paired = 0;
          cost = 0;
          for( ; i < nrecords; i++ ){
               if( strcmp( actual, records[i].license ) != 0 ) break;
               
               if( !paired ){
                   if( records[i].code[1] == 'n')
                       paired = 1;
                   else continue;
               }
               if( paired ){
                   if( records[i].code[1] == 'x' ){
                       paired = 0;
                       cost += 100 + fare[records[i-1].hour] * abs( records[i].location - records[i-1].location );
                   }
               } else continue;
          } 
          
          if( cost > 0 ){
              cost += 200;
              printf("%s $%d.%02d\n", actual, cost / 100, cost % 100 );
          }
     }
}

int main(){
    
    int cases, i;
    char line[MAXL];
    
    scanf("%d", &cases);

    while( cases-- ){
           
           for( i = 0; i < 24; i++ )
                scanf("%d", &fare[i] );
           getchar();
                
           nrecords = 0;
           while( fgets( line, MAXL, stdin ) && line[0] != '\n' ){

                  sscanf( line, "%s %d%*c%d%*c%d%*c%d %s %d\n",
                          records[nrecords].license, &records[nrecords].month, 
                          &records[nrecords].day, &records[nrecords].hour, 
                          &records[nrecords].min, records[nrecords].code,
                          &records[nrecords].location );
                  nrecords++;
           }
           
           qsort( records, nrecords, sizeof( photo ), comp );
           makeBills();
           if( cases ) printf("\n");
    }
           
           return 0;
}
