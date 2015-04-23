#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int element[128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            cin >> element[i];
        }
        sort(element, element + N);
        int res = 1;
        for (int i = 1; i < N; ++i) {
            if ((element[i]-element[i-1]) > K) res++;
        }
        cout << "Case #" << tc << ": " << res << "\n";
    }

	return 0;
}

















