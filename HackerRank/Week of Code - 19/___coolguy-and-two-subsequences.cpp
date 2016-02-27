#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MOD = 1e9 + 7;

struct node_t {
    int cnt, lazy;
};

node_t starting[1<<19], ending[1<<19], *tree;

void build(int node, int lo, int hi) {
    tree[node].cnt = 0;
    tree[node].lazy = 0;
    
    if (lo == hi) return;
    
    int mid = (lo+hi) >> 1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    build(ls, lo, mid);
    build(rs, mid+1, hi);
}

void push(int node, int len = 1) {
    if (!tree[node].lazy) return;
    if (len > 1) {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        tree[ls].lazy += tree[node].lazy; tree[ls].lazy %= MOD;
        tree[rs].lazy += tree[node].lazy; tree[rs].lazy %= MOD;
    }
    tree[node].cnt += (int64(len) * int64(tree[node].lazy)) % MOD;
    tree[node].cnt %= MOD;
    tree[node].lazy = 0;
}

int from, to, val;
void update(int node, int lo, int hi) {
    if (from <= lo && hi <= to) {
        tree[node].lazy += val;
        tree[node].lazy %= MOD;
        push(node, hi-lo+1);
    } else {
        int mid = (lo+hi) >> 1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;

        push(node);
        push(ls, mid-lo+1);
        push(rs, hi - mid);

        if (mid >= from) update(ls, lo, mid);
        if ((mid+1) <= to) update(rs, mid+1, hi);

        tree[node].cnt = tree[ls].cnt + tree[rs].cnt;
        tree[node].cnt %= MOD;
    }
}

int get(int node, int lo, int hi) {
    push(node, hi-lo+1);
    if (from <= lo && hi <= to) {
        return tree[node].cnt;
    }

    int mid = (lo+hi) >> 1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;

    int ans = 0;
    if (mid >= from) ans += get(ls, lo, mid);
    if ((mid+1) <= to) ans += get(rs, mid+1, hi);
    return ans % MOD;
}

int prv[1<<18], nxt[1<<18], a[1<<18], idx[1<<18];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    int top = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        while (top && a[idx[top-1]] > a[i]) top--;

        prv[i] = top ? (idx[top-1] + 1) : 0;
        idx[top++] = i;
    }

    top = 0;
    for (int i = N-1; i >= 0; --i) {
        while (top && a[idx[top-1]] >= a[i]) top--;

        nxt[i] = top ? (idx[top-1] - 1) : (N-1);
        idx[top++] = i;
    }

    for (int i = 0; i < N; ++i) idx[i] = i;

    sort(idx, idx+N, [&](const int i, const int j) {
        if (a[i] != a[j]) return a[i] > a[j];
        return i < j;
    });

    tree = starting; build(0, 0, N-1);
    tree = ending; build(0, 0, N-1);

    // for (int i = 0; i < N; ++i) {
    //     cout << prv[i] << " " << nxt[i] << endl;
    // }
    // cout << "----" << endl;
    // for (int i = 0; i < N; ++i) {
    //     cout << idx[i] << " - " << a[idx[i]] << endl;
    // }

    int ans = 0;
    int64 fb, fb2, sa, sa2;
    for (int i = 0; i < N; ++i) {
        int pos = idx[i];
        int lft = pos - prv[pos] + 1;
        int rgt = nxt[pos] - pos + 1;
        int total = (int64(lft)*int64(rgt)) % MOD;

        tree = ending;
        from = 0, to = prv[pos] - 1;
        fb = (from <= to) ? get(0, 0, N-1) : 0;
        int eat = prv[pos];
        fb2 = 0;
        int64 ax = (lft-1+MOD)%MOD;
        while (eat < pos) {
            from = to = eat;
            fb2 += ax * int64(get(0, 0, N-1)) % MOD; fb2 %= MOD;
            eat++; ax--;
        }

        from = pos, to = nxt[pos], val = lft;
        update(0, 0, N-1);

        tree = starting;

        from = nxt[pos]+1, to = N-1;
        sa = (from <= to) ? get(0, 0, N-1) : 0;
        eat = nxt[pos];
        sa2 = 0;
        ax = (rgt-1+MOD)%MOD;
        while (eat > pos) {
            from = to = eat;
            sa2 += ax * int64(get(0, 0, N-1)) % MOD; sa2 %= MOD;
            eat--; ax--;
        }

        from = prv[pos], to = pos, val = rgt;
        update(0, 0, N-1);

        ax = int64((fb + sa)%MOD)*int64(total)%MOD;
        ax += (fb2*int64(rgt)) % MOD; ax %= MOD;
        ax += (sa2*int64(lft)) % MOD; ax %= MOD;
        
        ans += (ax * int64(a[pos])) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";

	return 0;
}
