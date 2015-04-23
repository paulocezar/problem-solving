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

int64 A[100100];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    int64 mn = 3000000000;
    int64 mx = -mn;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }
    
    if (K) {
        for (int i = 0; i < N; ++i) A[i] = mx - A[i];
        K--;
        mx = mx - mn;
        
        if (K & 1) for (int i = 0; i < N; ++i) A[i] = mx - A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";

	return 0;
}

















