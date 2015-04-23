#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;

const int64 mod = 1000000007LL;

int64 pw[15][55];
int64 ac[15][55];
int64 p[15];
int64 e[15];
int64 pinv[15];

int64 fastpw(int64 x, int ex) {
	int64 res = 1;
	while (ex > 0) {
		if (ex & 1) { res *= x; res %= mod; }
		x *= x; x %= mod;
		ex >>= 1;
	}
	return res;
}

int main(){
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	FOR(kase,1,t) {
		
		int n;
		cin  >> n;
		REP(i, n) {
			cin >> p[i] >> e[i];
			pinv[i] = fastpw(p[i]-1,mod-2);
		} 

		REP(i, n) {
			pw[i][0] = 1;
			ac[i][0] = 0;
			FOR(j,1,e[i]+1) {
				ac[i][j] = (ac[i][j-1] + pw[i][j-1]) % mod;
				pw[i][j] = (pw[i][j-1] * p[i]) % mod;
			}
		}
        
		int64 divsum = 1LL;
		int64 divs = 1LL;
		int64 num = 1LL;
        REP(i, n) {
            num *= pw[i][e[i]]; num %= mod;
            divs *= (e[i]+1); divs %= mod;
			divsum *= (pw[i][e[i]+1] - 1) * (pinv[i]); divsum %= mod;
		}
        
        divsum += (divs*num)%mod; divsum %= mod;
        
        int all = (1<<n)-1;
        FOR(mask,1,all-1) {
            
            int64 val = 1, cnt = 1;
            REP(i,n) if (mask & (1<<i)) {
                val *= pw[i][e[i]];
                val %= mod;
                cnt *= e[i];
                cnt %= mod;
            } else {
                val *= ac[i][e[i]];
                val %= mod;
            }
            
            divsum += (cnt * val)%mod;
            divsum %= mod;
        }
        
        cout << "Case " << kase << ": " << divsum << "\n";
	}



    return 0;
}
