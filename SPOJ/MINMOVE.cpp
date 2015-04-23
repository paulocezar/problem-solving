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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 100002

char S[MAXN];

int main( int argc, char* argv[] ){
	
	
	gets(S);
	int N = strlen(S);
	int mn = 0;					// .. starting index of the best rotation
	int p = 1;					// .. rotations started fom 0 to p-1 already processed
	int l = (S[0] == S[1]);		// .. the first l charactes of the rotation starting at p are equal to the first l 
								//  characters starting at min
	
	while( (p<N) && (mn+l+1 < N) ){
		if( S[mn+l] == S[(p+l)%N] ){
			l++;
		} else if( S[mn+l] < S[(p+l)%N] ){
			p = p+l+1;
			l = 0;
		} else if( S[mn+l] > S[(p+l)%N] ){
			mn = max(mn+l+1,p);
			p = mn+1;
			l = 0;
		}
	}
	printf("%d\n", mn );
	
	return 0;
}

/*
Maybe I'm just stupid, but I found it quite tricky working out why this works.
There are a couple of things that need some non-trivial observations, which are
required to ensure the algorithm is linear and not quadratic.
	p = p+l+1;
How do we know that there is not some smaller rotation starting between p and p+l?
 The answer here is that the strings [min,min+l[ and [p p+l[ are the same.
Therefore, if there were a smaller rotation starting at p+k (k<l), there would
have to also be a smaller string starting at min+k, which we would already have
found (and min would already be equal to min+k). Since this is not the case, we
can skip over all these values.
	min = max(min+l+1, p)
Again, how can we tell that no smaller rotation starts between min and min+l?
 To see this, observe that once the ranges [min,min+l[ and [p,p+l[ overlap, the strings
being processed must be periodic with period p-min. If the periodic section of the string
is P and the last bit we've found which deviates from P is Q (which is lexicographically smaller than P),
then the string we've found looks like
	PPPPPPPPQ
Since P contains no substrings that are lexically smaller than it and Q is lexically less
than P, we can clearly skip all the Ps entirely. In fact, the number of characters skipped
in the algorithm above is slightly conservative (it skips to one full period before the end of the string,
when it could skip to the start of Q). This of course does not affect the time complexity of the algorithm.
*/




















