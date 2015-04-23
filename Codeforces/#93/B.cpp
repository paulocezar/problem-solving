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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1000100

int p[MAXN], p2[MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	string S;
	cin >> S;
	int N = SIZE(S);
	
	p[0] = p[1] = 0;
	FOR( i, 2, N ){
		int j = p[i-1];
		while( S[i-1] != S[j] ){
			if( j == 0 ){ j = -1; break; }
			j = p[j];
		}
		p[i] = ++j; 
	}
	
	string cand = "";
	for( int i = 0; i < p[N]; i++ ) cand += S[i];
	
	bool found = false;
	while( cand != "" ){
		
		int N2 = SIZE(cand);
		p[0] = p[1] = 0;
		FOR( i, 2, N2 ){
			int j = p[i-1];
			while( cand[i-1] != cand[j] ){
				if( j == 0 ){ j = -1; break; }
				j = p[j];
			}
			p[i] = ++j; 
		}
		
		int i = 1;
		int j = 0;
		while( i < N-1 ){
			if( S[i] == cand[j] ) i++, j++;
			else if( j ) j = p[j];
			else i++;
			
			if( j == N2 ){
				cout << cand << "\n"; found = true;
				goto hell;
			}	
		}
		
		string aux = "";
		for( int i = 0; i < p[N2]; i++ ) aux += cand[i];
		cand = aux;
	}
hell:	
	if( !found ) cout << "Just a legend\n";
	
	
	return 0;
}




















