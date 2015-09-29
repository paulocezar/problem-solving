#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int s[5];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
   	map<int64, vector<vector<int>>> results;

	for (int i = 0; i < 1024; ++i) {
		if (__builtin_popcount(i) == 5) {
			vector<int> candidate;
			for (int bit = 0; bit < 10; ++bit) {
				if (i & (1<<bit)) candidate.push_back(bit);
			}

			int64 sum = 0;
			do {

				int val = 0;
				for (auto &dig : candidate) {
					val = 10*val + dig;
				}
				sum += val;

			} while (next_permutation(candidate.begin(), candidate.end()));
			sort(candidate.begin(), candidate.end());
			results[sum].push_back(candidate);
		}
	}

	for (auto &x : results) sort(x.second.begin(), x.second.end());

    int t;
    cin >> t;
    while (t--) {
    	int64 K; cin >> K;

    	if (results.count(K)) {
    		for (vector<int> &result : results[K]) {
    			char p = '{';
    			for (int &val : result) {
    				cout << p << val;
    				p = ',';
    			}
    			cout << "}\n";
    		}
    	} else cout << "impossivel\n";

    	cout << "\n";
    }


	return 0;
}

















