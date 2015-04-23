#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define LGMN 17

unsigned int dsa[32];
int dsb[5];

unsigned int segt[1<<(LGMN+1)];
char lazy[1<<(LGMN+1)];
int pref[1<<(LGMN+1)][5];
int suff[1<<(LGMN+1)][5];

char T[5], P[100001];
int ts, ps, from, to;
 
void genpref(int node, int lo, int hi) {    
    int len = 1;
    while (len < ts) {
        
        if ((hi-len+1) < lo) break;
    
        int i = hi-len+1;
        int p = 0;
        int mask = 0;
        bool ok = true;
        while (i <= hi) {
            if (tolower(P[i]) != tolower(T[p])) {
                ok = false;
                break;
            } 
            mask <<= 1;
            if (P[i] != T[p]) mask |= 1;                
            i++; p++;
        }
        if (ok) pref[node][len] = mask;
        len++;
    }
}

void updpref(int node, int lo, int hi) {    
    int len = 1;
    while (len < ts) {
        if ((hi-len+1) < lo) break;
    
        int i = hi-len+1;
        int p = 0;
        int mask = 0;
        
        if (pref[node][len] != -1) {
            while (i <= hi) {
                if (from <= i && i <= to) {
                    if (!(pref[node][len] & dsb[len-p-1])) mask |= dsb[len-p-1];
                } else {
                    if (pref[node][len] & dsb[len-p-1]) mask |= dsb[len-p-1]; 
                }                                
                i++; p++;
            }
            pref[node][len] = mask;
        }
        
        len++;
    }
}

void gensuff(int node, int lo, int hi) {    
    int len = 1;
    while (len < ts) {
        if ((lo+len-1) > hi) break;
        int i = lo;
        int p = ts-len;
        int mask = 0;
        bool ok = true;
        while (p < ts) {
            if (tolower(P[i]) != tolower(T[p])) {
                ok = false;
                break;
            } 
            mask <<= 1;
            if (P[i] != T[p]) mask |= 1;                
            i++; p++;
        }
        if (ok) suff[node][len] = mask;
        len++;
    }
}
            
void updsuff(int node, int lo, int hi) {    
    int len = 1;
    while (len < ts) {
        if ((lo+len-1) > hi) break;
        int i = lo;
        int p = ts-len;
        int mask = 0;
        if (suff[node][len] != -1) {
            while (p < ts) {
            
                if (from <= i && i <= to) {
                    if (!(suff[node][len] & dsb[ts-p-1])) mask |= dsb[ts-p-1];
                } else {
                    if (suff[node][len] & dsb[ts-p-1]) mask |= dsb[ts-p-1];
                }
            
                i++; p++;
            }
            suff[node][len] = mask;
        }
        len++;
    }
}


void build(int node, int lo, int hi) {

    segt[node] = 0u;
    lazy[node] = 0;
    for (int i = 1; i < ts; ++i) {
        pref[node][i] = -1, suff[node][i] = -1;
    }
    
    if (lo == hi) {
        if (ts == 1) {
            if (tolower(T[0]) == tolower(P[lo])) {
                if (T[0] == P[lo]) segt[node] = 1u;
                else segt[node] = 2u;
            }
        } else {
            genpref(node, lo, hi);
            gensuff(node, lo, hi);
        }
    } else {
        int mid = (lo+hi) >> 1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        
        build(ls, lo, mid);
        build(rs, mid+1, hi);
        
        segt[node] = segt[ls] | segt[rs];
        
        if (ts > 1) {
            for (int preflen = 1; preflen < ts; ++preflen) {
                if ((pref[ls][preflen] != -1) && (suff[rs][ts-preflen] != -1)) {
                    segt[node] |= dsa[(pref[ls][preflen] << (ts-preflen)) | suff[rs][ts-preflen]];
                }
            }
            
            if ((hi-mid) >= (ts-1)) {
                for (int i = 1; i < ts; ++i) pref[node][i] = pref[rs][i];
            } else genpref(node,lo,hi);
            
            if ((mid-lo+1) >= (ts-1)) {
                for (int i = 1; i < ts; ++i) suff[node][i] = suff[ls][i];
            } else gensuff(node,lo,hi);
        }
    }
} 

int curbits;

void push(int node, char leaf) {
    if (!leaf) {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        lazy[ls] = 1-lazy[ls];
        lazy[rs] = 1-lazy[rs];
    }
    
    unsigned int nmask = 0u;
    for (int bit = 0; bit < curbits; ++bit) {
        nmask <<= 1;
        if (segt[node] & dsa[bit]) nmask |= 1u;
    }
    segt[node] = nmask;
    
    for (int i = 1; i < ts; ++i) {
        if (pref[node][i] != -1) pref[node][i] ^= (dsb[i]-1);
        if (suff[node][i] != -1) suff[node][i] ^= (dsb[i]-1);
    }   
    
    lazy[node] = 0; 
}

inline int bits(int x) {
    int res = 0;
    while (x) {
        res++;
        x -= (x & -x);
    }
    return res;
}


int get(int node, int lo, int hi) {
    
    if (lazy[node]) push(node, lo == hi);
    
    int ret = -1;
    
    if (from <= lo && hi <= to) {
        
        unsigned int nmask = 0u;
        for (int bit = 0; bit < curbits; ++bit) {
            nmask <<= 1;
            if (segt[node] & dsa[bit]) {
                nmask |= 1u;
                ret = max(ret, bits(bit));
            }
        }
        segt[node] = nmask;
        
        for (int i = 1; i < ts; ++i) {
            if (pref[node][i] != -1) pref[node][i] ^= (dsb[i]-1);
            if (suff[node][i] != -1) suff[node][i] ^= (dsb[i]-1);
        }
        
        if (lo != hi) {
            int ls = (node<<1) + 1;
            int rs = ls + 1;
            lazy[ls] = 1-lazy[ls];
            lazy[rs] = 1-lazy[rs];
        }
        
    } else {
        
        int mid = (lo+hi) >> 1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        
        if (lazy[ls]) push(ls,lo == mid);
        if (lazy[rs]) push(rs,(mid+1)==hi);
        
        if ((ts > 1) && (mid >= from) && ((mid+1) <= to)) {
            for (int preflen = 1; preflen < ts; ++preflen) {
                if ((pref[ls][preflen] != -1) && (suff[rs][ts-preflen] != -1)) {
                    if (((mid-preflen+1) >= from) && ((mid+ts-preflen) <= to)) {
                        ret = max(ret, bits(((pref[ls][preflen] << (ts-preflen)) | suff[rs][ts-preflen])));
                    }
                }
            }
        }
        
        if (mid >= from) ret = max(ret, get(ls, lo, mid));
        if ((mid+1) <= to) ret = max(ret, get(rs, mid+1, hi));
        segt[node] = segt[ls] | segt[rs];
        
        if (ts > 1) {
            for (int preflen = 1; preflen < ts; ++preflen) {
                if ((pref[ls][preflen] != -1) && (suff[rs][ts-preflen] != -1)) {
                    segt[node] |= dsa[((pref[ls][preflen] << (ts-preflen)) | suff[rs][ts-preflen])];
                }
            }

            if ((hi-mid) >= (ts-1)) {
                for (int i = 1; i < ts; ++i) pref[node][i] = pref[rs][i];
            } else updpref(node,lo,hi);
            
            if ((mid-lo+1) >= (ts-1)) {
                for (int i = 1; i < ts; ++i) suff[node][i] = suff[ls][i];
            } else updsuff(node,lo,hi);
            
        }        
        
    }
    
    return ret;
}

int getint() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) {
        if (c == EOF) return 0;
        c = getchar_unlocked();
    }
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

void getstring(char *ss, int &sz) {
    sz = 0;
    *ss = getchar_unlocked();
    while (isalpha(*ss)) {
        sz++;
        ss++;
        *ss = getchar_unlocked();
    }
}

int main() {
    //ios::sync_with_stdio(false);

    for (int i = 0; i < 5; ++i) dsb[i] = 1<<i;
    for (int i = 0; i < 32; ++i) dsa[i] = 1u<<i;

    int N = getint();
    while (N) {
        getstring(T, ts);
        getstring(P, ps);
        
        curbits = (1<<ts);
        build(0,0,ps-1);

        while (N--) {
            from = getint();
            to = getint();
            from--, to--;            
            printf("%d\n", get(0,0,ps-1));
        }
        N = getint(); 
    }
    
    return 0;
}
