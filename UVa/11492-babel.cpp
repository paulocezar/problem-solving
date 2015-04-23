#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <map>
#include <queue>
#include <vector>
#include <list>

#define INF INT_MAX

using namespace std;
    
int main(){

    int n;
    string _src, _dest, word;
    int src, dest, num;
    int id, d, u, i, nd;
    list< int >::iterator v;
    
    cout.sync_with_stdio (false);
    while( true ){
    
           cin >> n;
           if( n == 0 ) return 0;       
           
           num = 3*n + 3;
           
           map< string, int > hash;
           list< int > graph[num];
           char first[num];
           int length[num];
           int dist[num];
           
           cin >> _src >> _dest;
           src = 0, dest = 1;
           id = 2;
           
           hash[_src] = 0;
           hash[_dest] = 1;
           first[0] = first[1] = '_';
           length[0] = length[1] = 0;
           
           for( i = 0; i < n; i++ ){
                cin >> _src >> _dest >> word;
                if( hash.find( _src ) == hash.end() ){
                    hash[_src] = id;
                    length[id] = 0;
                    first[id] = '_';
                    dist[id] = INF;
                    id++;
                }
                if( hash.find( _dest ) == hash.end() ){
                    hash[_dest] = id;
                    length[id] = 0;
                    first[id] = '_';
                    dist[id] = INF;
                    id++;
                }
                
                first[id] = word[0];
                length[id] = word.length();
                dist[id] = INF;
                
                u = hash[_src];
                for( v = graph[u].begin(); v != graph[u].end(); v++ ){
                     if( first[*v] != first[id] ){
                         graph[*v].push_back( id );
                         graph[id].push_back( *v );
                     }
                }
                graph[u].push_back( id );
                if( u == src || u == dest ) graph[id].push_back( u );
                
                u = hash[_dest];
                for( v = graph[u].begin(); v != graph[u].end(); v++ ){
                     if( first[*v] != first[id] ){
                         graph[*v].push_back( id );
                         graph[id].push_back( *v );
                     }
                }
                graph[u].push_back( id );
                if( u == src || u == dest ) graph[id].push_back( u );
                
                id++;
           }
           
           dist[src] = 0;
           dist[dest] = INF;
           priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > >Q;
           Q.push( make_pair( 0, src ) );
           
           for( u = 0; u < id; u++ ) graph[u].unique();
           
           while( !Q.empty() ){
                  
                  d = Q.top().first;
                  u = Q.top().second; Q.pop();
                  
                  if( u == dest ) break;
                  if( d > dist[u] ) continue;
                  
                  for( v = graph[u].begin(); v != graph[u].end(); v++ ){
                       nd = d + length[u];
                       if( nd < dist[*v] ){ Q.push( make_pair( nd, *v ) ); dist[*v] = nd; }
                  }
                  
           }
           
           if( dist[dest] == INF ) cout << "impossivel\n";
           else cout << dist[dest] << endl;
    
    }

    return 0;
}


