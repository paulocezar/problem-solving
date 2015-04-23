/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline bool isfree( string s, char x, char y ){
	bool ret = true;
	REP( i, 4 ) ret = ret && ( x != s[2*i] || y != s[2*i+1] ); 
	return ret;
}

string ord( string s ){
	vector< pair<char,char> > x(4);
	REP( i, 4 ){ x[i].first = s[2*i]; x[i].second = s[2*i+1]; }
	sort( x.begin(), x.end() );
	REP( i, 4 ){ s[2*i] = x[i].first; s[2*i+1] = x[i].second; }
	return s;
}

int dir[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
set< string > vis, vis2;

bool busca( string from, bool meet ){
	
	queue< pair<string, int> > q;
	q.push( mp(from,0) );
	
	char x, y, nx, ny;
	int curm;
	string cur, nxt;
	
	if( meet ){
		vis2.clear();
		if( vis.find( from ) != vis.end() ) return true;
		vis2.insert( ord( from ) );
	} else {
		vis.clear();
		vis.insert( ord( from ) );
	}
	
	while( !q.empty() ){
		
		cur = q.front().first;
		curm = q.front().second; q.pop();
		
		if( curm == 4 ) continue;
		
		REP( i, 4 ){
			x = cur[2*i];
			y = cur[2*i+1];
			REP( dd, 4 ){
				nxt = cur;
				nx = x+dir[dd][0];
				ny = y+dir[dd][1];
				
				if( nx <= '8' && nx >= '1' && ny <= '8' && ny >= '1' ){
					
					if( isfree(cur, nx, ny) ){
						nxt[2*i] = nx;
						nxt[2*i+1] = ny;
						nxt = ord( nxt );
						
						if( meet ){
							if( vis.find( nxt ) != vis.end() ) return true;
							if( vis2.insert( nxt ).second ) q.push( mp(nxt,curm+1) );
						} else if( vis.insert(nxt).second ) q.push( mp(nxt,curm+1) );
						
					} else {
						
						nx += dir[dd][0];
						ny += dir[dd][1];
						if( nx <= '8' && nx >= '1' && ny <= '8' && ny >= '1' ){
							if( isfree( cur, nx, ny) ){						
								nxt[2*i] = nx;
								nxt[2*i+1] = ny;
								nxt = ord( nxt );
								if( meet ){
									if( vis.find( nxt ) != vis.end() ) return true;
									if( vis2.insert( nxt ).second ) q.push( mp(nxt,curm+1) );
									
								} else if( vis.insert(nxt).second ) q.push( mp(nxt,curm+1) );
							}
						}
					}
				}
			}
		}
		
	}
	
	return false;	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t, x, y;
	cin >> t;
	string start, end;
	
	while( t-- ){
		
		start = "00000000";
		end = "00000000";
		
		REP( i, 4 ){ cin >> x >> y; start[2*i]+=x; start[2*i+1] += y; }
		REP( i, 4 ){ cin >> x >> y; end[2*i]+=x; end[2*i+1] += y; }		
		
		busca( start, false );
		if( busca(end, true) ) cout << "YES\n";
		else cout << "NO\n";
		
	}
		
	return 0;
}
