#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXP 10000001

int primacity[MAXP];
vector<int> has_primacity[10];

void sieve() {
    for (int i = 0; i < MAXP; ++i) primacity[i] = 0;
    for (int i = 2; i < MAXP; ++i) {
        if (!primacity[i]) {
            for (int j = i; j < MAXP; j+=i) primacity[j]++;
        }
        has_primacity[primacity[i]].push_back(i);
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    sieve();
    
    int T, A, B, K;
    
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> A >> B >> K;
        
        int res = 0;
        if (K < 10) {
            res = distance(lower_bound(has_primacity[K].begin(), has_primacity[K].end(), A),
                           upper_bound(has_primacity[K].begin(), has_primacity[K].end(), B));
        }
        cout << "Case #" << tc << ": " << res << "\n";
        
    } 

	return 0;
}

















