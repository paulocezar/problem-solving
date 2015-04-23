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

const unsigned MAX = 1001000/60, MAX_S = sqrt(MAX/60);

unsigned w[16] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
unsigned short composite[MAX];
vector<int64> primes;

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

int fstpow( int64 a, int b ){
	int res = 1; a %= 10;
	while( b ){
		if( b&1 ){ res*=a; res %= 10; }
		a *= a; a %= 10;
		b >>= 1;
	}
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	sieve();
	int64 N;
	
	while( cin >> N && N ){
	
		int i = 0;
		int ans = 1;
		int twos = 0, fives = 0;
		
		while( primes[i] <= N ){
			
			int64 pot = primes[i];
			int xp = 0;
			
			while( pot <= N ){
				xp++;
				pot *= primes[i];
			}
			
			if( primes[i] == 2 ) twos = xp;
			else if( primes[i] == 5 ) fives = xp;
			else { ans *= fstpow(primes[i],xp); ans %= 10; }
			
			i++;
		}
		
		i = min( twos, fives );
		twos -= i;
		fives -= i;
		ans *= fstpow(2,twos); ans %= 10;
		ans *= fstpow(5,fives); ans %= 10;
		cout << ans << "\n";
	}
	
	return 0;
}

























