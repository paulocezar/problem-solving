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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
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

int popcount( int x ){
	int ans = 0;
	while( x ) { ans++; x -= ( x & -x); }
	return ans;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int group[4];
	group[0] = (1<<5)-1;
	group[1] = group[0]<<5;
	group[2] = group[1]<<5;
	group[3] = group[2]<<5;
	
	int N;
	int testno = 1;
	cin >> N;
	while( N ){
		
		string gentec[N], genco[N];
		
		REP( i, N ) cin >> gentec[i];
		REP( i, N ) cin >> genco[i];
		
		int ans[20], done[20];
		
		REP( i, 20 ) { ans[i] = (1<<20)-1; done[i] = 0; }
		
		REP( ind, N ){
			
			int mask = 0;
			REP( i, 4 ) mask |= ( 1<<(genco[ind][i]-'a') );
			REP( i, 4 ) ans[ gentec[ind][i]-'A' ] &= mask;
			
			queue< int > need;
			REP( i, 20 ) if( !done[i] && popcount(ans[i]) == 1 ){
				done[i] = 1;
				need.push( i );
			}
			
			while( !need.empty() ){
				
				int cur = need.front(); need.pop();
				
				REP( i, 20 ) if( !done[i] && ( ans[i] & ans[cur] ) ){
					ans[i] = ans[i] ^ ans[cur];
					if( popcount(ans[i]) == 1 ){
						done[i] = 1;
						need.push( i );
					}
				}
				
				int cgroup;
				if( ans[cur] >= 32768 ) cgroup = group[3];
				else if( ans[cur] >= 1024 ) cgroup = group[2];
				else if( ans[cur] >= 32 ) cgroup = group[1];
				else cgroup = group[0];
				
				int mygroup = 5*( cur/5 );
				FOR( i, mygroup, mygroup+5 ) ans[i] &= cgroup;
				
				cgroup = ((1<<20)-1) ^ cgroup;
				REP( i, mygroup ) ans[i] &= cgroup;
				FOR( i, mygroup+5, 20 ) ans[i] &= cgroup;
			
				REP( i, 20 ) if( !done[i] && ( ans[i] & ans[cur] ) ){
					ans[i] = ans[i] ^ ans[cur];
					if( popcount(ans[i]) == 1 ){
						done[i] = 1;
						need.push( i );
					}
				} else if( !done[i] && popcount( ans[i] ) == 1 ){ done[i] = 1; need.push( i ); }
				
			}
					
		}
		
		cout << "Test #" << testno++ << ":\n";
		REP( i, 20 ){
			cout << char(i+'A') << "-";
			if( popcount( ans[i] ) == 1 ){
				 REP( j, 20 ) if( ans[i] & 1<<j ) cout << char(j+'a');
			} else cout << "?";
			if( (i+1) % 5 == 0 ) cout << "\n";
			else cout << " ";
		}
		
		cin >> N;
	}
	
	return 0;
}
