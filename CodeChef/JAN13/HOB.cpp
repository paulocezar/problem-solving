#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <cctype>
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

inline int next_int() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

int len;
int name[11];
inline void fillname() {
    len = 0;
    char c = getchar_unlocked();
    while (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))) c = getchar_unlocked();
    while (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
        c = tolower(c);
        name[len] = c-'a'+1; len++;
        c = getchar_unlocked();
    }
}

#define MAXR 501
int idx[MAXR][MAXR];
int freeat[MAXR];

int main(int argc, char* argv[]) {

    for (int R = 1; R <= 500; ++R) {
        if ((R%33) == 0) continue;
        
        int a1 = 3%R, a2 = 2%R, a3 = 1%R;
        int S = 0;
        idx[R][0] = 1;
        int cnt = 1;
        for (int i = 1; i <= 14000 && cnt < R; ++i) {
            int cur;
            if (i == 1) cur = 1%R;
            else if (i == 2) cur = 2%R;
            else if (i == 3) cur = 3%R;
            else {
                cur = (a1 + a2 + a3)%R;   
                a3 = a2; a2 = a1; a1 = cur;
            }
            S += cur;
            if (S >= R) S -= R;
            if (!idx[R][S]) { idx[R][S] = i+1; cnt++; }
        }
    }

    int t;
    t = next_int();
    while (t--) {
        int N = next_int();
        int R = next_int();
        memset(freeat, 0, sizeof(freeat));
        
        int HH, MM, H, M, G, mdays = 0;
        HH = next_int(); MM = next_int(); G = next_int(); fillname();
        
        int r0 = 0;
        int i = 0;
        
        while (i < len) {
            r0 = 33*r0 + name[i++];
            r0 %= R;
        }
        puts("0");    
        freeat[r0] = HH*60 + MM + G*60;
        
        int inconv = 0;
        --N;
        
        while (N--) {
            H = next_int(); M = next_int(); G = next_int(); fillname();
            if (H < HH) mdays += 1440;
            else if ((H == HH) && (M < MM)) mdays += 1440;
            
            r0 = 0;
            i = 0;
            while (i < len) {
                r0 = 33*r0 + name[i++];
                r0 %= R;
            }
            r0 += inconv; r0 %= R;

            int gotin = H*60 + M + mdays;
            
            if (freeat[r0] <= gotin) {
                puts("0");
                freeat[r0] = gotin + G*60;
            } else {
                int fr, freed = -1;
                int occp = -1;

                for (int rr = 0; rr < R; ++rr) {
                    int ds = rr - r0;
                    if (rr < r0) ds = R - (r0-rr);
                
                    if (!idx[R][ds]) continue;
                    
                    if (freeat[rr] <= gotin) {
                        if ((freed == -1) || ((idx[R][ds]-1) < freed)) {  
                            freed = idx[R][ds]-1;
                            fr = rr;
                        }
                    } else {
                        if ((occp == -1) || ((freeat[rr]-gotin) < occp)) {
                            occp = freeat[rr]-gotin;
                        }
                    }
                }

                if (freed != -1) {
                    inconv += (freed%R); inconv %= R;
                    freeat[fr] = gotin + 60*G;
                    printf("%d\n", int(freed));
                } else {
                    inconv += (occp % R); inconv %= R;
                    printf("-%d\n", occp);
                }
            }
            
            HH = H, MM = M;
        }
    }

    return 0;
}
















