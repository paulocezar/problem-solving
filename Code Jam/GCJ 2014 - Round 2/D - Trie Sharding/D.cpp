#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string s[8];
int server[8];
int N, M;

int mx, cnt;

struct node_t {
    map<char, node_t*> chld;
};

int used[4];

void gen(int at) {
    if (at == M) {
        for (int i = 0; i < N; ++i) if (!used[i]) return;
        int nodes = N;
        
        node_t* r_trie[N];
        for (int i = 0; i < N; ++i) r_trie[i] = new node_t();
        
        for (int i = 0; i < M; ++i) {
            
            node_t *cur = r_trie[server[i]];
            
            int j = 0;
            while (j < int(s[i].size()) && cur->chld.count(s[i][j])) {
                cur = cur->chld[s[i][j]];
                j++;
            }
            while (j < int(s[i].size())) {
                cur->chld[s[i][j]] = new node_t();
                nodes++;
                cur = cur->chld[s[i][j]];
                j++;
            }            
        }
        
        if (nodes > mx) {
            mx = nodes;
            cnt = 1;
        } else if (nodes == mx) cnt++;        
        
        return;
    }
    
    for (int put = 0; put < N; ++put) {
        server[at] = put;
        used[put]++;
        gen(at+1);
        used[put]--;
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> M >> N;

        for (int i = 0; i < M; ++i) cin >> s[i];
        
        mx = 0, cnt = 0;
        gen(0);
        
        cout << "Case #" << kase << ": " << mx << " " << cnt << "\n";
    }

	return 0;
}

















