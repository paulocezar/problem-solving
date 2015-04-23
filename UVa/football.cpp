#include <iostream>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SNAME 32
#define STOURNAME 102
#define MAXT 30
#define LSIZE 105

using namespace std;

struct team{
   char name[SNAME];
   int played;
   int wins;
   int ties;
   int goalS;
   int goalA;
};

struct strcmpr {
       bool operator()( char const *s1, char const *s2 ){
            return strcmp(s1, s2) < 0;
       }
};
   
int comp( const void* a, const void* b ){
    team* ta = (team*)a;
    team* tb = (team*)b;
    int r, pa, pb;
    
    pa = (ta->wins * 3) + ta->ties;
    pb = (tb->wins * 3) + tb->ties;
    
    r = pb - pa;
    if( r ) return r;
    
    r = tb->wins - ta->wins;
    if( r ) return r;
    
    pa = ta->goalS - ta->goalA;
    pb = tb->goalS - tb->goalA;
    r = pb - pa;
    if( r ) return r;
    
    r = tb->goalS - ta->goalS;
    if( r ) return r;
    
    r = ta->played - tb->played;
    if( r ) return r;
    
    return strcasecmp( ta->name, tb->name );
    
}
         
int main( ){
    
  int cases, t, g;
  char tourname[LSIZE];
  char line[LSIZE];
  char t1[SNAME];
  char t2[SNAME];
  char num[3];
  int i, g1, g2;
  char* ptr;
  char* tptr;

  team results[MAXT];
  
  scanf("%d", &cases ); getchar();
  while( cases-- ){
         
    gets(tourname);
    map< char *, int, strcmpr > tid;
      
    scanf("%d", &t ); getchar();
    for( i = 0; i < t; i++ ){
      gets( results[i].name );
      tid[results[i].name] = i;
      results[i].played = 0;
      results[i].wins = 0;
      results[i].ties = 0;
      results[i].goalS = 0;
      results[i].goalA = 0;
    }

    
    scanf("%d", &g ); getchar();
    for( i = 0; i < g; i++ ){
         
      gets( line );
      ptr = line; tptr = t1;
      while( *ptr != '#' ){
             *tptr = *ptr;
             ptr++, tptr++;
      }
      *tptr = 0;
      tptr = num; ptr++;
      while( *ptr != '@' ){
             *tptr = *ptr;
             ptr++, tptr++;
      }
      *tptr = 0;
      g1 = atoi( num );
      ptr++; tptr = num;
      while( *ptr != '#' ){
             *tptr = *ptr;
             ptr++, tptr++;
      }
      *tptr = 0;
      g2 = atoi( num );
      tptr = t2; ptr++;
      while( *ptr && *ptr != '\n' ){
             *tptr = *ptr;
             ptr++, tptr++;
      }
      *tptr = 0;
      
      results[tid[t1]].goalS += g1;
      results[tid[t1]].goalA += g2;
      results[tid[t2]].goalS += g2;
      results[tid[t2]].goalA += g1;
      if( g1 > g2 ) results[tid[t1]].wins++;
      else if( g1 < g2 ) results[tid[t2]].wins++;
      else{ results[tid[t1]].ties++; results[tid[t2]].ties++; }
      
      results[tid[t1]].played++;
      results[tid[t2]].played++;
      
    }
    
    qsort( results, t, sizeof( team ), comp );
    
    puts( tourname );
    for( i = 0; i < t; i++ )
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
             i + 1, results[i].name, results[i].wins * 3 + results[i].ties,
             results[i].played, results[i].wins, results[i].ties,
             results[i].played - results[i].wins - results[i].ties,
             results[i].goalS - results[i].goalA, results[i].goalS, 
             results[i].goalA );
    
    if( cases ) puts("");
  }
  
  return 0;
}
