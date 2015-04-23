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


int pr[100000];
int acm[100000];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
    
    string s;
    cin >> s;
    int N = SIZE(s);
    
    stack< int > stk;
	
	REP( i, N ){
		pr[i] = -1;
		acm[i] = i?acm[i-1]:0;
		
		switch( s[i] ){
                
			case '[': 
				stk.push(i);
				acm[i]++;
				break;
			case '(':
				stk.push(i);
				break;
                
			case ')':
				if( stk.empty() || (s[stk.top()] != '(') ){
                    while (!stk.empty()) {
                        stk.pop();
                    }
                } else {
					pr[stk.top()] = i;
					stk.pop();
                }
				break;
			case ']':
				if( stk.empty() || (s[stk.top()] != '[') ){
                    while (!stk.empty()) {
                        stk.pop();
                    }
                } else {
					pr[stk.top()] = i;
					stk.pop();
                }
				break;
		}
	}
	
	int ans = 0;
	int beg, end;
	REP(i,N) if(pr[i] != -1) {
		int nbeg = i;
		int now = acm[pr[i]] - (i?acm[i-1]:0);
		while(pr[i]+1 < N && pr[pr[i]+1] != -1) {
			i = pr[i]+1;
			now += acm[pr[i]] - acm[i-1];
		}
		if( now > ans) {
			ans = now;
			beg = nbeg;
			end = pr[i];
		}
		i = pr[i];
	}
	
    cout << ans << "\n";
	if(ans) { FOR(i,beg,end) cout << s[i]; cout << "\n"; }
	
    
	return 0;
}