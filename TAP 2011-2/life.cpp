#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

#define INF 0x3F3F3F3F

int d[1<<20], pop[1<<20], bit[5][5], neg[5][5];
int ds[][2] = { {-1,-1}, {0,-1}, {1,-1}, {-1, 0}, {1,0}, {-1,1}, {0,1}, {1,1}  };
vector< vector< int > > gr;

int main(){
	
	int t, n, m, a, b, c;
	char cell;
	
	pop[0] = 0;
	for( int i = 1; i < 1<<20; i++ ) pop[i] = pop[i>>1]+(i&1);
	
	t = next_int();
	while( t-- ){
		n = next_int();
		m = next_int();
		a = next_int();
		b = next_int();
		c = next_int();
		
		int state = 0; int bbit = 0;
		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < m; j++ ){
				cell = getchar_unlocked(); while( cell != '.' && cell != '*' ) cell = getchar_unlocked();
				if( cell == '*' ) state |= (1<<bbit);
				neg[i][j] = 0;
				bit[i][j] = bbit++;
			}
		}
		
		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < m; j++ ){
				for( int dir = 0; dir < 8; dir++ ){
					int ni = i+ds[dir][0];
					int nj = j+ds[dir][1];
					if( 0 <= ni && ni < n && 0 <= nj && nj < m )
						neg[i][j] |= (1<<bit[ni][nj]);
				}
			}
		}
		
		int lim = 1<<(n*m);
		gr.resize(lim);
		for( int i = 0; i < lim; i++ ) gr[i].clear();
		
		for( int cur = 0; cur < lim; cur++ ){
			int nstate = 0;
			d[cur] = INF;
			
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ){
					
					int alive = pop[ cur & neg[i][j] ];
					
					nstate |= (cur & (1<<bit[i][j]));
					if( cur & (1<<bit[i][j]) ){
						if( alive < a || alive > b ) nstate &= ~(1<<bit[i][j]);
					} else if( alive > c ) nstate |= (1<<bit[i][j]);
					
			}
			
			gr[nstate].push_back( cur );
		}
		
		queue< int > q;
		q.push( state ); d[state] = 0;
		while( !q.empty() ){
			int now = q.front(); q.pop();
			if( gr[now].size() == 0 ){ printf("%d",d[now]);; goto hell; }
			for( size_t i = 0, sz = gr[now].size(); i < sz; i++ ){
				if( d[now]+1 < d[gr[now][i]] ){
					d[gr[now][i]] = d[now]+1;
					q.push( gr[now][i] );
				}
			}
		}
		printf("-1");
hell:
		puts("");
	}

	return 0;
}

