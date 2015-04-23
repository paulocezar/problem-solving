#include <iostream>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

string word[100001];

struct node_t {
    map<char, node_t*> chld;
    bool end;
};

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    
    int N;
    while (cin >> N && N) {
        for (int i = 0; i < N; ++i) cin >> word[i];
        
        node_t *trie = new node_t();
        
        for (int i = 0; i < N; ++i) {
            node_t *cur = trie;
            int j = 0;
            while (j < int(word[i].size()) && cur->chld.count(word[i][j])) {
                cur = cur->chld[word[i][j]];
                j++;
            }
            while (j < int(word[i].size())) {
                cur->chld[word[i][j]] = new node_t();
                cur = cur->chld[word[i][j]];
                j++;
            }
            cur->end = true;
        }
        
        int tot = 0;
        for (int i = 0; i < N; ++i) {
            
            node_t *cur = trie->chld[word[i][0]];
            bool ended = cur->end;
            
            tot++;
            int j = 1;
            
            while (j < int(word[i].size())) {
                
                if (int((cur->chld).size()) > 1) tot++;
                else if (ended) tot++;
                
                cur = cur->chld[word[i][j]];
                ended = cur->end;
                j++;
            }

        }
        
        cout << 1.0 * tot / N << "\n";
    }
    
    return 0;
}