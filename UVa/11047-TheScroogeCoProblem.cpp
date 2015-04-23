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

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXP 111

string loc[MAXP];
int gr[MAXP][MAXP], p[MAXP][MAXP];

void show( int u, int v ){
	if( u != v ){
		show( u, p[u][v] );
		cout << " ";
	}
	cout << loc[v];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	map<string,int> id;
	string name, l1, l2;
	
	int c, P, R, u, v;
	cin >> c;
	while( c-- ){
		cin >> P;
		
		id.clear();
		REP( i, P ){
			cin >> loc[i];
			id[ loc[i] ] = i;
		}
		
		REP( i, P ) REP( j, P ){
			cin >> gr[i][j];
			if( gr[i][j] == -1 ) gr[i][j] = INF; 
			p[i][j] = i;
		}
		
		REP( k, P )
			REP( i, P )
			REP( j, P )
				if( gr[i][k]+gr[k][j] < gr[i][j] ){
					gr[i][j] = gr[i][k]+gr[k][j];
					p[i][j] = p[k][j];
				}
		
		cin >> R;
		while( R-- ){
			cin >> name >> l1 >> l2;
			u = v = -1;
			if( id.find(l1) != id.end() ) u = id[l1];
			if( id.find(l2) != id.end() ) v = id[l2];
			if( u != -1 && v != -1 && gr[u][v] != INF ){
				cout << "Mr " << name << " to go from " << l1 << " to " << l2 << ", you will receive " << gr[u][v] << " euros\n";
				cout << "Path:"; show(  u, v );
				if( u == v ) cout << " " << loc[v]; 
				cout << "\n";
			} else cout << "Sorry Mr " << name << " you can not go from " << l1 << " to " << l2 << "\n";
		}
	}
	
	return 0;
}




















