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
typedef unsigned int uint;

using namespace std;

int64 next_int() {
    int64 res = 0LL;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10LL*res + int64(c-'0');
        c = getchar_unlocked();
    }
    return res;
}

#define NFAC 4
int change[][NFAC] = {{0,0,0,0},
                      {0,0,0,0},
                      {1,0,0,0},
                      {0,1,0,0},
                      {2,0,0,0},
                      {0,0,1,0},
                      {1,1,0,0},
                      {0,0,0,1},
                      {3,0,0,0},
                      {0,2,0,0}};

uint cache[36][55*37*19*19];
uint has[2][109*73*37*37];
bitset< 109*73*37*37 > enq[2];

inline int encoder(int x[]) {
    int res = x[0];
    res = 37*res + x[1];
    res = 19*res + x[2];
    res = 19*res + x[3];
    return res;
}

inline bool okay(int x[]) {
    return ((0 <= x[0] && x[0] <= 54)
         && (0 <= x[1] && x[1] <= 36)
         && (0 <= x[2] && x[2] <= 18)
         && (0 <= x[3] && x[3] <= 18));
}

inline int encode(int x[]) {
    int res = x[0]+54;
    res = 73*res + (x[1]+36);
    res = 37*res + (x[2]+18);
    res = 37*res + (x[3]+18);
    return res;
}

void decode(int y, int x[]) {
    x[3] = (y % 37) - 18; y /= 37;
    x[2] = (y % 37) - 18; y /= 37;
    x[1] = (y % 73) - 36; y /= 73;
    x[0] = y-54;
}

uint zr[36], nzr[36];

int main(int argc, char* argv[]) {
	
    int64 factor[] = {2LL, 3LL, 5LL, 7LL};
    int fac[NFAC], fz[NFAC];
    
    queue<int> q;
    int qc = 1, qo = 0;
    for (int i = 1; i <= 9; ++i) {
        int xx = encode(change[i]);
        q.push(xx);
        enq[qo][xx] = 1;
        has[qo][xx] = uint(1);
    }
    
    int len = 0;
    while (len < 36) {
        int sig = (len & 1) ? (+1) : (-1);
        int qsz = SIZE(q);
        while (qsz--) { 
            int ifz = q.front(); q.pop();
            uint had = has[qo][ifz];
            enq[qo][ifz] = 0;
            has[qo][ifz] = uint(0);
            nzr[len] += had;
            
            decode(ifz, fz);
            if (okay(fz)) cache[len][encoder(fz)] = had;

            if (len != 35) {
                for (int dig = 1; dig <= 9; ++dig) {
                    for (int i = 0; i < NFAC; ++i) {
                        fac[i] = fz[i] + sig * change[dig][i];
                    }
                    int ifac = encode(fac);
                    
                    if (!enq[qc][ifac]) {
                        enq[qc][ifac] = 1;
                        q.push(ifac);
                    }
                    has[qc][ifac] += had;    
                }
            }
        }
        qo = 1-qo;
        qc = 1-qc;
        
        if (len & 1) zr[len] = uint(9) * zr[len-1];
        else if (len) zr[len] = uint(10) * zr[len-1] + nzr[len-1];
        
        len++;
    }
    
    int t = next_int();
    while (t--) {
        int L = next_int();
        int64 V = next_int();
    
        if (V) {
            for (int i = 0; i < NFAC; ++i) {
                int xp = 0;
                while ((V % factor[i]) == 0LL) V /= factor[i], xp++;
                fac[i] = xp;
            }
            if ((V != 1LL) || !okay(fac)) puts("0");
            else printf("%u\n", cache[L-1][encoder(fac)]);
        } else {
            printf("%u\n", zr[L-1]);
        }        
    }
	
	return 0;
}
















