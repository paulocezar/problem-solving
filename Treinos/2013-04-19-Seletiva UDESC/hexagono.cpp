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

struct piece_t {
    int color[6];
    void rotate() {
        int first = color[0];
        for (int i = 0; i < 5; ++i) color[i] = color[i+1];
        color[5] = first;
    }
    void read() {
        for (int i = 0; i < 6; ++i) cin >> color[i];
    }
};

piece_t piece[7];
int id[7];

inline bool check() {
    
    while (piece[id[0]].color[0] != 1) piece[id[0]].rotate();
    while (piece[id[1]].color[3] != piece[id[0]].color[0]) piece[id[1]].rotate();
    
    while (piece[id[2]].color[5] != piece[id[1]].color[2]) piece[id[2]].rotate();
    if (piece[id[0]].color[1] != piece[id[2]].color[4]) return false; 
    
    while (piece[id[3]].color[0] != piece[id[2]].color[3]) piece[id[3]].rotate();
    if (piece[id[0]].color[2] != piece[id[3]].color[5]) return false; 
    
    while (piece[id[4]].color[1] != piece[id[3]].color[4]) piece[id[4]].rotate();
    if (piece[id[0]].color[3] != piece[id[4]].color[0]) return false; 
    
    while (piece[id[5]].color[2] != piece[id[4]].color[5]) piece[id[5]].rotate();
    if (piece[id[0]].color[4] != piece[id[5]].color[1]) return false;
    
    while (piece[id[6]].color[3] != piece[id[5]].color[0]) piece[id[6]].rotate();    
    
    return  ((piece[id[0]].color[5] == piece[id[6]].color[2]) && 
             (piece[id[6]].color[1] == piece[id[1]].color[4]));
}

int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; ++kase) {
        for (int i = 0; i < 7; ++i) {
            piece[i].read();
            id[i] = i;
        }
        
        bool found = false;
        do {
            
            if (check()) {
                cout << "Caso " << kase << ":";
                for (int i = 0; i < 7; ++i) cout << " " << id[i];
                cout << "\n";
                found = true;
                break;
            }
            
        } while (next_permutation(id, id+7));
        
        
        if (!found) cout << "Caso " << kase << ": Sem solucao\n";
        
    }
    
    return 0;
}