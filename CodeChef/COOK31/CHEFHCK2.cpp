#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 314159
uint64 pass[MAXN];
vector<uint64> power;
uint64 mx;

uint64 get(uint64 pos) {
    uint64 lo = 0ULL, hi = ULLONG_MAX;
    while (lo < hi) {
        uint64 mid = lo + ((hi-lo)>>1);
        uint64 qnt = mid + 1ULL - uint64(lower_bound(ALL(power),mid) - power.begin());
        if (qnt < pos) lo = mid + 1ULL;
        else if (qnt > pos) hi = mid - 1ULL;
        else return mid;
    }
    return lo;
}

int next_int() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

uint64 next_uint() {
    uint64 res = 0ULL;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10ULL*res + uint64(c-'0');
        c = getchar_unlocked();
    }
    return res;
}


int main(int argc, char* argv[]) {
	
	int N = next_int();
    
    mx = 0ULL;
    REP(i, N) { pass[i] = next_uint(); mx = max(mx, pass[i]); }
    
    
    uint64 lim2 = sqrt(ULLONG_MAX);
    uint64 cur = 2ULL;
    
    while (cur < lim2) {
        
        uint64 lim = (ULLONG_MAX / cur);        
        uint64 pw = cur*cur;
        power.PB(pw);
        if (pw >= lim) break;
        
        while (pw < lim) {
            pw *= cur;
            power.PB(pw);
        }
        cur++;
    }
    
    sort(ALL(power));
    power.resize(unique(ALL(power))-power.begin());
    mx = power[SIZE(power)-1] + 1ULL;

    REP(i, N) {
        int pos = lower_bound(ALL(power),pass[i]) - power.begin();
        
        if (power[pos] == pass[i]) {
            pass[i] = uint64(pos+1);
        } else {
            uint64 tries = 1ULL;
            uint64 hi = 2ULL;
            while (get(hi) < pass[i]) {
                hi *= 2ULL;
                tries++;
            }
            
            if (get(hi) != pass[i]) {
                uint64 lo = hi >> 1;
                
                while (lo < hi) {
                    
                    uint64 mid = lo + ((hi-lo)>>1);
                    tries++;
                    uint64 pss = get(mid);
                    if (pss < pass[i]) {
                        lo  = mid;
                    } else if (pss > pass[i]) {
                        hi = mid;
                    } else break;
                }
                
            }
                       
            pass[i] = tries;
        }
        
    }
    
    printf("%llu", pass[0]);
    FOR(i,1,N-1) printf(" %llu", pass[i]);
    puts("");
    
	return 0;
}

















