#include <cstdio>
#include <cstdlib>

template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

using namespace std;

#define MAXL  401

int ok[MAXL][MAXL];
int scan[MAXL][MAXL];
int L;
double pieces;

double getConf(){
	
	int ct;
	double ans = 0.0;
	
	ct = 0;
	for( int i = 0; i < L; i++ ){
		for( int j = 0; j < L; j++ ){
			if( ABS( scan[i][j] - ok[i][j] ) <= 100 ) ct++;
		}
	}
	ans = MAX( ans, double( 100 * ct ) / pieces );
	
	
	ct = 0;
	for( int i = 0; i < L; i++ ){
		for( int j = 0; j < L; j++ ){
			if( ABS( scan[L-i-1][L-j-1] - ok[i][j] ) <= 100 ) ct++;
		}
	}
	ans = MAX( ans, double( 100 * ct ) / pieces );
	
	
	ct = 0;
	for( int i = 0; i < L; i++ ){
		for( int j = 0; j < L; j++ ){
			if( ABS( scan[j][L-i-1] - ok[i][j] ) <= 100 ) ct++;
		}
	}
	ans = MAX( ans, double( 100 * ct ) / pieces );
	
	
	ct = 0;
	for( int i = 0; i < L; i++ ){
		for( int j = 0; j < L; j++ ){
			if( ABS( scan[L-j-1][i] - ok[i][j] ) <= 100 ) ct++;
		}
	}
	ans = MAX( ans, double( 100 * ct ) / pieces );
	return ans;
}

int main(){
	
	double ans;
	
	scanf("%d", &L );
	while( L ){
		
		pieces = double( L*L );
		
		for( int i = 0; i < L; i++ )
			for( int j = 0; j < L; j++ ) scanf("%d", &ok[i][j] );
		
		for( int i = 0; i < L; i++ )
			for( int j = 0; j < L; j++ ) scanf("%d", &scan[i][j]);
		
		ans = 0.0;
		ans = MAX( ans, getConf() );
		
		for( int i = 0; i < L; i++ )
			for( int j1 = 0, j2 = L-1; j1 < j2; j1++, j2-- ){
				scan[i][j1] ^= scan[i][j2]; scan[i][j2] ^= scan[i][j1]; scan[i][j1] ^= scan[i][j2];
			}
		
		ans = MAX( ans, getConf() );
		
		printf("%.2lf\n", ans );	
	
		scanf("%d", &L );
	}

	return 0;
}
