#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <tr1/unordered_map>
    
using namespace std;

typedef long long int64;

#define MAXN 10000
#define MAXM 10

int64 table[MAXN][MAXM];

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    string line, entry;
    
    while (cin >> n >> m) {
        cin.ignore();
        
        tr1::unordered_map<string, int> hash;
        int wrd_id = 0;
        for (int i = 0; i < n; ++i) {
            
            getline(cin, line);
            int ps = 0;
            for (int j = 0; j < m; ++j) {
                entry = "";
                while (ps < int(line.size()) && line[ps] != ',') entry += line[ps++];
                if (!hash.count(entry)) hash[entry] = wrd_id++;
                table[i][j] = hash[entry];
                ps++;    
            }
        }
        
        for (int j1 = 0; j1 < m; ++j1) {
            for (int j2 = j1+1; j2 < m; ++j2) {
                tr1::unordered_map< int64, int> seen;
                
                for (int i = 0; i < n; ++i) {
                    if (seen.count((table[i][j1]<<17) | table[i][j2])) {
                        cout << "NO\n";
                        cout << seen[(table[i][j1]<<17) | table[i][j2]]+1 << " " << i+1 << "\n";
                        cout << j1+1 << " " << j2+1;
                        goto hell;
                    } else seen[(table[i][j1]<<17) | table[i][j2]] = i;
                }
                
            }
        }
        cout << "YES";
        hell:
        cout << "\n";
    }
    
    
    return 0;
}
