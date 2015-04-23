#include <iostream>

using namespace std;

int val[1<<17], seg[1<<18];

void build(int node, int lo, int hi) {
    if (lo == hi) {
        seg[node] = val[lo];
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls,lo,mid);
        build(rs,mid+1,hi);
        seg[node] = seg[ls] * seg[rs];
    }
}

int from, to, nval;

void update(int node, int lo, int hi) {
    if (lo == hi) {
        val[lo] = nval;
        seg[node] = nval;
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        
        if (from <= mid) update(ls,lo,mid);
        else update(rs,mid+1,hi);
        
        seg[node] = seg[ls] * seg[rs];
    }
}

int get(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return seg[node];
    
    int mid = (lo+hi)>>1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    if (to < (mid+1)) return get(ls,lo,mid);
    if (from > mid) return get(rs,mid+1,hi);
    
    return (get(ls,lo,mid) * get(rs,mid+1,hi));
}

int main() {
    ios::sync_with_stdio(false);
    
    int N, K;
    while (cin >> N >> K) {
        
        for (int i = 0; i < N; ++i) {
            cin >> val[i];
            if (val[i] < 0) val[i] = -1;
            else if (val[i] > 0) val[i] = +1;
        }
        build(0,0,N-1);
        while (K--) {
            char cmd;
            cin >> cmd >> from; from--;
            if (cmd == 'C') {
                cin >> nval;
                if (nval > 0) nval = +1;
                else if (nval < 0) nval = -1;
                update(0,0,N-1);
            } else  {
                cin >> to; to--;
                nval = get(0,0,N-1);
                if (nval > 0) cout << "+";
                else if (nval < 0) cout << "-";
                else cout << "0";
            }
        }
        cout << "\n";
    }
    
    return 0;
}