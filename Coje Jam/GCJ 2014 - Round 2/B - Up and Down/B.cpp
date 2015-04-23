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

int get(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += AA[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

void up(int idx) {
    while (idx <= N) {
        AA[idx]++;
        idx += (idx & -idx);
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            AA[i] = A[i];
        }
        
        sort(AA, AA+N);
        map<int,int> opa;
        
        for (int i = 0; i < N; ++i) opa[AA[i]] = i+1;
        for (int i = 0; i < N; ++i) A[i] = opa[A[i]];
                  
        int res = 2e9;   
        for (int m = 0; m < N; ++m) {
        
            memset(AA,0,sizeof(AA));
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                int ax = get(A[i]);
                cnt += (i-ax);
                up(A[i]);
            }
            memset(AA,0,sizeof(AA));
            for (int i = m; i < N; ++i) {
                cnt += get(A[i]);
                up(A[i]);
            }
            res = min(res, cnt);
            
            memset(AA,0,sizeof(AA));
            cnt = 0;
            for (int i = 0; i <= m; ++i) {
                int ax = get(A[i]);
                cnt += (i-ax);
                up(A[i]);
            }
            memset(AA,0,sizeof(AA));
            for (int i = m+1; i < N; ++i) {
                cnt += get(A[i]);
                up(A[i]);
            }
            
            res = min(res, cnt);
                        
        }
        
        cout << "Case #" << kase << ": " << res << "\n";
    }

	return 0;
}

















