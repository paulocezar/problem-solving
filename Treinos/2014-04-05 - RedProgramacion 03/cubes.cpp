#include <set>
#include <string> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int has[4], somewhere, N, K;
string dict[32];

vector< vector<int> > orders[5];

bool gen(int pos) {
    
    if (pos == N) {
        
        vector<string> res;
        for (int i = 0; i < K; ++i) {
            string ss = "";
            for (int j = 0; j < 26; ++j) {
                if (has[i] & (1<<j)) ss += (j+'A');
            }
            res.push_back(ss);
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < K; ++i) {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << "\n";
        return true;
    }
    
    int add[K]; memset(add,0,sizeof(add));
    int ctry = 0;
    while (ctry < int(orders[K].size())) {
        
        bool ok = true;
        for (int i = 0; ok && (i < K); ++i) {
            
            
            
            if (!(has[orders[K][ctry][i]] & (1<<dict[pos][i]))) {
                if (somewhere & (1<<dict[pos][i])) {
                    ok = false;
                }
                add[orders[K][ctry][i]] |= (1<<dict[pos][i]);
            }
        }
        
        if (!ok) {
            memset(add, 0, sizeof(add));
            ctry++;
            continue;
        }
        
        for (int i = 0; i < K; ++i) {
            has[i] |= add[i];
            somewhere |= add[i];
        }

        for (int i = 0; ok && (i < K); ++i)
            if (__builtin_popcount(has[i]) > 6) ok = false;
        
        if (ok) if (gen(pos+1)) return true;
         
        for (int i = 0; i < K; ++i) {
            has[i] ^= add[i];
            somewhere ^= add[i];
            add[i] = 0;
        }
        
        ctry++;
    }
    return false;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    for (K = 2; K <= 4; ++K) {
        vector<int> ord(K);
        for (int i = 0; i < K; ++i) ord[i] = i;
        do {
            orders[K].push_back(ord);
        } while (next_permutation(ord.begin(), ord.end()));
        random_shuffle(orders[K].begin(), orders[K].end());
    }
            
    while (cin >> N && N) {
        
        char xtra; cin >> xtra;
        
        memset(has, 0, sizeof(has));
        somewhere = 0;
        
        if (xtra != '-') {
            has[0] |= (1<<(xtra-'A'));
            somewhere |= (1<<(xtra-'A'));
        }
        
        for (int i = 0; i < N; ++i) cin >> dict[i];
        K = int(dict[0].size());
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < K; ++j) dict[i][j] -= 'A';
        gen(0);
          
    }

	return 0;
}

















