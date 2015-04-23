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
#include <iomanip>
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 50100
 
string text;
int N, sa[MAXN], rank[MAXN], LCP[MAXN];
int cnt[MAXN], sa2[MAXN], key[MAXN];
 
void buildSA()
{
	int i, j, k, m;
 
	memset(cnt, 0, 256*sizeof(int));
	for (i = 0; i < N; i++) ++cnt[(unsigned char)text[i]];
	for (i = 0; i < 255; i++) cnt[i+1] += cnt[i];
	for (i = 0; i < N; i++) sa[--cnt[(unsigned char)text[i]]] = i;
	for (i = 0; i < N; i = j) {
		for (j = i + 1; j < N && text[sa[i]] == text[sa[j]]; j++);
		for (k = i; k < j; k++) rank[sa[k]] = i;
	}
 
	for (m = 1; m < N; m *= 2) {
		memset(cnt, 0, (N+1)*sizeof(int));
		for (i = 0; i < N; i++) ++cnt[key[i] = i+m < N ? 1+rank[i+m] : 0];
		for (i = 0; i < N; i++) cnt[i+1] += cnt[i];
		for (i = 0; i < N; i++) sa2[--cnt[key[sa[i]]]] = sa[i];
 
		memset(cnt, 0, (N+1)*sizeof(int));
		for (i = 0; i < N; i++) ++cnt[rank[sa2[i]]];
		for (i = 0; i < N; i++) cnt[i+1] += cnt[i];
		for (i = N-1; i >= 0; i--) sa[--cnt[rank[sa2[i]]]] = sa2[i];
 
		for (i = 0; i < N; i = j) {
			for (j = i+1; j < N && rank[sa[j]] == rank[sa[i]] && key[sa[j]] == key[sa[i]]; j++);
			for (k = i; k < j; k++) rank[sa[k]] = i;
		}
	}
}

void buildLCP(){
	REP( i, N ) rank[ sa[i] ] = i;
	LCP[0] = 0;
	for( int i = 0, h = 0; i < N; i++ ){
		if( rank[i] > 0 ){
			int j = sa[ rank[i]-1 ];
			while( ((i + h) < N) && ((j + h) < N) && (text[i+h] == text[j+h]) ) h++;
			LCP[ rank[i] ] = h;
			if( h > 0 ) h--;
		}
	}
	
}
 
int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	while( t-- ){
		
		cin >> text;
		N = SIZE( text );
		buildSA();
		buildLCP();
		int64 ans = 0;
		REP( i, N ) ans += N-sa[i]-LCP[i];
		cout << ans << "\n";
		
	}
	
	return 0;
}




















