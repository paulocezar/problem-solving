/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

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
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

char stk[55];

int main( int argc, char* argv[] ){

	int t;
	char c;
	int top;
	
	scanf("%d", &t ); getchar(); getchar();
	while( t-- ){
		
		top = 0;
		string s = "";
		
		c = getchar();
		while( c != '\n' ){
			getchar();
			switch( c ){
				case '(':
					stk[top++] = c;
					break;
				case ')':
					while( top && stk[top-1] != '(' ){
						s += stk[--top];
					}
					if( top ) top--;
					break;
				case '+':
				case '-':
					while( top && stk[top-1] != '(' ){
						s += stk[--top];
					}
					stk[top++] = c;
				break;
				case '*':
				case '/':
					while( top && ( stk[top-1] == '*' || stk[top-1] == '/' )  ){
						s += stk[--top];
					}
					stk[top++] = c;
					break;
				default: s += c;				
			}
			if( (c = getchar()) == EOF ) break;
		}
		while( top ) s += stk[--top];
		printf("%s\n", s.c_str() );
		if( t ) puts("");
	}
	
	return 0;
}


































