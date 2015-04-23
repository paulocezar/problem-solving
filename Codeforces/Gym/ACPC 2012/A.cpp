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

int pref[128][128];
int cnt[128];
int cand[128];

bool comp(int a, int b) {
    return cnt[a] > cnt[b];
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    int C, V;
    cin >> C >> V;
    
    REP(i, V) REP(j, C)
        cin >> pref[i][j];
    
    FOR(i, 1, C) cand[i-1] = i;
    REP(i, V) cnt[pref[i][0]]++;
    sort(cand, cand+C, comp);
    
    int ndd = (V+1) / 2;
    
    if (cnt[cand[0]] >= ndd) {
        cout << cand[0] << " 1\n";
    } else {
        int cnt1 = 0, cnt2 = 0;
        
        REP(i, V) {
            int j = 0;
            while (pref[i][j] != cand[0] && pref[i][j] != cand[1]) j++;
            if (pref[i][j] == cand[0]) cnt1++;
            else cnt2++;
        }
        
        if (cnt1 > cnt2) cout << cand[0] << " 2\n";
        else cout << cand[1] << " 2\n";

    }
	 
	return 0;
}

















