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

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct cube_t{
	int color, size, id;
	cube_t( int a = 0, int b = 0, int c = 0 ) : color(a), size(b), id(c) {}
	bool operator < ( const cube_t &cb ) const {
		if( color != cb.color ) return color < cb.color;
		if( size != cb.size ) return size > cb.size;
		return id < cb.id;
	}
};

#define MAXN 100001

int64 best[2][MAXN];
vector< int > who[2][MAXN];
cube_t cube[MAXN];

void check( int64 cur, int len, int color ){
	
	if( cur == best[0][len] ){
		
		who[0][len].PB( color );
		
	} else if( cur > best[0][len] ){
		
		best[1][len] = best[0][len];
		who[1][len] = who[0][len];
		
		best[0][len] = cur;
		who[0][len].clear();
		who[0][len].PB( color );
		
	} else if( cur == best[1][len] ){
		
		who[1][len].PB( color );
		
	} else if( cur > best[1][len] ){
		
		best[1][len] = cur;
		who[1][len].clear();
		who[1][len].PB( color );
		
	}
}

pair< int64, pair<int,int> > aux;

bool can_combine( vector<int> &a, vector<int> &b ){
	if( !SIZE(a) || !SIZE(b) ) return false;
	aux.second.first = a[0];
	int i = 0;
	while( i < SIZE(b) ){
		if( b[i] != a[0] ){
			aux.second.second = b[i];
			return true;
		} 
		i++;
	}
	if( SIZE(a) > 1 ){
		aux.second.first = a[1];
		i = 0;
		while( i < SIZE(b) ){
			if( b[i] != a[1] ){
				aux.second.second = b[i];
				return true;
			} 
			i++;
		}
	}
	return false;
}

void longest( int len1, int len2 ){
	
	aux.first = -1;
	
	if( can_combine( who[0][len1], who[0][len2] ) ){
		aux.first = best[0][len1] + best[0][len2];	
		return ;
	} 
	
	if( can_combine(who[0][len1], who[1][len2]) ){
		aux.first = best[0][len1] + best[1][len2];
	}
	
	int ac1 = aux.second.first, ac2 = aux.second.second;
	
	if( can_combine(who[1][len1], who[0][len2]) ){
		int64 secch = best[1][len1]+best[0][len2];
		if( secch > aux.first ){
			aux.first = secch;
		} else aux.second.first = ac1, aux.second.second = ac2;
	} else aux.second.first = ac1, aux.second.second = ac2;
	
	ac1 = aux.second.first, ac2 = aux.second.second;
	if( can_combine(who[1][len1], who[1][len2]) ){
		int64 secch = best[1][len1]+best[1][len2];
		if( secch > aux.first ){
			aux.first = secch;
		} else aux.second.first = ac1, aux.second.second = ac2;
	} else aux.second.first = ac1, aux.second.second = ac2;
		
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n;
	cin >> n;
	
	REP( i, n ){
		best[0][i] = -1;  best[1][i] = -1;
		who[0][i].clear(); who[1][i].clear();
		cin >> cube[i].color >> cube[i].size;
		cube[i].id = i+1;
	}
	
	sort( cube, cube+n );
	
	
	int64 cur = cube[0].size;
	int len = 1;
	check( cur, len, cube[0].color );
	
	FOR( i, 1, n-1 ){
		
		if( cube[i].color == cube[i-1].color ){
			cur += cube[i].size;
			len++;
		} else {
			cur = cube[i].size;
			len = 1;
		}
		
		check( cur, len, cube[i].color );
		
	}
	
	int64 ans = -1;
	int ans_height = 0;
	int ans_c1 = -1, ans_c2 = -1;
	
	FOR( i, 2, n ){
		int len2 = i/2;
		int len1 = i-len2;
		longest( len1, len2 );
		if( aux.first > ans ){
			ans = aux.first;
			ans_c1 = aux.second.first;
			ans_c2 = aux.second.second;
			ans_height = i;
		}
	}
	
// ...	
	cout << ans << "\n";
	cout << ans_height << "\n";
	
	int color1 = 0;
	while( cube[color1].color != ans_c1 ) color1++;
	int color2 = 0;
	while( cube[color2].color != ans_c2 ) color2++;
	
	REP( i, ans_height ){
		if( i ) cout << " ";
		if( i&1 )  cout << cube[color2++].id;
		else  cout << cube[color1++].id;
	}
	cout << '\n';
	
	return 0;
}

























