#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#define INF 0x3f3f3f3f;

using namespace std;

int n, t, m;

string names[110];

int times[110];
int dp[110];
int to[110];

int solve(int x){
	if(x == n) return 0;
	if(dp[x] != -1) return dp[x];
	
	int maxi = 0;
	int best = INF;
	for(int i = 0; i < m && x+i < n; i++){
		maxi = max(maxi, times[x+i]);
		int res = maxi + solve(x+i+1);
		if(best > res){
			to[x] = x+i;
			best = res;
		}
	}	
	return dp[x] = best;
}

void construct(int x){
	bool first = true;
	int lim = to[x];
	while(x < n){
		if(first) first = false;
		else cout << " ";
		cout << names[x];
		if(x == lim){
			lim = to[x+1];
			first = true;
			cout << "\n";
		}
		x++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	
	while(t--){
		cin >> m >> n;
		for(int i = 0; i < n; i++){
			cin >> names[i] >> times[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << "Total Time: " << solve(0) << "\n"; 
		construct(0);	
	}	
	return 0;
}
