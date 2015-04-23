#include <iostream>
#include <tr1/unordered_set>

using namespace std;

#define MAXN 1000100

int k[MAXN];
int cool[MAXN];

int main() {
    ios::sync_with_stdio(false);
    
    int M, Q;
    while (cin >> M >> Q && (M || Q)) {
        
        for (int i = 0; i < M; ++i) cin >> k[i];
        
        int l = M-2;
        int r = M-1;
        cool[M-1] = 0;
        
        tr1::unordered_set<int> ex;
        ex.insert(k[M-1]);
        
        while (l >= 0) {
            while (ex.count(k[l])) {
                ex.erase(k[r]);
                r--;
            }
            ex.insert(k[l]);
            cool[l] = r-l;
            l--;
        }
        
        while (Q--) {
            int from, to;
            cin >> from >> to;
            from--, to--;
            
            if (from + cool[from] >= to) cout << "OK\n";
            else cout << k[from+cool[from]+1] << "\n";
        }
        cout << "\n";
        
    }
    
    return 0;
}