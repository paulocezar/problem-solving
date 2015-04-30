#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int res[1<<20];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int msk = 1;
    vector<int> quasi;
    
    while (true) {
        int pot = 1;
        int num = 0;
        int ax = msk;
        while (ax) {
            if (ax & 1) num += pot;
            pot *= 10;
            ax >>= 1;
        }
        quasi.push_back(num);
        if (num > n) break;
        msk++;
    }
    
    
    for (int i = 1; i <= n; ++i) {
        res[i] = 2e9;
        for (int j = 0; quasi[j] <= i; ++j) {
            res[i] = min(res[i], 1 + res[i-quasi[j]]);
        }
    }
    
    cout << res[n] << "\n";
    while (n > 0) {
        for (int j = 0; quasi[j] <= n; ++j) {
            if (res[n-quasi[j]] == (res[n]-1)) {
                cout << quasi[j] << " "; 
                n -= quasi[j];
                break;
            }
        }
    }
    
	return 0;
}

















