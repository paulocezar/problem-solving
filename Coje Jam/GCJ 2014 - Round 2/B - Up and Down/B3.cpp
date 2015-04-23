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

int A[1024], AA[1024], N;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];
        
        int res = 2e9;
        for (int m = 0; m < N; ++m) {
            
            for (int i = 0; i < N; ++i) AA[i] = A[i];

            int cnt = 0;
            int swapped;
            
            do {
                swapped = 0;
                for (int i = 0; (i+1) < N; ++i) {
                    if (i < m) {
                        if (AA[i] > AA[i+1]) { swap(AA[i], AA[i+1]); swapped++; }
                    } else {
                        if (AA[i] < AA[i+1]) { swap(AA[i], AA[i+1]); swapped++; }
                    }
                }
                cnt += swapped;
            } while (swapped);
            
            res = min(res, cnt);
        }
        
        cout << "Case #" << kase << ": " << res << "\n";
    }

	return 0;
}

















