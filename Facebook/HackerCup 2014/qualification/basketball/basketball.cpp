#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void get_playin(int P, int M, vector<int> &players) {
    
    vector< pair<int,int> > playn, bench;
    
    for (int i = 0; i < P; ++i)
        playn.push_back(make_pair(0,-players[i]));
    
    for (int i = P; i < int(players.size()); ++i)
        bench.push_back(make_pair(0,players[i]));
    
    while (M--) {
        for (int i = 0; i < P; ++i) playn[i].first--;
        
        sort(playn.begin(), playn.end());
        sort(bench.begin(), bench.end());
        
        if (bench.size()) {
            swap(playn[0],bench[0]);
            playn[0].first *= -1; playn[0].second *= -1;
            bench[0].first *= -1; bench[0].second *= -1;
        }
    }
    
    players.resize(P);
    for (int i = 0; i < P; ++i) players[i] = -playn[i].second;
}

string name[32];
int shot[32], height[32], id[32];

bool comp(int a, int b) {
    if (shot[a] != shot[b]) return (shot[a] > shot[b]);
    return (height[a] > height[b]);
}

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    for (int kase = 1; kase <= T; ++kase) {
        
        int N, M, P;
        cin >> N >> M >> P;
            
        for (int i = 0; i < N; ++i) {
            id[i] = i;
            cin >> name[i] >> shot[i] >> height[i];
        }
        
        sort(id, id+N, comp);
        
        vector<string> names;
        
        for (int team = 0; team < 2; ++team) {
            vector<int> players;
            
            for (int i = 1; i <= N; ++i) if ((i & 1) == team)
                players.push_back(i);
            
            get_playin(P,M,players);
            
            for (int i = 0; i < P; ++i)
                names.push_back(name[id[players[i]-1]]);    
        }
        
        sort(names.begin(), names.end()); 
        
        cout << "Case #" << kase << ":";
        for (auto player : names) cout << " " << player;
        cout << "\n";

    }
    
    return 0;
}
