#include <iostream>

using namespace std;

#define MAXN 200000
#define LGMN 18

typedef long long int64;

int a[MAXN];
int64 segt[1<<(LGMN+1)];

void build(int node, int lo, int hi) {
    if (lo == hi) segt[node] = a[lo];
    else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        segt[node] = segt[ls] + segt[rs];
    }
}

int pos, val;
void updt(int node, int lo, int hi) {
    if (lo == hi)  {
        segt[node] = val;
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        if (pos <= mid) updt(ls,lo,mid);
        else updt(rs,mid+1,hi); 
        segt[node] = segt[ls] + segt[rs];
    }
}

int from, to;
int64 get(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return segt[node];
    else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int64 ret = 0;
        if (from <= mid) ret += get(ls,lo,mid);
        if (to >= (mid+1)) ret += get(rs,mid+1,hi);
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, tc = 1;
    bool first = true;
    while (cin >> n && n) {
        if (first) first = false;
        else cout << "\n";
        
        for (int i = 0; i < n; ++i) cin >> a[i];
        build(0,0,n-1);
        string cmd;
        cout << "Case " << tc++ << ":\n";
        while (cin >> cmd && cmd[0] != 'E') {
            if (cmd[0] == 'S') {
                cin >> pos >> val; pos--;
                updt(0,0,n-1);
            } else {
                cin >> from >> to; from--, to--;
                cout << get(0,0,n-1) << "\n";
            }
        }
    }
    
}