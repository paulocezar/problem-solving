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



int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int K;
	string s;
	
	cin >> K;
	cin >> s;
	
	int cur = 0;
	int64 ans = 0;
	
	int N = SIZE(s);
	
	if( K == 0 ){
		int lo = 0, hi;
		
		while( lo < N && s[lo] == '1' ) lo++;
		
		while( lo < N ){
			hi = lo+1;
			while( (hi < N) && s[hi] == '0' ) hi++;
			
			ans += (int64(hi-lo)*int64(hi-lo+1LL))/2LL;
			lo = hi;
			while( lo < N && s[lo] == '1' ) lo++;
		}
		cout << ans << "\n";
		return 0;
	}
	
	int lo = 0, hi, hi2;
	
	while( lo < N && s[lo]!='1' ) lo++;
	int last = -1;
	
	if( lo < N ){
		hi = lo;
		cur = 1;
		
		while( (hi+1) < N && cur != K ){
			hi++;
			cur += (s[hi]-'0');
		}
		
		if( cur == K ){
			
			while( hi < N ){
				hi2 = hi+1;
				while( hi2 < N && s[hi2]=='0') hi2++;
			
				ans += int64(lo-last)*int64(hi2-hi);
				last = lo; lo++;
			
				while( lo < N && s[lo] == '0' ) lo++;
				hi = hi2;
			}
			
		}
		
	}
	
	cout << ans << "\n";
		
	return 0;
}

























