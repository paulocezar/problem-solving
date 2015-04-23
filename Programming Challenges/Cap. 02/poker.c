#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NVALUES 13
#define NSUITS 4

char w, t;

enum {
  HighCard, Pair, TwoPairs, TreeKind, Straight, Flush, FullHouse, FourKind, StraightFlush,
};

int comp( const void* a, const void* b ){
	return *(int*)b - *(int*)a;
}

void rank( int values[], char suits[], int rank[] ){
     
  int i, j;
  int count[NVALUES] = {0};
  char flush, straight, pair, three, four;
  int kind;
  flush = straight = pair = three = four = 0;
  
  for (i = 0; i < 5; i++ )
    count[values[i]]++;
    
  straight = values[0] - values[1] == 1 && values[1] - values[2] == 1 &&
    values[2] - values[3] == 1 && values[3] - values[4] == 1;
  
  flush = suits[0] == suits[1] && suits[1] == suits[2] &&
    suits[2] == suits[3] && suits[3] == suits[4];
    
  for( i = 0; i < NVALUES; i++ ) {
    if( count[i] == 2 )
        pair += 1;
    else if( count[i] == 3 )
      three += 1;
    else if( count[i] == 4 )
      four += 1;
  }
  
  if( straight && flush )
    kind = StraightFlush;
  else if( four )
    kind = FourKind;
  else if( three && pair )
    kind = FullHouse;
  else if( flush )
    kind = Flush;
  else if( straight )
    kind = Straight;
  else if( three )
    kind = TreeKind;
  else if( pair == 2 )
    kind = TwoPairs;
  else if( pair )
    kind = Pair;
  else
    kind = HighCard;
  
  rank[0] = kind;
  switch( kind ){
         case HighCard:
         case Flush:
                    for( i = 0; i < 5; i++ )
                         rank[i+1] = values[i];
                    break;
         case Straight:
         case StraightFlush:
                    rank[1] = values[0];
                    break;
         case FourKind:
                       if( values[0] == values[1] )
                          rank[1] = values[0];
                       else
                          rank[1] = values[1];
                       break;
         case FullHouse:
                       if( values[0] == values[1] && values[1] == values[2] )
                          rank[1] = values[0];
                       else
                          rank[1] = values[2];
                       break;
         case TreeKind:
                       if (values[0] == values[1])
                          rank[1] = values[0];
                       else if (values[1] == values[2])
                          rank[1] = values[1];
                       else
                           rank[1] = values[2];
                       break;
         case Pair:
                       for( i = 0, j = 2; i < 4; i++ )
                            if( values[i] == values[i+1] )
                                rank[1] = values[i++];
                            else
                                rank[j++] = values[i];
                            break;
         case TwoPairs:
                       for( i = 0, j = 3; i < 4; i++ )
                            if( values[i] == values[i+1] )
                                rank[1] = values[i++];
                            else
                                rank[j++] = values[i];
                       if( rank[1] < rank[2] ){
                          i = rank[2]; rank[2] = rank[1]; rank[1] = i;
                       }
                       break;
         default:
                 break;
  }
}
         
void analise( int bvalues[], char bsuits[], int wvalues[], char wsuits[] ){
    
  int brank[6] = {-1, -1, -1, -1, -1, -1, };
  int wrank[6] = {-1, -1, -1, -1, -1, -1, };
  int i;
  
  rank( bvalues, bsuits, brank );
  rank( wvalues, wsuits, wrank );
  
  for (i = 0; i < 6; ++i) 
    if( brank[i] > wrank[i] )
      return;
    else if( brank[i] < wrank[i] ){
      w = 1;  
      return;
    }
  
  t = 1;    
  return;
}
     
int main( ){

  char *cvalues = "23456789TJQKA";
  int values[128];
  int bvalues[5], wvalues[5];
  char bsuits[5], wsuits[5];
  char line[40];
  int i;
  
  for (i = 0; i < NVALUES; ++i)
    values[cvalues[i]] = i;
    
  while( fgets( line, 40, stdin) != NULL ){
    for (i = 0; i < 5; ++i) {
      bvalues[i] = values[line[3*i]];
      bsuits[i] = line[3*i+1];
      wvalues[i] = values[line[3*i+15]];
      wsuits[i] = line[3*i+16];
    }
    qsort( wvalues, 5, sizeof( int ), comp );
    qsort( bvalues, 5, sizeof( int ), comp );
    w = t = 0;
    
    analise( bvalues, bsuits, wvalues, wsuits );
    
    if( t )
		printf("Tie.\n");
    else if( w )
		printf("White wins.\n");
    else
		printf("Black wins.\n");
  }
  return 0;
}
