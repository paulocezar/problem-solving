#include <bits/stdc++.h> 
#include <chrono>
#include <random>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1000000

vector< pair<int,int> > gr[MAXN + 10];

int64 acm[MAXN + 10];
int64 same[MAXN + 10], opposite[MAXN + 10];

int ids[MAXN + 10];

char side[MAXN + 10];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, M, a, b, c;
    cin >> N >> M;

    while (M--) {
        cin >> a >> b >> c;
        acm[a] += c;
        acm[b] += c;
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
    }
    
    for (int i = 0; i < N; ++i) ids[i] = i;
    
    sort(ids, ids+N, [](const int &x, const int &y) { return acm[x] < acm[y]; });
    
    int need = N>>1;
    for (int i = 0; i < need; ++i) side[ids[i]] = 0;
    for (int i = need; i < N; ++i) side[ids[i]] = 1;
    
    
    for (int u = 0; u < N; ++u) {
        same[u] = 0;
        opposite[u] = 0;
        for (auto &w : gr[u]) {
            if (side[w.first] == side[u]) same[u] += w.second;
            else opposite[u] += w.second;
        }
    }
    //unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // shuffle(ids+greedy, ids+N, default_random_engine(seed));
    
    
    
    
    for (int i = 0; i < need; ++i) {
        if (i) cout << " "; cout << ids[i];
    }
    cout << "\n";

	return 0;
}

















