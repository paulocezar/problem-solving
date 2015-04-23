#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int used[1001];
vector< pair<int,int> > losing;

int getworst( pair<int,int> &pos ){
	int i = 0;
	while( losing[i] != pos ) i++;
	return i;
}

int getbest( pair<int,int> &pos ){	
	int i = 0;
	while( i < SIZE(losing) ){
		if( pos.second-pos.first == losing[i].second-losing[i].first ) break;
		if( pos.first == losing[i].first ) break;
		if( pos.first == losing[i].second ) break;
		if( pos.second == losing[i].first ) break;
		if( pos.second == losing[i].second ) break;
		i++;
	}
	return i;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int dif = 0;
	
	for( int X = 0; X <= 1000; X++ ) if( !used[X] ){
		used[X] = 1;
		if( X+dif <= 1000 ){
			used[X+dif] = 1;
			losing.PB( MP(X, X+dif) );
		} else break;
		dif++;
	}
	
	int t, X, Y, P;
	
	cin >> t;
	while( t-- ){
		cin >> X >> Y >> P;
		pair<int,int> pos(min(X,Y),max(X,Y));
		if( binary_search(ALL(losing), pos ) ){
			cout << "Gita " << (2*P + 2*getworst(pos)) << "\n";
			/* first player loses.. so, start passing the turn..
				second player will pass the turn in order to keep winning..
				then first player get the worst losing position */
		} else {
			cout << "Sita " << (1 + 2*P + 2*getbest(pos)) << "\n";
			/* first player wins.. so, start moving to the smallest losing
			position. then second player goes passing turns and to keep winnin
			first player also pass.*/
		}
	}
		
	
	return 0;
}

























