#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define NOR 0
#define SUL 1
#define LES 2
#define OES 3

#define DIR 0
#define ESQ 1

int d[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0,-1}};
int t[4][2] = { {LES, OES}, {OES, LES}, {SUL, NOR}, {NOR, SUL} };

string grid[111];

int main(){
    
    ios::sync_with_stdio( false );
    
    int N, M, S, ans;
    string line, trav = "";
    int x, y, pointin;
    
    REP( i, 111 ) trav += "#";
    
    cin >> N >> M >> S;
    while( N+M+S ){
    
           grid[0] = grid[N+1] = trav;
           
           REP( i, N ){
                cin >> line;
                grid[i+1] = "#" + line + "#";
           }
           cin >> line;
           
           REP( i, N ){
                REP( j, M ){
                     switch( grid[i+1][j+1] ){
                        case 'N': pointin = NOR; grid[i+1][j+1] = '.'; x = i+1, y = j+1; goto play;
                        case 'S': pointin = SUL; grid[i+1][j+1] = '.'; x = i+1, y = j+1; goto play;
                        case 'L': pointin = LES; grid[i+1][j+1] = '.'; x = i+1, y = j+1; goto play;
                        case 'O': pointin = OES; grid[i+1][j+1] = '.'; x = i+1, y = j+1; goto play;
                     } 
                }
           }

           
           play:
                ans = 0;
                int i = 0;
                while( i < S ){
                
                       switch( line[i] ){
                               case 'D': pointin = t[pointin][DIR]; break;
                               case 'E': pointin = t[pointin][ESQ]; break;
                               case 'F': 
                                         char &ref =  grid[x+d[pointin][0]][y+d[pointin][1]];
                                         if( ref != '#' ){
                                             x+=d[pointin][0];
                                             y+=d[pointin][1];
                                             if( ref == '*' ) ans++, ref = '.';
                                         }
                       }
                
                       i++;
                }
                cout << ans << "\n";
           
    cin >> N >> M >> S;
    }    

    return 0;    
}
