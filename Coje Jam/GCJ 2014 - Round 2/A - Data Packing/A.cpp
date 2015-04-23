#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int S[10101];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        int N, X;
        cin >> N >> X;
        
        for (int i = 0; i < N; ++i) cin >> S[i];
        
        sort(S, S+N);
        
        int res = 0;
        
        for (int i = N-1; i >= 0; --i) {
            if (!S[i]) continue;
            
            res++;
            for (int j = i-1; j >= 0; --j) {
                if (S[j] && ((S[i]+S[j]) <= X)) {
                    S[j] = 0; break;
                }
            } 

            S[i] = 0;
        }
        
        cout << "Case #" << kase << ": " << res << "\n";
        
    }

	return 0;
}

















