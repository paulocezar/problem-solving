#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int gr[128][128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, M;
    while (cin >> N >> M && N) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                gr[i][j] = (i==j) ? 0 : -1;
            }
        }
        while (M--) {
            int a, b, c;
            cin >> a >> b >> c;
            gr[a][b] = (gr[a][b] == -1) ? c : min(gr[a][b], c);
            gr[b][a] = (gr[b][a] == -1) ? c : min(gr[b][a], c);
        }
            
        int K;
        cin >> K;
        while (K--) {
            int a, b;
            cin >> a >> b;
            gr[a][b] = -1;
            gr[b][a] = -1;
        }
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    int dist = ((gr[i][k] == -1) || (gr[k][j] == -1)) ? (-1) : (gr[i][k]+gr[k][j]);
                    if (dist != -1) gr[i][j] = (gr[i][j] == -1) ? dist : min(dist, gr[i][j]);
                }
            }
        }
        cin >> K;
        while (K--) {
            int a, b;
            cin >> a >> b;
            cout << gr[a][b] << "\n";
        }
    }

	return 0;
}

















