#include <set>
#include <string> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dig[16], cnt[16], N;

int64 getmin(int mask) {
    for (int i = 0; i < 10; ++i) cnt[i] = 0;
    for (int i = 0; i < N; ++i) {
        if (mask & (1<<i)) cnt[dig[i]]++;
    }
    int64 res = 0LL;
    for (int i = 1; i < 10; ++i) if (cnt[i]) {
        res = i;
        cnt[i]--; break;
    }
    if (!res) return 0LL;
    for (int i = 0; i < 10; ++i) {
        while (cnt[i]) {
            res = 10LL*res + i; cnt[i]--;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    while (cin >> N && N) {
        for (int i = 0; i < N; ++i) cin >> dig[i];
        int all = (1<<N)-1;
        int64 res = -1LL;
        for (int mask = 1; mask < all; ++mask) {
            int64 a = getmin(mask);
            if (!a) continue;
            int64 b = getmin(all^mask);
            if (!b) continue;
            if (res == -1) res = a+b;
            res = min(res, a+b);
        }
        cout << res << "\n";
    }
    

	return 0;
}

















