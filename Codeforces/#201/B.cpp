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

string S1, S2, S;
int NS1, NS2, NS;

int p[128];
int tr[128][26];

int dp[128][128][128];

int solve(int p1, int p2, int pz) {
    if (p1 == NS1 || p2 == NS2) return 0;
    
    int &res = dp[p1][p2][pz];
    if (res != -1) return res;
    
    res = solve(p1+1,p2,pz);
    res = max(res, solve(p1,p2+1,pz));
    
    if (S1[p1] == S2[p2]) {
        int npz = tr[pz][S1[p1]-'A'];
        if (npz != NS) res = max(res, 1+solve(p1+1,p2+1,npz));
    }
    
    return res;
}

void print(int p1, int p2, int pz) {
    if (p1 == NS1 || p2 == NS2) return;   
    if (dp[p1][p2][pz] == solve(p1+1,p2,pz)) print(p1+1,p2,pz);
    else if (dp[p1][p2][pz] == solve(p1,p2+1,pz)) print(p1,p2+1,pz);
    else {
        cout << S1[p1];
        print(p1+1,p2+1,tr[pz][S1[p1]-'A']);
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> S1 >> S2 >> S;
    
    NS1 = SIZE(S1);
    NS2 = SIZE(S2);
    NS = SIZE(S);
    
    p[0] = p[1] = 0;
    FOR(i, 2, NS) {
        int j = p[i-1];
        while (S[i-1] != S[j]) {
            if (j == 0) { j = -1; break; }
            j = p[j];
        }
        p[i] = ++j; 
    }
    
    REP(j,26) tr[0][j] = (S[0]==char(j+'A')) ? 1 : 0;
    
    FOR(i, 1, NS-1) REP(j, 26)
        tr[i][j] = (S[i]==(char(j+'A'))) ? (i+1): (tr[p[i]][j]);
     
    FILL(dp,-1);   
    int len = solve(0,0,0);
    
    if (len) print(0,0,0);
    else cout << "0";
    
    cout << "\n";
    
	return 0;
}

















