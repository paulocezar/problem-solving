#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<vector<int>> tab = {{0, 0, 0, 0, 0},
                           {0, 1, 2, 3, 4},
                           {0, 2,-1, 4,-3},
                           {0, 3,-4,-1, 2},
                           {0, 4, 3,-2,-1}};

int mult(int a, int b) {
    int sgn = ((a*b) < 0) ? -1 : +1;
    return sgn * tab[abs(a)][abs(b)];
}
                        

int L, X;
string s;

int tree[1<<15];

void build(int node, int lo, int hi) {
    if (lo == hi) {
        tree[node] = s[lo%L]-'i'+2;
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls, lo, mid);
        build(rs, mid+1, hi);
        tree[node] = mult(tree[ls], tree[rs]);
    }
}

int from, to;
int get(int node, int lo, int hi) {
    if (from <= lo && hi <= to) return tree[node];
    int mid = (lo+hi)>>1;
    int ls = (node<<1) + 1;
    int rs = ls + 1;
    if (mid >= to) return get(ls,lo,mid);
    if (mid < from) return get(rs,mid+1,hi);        
    return mult(get(ls,lo,mid), get(rs,mid+1,hi));
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> L >> X;
        cin >> s;
        int N = L*X;
        build(0, 0, N-1);
        bool ok = false;
        for (int i1 = 0; i1 < N-2; ++i1) {
            from = 0, to = i1;
            if (get(0, 0, N-1) == 2) {
                for (int i2 = N-1; (i2-i1) > 1; --i2) {
                    from = i2, to = N-1;
                    if (get(0, 0, N-1) == 4) {
                        from = i1+1, to = i2-1;
                        if (get(0, 0, N-1) == 3) {
                            ok = true;
                            goto hell;
                        }
                    }
                }
            }
        }
    hell:
        cout << "Case #" << tc << ": " << (ok ? "YES\n" : "NO\n");
    }

	return 0;
}

















