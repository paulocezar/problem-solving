#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

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

#define MAXN 100001
#define LOGN  17

struct tnode{
	int pr, sf, sm, mx;
	char temp;
	int ind[4]; /* ind[0] = fim do prefixo, ind[1] = inicio do sufixo, ind[2] = inicio do maximo, ind[3] = fim do maximo */
};

int a[MAXN];
tnode segt[ 1<<(LOGN+1) ];
tnode ans, aux;

void build( int node, int lo, int hi ){
	if( lo == hi ){
		segt[node].pr = a[lo-1];
		segt[node].sf = a[lo-1];
		segt[node].sm = a[lo-1];
		segt[node].mx = a[lo-1];
		segt[node].ind[0] = lo;
		segt[node].ind[1] = lo;
		segt[node].ind[2] = lo;
		segt[node].ind[3] = lo;
	} else {

		int mid = (lo+hi)>>1;
		int lft = 2*node + 1, rgt = 2*node + 2;
		build( lft, lo, mid );
		build( rgt, mid+1, hi );

		segt[node].sm = segt[lft].sm + segt[rgt].sm;

		if( segt[lft].sm + segt[rgt].pr >= segt[lft].pr ){
			segt[node].pr = segt[lft].sm + segt[rgt].pr;
			segt[node].ind[0] = segt[rgt].ind[0];
		} else {
			segt[node].pr = segt[lft].pr;
			segt[node].ind[0] = segt[lft].ind[0];
		}

		if( segt[rgt].sm + segt[lft].sf >= segt[rgt].sf ){
			segt[node].sf = segt[rgt].sm + segt[lft].sf;
			segt[node].ind[1] = segt[lft].ind[1];
		} else {
			segt[node].sf = segt[rgt].sf;
			segt[node].ind[1] = segt[rgt].ind[1];
		}

		if( segt[lft].mx > segt[rgt].mx ){
			segt[node].mx = segt[lft].mx;
			segt[node].ind[2] = segt[lft].ind[2];
			segt[node].ind[3] = segt[lft].ind[3];
		} else if( segt[lft].mx < segt[rgt].mx ){
			segt[node].mx = segt[rgt].mx;
			segt[node].ind[2] = segt[rgt].ind[2];
			segt[node].ind[3] = segt[rgt].ind[3];
		} else {
			if( segt[lft].ind[3]-segt[lft].ind[2] > segt[rgt].ind[3]-segt[rgt].ind[2] ){
				segt[node].mx = segt[lft].mx;
				segt[node].ind[2] = segt[lft].ind[2];
				segt[node].ind[3] = segt[lft].ind[3];
			} else {
				segt[node].mx = segt[rgt].mx;
				segt[node].ind[2] = segt[rgt].ind[2];
				segt[node].ind[3] = segt[rgt].ind[3];
			}
		}
		if( segt[lft].sf+segt[rgt].pr > segt[node].mx ){
			segt[node].mx = segt[lft].sf+segt[rgt].pr;
			segt[node].ind[2] = segt[lft].ind[1];
			segt[node].ind[3] = segt[rgt].ind[0];
		} else if( ( segt[lft].sf+segt[rgt].pr == segt[node].mx ) && ( segt[rgt].ind[0]-segt[lft].ind[1] > segt[node].ind[3]-segt[node].ind[2] ) ){
			segt[node].ind[2] = segt[lft].ind[1];
			segt[node].ind[3] = segt[rgt].ind[0];
		}

	}
	segt[node].temp = 0;
}

int _beg, _end;

tnode get( int node, int lo, int hi ){

	if( _beg > hi || _end < lo ){
         return aux;
     } else if( lo >= _beg && hi <= _end ){
         return segt[node];
     } else {
            tnode q1, q2;
			int mid = (lo+hi)>>1;
            q1 = get( (node<<1) + 1, lo, mid );
            q2 = get( (node<<1) + 2, mid+1, hi );

            if( q1.temp ){
                return q2;
            } else if( q2.temp ){
                return q1;
            } else {
                tnode ans;
                ans.temp = 0;

				ans.sm = q1.sm + q2.sm;

				if( q1.sm + q2.pr >= q1.pr ){
					ans.pr = q1.sm + q2.pr;
					ans.ind[0] = q2.ind[0];
				} else {
					ans.pr = q1.pr;
					ans.ind[0] = q1.ind[0];
				}

				if( q2.sm + q1.sf >= q2.sf ){
					ans.sf = q2.sm + q1.sf;
					ans.ind[1] = q1.ind[1];
				} else {
					ans.sf = q2.sf;
					ans.ind[1] = q2.ind[1];
				}

				if( q1.mx > q2.mx ){
					ans.mx = q1.mx;
					ans.ind[2] = q1.ind[2];
					ans.ind[3] = q1.ind[3];
				} else if( q1.mx < q2.mx ){
					ans.mx = q2.mx;
					ans.ind[2] = q2.ind[2];
					ans.ind[3] = q2.ind[3];
				} else {
					if( q1.ind[3]-q1.ind[2] > q2.ind[3]-q2.ind[2] ){
						ans.mx = q1.mx;
						ans.ind[2] = q1.ind[2];
						ans.ind[3] = q1.ind[3];
					} else {
						ans.mx = q2.mx;
						ans.ind[2] = q2.ind[2];
						ans.ind[3] = q2.ind[3];
					}
				}
				if( q1.sf+q2.pr > ans.mx ){
					ans.mx = q1.sf+q2.pr;
					ans.ind[2] = q1.ind[1];
					ans.ind[3] = q2.ind[0];
				} else if( ( q1.sf+q2.pr == ans.mx ) && ( q2.ind[0]-q1.ind[1] > ans.ind[3]-ans.ind[2] ) ){
					ans.ind[2] = q1.ind[1];
					ans.ind[3] = q2.ind[0];
				}

                return ans;
            }
     }

}

int main(){

	int t, N, Q;

	aux.temp = 1;

	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &N );
		REP( i, N ) scanf("%d", a+i);
		scanf("%d", &Q );
		build( 0, 1, N );
		REP( i, Q ){
			scanf("%d %d", &_beg, &_end);
			//beg--; end--;
			ans = get( 0, 1, N );
			printf("%d %d\n", ans.mx, ans.ind[3]-ans.ind[2]+1 );
		}
	}
    return 0;
}
