#include <iostream>
#include <algorithm>

using namespace std;

int sol[7], piece[7][6];

void rotate(int* vet) {
    int ax = vet[0];
    for (int i = 0; i < 5; ++i)
        vet[i] = vet[i+1];
    vet[5] = ax;
}

int main() {
    ios::sync_with_stdio(false);
    
    int tc;
    cin >> tc;
    for (int kase = 1; kase <= tc; ++kase) {
        for (int i = 0; i < 7; ++i) {
            sol[i] = i;
            for (int j = 0; j < 6; ++j)
                cin >> piece[i][j];
        }
        
        bool ok = false;
        do {
            
            while (piece[sol[0]][0] != 1) rotate(piece[sol[0]]);
            while (piece[sol[1]][3] != piece[sol[0]][0]) rotate(piece[sol[1]]);
            
            while (piece[sol[2]][4] != piece[sol[0]][1]) rotate(piece[sol[2]]);
            ok = (piece[sol[1]][2] == piece[sol[2]][5]);
                
            while (ok && piece[sol[3]][5] != piece[sol[0]][2]) rotate(piece[sol[3]]);
            ok = ok && (piece[sol[2]][3] == piece[sol[3]][0]);
            
            while (ok && piece[sol[4]][0] != piece[sol[0]][3]) rotate(piece[sol[4]]);
            ok = ok && (piece[sol[3]][4] == piece[sol[4]][1]);
            
            while (ok && piece[sol[5]][1] != piece[sol[0]][4]) rotate(piece[sol[5]]);
            ok = ok && (piece[sol[4]][5] == piece[sol[5]][2]);
            
            while (ok && piece[sol[6]][2] != piece[sol[0]][5]) rotate(piece[sol[6]]);
            
            ok = ok &&
                 (piece[sol[5]][0] == piece[sol[6]][3]) &&
                 (piece[sol[6]][1] == piece[sol[1]][4]);
            
            if (ok) break;
            
        } while (next_permutation(sol, sol+7));
        
        if (ok) {
            cout << "Case " << kase << ":";
            for (int i = 0; i < 7; ++i) cout << " " << sol[i];
            cout << "\n"; 
        } else cout << "Case " << kase << ": No solution\n";
        
    }
    
    return 0;
}
