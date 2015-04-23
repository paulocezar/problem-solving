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

#define MAXN 100001
string S, b_word;

int N, SA[MAXN], LCP[MAXN], rank[MAXN], bucket[CHAR_MAX-CHAR_MIN+1];
char bh[MAXN+1];

int segt[2][1<<18];

void build(int node, int lo, int hi){
	if( lo == hi ){
		segt[0][node] = SA[lo];
		segt[1][node] = SA[lo];
	} else {
		int ls = 2*node+1;
		int rs = ls+1;
		int mid = (lo+hi)/2;
		build( ls, lo, mid );
		build( rs, mid+1, hi );
		segt[0][node] = min(segt[0][ls],segt[0][rs]);
		segt[1][node] = max(segt[1][ls],segt[1][rs]);
	}
}

int rmbeg, rmend;
int getmin(int node, int lo, int hi){
	if( rmbeg <= lo && hi <= rmend ) return segt[0][node];
	else {
		int ls = 2*node+1;
		int rs = ls+1;
		int mid = (lo+hi)/2;
		if( mid+1 > rmend ) return getmin(ls,lo,mid);
		if( mid < rmbeg ) return getmin(rs,mid+1,hi);
		return min( getmin(ls,lo,mid), getmin(rs,mid+1,hi) ); 
	}
}

int getmax(int node, int lo, int hi){
	if( rmbeg <= lo && hi <= rmend ) return segt[1][node];
	else {
		int ls = 2*node+1;
		int rs = ls+1;
		int mid = (lo+hi)/2;
		if( mid+1 > rmend ) return getmax(ls,lo,mid);
		if( mid < rmbeg ) return getmax(rs,mid+1,hi);
		return max( getmax(ls,lo,mid), getmax(rs,mid+1,hi) ); 
	}
}

void buildSA(){
	
	int a, c, d, e, f, h, i, j, x;
	int *cnt = LCP;
	memset( bucket, -1, sizeof(bucket) ); 
	for( i = 0; i < N; i++ ){
		j = S[i] - CHAR_MIN;
		rank[i] = bucket[j];
		bucket[j] = i;
	}
	for( a = c = 0; a <= CHAR_MAX-CHAR_MIN; a++ ){
		for( i = bucket[a]; i != -1; i=j ){
			j = rank[i]; rank[i] = c;
			bh[c++] = (i==bucket[a]);
		}
	}
	bh[N] = 1;
	for( i = 0; i < N; i++ )
		SA[ rank[i] ] = i;
	x = 0;
	int limt = min(N, 1001);
	for( h = 1; h < limt; h *= 2 ){
		for( i = 0; i < N; i++ ){
			if( bh[i] & 1 ){
				x = i;
				cnt[x] = 0;
			}
			rank[ SA[i] ] = x;
		}
		d = N-h; e = rank[d];
		rank[d] = e + cnt[e]++;
		bh[rank[d]] |= 2;
		
		i = 0;
		while( i < N ){
			for( j = i; (j == i || !(bh[j] & 1)) && j < N; j++ ){
				d = SA[j]-h;
				if( d >= 0 ){
					e = rank[d]; rank[d] = e + cnt[e]++; bh[rank[d]] |= 2;
				}
			}
			for( j = i; (j == i || !(bh[j] & 1)) && j < N; j++ ){
				d = SA[j]-h;
				if( d >= 0 && (bh[rank[d]] & 2)){
					for( e = rank[d]+1; bh[e] == 2; e++);
					for( f = rank[d]+1; f < e; f++ ) bh[f] &= 1;
				}
			}
			i = j;
		}
		for( i = 0; i < N; i++ ){
			SA[rank[i]] = i;
			if( bh[i] == 2 ) bh[i] = 3;	
		}
	}	
}

int comp( int from, int to, int where ){
	int nx = to-from+1;
	int ns = N-SA[where];
	int lim = min(nx,ns);
	REP( i, lim ){
		if( b_word[from] != S[SA[where]+i] ) return (b_word[from]-S[SA[where]+i]);
		from++;
	}
	return (ns >= nx)?(0):(1);
}

int thereis( int from, int to, bool min_indx = true ){	
	
	//FOR( j, from, to ) cout << b_word[j]; cout << " ";
	
	int lo = 0, hi = N-1;
	
	int ans = -1;
	while( lo <= hi ){
		int mid = (lo+hi)/2;
		int res = comp(from,to,mid);
		if( res == 0 ){ ans = mid; hi = mid-1; }
		else if( res > 0 ) lo = mid+1;
		else hi = mid-1;
	}
	if( ans == -1 ) return (min_indx?(INF):(-1));
	rmbeg = ans;
	
	lo = 0, hi = N-1;
	ans = -1;
	while( lo <= hi ){
		int mid = (lo+hi)/2;
		int res = comp(from,to,mid);
		if( res == 0 ){ ans = mid; lo = mid+1; }
		else if( res > 0 ) lo = mid+1;
		else hi = mid-1;
		
	}
	if( ans == -1 ) return (min_indx?(INF):(-1));
	
	rmend = ans;
	
	//FOR( j, rmbeg, rmend ) cout << SA[j] << " "; cout << endl;
	
	
	if( min_indx ) return getmin(0,0,N-1);
	else return getmax(0,0,N-1);
	
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> S;
	N = SIZE(S); buildSA();
	build(0,0,N-1);
	
	int M;
	cin >> M;
	int ans = 0;
	REP( i, M ){
		cin >> b_word;
		int nn = SIZE(b_word);
		REP( j, nn-1 ){
			int fst = thereis(0,j);
			int scn = thereis(j+1, nn-1,false);
			//cout << ' ' << fst << " " << scn << endl;
			
			if( fst+j < scn ){ ans++; break; }
		}
	}
	cout << ans << "\n";
	
	return 0;
}




















