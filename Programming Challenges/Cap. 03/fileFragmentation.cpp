#include <iostream>
#include <string>

using namespace std;

int cases;
int nfiles, nfrags, totalSize, fileSize;
char used[288];
string fragments[288];
string line, file;

int comp( const void* a, const void* b ){
    return (*(string*)a).size() - (*(string*)b).size();
}

char solve( int x, int ff ){
     
     if( ff == nfiles ) return 1;
     
     char ret = 0;
     int j, l;
     string str;
     used[x] = 1;
     
     for( j = nfrags-1; !ret && j != x ; j-- ){
          if( used[j] ) continue;
     
          l = fragments[x].size() + fragments[j].size();
          if( l != fileSize ){
              break;
          }
          else{
               used[j] = 1;
               str = fragments[x] + fragments[j];
               if( str == file )
                   ret = solve( x+1, ff+1 );
               if( !ret ){
                   str = fragments[j] + fragments[x];
                   if( str == file )
                       ret = solve( x+1, ff+1 );
               }
               used[j] = 0;
          }
     }
     
     used[x] = 0;
     return ret;     
}

int main(){
    
    int i, j, k, l;
    char find;
           
    scanf("%d", &cases ); getchar(); getchar();
    while( cases-- ){
    
           nfrags = totalSize = 0;
           
           while( getline( cin, line ) && line[0] ){
                  fragments[nfrags++] = line;
                  totalSize += line.size();                
           }
           nfiles = nfrags / 2;
           fileSize = totalSize / nfiles;

           qsort( fragments, nfrags, sizeof( string ), comp );

           memset( used, 0, sizeof( char ) * nfrags );
           used[0] = 1;
           find  = 0;
           
           for( j = nfrags-1; !find && j != 0 ; j-- ){
                l = fragments[0].size() + fragments[j].size();
                if( l != fileSize ) break;
                else{
                     used[j] = 1;
                     file = fragments[0] + fragments[j];
                     find = solve( 1, 1 );
                     if( !find ){
                         file = fragments[j] + fragments[0];
                         find = solve( 1, 1 );
                     }
                     used[j] = 0;
                }
           }
           cout << file << endl;
    
           if( cases ) printf("\n");
    }
    
    return 0;
}
