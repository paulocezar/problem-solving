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

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int val[256];

const int DIG = 4;
const int BASE = 10000;
const int TAM = 2048;

struct bigint {
	int v[TAM], n;
	bigint(int x = 0): n(1) {
		FILL( v, 0 );
		v[n++] = x; fix();
	}
	bigint(char *s): n(1) {
		FILL( v, 0 );
		int sign = 1;
		while (*s && !isdigit(*s)) if (*s++ == '-') sign *= -1;
		char *t = strdup(s), *p = t + strlen(t);
		while (p > t) {
			*p = 0; p = max(t, p - DIG);
			sscanf(p, "%d", &v[n]);
			v[n++] *= sign;
		}
		free(t); fix();
	}
	bigint& fix(int m = 0) {
		n = max(m, n);
		int sign = 0;
		for (int i = 1, e = 0; (i <= n) || ( e && (n = i) ); i++) {
			v[i] += e; e = v[i] / BASE; v[i] %= BASE;
			if (v[i]) sign = (v[i] > 0) ? 1 : -1;
		}
		for (int i = n - 1; i > 0; i--)
			if (v[i] * sign < 0) { v[i] += sign * BASE; v[i+1] -= sign; }
		while (n && !v[n]) n--;
		return *this;
	}
	
	bigint& operator +=(const bigint& x) {
		for (int i = 1; i <= x.n; i++) v[i] += x.v[i];
		return fix(x.n);
	}
	bigint operator +(const bigint& x) { return bigint(*this) += x; }
	void ams(const bigint& x, int m, int b) {
		for (int i = 1, e = 0; (i <= x.n || e) && (n = i + b); i++) {
			v[i+b] += x.v[i] * m + e; e = v[i+b] / BASE; v[i+b] %= BASE;
		}
	}
	bigint operator *(const bigint& x) const {
		bigint r;
		for (int i = 1; i <= n; i++) r.ams(x, v[i], i-1);
		return r;
	}
	bigint& operator *=(const bigint& x) { return *this = *this * x; }
	operator string() const {
		ostringstream s; s << v[n];
		for (int i = n - 1; i > 0; i--) {
			s.width(DIG); s.fill('0'); s << abs(v[i]);
		}
		return s.str();
	}
	friend ostream& operator <<(ostream& o, const bigint& x) {
		return o << (string) x;
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	bool first = true;
	string line = "\n";
	while( line == "\n" ) getline(cin,line);
	
	while( true ){
		
		if( first ) first = false;
		else cout << "\n";
		
		int dig = 0;
		
		REP( i, SIZE(line) ) if( line[i] != 0x20 ){
			val[(int)line[i]] = dig++;
		}
		
		getline( cin, line );
		
		while( line[0] && line != "\n" ){
			
			vector<int> digs;
			REP( i, SIZE(line) ) if( line[i] > 0x20 )
				digs.pb( val[(int)line[i]] );
			
			bigint ans = bigint(0);
			FOR( base, 2, dig+1 ){
				bigint cur = bigint(0); bigint pot = bigint(1);
				RREP( i, SIZE(digs) ) if( digs[i] >= base ){ cur = bigint(0); break; }
				else{ cur += pot*digs[i]; pot *= base;  }
				ans += cur;
			}
			cout << ans << "\n";
			
			if( !getline(cin, line) ) return 0;
		}
		
		
		while( !line[0] || line == "\n" ){
			if( !getline(cin,line) ) return 0;
		}
	}
	
	return 0;
}




















