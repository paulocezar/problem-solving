#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int N, M;
    while ((cin >> N >> M) && (N || M)) {
        string app;
        
        tr1::unordered_map< string, vector<int> > aval;
        
        for (int i = 0; i < N; ++i) {
            int Q;
            cin >> Q;
            for (int j = 0; j < Q; ++j) {
                cin >> app;
                aval[app].push_back(i);
            }
        }
    
        long long res = 0LL;
        for (int i = 0; i < M; ++i) {
            int P;
            cin >> P;
            tr1::unordered_set<int> cnct;
            for (int j = 0; j < P; ++j) {
                cin >> app;
                for (int k = 0; k < aval[app].size(); ++k)
                    cnct.insert(aval[app][k]);
            }
            res += ((long long)(cnct.size()));
        
        }
        cout << res << "\n";
        
    }
    return 0;
}