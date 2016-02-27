#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int prefix[2][1<<17], suffix[2][1<<17];

int N;
string A, B;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	cin >> N;
    	cin >> A;
    	cin >> B;

    	for (int i = 0; i < N; ++i) {
    		bool eq = A[i] == B[i];

    		prefix[0][i] = eq ? 0 : 1;
    		if (i) {
    			prefix[0][i] += (eq ? prefix[0][i-1] : prefix[1][i-1]);
    		}

    		eq = ((i+1) < N) && (B[i] == B[i+1]);
    		prefix[1][i] = eq ? 0 : 1;
    		if (i) {
    			prefix[1][i] += prefix[1][i-1];
    		}
    	}

    	for (int i = N-1; i >= 0; --i) {
    		bool eq = A[i] == B[i];

    		suffix[0][i] = eq ? 0 : 1;
    		if ((i+1) < N) {
    			suffix[0][i] += (eq ? suffix[0][i+1] : suffix[1][i+1]);
    		}

    		eq = i && (B[i] == B[i-1]);
    		suffix[1][i] = eq ? 0 : 1;
    		if ((i+1) < N) {
    			suffix[1][i] += suffix[1][i+1];
    		}
    	}

    	int res = min(suffix[0][0], prefix[0][N-1]);
    	for (int i = 0; i < N-1; ++i) {
    		res = min(res, max(prefix[0][i], suffix[0][i+1]));
    	}

    	cout << "Case #" << tc << ": " << res << "\n";
    }

	return 0;
}
