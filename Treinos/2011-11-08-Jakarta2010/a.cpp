#include <iostream>
#include <vector>

using namespace std;

#define MAXN 15

int p[1<<MAXN];
int tree[1<<(MAXN+1)];
int ptree[1<<(MAXN+1)];

int main(){
	ios::sync_with_stdio(false);
	
	int t, N, K;
	
	cin >> t;
	while( t-- ){
		cin >> N >> K;
		
		int offset = (1<<N)-1;
		
		for( int i = 0; i < (1<<N); i++ ){
			cin >> p[i];
			tree[offset+i] = i;
			ptree[offset+i] = p[i];
		}
		
		int ls, rs;
		while( offset > 0 ){
			offset--;
			ls = 2*offset+1; rs = ls+1;
			if( ptree[ls] < ptree[rs] ){
				ptree[offset] = min( ptree[rs]-ptree[ls]+K, p[ tree[rs] ] );
				tree[offset] = tree[rs];
			} else {
				ptree[offset] = min( ptree[ls]-ptree[rs]+K, p[ tree[ls] ] );
				tree[offset] = tree[ls];
			}
		}
		cout << tree[0]+1 << "\n";
		
		offset = (1<<N)-1;
		int cur = 0;
		
		vector< int > ans;
		while( cur < offset ){
			ls = 2*cur+1; rs = ls+1;
			if( tree[cur] == tree[ls] ){
				ans.push_back( tree[rs]+1 );
				cur = ls;
			} else {
				ans.push_back( tree[ls]+1 );
				cur = rs;
			}
		}
		
		for( size_t i = ans.size(); i > 0; i-- ){ cout << ans[i-1]; if( i-1 ) cout << " "; else cout << "\n"; }
		
	}
	
	return 0;
}
