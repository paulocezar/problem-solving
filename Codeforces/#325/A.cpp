#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			res++;
		} else if (res) {
			int j = i;
			while ((j < n) && !a[j]) j++;
			if (((j-i) < 2) && (j != n)) res++;
			i = j-1;
		}
	}
	cout << res << "\n";

	

	return 0;
}
