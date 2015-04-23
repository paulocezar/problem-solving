/*
 *  Problema: 3577. Parity
 *  Tecnica Utilizada: Meet in the Middle + Backtracking + Bitmasks  
 *	
 *
 *  Dificuldade: FODA!
 *	Complexidade:
 *				O( C(M, K/2) * log( C(M, K/2) ) * N )
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

#define MAXN 64
int64 s[MAXN], b[MAXN];
int n, m, k, pos, falta;

int64 MASK, BIS;
map< int64, int64 > middle;

#define DEBG(xxx, sz) REP(bit, sz) if(xxx&(1LL<<bit)) cout << "1"; else cout << "0"; cout << endl;

void buildSets( int64 XORS ){
	
	if( pos == m || !falta ){
		middle[XORS] = MASK;
		return;
	}
	
	MASK |= (1LL<<pos);
	int64 NXORS = XORS;
	REP( i, n ) if( s[i] & (1LL<<pos) ) NXORS ^= (1LL<<i);
	
	pos++; falta--;
	buildSets( NXORS );
	pos--; falta++;
	MASK ^= (1LL<<pos);
	
	pos++;
	buildSets( XORS );
	pos--;
}

bool meetInMiddle( int64 XORS ){
	
	if( pos == m || !falta ){
		
		if( middle.find(XORS) == middle.end() ) return false;
		
		int64 SET = MASK ^ middle[XORS];
		
		int cnt = 0;
		int ans[m];
		REP( i, m ) if( SET & (1LL<<i) ) ans[cnt++] = i;
		cout << cnt << "\n";
		REP( i, cnt ){ if( i ) cout << " "; cout << ans[i]; }
		if( cnt ) cout << "\n";
		
		return true;
	}
	
	MASK |= (1LL<<pos);
	int64 NXORS = XORS;
	REP( i, n ) if( s[i] & (1LL<<pos) ) NXORS ^= (1LL<<i);
	
	pos++; falta--;
	bool rt = meetInMiddle( NXORS );
	pos--; falta++;
	MASK ^= (1LL<<pos);
	
	if( rt ) return true;
	
	pos++;
	rt = meetInMiddle( XORS );
	pos--;
	if( rt ) return true;
	return false;
}


int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	string ss;
	
	cin >> n >> k;
	cin >> ss >> b[0];
	
	BIS = 0;
	m = SIZE(ss);
	s[0] = 0;
	
	REP( bit, m ) if( ss[bit] == '1' ) s[0] |= (1LL<<bit);
	if( b[0] ) BIS |= 1LL;
	
	FOR( i, 1, n ){
		cin >> ss >> b[i];
		s[i] = 0;
		REP( bit, m ) if( ss[bit] == '1' ) s[i] |= (1LL<<bit);
		if( b[i] ) BIS |= (1LL<<i);
	}
	
	middle.clear();
	MASK = 0;
	pos = 0;
	falta = k/2;
	
	buildSets( 0 );
	
	falta = k - (k/2);
	
	if( !meetInMiddle(BIS) ) cout << "-1\n";
	
	return 0;
}
