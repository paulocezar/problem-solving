#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char wrd[18];
        int id;
        int size;
} word;

struct node{
        int v;
        struct node* nxt;
};
typedef struct node node;

typedef struct{
        node* head;
}list;

word dict[25144];
char words[25144][18];
list graph[25144];
int parent[25144];
int queue[25144];
char used[25144];
int front, back, eid;

char areDoublet( char* x, char* y ){

     char err = 1;   
     
     while( *x ){
          if( *x != *y )
              if( err ) err--;
              else return 0;
          x++; y++;
     }
     return 1;
}

int findId( char* str, int a, int b ){

    if( a > b ) return -1;
    int p = ( a + b ) / 2;
    int r = strcmp( str, dict[p].wrd );
    if( r == 0 ) return dict[p].id;
    else if( r > 0 ) return findId( str, p+1, b );
    else return findId( str, a, p-1 );
}

int comp( const void* a, const void* b ){
    return strcmp( ((word*)a)->wrd, ((word*)b)->wrd );
}

void printPath( int x ){
     
     if( parent[x] != x )
         printPath( parent[x] );
     printf("%s\n", words[x] );

}

int main(){

    int dictsize = 0;
    int i, u, bid;
    char line[40], begin[18], end[18];
    char prnt = 0;
    node* aux;
    node* v;
    
    for( i = 0; i < 25144; i++ )
      graph[i].head = NULL;

    while( gets( dict[dictsize].wrd ) && dict[dictsize].wrd[0] ){
           strcpy( words[dictsize], dict[dictsize].wrd );
           dict[dictsize].id = dictsize;
           dict[dictsize].size = strlen( dict[dictsize].wrd );
           for( i = dictsize-1; i >= 0; i-- ){
                if( dict[dictsize].size == dict[i].size )
                    if( areDoublet( dict[dictsize].wrd, dict[i].wrd ) ){
                            aux = (node *)malloc(sizeof(node));
                            aux->v = dictsize;
                            aux->nxt = graph[i].head;
                            graph[i].head = aux;
                            aux = (node *)malloc(sizeof(node));
                            aux->v = i;
                            aux->nxt = graph[dictsize].head;
                            graph[dictsize].head = aux;
                    }
           }
           dictsize++;
    }
           
    qsort( dict, dictsize, sizeof( word ), comp );
    dictsize--;

    while( gets( line ) ){
           if( line[0] == 0 ) continue;
           sscanf(line, "%s %s", begin, end );
           if( prnt ) printf("\n"); else prnt++;
           
           if( strlen( begin ) != strlen( end ) ){
               printf("No solution.\n"); 
               continue;
           }
           bid = findId( begin, 0, dictsize );
           if( bid == -1 ){
               printf("No solution.\n"); 
               continue;
           }
           eid = findId( end, 0, dictsize );
           if( eid == -1 ){
               printf("No solution.\n"); 
               continue;
           }
           
           memset( used, 0, (sizeof(char)*(dictsize+1)) );
           front = back = 0;
           queue[back++] = bid;
           parent[eid] = -1;
           parent[bid] = bid;
                
           while( front != back && parent[eid] == -1 ){
                  u = queue[front++];
                  used[u] = 1;

                  for( v = graph[u].head; v != NULL; v = v->nxt ){
                       if( !used[v->v] ){
                           queue[back++] = v->v;
                           parent[v->v] = u;
                           used[v->v] = 1;
                           if( v->v == eid ) break;
                       }     
                  }
           }          
           
           if( parent[eid] == -1 )
               printf("No solution.\n");
           else
               printPath( eid );
           
    }


    return 0;    
}
