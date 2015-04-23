#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 200000

char trans[256][256];
int a[MAXN+10];

int can[256];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, M, K, N, x, y;
    cin >> T;
    
    while (T--) {
        cin >> M >> K >> N;
        for (int i = 1; i <= M; ++i) memset(trans[i], 0, (M+1)*sizeof(char));
        
        while (K--) {
            cin >> x >> y;
            trans[x][y] = trans[y][x] = 1;
        }
        
        for (int i = 0; i < N; ++i) cin >> a[i];
        
        for (K = 1; K <= M; ++K) {
            for (x = 1; x <= M; ++x) {
                for (y = 1; y <= M; ++y) {
                    trans[x][y] = trans[x][y] | (trans[x][K] & trans[K][y]);  
                }
            }
        }
        
        for (int i = 1; i <= M; ++i) {
            can[i] = -1;
            if (trans[a[0]][i]) can[i] = 1;
            can[a[0]] = 0;
        }
        
        for (int i = 1; i < N; ++i) {
            int lst = -1;
            for (int j = 1; j <= M; ++j) {
                if (lst == -1) lst = can[j];
                else if (can[j] != -1) lst = min(lst, can[j]);
                
                if (a[i] == j) {
                    can[j] = lst;
                } else if (trans[a[i]][j] && (lst != -1)) {
                    can[j] = lst + 1;
                } else {
                    can[j] = -1;
                }
            }
            if (lst == -1) break;
        }
        
        int res = -1;
        for (int j = 1; j <= M; ++j) if (can[j] >= 0) {
            if (res == -1) res = can[j];
            res = min(res, can[j]);
        }
        cout << res << "\n";
        
    }

	return 0;
}

















