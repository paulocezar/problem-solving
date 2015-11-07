#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

pair<int,int> a[101101];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			cin >> a[i].second >> a[i].first;
		}
		sort(a, a+N);

		int last = a[0].first;
		int res = 1;
		for (int i = 1; i < N; ++i) {
			if (a[i].second >= last) {
				res++;
				last = a[i].first;
			}
		}

		cout << res << "\n";
	}    

	return 0;
}

















