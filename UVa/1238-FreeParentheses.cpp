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

#define MAXN 33
#define MAXVAL 101

int N, num[MAXN];
char op[MAXN];

int seen[MAXN][MAXN][MAXN*MAXVAL*2], seen_now;
set< int > gen;

void build( int open, int pos, int val ){
	
	int &last_seen = seen[open][pos][val+3001];
	if( last_seen == seen_now ) return;
	last_seen = seen_now;
	
	if( pos == N ){ gen.insert( val ); return; }
	
	int nval = (open&1)?( (op[pos]=='+') ? (val-num[pos]) : (val+num[pos]) )
					   :( (op[pos]=='+') ? (val+num[pos]) : (val-num[pos]) );									
	
	build( open, pos+1, nval );
	if( open ) build( open-1, pos+1, nval );
	if( op[pos] == '-' ) build( open+1, pos+1, nval );	
	
	return;
}

	
int main( int argc, char* argv[] ){
	
	char line[333];
	op[0] = '+';
	
	while( gets(line) != NULL ){
		N = 0;
		int ptr = 0;
		while( line[ptr] != '\0' ){
			if( isdigit( line[ptr] ) ){
				num[N] = 0;
				while( isdigit( line[ptr] ) ){ num[N] = 10*num[N] + (line[ptr]-'0'); ptr++; }
				N++;
			} else if( line[ptr] == '-' || line[ptr] == '+' ){
				op[N] = line[ptr]; ptr++;
			} else ptr++;	
		}
		
		seen_now++;
		gen.clear();
		build(0,1,num[0]);
		printf("%d\n", SIZE(gen) );
	}
	
	return 0;
}












