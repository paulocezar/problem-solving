#include <vector> 
#include <string> 
#include <cstdio>
#include <cstdlib> 
#include <cstring> 
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100000

int ans[MAXN+1];
char s[MAXN+1];

int main( int argc, char* argv[] ){
	
	int t;
	scanf("%d", &t); getchar();
	while( t-- ){
		
		gets(s);
		
		int n = 1;
		for( int i = 1; s[i]; i++ ) if( s[i] != s[i-1] )
			s[n++] = s[i];
		
		for( int i = 0; i < n; i++ ) ans[i] = 1;

		int cur = 1;
		int res = 1;
		while( cur < n ){
	
			while( cur >= ans[cur]
					&& cur+ans[cur] < n
					&& s[cur-ans[cur]]==s[cur+ans[cur]] ) ans[cur]++;
			
			res = max( res, ans[cur] );
			int j = 1;
			
			while( (cur+j < n) && (j < ans[cur]-ans[cur-j]) ){
				ans[cur+j] = ans[cur-j];
				j++;
			}
			if( cur+j < n )
				ans[cur+j] = ans[cur]-j;
			cur += j;		
		}
		
		printf("%d\n", res );
	}
	return 0;
}




















