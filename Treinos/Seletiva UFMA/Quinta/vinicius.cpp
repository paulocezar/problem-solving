#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <vector>

using namespace std;

list< int > graph[300];
int color[300];

bool dfsRecolor( int u, int ncolor ){
     
     list< int >::iterator v;
     color[u] = 1 - ncolor;
     
     for( v = graph[u].begin(); v != graph[u].end(); v++ ){
          if( color[*v] == 2 ){
              if( !dfsRecolor( *v, 1-ncolor ) ) return false;
          } else if( color[*v] == 1-ncolor ) return false;     
     }
     
     return true;
     
}

bool bicolorable( int N ){
     
     int u;

     for( u = 0; u < N; u++ )
          color[u] = 2;
     
     for( u = 0; u < N; u++ )
          if( color[u] == 2 ) if( !dfsRecolor( u, 0 ) ) return false;
     
     return true;
     
}


int main(){
    
    int n, id;
    int i, j;
    string s1, s2;
    int a1, a2;
    
    while( true ){
    
           cin >> n;
           if( n == 0 ) return 0;
           
           map< string, int > hash;
     
           id = 0;
           for( i = 0; i < n; i++ ){
                
                cin >> s1 >> s2;
                
                if( hash.find( s1 ) != hash.end() ) a1 = hash[s1];
                else { hash[s1] = id; a1 = id++; graph[a1].clear(); }
                
                if( hash.find( s2 ) != hash.end() ) a2 = hash[s2];
                else { hash[s2] = id; a2 = id++; graph[a2].clear(); }
                
                graph[a1].push_back( a2 );
                graph[a2].push_back( a1 );
                
           }
           
           if( id > 300 ) return 1;
           
           if( bicolorable( id ) ) cout << "sim" << endl;
           else cout << "nao" << endl;
           
    }    

    return 0;    
}
