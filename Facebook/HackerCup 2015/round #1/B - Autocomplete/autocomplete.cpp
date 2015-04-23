#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int chld[1<<20][32], cur_ptr;

int new_node() {
    for (int i = 0; i < 32; ++i) chld[cur_ptr][i] = -1;
    return cur_ptr++;
}

void reset_trie() {
    cur_ptr = 0;
    new_node();    
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc =1; tc <= T; ++tc) {
        int N; cin >> N;
        int res = 0;
        
        reset_trie();
        
        string word;
        
        for (int i = 0; i < N; ++i) {
            cin >> word;
            int cur_node = 0;
            int j = 0;
            while (j < int(word.size()) && (chld[cur_node][word[j]-'a'] != -1)) {
                cur_node = chld[cur_node][word[j]-'a'];
                res++;
                j++;
            }
            
            if (j < int(word.size())) res++;
            
            while (j < int(word.size())) {
                chld[cur_node][word[j]-'a'] = new_node();
                cur_node = chld[cur_node][word[j]-'a'];
                j++;
            }
        }
        
        cout << "Case #" << tc << ": " << res << "\n";
    }
    

	return 0;
}

















