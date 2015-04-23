#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

//int segt[1<<18];
//int a[1<<17];
int st[17][1<<17];

int ans;
int from, to;
/*
void build(int node, int lo, int hi) {
    if (lo == hi) segt[node] = a[lo];
    else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        segt[node] = max(segt[ls],segt[rs]);
    }
}


void get(int node, int lo, int hi) {
    if (from <= lo && hi <= to) ans = max(ans, segt[node]);
    else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        if (from <= mid) get(ls, lo, mid);
        if (to > mid) get(rs, mid+1, hi);
    }
}
*/

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N; cin >> N;
    for (int i = 0; i < N; ++i) cin >> st[0][i];
    //build(0,0,N-1);
    
    for (int k = 1; (1<<k) <= N; ++k) {
        int ds = 1<<(k-1);
        for (int i = 0; i+ds < N; ++i) {
            st[k][i] = max(st[k-1][i], st[k-1][i+ds]);
        }
    }
    
    int M, x, y;
    cin >> M >> x >> y;
    int64 res = 0;
    while (M--) {
        from = min(x,y), to = max(x,y);
        //ans = 0;
        
        //get(0,0,N-1);
        int k = 31-__builtin_clz(to-from+1);
        res += max(st[k][from], st[k][to-(1<<k)+1]);        
        x += 7; while (x >= (N-1)) x -= N-1;
        y += 11; while (y >= N) y -= N;
    }
    cout << res << "\n";

	return 0;
}

















