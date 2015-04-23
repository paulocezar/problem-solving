#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int A[1<<17];
pair<int, int> B[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N; cin >> N;
        
        set<int> firsts;
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i] >> B[i].second >> B[i].first;
            firsts.insert(A[i]);
        }
        
        for (int i = 0; i < N; ++i) {
            auto x = firsts.lower_bound(B[i].second);
            if ((x != firsts.end()) && ((*x) <= B[i].first)) {
                if ((*x) != A[i]) {
                    B[i].first = 2e9;
                } else {
                    x++;
                    if ((x != firsts.end()) && ((*x) <= B[i].first)) {
                        B[i].first = 2e9;
                    }
                }
            }
        }
        
        sort(B, B+N);
        
        int res = firsts.size();
        
        int covered = 0;
        
        for (int i = 0; i < N; ++i) {
            if (B[i].first == 2e9) break;
            if (B[i].second > covered) {
                res++;
                covered = B[i].first;
            }
        }
        
        cout << "Case #" << tc << ": " << res << "\n";
        
    }

	return 0;
}

















