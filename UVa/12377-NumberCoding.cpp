#include <iostream>
#include <string>
#include <cstring>

typedef unsigned long long int64;
using namespace std;

int64 C[13][13];
int64 f[13];
int64 e[13];

int N, k;
string s;
int64 res;

void solve( int pos, int64 last, int depth ){
	int64 cur = 0ULL;
	
	if( depth==k && pos==N ){
		
		int64 ans = C[9][k] * f[k];
		int repeated = 0;
		for( int cpos = 0; cpos < depth; cpos++ ){
			
			if( cpos == 0 || e[cpos] == e[cpos-1] ) repeated++;
			else {
				ans /= f[repeated];
				repeated = 1;
			}
		}
		ans /= f[repeated];
		
		res += ans;
		return;
	}
	if( depth==k || pos==N ) return;
	
	if( s[pos] == '0' ) return;
	for( int cpos = pos; cpos < N && (N-cpos >= k-depth); cpos++ ){
		
		cur = (10ULL*cur) + int64(s[cpos]-'0');
		if( cur >= last ){
			e[depth] = cur;
			solve( cpos+1, cur, depth+1 );
		}

	}
	
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	
	f[0] = 1ULL;
	C[0][0] = 1ULL; C[0][1] = 0ULL;
	for( int i = 1; i < 11; i++ ){
		C[i][0] = 1ULL;
		f[i] = f[i-1]*int64(i);
		for( int j = 1; j <= i; j++ )
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		C[i][i+1] = 0ULL;
	}

	cin >> t;
	while( t-- ){
		cin >> s;
		N = int(s.size());
		k = (s[0]-'0');
		res = 0ULL;
		solve( 1, 0ULL, 0 );
		cout << res << "\n";
	}

	return 0;
}

