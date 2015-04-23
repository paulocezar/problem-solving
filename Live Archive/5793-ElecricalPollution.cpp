#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

#define MAXM 10001
#define MAXN 2*MAXM

vector< pair<int,int> > gr[MAXN];

int last_seen[2][MAXN], seen_now;
int comp[2][MAXN];
int dist[2][MAXN];

int cur_dist, cur_comp;

void go(int p, int u) {
    dist[p][u] = cur_dist;
    last_seen[p][u] = seen_now;
    comp[p][u] = cur_comp;
    
    for (int i = 0; i < int(gr[u].size()); ++i) {
        int v = gr[u][i].first;
        if (last_seen[1-p][v] != seen_now) {
            if (p) {
                cur_dist -= gr[u][i].second;
                go(1-p,v);
                cur_dist += gr[u][i].second;
            } else {
                cur_dist += gr[u][i].second;
                go(1-p,v);
                cur_dist -= gr[u][i].second;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    
    int M, Q;
    while (cin >> M >> Q && (M || Q)) {
        
        map<int, int> hash;
        int N = 0;
        
        while (M--) {
            int X, Y, A;
            cin >> X >> Y >> A;
            if (X == Y) A <<= 1;
            if (!hash.count(X)) {
                gr[N].clear();
                hash[X] = N++;
            }
            if (!hash.count(Y)) {
                gr[N].clear();
                hash[Y] = N++;
            }
            X = hash[X];
            Y = hash[Y];
            gr[X].push_back(make_pair(Y,A));
            gr[Y].push_back(make_pair(X,A));
        }
        
        seen_now++;
        cur_comp = 0;
        cur_dist = 0;
        for (int i = 0; i < N; ++i) {
            if (last_seen[0][i] != seen_now) {
                go(0,i);
                cur_comp++;
            }
        }
        
        while (Q--) {
            int X, Y;
            cin >> X >> Y;
            if (!hash.count(X) || !hash.count(Y)) cout << "*\n";
            else {
                X = hash[X];
                Y = hash[Y];
                if (comp[0][X] == comp[1][Y]) cout << ((dist[1][Y]-dist[0][X])>>(X==Y)) << "\n";
                else if (comp[1][X] == comp[0][Y]) cout << ((dist[1][X] - dist[0][Y])>>(X==Y)) << "\n";
                else if ((comp[0][X] == comp[1][X]) && (comp[0][Y] == comp[1][Y]))
                    cout << ((-dist[0][X] + dist[1][X] - dist[0][Y] + dist[1][Y])>>1) << "\n";
                else cout << "*\n";
            }
        }
        cout << "-\n";
        
    }
    
    return 0;
}