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

int64 dcount( int x, int dig ){
	if( x <= 0 ) return 0;
	int64 res = 0; char buff[15];
	int i, ct, sz;
	res += x/10 + ((x%10) >= dig);
	if( dig == 0 ) res--;
	res += 10*dcount(x/10-1,dig);
	sprintf(buff,"%d", x/10);
	for( i = 0, ct = 0, sz = strlen(buff); i < sz; i++)
		if( buff[i] == dig+'0') ct++;
	res += (1 + (x%10))*ct;
	return res;
}

int64 countDigits( int digit, int num ){
	int64 count = 0;
	int64 pot = 1;
	int64 numDigit;
	
	if( digit == 0 ){
		while(num > pot){
			numDigit = (num/pot)%10;
			if(numDigit == digit) count += (num/(pot*10) - 1)*pot + num%pot + 1;
			else count += num/(pot*10)*pot;
			pot *= 10;
		}
	} else while(num >= pot){
		numDigit = (num/pot)%10;
		if(numDigit == digit) count += (num/(pot*10))*pot + num%pot + 1;
		else if(numDigit < digit) count += (num/(pot*10))*pot;
		else count += (num/(pot*10) + 1)*pot;
        pot *= 10;
	}
	return count;
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int64 a, b, ans;
	cin >> a >> b;
	while( a != -1 || b != -1 ){
		ans = 0;
		FOR( i, 1, 9 ) ans += i*(countDigits(i,b)-countDigits(i,a-1));
		cout << ans << "\n";
		cin >> a >> b;
	}
	return 0;
}




















