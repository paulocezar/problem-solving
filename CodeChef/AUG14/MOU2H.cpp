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
#include <unordered_map>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline int next_int() {
    int res = 0;
    char sig = '+';
    char c = getchar_unlocked();
    while (!isdigit(c) && c != '-') c = getchar_unlocked();
    if (c == '-') sig = '-', c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    if (sig == '-') return -res;
    return res;
}

const int64 mod = 1000000009LL;

int main(int argc, char* argv[]) {
	
	int T, N, last, cur;
    
    T = next_int();
    while (T--) {
        N = next_int(); N--;
        last = next_int();
        
        unordered_map<int, int> last_calc;
        
        int64 nw, ret = 1LL;
        for (int i = 0; i < N; ++i) {
            cur = next_int();
            last = cur - last;
            nw = (ret - last_calc[last] + mod)%mod;
            ret = (ret + nw) % mod;
            last_calc[last] = (last_calc[last]+nw)%mod;
            last = cur;
        }
        ret = (ret+mod-1LL)%mod;
        printf("%d\n", int(ret));        
    }
    

	return 0;
}

















