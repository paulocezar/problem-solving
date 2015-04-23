#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int chld[1<<15][32], cur_ptr;
int wrds[1<<15];
int isnd[1<<15];

int new_node() {
    for (int i = 0; i < 32; ++i) chld[cur_ptr][i] = -1;
    wrds[cur_ptr] = 0;
    isnd[cur_ptr] = 0;
    return cur_ptr++;
}

void reset_trie() {
    cur_ptr = 0;
    new_node();    
}

int res[1<<15][128];
int K;

void solve(int node) {
    
    int mx = min(K, wrds[node]+isnd[node]);
    for (int i = 0; i <= mx; ++i) res[node][mx] = 1e9;
    res[node][0] = 0;
    res[node][1] = 1;
    
    for (int s = 0; s < 26; ++s) {
        int son = chld[node][s];
        if (son != -1) {
            solve(son);
            int mxson = min(K, wrds[son]+isnd[son]);
            for (int i = 0; i <= mxson; ++i) res[node][i] = min(res[node][i], res[son][i]);
        }
    }
    
    for (int i = 2; i <= mx; ++i) res[node][i] += i;    
    if (isnd[node]) res[node][mx] = (mx == 1) ? 1 : res[node][mx-1];
    
    cout << ":: " << node << endl;    
    for (int i = 0; i <= mx; ++i) {
        cout << " " << res[node][i];
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc =1; tc <= T; ++tc) {
        int N; cin >> N >> K;

        reset_trie();
        
        string word;
        
        for (int i = 0; i < N; ++i) {
            cin >> word;
            int cur_node = 0;
            int j = 0;
            while (j < int(word.size()) && (chld[cur_node][word[j]-'a'] != -1)) {
                wrds[cur_node]++;
                cur_node = chld[cur_node][word[j]-'a'];
                j++;
            }
            
            while (j < int(word.size())) {
                chld[cur_node][word[j]-'a'] = new_node();
                wrds[cur_node]++;
                cur_node = chld[cur_node][word[j]-'a'];
                j++;
            }
            isnd[cur_node]++;
        }
        
        solve(0);
        
        cout << "Case #" << tc << ": " << res[0][K] << "\n";
    } 

	return 0;
}

















