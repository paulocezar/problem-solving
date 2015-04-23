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

char cmd[16];
void readcmd() {
    int p = 0;
    cmd[p] = getchar_unlocked();
    while (!isalpha(cmd[p])) cmd[p] = getchar_unlocked();
    while (isalpha(cmd[p])) cmd[++p] = getchar_unlocked();
}

#define MAXN 500500
int r0[MAXN], r1[MAXN], c0[MAXN], c1[MAXN];
int rx[MAXN], cx[MAXN];
int lr[MAXN], lc[MAXN];

int main(int argc, char* argv[]) {
	
    int n, q, ii, xx;
    
    n = next_int();
    q = next_int();
    
    int rr0 = n, cc0 = n, rr1 = 0, cc1 = 0;
    
    FOR(i,1,n) lr[i] = lc[i] = 1;
    
    q++;
    int idx = 1;
    while (idx <= q) {
        r0[idx] += n;
        c0[idx] += n;
        idx += (idx & -idx);
    }
    
    
    REP(cmds, q-1) {
        readcmd();
        if (cmd[3] == 'S') {
            ii = next_int();
            xx = next_int();
            if (cmd[0] == 'R') {
                idx = lr[ii];
                if (rx[ii]) while (idx <= q) {
                    r1[idx]--;
                    idx += (idx & -idx);
                } else while (idx <= q) {
                    r0[idx]--;
                    idx += (idx & -idx);
                }
                if (rx[ii]) rr1--;
                else rr0--;
                if (xx) rr1++;
                else rr0++;
                rx[ii] = xx;
                lr[ii] = cmds+2;
                
                idx = lr[ii];
                if (xx) while (idx <= q) {
                    r1[idx]++;
                    idx += (idx & -idx);
                } else while (idx <= q) {
                    r0[idx]++;
                    idx += (idx & -idx);        
                }
            } else {
                idx = lc[ii];
                if (cx[ii]) while (idx <= q) {
                    c1[idx]--;
                    idx += (idx & -idx);
                } else while (idx <= q) {
                    c0[idx]--;
                    idx += (idx & -idx);
                }
                if (cx[ii]) cc1--;
                else cc0--;
                if (xx) cc1++;
                else cc0++;
                
                cx[ii] = xx;
                lc[ii] = cmds+2;
                
                idx = lc[ii];
                if (xx) while (idx <= q) {
                    c1[idx]++;
                    idx += (idx & -idx);
                } else while (idx <= q) {
                    c0[idx]++;
                    idx += (idx & -idx);        
                }   
            }
        } else {
            ii = next_int();
            if (cmd[0] == 'R') {
                idx = lr[ii];
                xx = rx[ii] ? cc0 : n - cc1;
                if (rx[ii]) while (idx > 0) {
                    xx -= c0[idx];
                    idx -= (idx & -idx);
                } else while (idx > 0) {
                    xx += c1[idx];
                    idx -= (idx & -idx);
                }
            } else {
                idx = lc[ii];
                xx = cx[ii] ? rr0 : n - rr1;
                if (cx[ii]) while (idx > 0) {
                    xx -= r0[idx];
                    idx -= (idx & -idx);
                } else while (idx > 0) {
                    xx += r1[idx];
                    idx -= (idx & -idx);
                }   
            }
            printf("%d\n", xx);
        }
    }
    
	return 0;
}

















