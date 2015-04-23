/*
ID: knightp2
PROG: calfflac
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

#define MAXN 20202
char txt[MAXN];
int pos[MAXN];

inline bool ok(char c) {
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

#define BASE 33ULL
#define VALUE(c) ((c)-'a')

typedef unsigned long long hash;

hash h[MAXN], rh[MAXN], pw[MAXN];

hash calc_hash(int from, int to) {
    return h[to]-h[from]*pw[to-from];
}

hash calc_rhash(int from, int to) {
    return rh[to]-rh[from]*pw[to-from];
}


int main() {
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");
    
    string text = "";
    string line;
    bool first = true;
    while (getline(fin,line)) {
        if (first) first = false;
        else text += "\n";
        text += line;
    }
    
    int at = 0;
    int len = int(text.size());
    int N = 0;
    char lwr = 1<<5;
    while (at < len) {
        if (ok(text[at])) {
            txt[N] = text[at] | lwr;
            pos[N] = at;
            ++N;
        }
        ++at;
    }
    
    pw[0] = 1ULL;
    for (int i = 1; i <= N; ++i) pw[i] = pw[i-1]*BASE;
    
    h[0] = 0ULL;
    rh[0] = 0ULL;
    for (int i = 0; i < N; ++i) {
        h[i+1] = h[i]*BASE + VALUE(txt[i]);
        rh[i+1] = rh[i]*BASE + VALUE(txt[N-i-1]);
    }
    
    int res = min(2000,N);
    int frm = 0;
    while (res) {
        
        int beg = 0;
        int end = N;
        
        while (beg < N) {
        
            if (calc_hash(beg,beg+res) == calc_rhash(end-res,end)) {
                frm = beg;
                goto hell;
            }
            beg++;
            end--;
        }
        
        --res;
    }
hell:
    fout << res << "\n";
    at = pos[frm];
    while (res) {
        fout << text[at];
        if (ok(text[at])) res--;
        at++;
    }
    fout << "\n";    
    
    return 0;
}
