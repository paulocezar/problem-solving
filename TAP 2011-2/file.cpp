#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <tr1/unordered_set>

#define MAXN 606060

using namespace std;

char S[MAXN];

int N, SA[MAXN], LCP[MAXN], rank[MAXN], bucket[CHAR_MAX-CHAR_MIN+1];
char bh[MAXN+1];

int who[MAXN], len[MAXN];

void buildSA(){
	
	int a, c, d, e, f, h, i, j, x;
	int *cnt = LCP;
	memset( bucket, -1, sizeof(bucket) ); 
	for( i = 0; i < N; i++ ){
		j = S[i] - CHAR_MIN;
		rank[i] = bucket[j];
		bucket[j] = i;
	}
	for( a = c = 0; a <= CHAR_MAX-CHAR_MIN; a++ ){
		for( i = bucket[a]; i != -1; i=j ){
			j = rank[i]; rank[i] = c;
			bh[c++] = (i==bucket[a]);
		}
	}
	bh[N] = 1;
	for( i = 0; i < N; i++ )
		SA[ rank[i] ] = i;
	x = 0;
	for( h = 1; h < N; h *= 2 ){
		for( i = 0; i < N; i++ ){
			if( bh[i] & 1 ){
				x = i;
				cnt[x] = 0;
			}
			rank[ SA[i] ] = x;
		}
		d = N-h; e = rank[d];
		rank[d] = e + cnt[e]++;
		bh[rank[d]] |= 2;
		
		i = 0;
		while( i < N ){
			for( j = i; (j == i || !(bh[j] & 1)) && j < N; j++ ){
				d = SA[j]-h;
				if( d >= 0 ){
					e = rank[d]; rank[d] = e + cnt[e]++; bh[rank[d]] |= 2;
				}
			}
			for( j = i; (j == i || !(bh[j] & 1)) && j < N; j++ ){
				d = SA[j]-h;
				if( d >= 0 && (bh[rank[d]] & 2)){
					for( e = rank[d]+1; bh[e] == 2; e++);
					for( f = rank[d]+1; f < e; f++ ) bh[f] &= 1;
				}
			}
			i = j;
		}
		for( i = 0; i < N; i++ ){
			SA[rank[i]] = i;
			if( bh[i] == 2 ) bh[i] = 3;	
		}
	}
	
	
	LCP[0] = 0;
	for( i = 0, h = 0; i < N; i++ ){
		e = rank[i];
		if( e > 0 ){
			j = SA[e-1];
			while( ((i+h) < N) && ((j+h) < N) && (S[i+h] == S[j+h]) ) h++;
			LCP[e] = h;
			if( h > 0 ) h--;
		}
	}

}

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


char ss[10100];

int main(){
	//ios::sync_with_stdio(false);
	int n, ssz;
play:	
	n = next_int();
	if( n ){
		N = 0;
		
		for( int i = 0; i < n; i++ ){
			ssz = 0;
			ss[ssz] = getchar_unlocked();
			while( ss[ssz] != '\n' ) ss[++ssz] = getchar_unlocked();
			
			for( int j = 0; j < ssz; j++ ){
				S[N] = ss[j];
				who[N] = i;
				len[N] = ssz-j;
				N++;
			}
			
			S[N] = char('z'+(i+1));
			who[N] = -1;
			N++;
		}
		
		buildSA();
		LCP[N] = 0;
		tr1::unordered_set< long long > ans;
		
		for( int i = 0; i < N; i++ ) if( who[ SA[i] ] != -1 ){
			
			ssz = len[ SA[i] ];
			
			long long now = ( 1LL << who[ SA[i] ] );
			//cout << i << " put " << who[ SA[i] ] << "\n";
			
			int j = i+1;
			while( ssz > LCP[i] ){
						
				while( j < N && LCP[j] >= ssz ){
					now |= ( 1LL << who[ SA[j] ] );
					//cout << "add " << " " << who[ SA[j] ] << "\n";
					j++;
				}
				
				//cout << "group.." << endl;
				ans.insert( now );
				
				ssz = LCP[j];
			}
				
		}
		
		printf("%lld\n", (long long)ans.size() );
		goto play;
	}
	return 0;
}