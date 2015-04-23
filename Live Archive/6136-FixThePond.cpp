#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAXN 300
#define MAXL (2*MAXN)
#define MAXC (2*MAXN+1)
#define MAXV (MAXL*MAXC)

int pa[MAXV], rk[MAXV];

int find(int x) {
    int px = x, ax;
    while (pa[px] != px) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

void fUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rk[y] > rk[x]) swap(x,y);
    if (rk[x] == rk[y]) rk[x]++;
    pa[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    
    int N;
    while (cin >> N && N) {
        
        int L = 2*N, C = 2*N+1;
        int V = L*C;
        
        for (int i = 0; i < V; ++i) pa[i] = i, rk[i] = 0;
        
        for (int i = 0; i < (L-1); ++i) {
            string line; cin >> line;
            for (int j = 0; j < N; ++j) {
                int a = i*C + 2*j + (i&1),      b = i*C+2*j+1 + (i&1);
                int c = (i+1)*C + 2*j + (i&1),  d = (i+1)*C+2*j+1 + (i&1);
                if (line[j] == 'H') {
                    fUnion(a, b);
                    fUnion(c, d);
                } else {
                    fUnion(a,c);
                    fUnion(b,d);
                }
            }
        }
        
        for (int i = 1; (i+1) < C; i+=2) {
            fUnion(i, i+1);
            fUnion((L-1)*C + i, (L-1)*C + i+1);
        }
        for (int i = 1; (i+1) < L; i+=2) fUnion(i*C, (i+1)*C);
        for (int i = 0; (i+1) < L; i+=2) fUnion(i*C+C-1, (i+1)*C+C-1);
    
        
        int comps = 0;
        for (int i = 0; i < V; ++i) if (find(i) == i) comps++;
        cout << comps-1 << "\n";
        
    }
    
    return 0;
}