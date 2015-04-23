#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

double ratio[8][8];


int main() {
    ios::sync_with_stdio(false);
    
    int n, tc = 1;
    while (cin >> n && n) {
        
        map<string, int> hsh;
        string ish[8];
        int cur = 0;
        
        for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j)
            ratio[i][j] = 0.0;
        
        for (int i = 0; i < n; ++i) {
            string c1, c2;
            int ic1, ic2, v1, v2;
            char trsh;
            cin >> v1 >> c1 >> trsh >> v2 >> c2;
            if (!hsh.count(c1)) { ish[cur] = c1, hsh[c1] = cur; cur++; }
            if (!hsh.count(c2)) { ish[cur] = c2, hsh[c2] = cur; cur++; }
            ic1 = hsh[c1];
            ic2 = hsh[c2];
            ratio[ic1][ic2] = double(v2) / double(v1);
            ratio[ic2][ic1] = double(v1) / double(v2); 
        }
        
        bool changed = true;
        while (changed) {
            changed = false;
            
            for (int i = 0; i < cur; ++i) {
                for (int j = 0; j < cur; ++j) {
                    if (i == j) continue;
                    if (ratio[i][j] == 0.0) continue;
                    for (int k = 0; k < cur; ++k) {
                        if (ratio[i][k] != 0.0) continue;
                        if (ratio[j][k] == 0.0) continue;
                        ratio[i][k] = ratio[i][j] * ratio[j][k];
                        ratio[k][i] = 1.0 / ratio[i][k];
                        changed = true;
                    }
                }
            }
                        
        }
        
        int need, req;
        string sreq;
        cin >> need >> sreq;
        
        double best = 2e9;
        int bget = 0, bb;
        
        req = hsh[sreq];
        
        for (int i = 0; i < cur; ++i) {
            if (i == req) continue;
            if (ratio[req][i] == 0.0) continue;
            
            int get = ceil(need * ratio[req][i] - 1e-9);
            
            if (get > 100000) continue;
            
                double got = get * ratio[i][req];
                if (bget == -1 || ((got-best) < 1e-9)) {
                    best = got;
                    bget = get;
                    bb = i;
                }  
        }
        
        cout << "Case " << tc++ << ": " << bget << " " << ish[bb] << "\n";
        
    }
    
    return 0;
}