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

#define MAXN 91

inline int next_int() {
	int res = 0;
	char c = getchar_unlocked();	
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = (res * 10) + (c - '0');
		c = getchar_unlocked();
	}
	return res;
}

int64 mod;

int ds[][2] = { {0,-1}, {0,+1}, {-1,-1}, {+1,+1}, {-1,0}, {+1,0} };

int id[30][30], valid[30][30], validnow;
int64 base[MAXN], aux[MAXN][MAXN], pot[MAXN][MAXN], ans[MAXN][MAXN];
int DIM;

void mult( int64 a[][MAXN], int64 b[][MAXN] ){
	REP( i, DIM ) REP( j, DIM ){
		aux[i][j] = 0;
		REP( k, DIM ){
			aux[i][j] += (a[i][k]*b[k][j])%mod;
			aux[i][j] %= mod;
		}
	}
	REP( i, DIM ) REP( j, DIM )
		a[i][j] = aux[i][j];
}

int main( int argc, char* argv[] ){
	
	
	int N, MM;
	N = next_int();
	mod = next_int();
	MM = next_int();
	int tc = 1;
	
	while( N || mod || MM ){		
		validnow++;
		
		DIM = 0;
		REP( i, N ){
			REP( j, N+i ){
				valid[i][j] = validnow;
				base[DIM] = next_int();
				id[i][j] = DIM++;
			}
		}
		
		int L = N-1;
		int C = 0;
		RREP( i, N-1 ){
			L++;
			int curc = ++C;
			REP( j, N+i ){
				valid[L][curc] = validnow;
				base[DIM] = next_int();
				id[L][curc] = DIM++;
				curc++;
			}
		}
		
		REP( i, DIM ) REP( j, DIM ){
			ans[i][j] = (i==j);
			pot[i][j] = (i==j);
		}
		
		REP( i, N ){
			REP( j, N+i ){
				REP( k, 6 ){
					int ni = i+ds[k][0];
					int nj = j+ds[k][1];
					if( ni >= 0 && nj >= 0 && valid[ni][nj] == validnow ){
						pot[ id[i][j] ][ id[ni][nj] ] = 1;
					}
				}
			}
		}
		
		L = N-1;
		C = 0;
		RREP( i, N-1 ){
			L++;
			int curc = ++C;
			REP( j, N+i ){
				REP( k, 6 ){
					int ni = L+ds[k][0];
					int nj = curc+ds[k][1];
					if( ni >= 0 && nj >= 0 && valid[ni][nj] == validnow ){
						pot[ id[L][curc] ][ id[ni][nj] ] = 1;
					}
				}
				curc++;
			}
		}
		
		//REP( i, DIM ) REP( j, DIM ) if( pot[i][j] )
		//	cout << i << " .. " << j << endl;
		
		while( MM ){
			if( MM&1 ){
				REP( i, DIM ) REP( j, DIM ){
					aux[i][j] = 0;
					REP( k, DIM ){
						aux[i][j] += (ans[i][k]*pot[k][j])%mod;
						aux[i][j] %= mod;
					}
				}
				REP( i, DIM ) REP( j, DIM )
					ans[i][j] = aux[i][j];
			}
			//mult( ans, pot );
			//mult( pot, pot );
			
			REP( i, DIM ) REP( j, DIM ){
				aux[i][j] = 0;
				REP( k, DIM ){
					aux[i][j] += (pot[i][k]*pot[k][j])%mod;
					aux[i][j] %= mod;
				}
			}
			REP( i, DIM ) REP( j, DIM )
				pot[i][j] = aux[i][j];
			
			MM >>= 1;
		}
		
		int64 res = 0;
		REP( i, DIM ){
			int64 temp = 0;
			REP( j, DIM ){
				temp += (ans[i][j]*base[j])%mod;
				temp %= mod;
			}
			res += temp;
		}
		printf("Case %d: %lld\n", tc++, res );
		
		N = next_int();
		mod = next_int();
		MM = next_int();
	}
	
	return 0;
}

























