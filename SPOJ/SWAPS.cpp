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

inline int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

#define MAXVAL 50000
#define MAXN 250000
#define SQMN 500

int a[MAXN], b[MAXN], aux[MAXN];
int bit[SQMN][MAXVAL];

int main( int argc, char* argv[] ){
	
	int N = next_int();
	int sq = int( ceil( sqrt(N) ) );	
	
	int64 inversions = 0;
	
	int ax, wt;
	REP( i, N ) a[i] = next_int();
	
	REP( i, N ){
		b[i] = a[i];
		ax = a[i];
		wt = (i / sq) + 1;
		while( wt <= sq ){
			ax = a[i];
			while( ax <= MAXVAL ){
				bit[wt-1][ax-1]++;
				ax += (ax & -ax);
			}
			wt += (wt & -wt);
		}
	}

	for( int len = 2; len < 2*N; len *= 2 ){
	
		for( int i = 0; i < N; i += len ){
			int from1 = i;
			int to1 = i+len/2;
			int from2 = to1;
			int to2 = min( from2+len/2, N );
			int pos = 0;
			
			while( from1 < to1 && from2 < to2 ){
				if( b[from1] > b[from2] ){
					aux[pos++] = b[from2++];
					inversions += (to1-from1);
				} else {
					aux[pos++] = b[from1++];
				}
			}
			while( from1 < to1 ) aux[pos++] = b[from1++];
			while( from2 < to2 ) aux[pos++] = b[from2++];
			REP( j, len ){ if( i + j >= N ) break; b[i+j] = aux[j]; }
		}
	}
		
	int M = next_int();
	int X, Y, idax, idy;
	int mtree, grtax_bfr, grty_bfr, lssax_aft, lssy_aft;
	
	REP( qry, M ){
		X = next_int(); X--;
		Y = next_int();
		
		mtree = (X/sq) + 1;
		grtax_bfr = 0, grty_bfr = 0, lssax_aft = 0, lssy_aft = 0;
		
		int tr = mtree - 1;
		while( tr > 0 ){

			idax = a[X];
			while( idax > 0 ){
				grtax_bfr += bit[tr-1][idax-1];
				idax -= (idax & -idax);
			}
			
			idy = Y;
			while( idy > 0 ){
				grty_bfr += bit[tr-1][idy-1];
				idy -= (idy & -idy);
			}
			
			tr -= (tr & -tr);
		}

		tr = sq;
		while( tr > 0 ){
			
			idax = a[X]-1;
			while( idax > 0 ){
				lssax_aft += bit[tr-1][idax-1];
				idax -= (idax & -idax);
			}
			
			idy = Y-1;
			while( idy > 0 ){
				lssy_aft += bit[tr-1][idy-1];
				idy -= (idy & -idy);
			}
			
			tr -= (tr & -tr);
		}
		
		tr = mtree;
		while( tr > 0 ){
			
			idax = a[X]-1;
			while( idax > 0 ){
				lssax_aft -= bit[tr-1][idax-1];
				idax -= (idax & -idax);
			}
			
			idy = Y-1;
			while( idy > 0 ){
				lssy_aft -= bit[tr-1][idy-1];
				idy -= (idy & -idy);
			}
			
			tr -= (tr & -tr);
		}
		
		int frm = (mtree-1)*sq;
		int to = min( mtree*sq-1, N-1 );
		
		while( frm < X ){
			if( a[frm] <= a[X] ) grtax_bfr++;
			if( a[frm] <= Y ) grty_bfr++;
			frm++;
		}
		
		frm++;
		while( frm <= to ){
			if( a[frm] < a[X] ) lssax_aft++;
			if( a[frm] < Y ) lssy_aft++;
			frm++;
		}
				
		while( mtree <= sq ){
			
			idax = a[X];
			while( idax <= MAXVAL ){
				bit[mtree-1][idax-1]--;
				idax += (idax&-idax);
			}			
			
			idy = Y;
			while( idy <= MAXVAL ){
				bit[mtree-1][idy-1]++;
				idy += (idy&-idy);
			}
			
			mtree += (mtree & -mtree);
		}
		
		a[X] = Y;
		
		grtax_bfr = X-grtax_bfr;
		grty_bfr = X-grty_bfr;
		
		inversions -= (grtax_bfr+lssax_aft);
		inversions += (grty_bfr+lssy_aft);
		
		printf("%lld\n", inversions );
	}
	
	return 0;
}

























