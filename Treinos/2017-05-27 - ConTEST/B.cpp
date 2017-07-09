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
	int t;
	cin >> t;
	int64 n, k;
	for (int i = 1; i <= t; i++){
		cin >> n >> k;
		cout << "Caso " << i << ": " << ((n/(k-1)) + ((n % (k-1)) ? (1) : (0))) << "\n";
	}
	
	return 0;
}
