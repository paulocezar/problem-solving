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

const unsigned MAX = 20010000/60, MAX_S = sqrt(MAX/60);

unsigned w[16] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
unsigned short composite[MAX];
vector<int> primes;

void sieve() {
   unsigned mod[16][16], di[16][16], num;
   for(int i = 0; i < 16; i++)
       for(int j = 0; j < 16; j++) {
           di[i][j] = (w[i]*w[j])/60;
           mod[i][j] = lower_bound(w, w + 16, (w[i]*w[j])%60) - w;
       }

   primes.push_back(2); primes.push_back(3); primes.push_back(5);

   for(unsigned i = 0; i < MAX; i++)
       for(int j = (i==0); j < 16; j++) {
           if(composite[i] & (1<<j)) continue;
           primes.push_back(num = 60*i + w[j]);

           if(i > MAX_S) continue;
           for(unsigned k = i, done = false; !done; k++)
               for(int l = (k==0); l < 16 && !done; l++) {
                   unsigned mult = k*num + i*w[l] + di[j][l];
                   if(mult >= MAX) done = true;
                   else composite[mult] |= 1<<mod[j][l];
               }
       }
}

int fpow( int b, int e ){
	int ans = 1;
	b %= 10;
	while( e > 0 ){
		if( e&1 ){ ans *= b; ans %= 10; }
		b *= b; b %= 10;
		e >>= 1;
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio(false);
	
	primes.clear();
	sieve();
	
	int n, m;
	while( cin >> n >> m ){
		
		int ans = 1;
		int twos = 0, fives = 0;
		
		for( int i = 0; primes[i] <= n; i++ ){
			
			int cur = 0;
			
			int now = n;
			while( now ){ now /= primes[i]; cur += now; }
			
			now = n-m;
			while( now ){ now /= primes[i]; cur -= now; }
			
			//cout << primes[i] << "^" << cur << "\n";
			
			if( primes[i] == 2 ) twos = cur;
			else if( primes[i] == 5 ) fives = cur;			
			else if( cur ){
				ans *= fpow(primes[i], cur); ans %= 10;
			}
		}
		
		if( fives > twos ){
			fives -= twos;
			ans *= fpow(5,fives); ans %= 10;
		} else {
			twos -= fives;
			ans *= fpow(2,twos); ans %= 10;
		}
		
		cout << ans << "\n";
		
	}
	
		
	return 0;
}

























