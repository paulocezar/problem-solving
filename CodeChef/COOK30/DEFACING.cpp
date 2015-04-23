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

int led[10] = { 0x7E,
                0x30,
                0x6D,
                0x79,
                0x33,
                0x5B,
                0x5F,
                0x70,
                0x7F,
                0x7B };

bool turn[10][10];
int p10[10];

string S, M;
int mlen, slen;

int calc[10][10][2][2], calc_now;
int dp[10][10][2][2];

int solve(int pos, int poss, int nzr, int lssr) {
    if (pos == mlen) {
        if (poss < slen) return -2000000000;
        return 0;
    }
    
    int &res = dp[pos][poss][nzr][lssr];
    if (calc[pos][poss][nzr][lssr] == calc_now) return res;
    calc[pos][poss][nzr][lssr] = calc_now;
    res = -2000000000;
    
    if (1 <= poss && poss < slen) {
        int hi = lssr ? 9 : (M[pos]-'0');
        int lo = (nzr ? 0 : 1);
        while (lo <= hi) {
            if (turn[S[poss]-'0'][lo]) {
                res = max(res, p10[mlen-pos-1]*lo + solve(pos+1, poss+1, nzr || (lo != hi), lssr || (lo < hi)));
            }
            lo++;
        }
    } else {
        
        int lo = 0, hi = (lssr ? 9 : (M[pos]-'0'));
        while (lo <= hi) {
            res = max(res, p10[mlen-pos-1]*lo + solve(pos+1, poss, nzr || (lo != 0), lssr || (lo < hi)));
            lo++;
        }
        
        if (poss == 0) {
            lo = (nzr ? 0 : 1);
            hi = (lssr ? 9 : (M[pos]-'0'));
            while (lo <= hi) {
                if (turn[S[poss]-'0'][lo])
                res = max(res, p10[mlen-pos-1]*lo + solve(pos+1, 1, nzr || (lo != 0), lssr || (lo < hi)));
                lo++;
            }   
        }
        
    }
    
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    REP(i, 10) {
        REP(j, 10) {
            turn[i][j] = false;
            if ((led[i] & led[j]) == led[i]) turn[i][j] = true;
        }
    }
    p10[0] = 1;
    FOR(i, 1, 8) p10[i] = 10*p10[i-1];
    
    int t;
    cin >> t;
    while (t--) {
        cin >> S >> M;
        
        slen = SIZE(S);
        mlen = SIZE(M);
        int ss = 0;
        REP(i, slen) ss = 10*ss + (S[i]-'0');
        
        calc_now++;
        int res = max(ss, solve(0,0,0,0));        
        cout << res << "\n";
    }
	 
	return 0;
}

















