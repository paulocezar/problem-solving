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
#include <bitset>

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

#define MAXN 2222

string S;

int N, SA[MAXN], LCP[MAXN], rank[MAXN], bucket[CHAR_MAX-CHAR_MIN+1];
char bh[MAXN+1];

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
	for( h = 1; h < N; h *= 2 ){
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
	
	
	LCP[0] = 0;
	for( i = 0, h = 0; i < N; i++ ){
		e = rank[i];
		if( e > 0 ){
			j = SA[e-1];
			while( ((i+h) < N) && ((j+h) < N) && (S[i+h] == S[j+h]) ) h++;
			LCP[e] = h;
			if( h > 0 ) h--;
		}
	}
	
}

int ok( int pos, string& ss ){
	int ssz = SIZE(ss);
	REP( i, ssz ) if( S[pos+i] != ss[i] ) return (ss[i]-S[pos+i]);
	return 0;
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	string sbegin, send;
	cin >> S;
	cin >> sbegin;
	cin >> send;
	N = SIZE(S);
	buildSA();
	
	int lo = 0, hi = N-1;
	
	int goodst = -1;
	
	while( lo <= hi ){
		int mid = (lo+hi)/2;
		int wut = ok( SA[mid], sbegin );
		if( wut == 0 ){
			goodst = mid;
			lo = mid+1;
		} else if( wut > 0 ){
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	
	lo = 0, hi = N-1;
	int gooded = -1;
	
	while( lo <= hi ){
		int mid = (lo+hi)/2;
		int wut = ok( SA[mid], send );
		if( wut == 0 ){
			gooded = mid;
			lo = mid+1;
		} else if( wut > 0 ){
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	//cout << goodst << " " << gooded << endl;
	//cout << SA[goodst] << " " << SA[gooded] << endl;
	
	int begsz = SIZE(sbegin);
	int endsz = SIZE(send);
	
	if( goodst == -1 || gooded == -1 ) cout << "0\n";
	else {
		
		int goodede = gooded;
		while( gooded && LCP[gooded] >= endsz ) gooded--;
		
		int goodste = goodst;
		while( goodst && LCP[goodst] >= begsz ) goodst--;
		
		int ans = 0;
		
		while( goodst <= goodste ){
			
			int beg = SA[goodst];
			
			for( int pos = gooded; pos <= goodede; pos++ ){
				int fnsh = SA[pos]+endsz-1;
				int len = fnsh-beg+1;
				if( (fnsh >= beg) && (LCP[goodst] < len) && (len >= endsz) && (len >= begsz) ) ans++;
			}
						
			goodst++;
		}
		cout << ans << "\n";
				
	}
	
	
		
	
	
	return 0;
}




















