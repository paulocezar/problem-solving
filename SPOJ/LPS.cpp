#include <vector> 
#include <string> 
#include <cstdio>
#include <cstdlib> 
#include <cstring> 
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100100

int ans[2*MAXN+1];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int k;
	string ss;
	
	cin >> k;
	cin >> ss;
	
	string s = "#";
	for( size_t i = 0, sz = ss.size(); i < sz; i++ ){
		s += ss[i];
		s += "#";
	}
	
	int n = int( s.size() );
	for( int i = 0; i < n; i++ ) ans[i] = 0;
	
	int cur = 1;
	while( cur < n ){
		
		while( (cur > ans[cur])
			&& (cur+ans[cur]+1 < n)
			&& (s[cur-ans[cur]-1] == s[cur+ans[cur]+1]) ) ans[cur]++;
		
		int j = 1;
		while( (cur+j < n) && (j < ans[cur]-ans[cur-j]) ){
			ans[cur+j] = ans[cur-j];
			j++;
		}
		
		if( cur+j < n )
			ans[cur+j] = ans[cur]-j;
		cur += j;
	}
	
	int res = 0;
	for( int i = 0; i < n; i++ ) res = max( res, ans[i] );
	cout << res << "\n";
	
	return 0;
}




















