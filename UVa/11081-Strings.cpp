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

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 10007;

char s1[66], s2[66], s3[66];
int len1, len2, len3;

int dp1[66][66][66], dp2[66][66][66];

int calc1[66][66][66], calc1_now;
int calc2[66][66][66], calc2_now;

int solve(int,int,int);
int solve1(int,int,int);
int solve2(int,int,int);

int solve1( int p1, int p2, int p3 ){
	if( p1 == len1 ) return 0;
	
	int &res = dp1[p1][p2][p3];
	
	if( calc1[p1][p2][p3] == calc1_now ) return res;
	calc1[p1][p2][p3] = calc1_now;
	
	res = solve1(p1+1,p2,p3);
	if( s1[p1] == s3[p3] ) res = (res+solve(p1+1,p2,p3+1))%MOD;
	
	return res;
}

int solve2( int p1, int p2, int p3 ){
	if( p2 == len2 ) return 0;
	
	int &res = dp2[p1][p2][p3];
	
	if( calc2[p1][p2][p3] == calc2_now ) return res;
	calc2[p1][p2][p3] = calc2_now;
	
	res = solve2(p1,p2+1,p3);
	if( s2[p2] == s3[p3] ) res = (res+solve(p1,p2+1,p3+1))%MOD;
	
	return res;
}

int solve( int p1, int p2, int p3 ){
	if( p3 == len3 ) return 1;
	return ((solve1(p1,p2,p3) + solve2(p1,p2,p3))%MOD);
}

int main( int argc, char* argv[] ){
	
	
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%s%s%s", s1,s2,s3);
		len1 = strlen(s1);
		len2 = strlen(s2);
		len3 = strlen(s3);
		calc1_now++;
		calc2_now++;			
		printf("%d\n", solve(0,0,0) );
	}
	
	return 0;
}

























