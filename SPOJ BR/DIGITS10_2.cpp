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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int countDigits( int dig, int x ){
	if( x <= 0 ) return 0;
	int res = 0; char buff[15];
	int i, ct, sz;
	res += x/10 + ((x%10) >= dig);
	if( dig == 0 ) res--;
	res += 10*countDigits(dig,x/10-1);
	if( x < 10 && dig == 0 ) return res;
	sprintf(buff,"%d", x/10);
	for( i = 0, ct = 0, sz = strlen(buff); i < sz; i++)
		if( buff[i] == dig+'0') ct++;
	res += (1 + (x%10))*ct;
	return res;
}

int main( int argc, char* argv[] ){
	
	int a, b;
	int digitsA, digitsB;
    int i;
	
	while(true){
		scanf("%d %d", &a, &b);
		if(a + b == 0) break;
		
		digitsA = countDigits(0, a-1);
		digitsB = countDigits(0, b);
		printf("%d", digitsB - digitsA);
		for(i = 1; i < 10; i++){
			digitsA = countDigits(i, a-1);
			digitsB = countDigits(i, b);
			printf(" %d", digitsB - digitsA);
		}
		printf("\n");
	}
	
	return 0;
}






















