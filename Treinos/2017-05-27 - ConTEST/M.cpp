#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	
	int t, n, val;
	cin >> t;
	
	for(int k = 1; k <= t; k++){
		cin >> n;
		map < int, int > mapa;
		for(int i = 0; i < n; i++){
			cin >> val;
			mapa[val]++;
		}
		cout << "Caso " << k << ": " << mapa.size() << "\n";
	}
	
	return 0;
}
