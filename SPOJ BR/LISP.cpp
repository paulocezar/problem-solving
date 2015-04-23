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

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char dig[300];
void init();
string phone, wrd;
map< string, vector<string> > dict;

string tophone( string& s ){
	string ans = "";
	REP( i, SIZE(s) ) if( ( 'a' <= s[i] && s[i] <= 'z' ) || ( 'A' <= s[i] && s[i] <= 'Z' ) ) ans += dig[ s[i] ];
	return ans;
}

vector< string > ans;
void build( string sofar, int pos, bool usnum ){
	//cout << sofar << " " << pos << endl;
	if( pos == SIZE(wrd) ){
		ans.PB( sofar );
		return;
	}
	string now = "";
	bool fl = true;
	int mm = pos;
	while( pos < SIZE(wrd) ){
		now += wrd[pos];
		REP( i, SIZE(dict[ now ]) ){
			fl = false;
			build( sofar + " " + dict[now][i], pos+1, false );
		}
		pos++;
	}
	if( fl && !usnum ) build( sofar + " " + wrd[mm], mm+1, true );
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	init();
	
	int n, t, tc = 1;
	
	while( cin >> n && n ){
		
		dict.clear();
		REP( i, n ){
			cin >> wrd;
			dict[ tophone(wrd) ].PB( wrd );
		}
		
		cin >> t;
		cout << "Instancia " << tc++ << "\n";
		while( t-- ){
			cin >> phone;
			wrd = "";
			ans.clear();
			REP( i, SIZE(phone) ) if( '0' <= phone[i] && phone[i] <= '9' ) wrd += phone[i];
			build( "", 0, false );
			sort( ALL(ans) );
			REP( i, SIZE(ans) ) cout << phone << ":" << ans[i] << "\n";
		}
		cout << "\n";
		
	}
	
	return 0;
}

void init(){
dig['E'] = dig['e'] = '0';
dig['J'] = dig['N'] = dig['Q'] = dig['j'] = dig['n'] = dig['q'] = '1';
dig['R'] = dig['W'] = dig['X'] = dig['r'] = dig['w'] = dig['x'] = '2';
dig['D'] = dig['S'] = dig['Y'] = dig['d'] = dig['s'] = dig['y'] = '3';
dig['F'] = dig['T'] = dig['f'] = dig['t'] = '4';
dig['A'] = dig['M'] = dig['a'] = dig['m'] = '5';
dig['C'] = dig['I'] = dig['V'] = dig['c'] = dig['i'] = dig['v'] = '6';
dig['B'] = dig['K'] = dig['U'] = dig['b'] = dig['k'] = dig['u'] = '7';
dig['L'] = dig['O'] = dig['P'] = dig['l'] = dig['o'] = dig['p'] = '8';
dig['G'] = dig['H'] = dig['Z'] = dig['g'] = dig['h'] = dig['z'] = '9';
}



















