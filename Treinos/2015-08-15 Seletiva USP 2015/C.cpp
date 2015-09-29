#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define TAM 3

const double pi = acos(-1);

double ax[TAM][TAM];

void mult(double a[TAM][TAM], double b[TAM][TAM]) {
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            ax[i][j] = 0.0;
            for (int k = 0; k < TAM; ++k) {
                ax[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < TAM; ++i) {
        for (int j = 0; j < TAM; ++j) {
            a[i][j] = ax[i][j];
        }
    }
}
    
int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t, N;
    double a, l;

    cout << fixed << setprecision(2);
    
    cin >> t;
    while (t--) {
        cin >> a >> l >> N;
        a = a * pi / 180.0;
                      
        double tr[TAM][TAM] = {{cos(a), -sin(a), 1},
                               {sin(a),  cos(a), 0},
                               {0,            0, 1}};
                      
        double id[TAM][TAM] = {{1, 0, 0},
                               {0, 1, 0},
                               {0, 0, 1}};
                              
       while (N > 0) {
           if (N & 1) mult(id, tr);
           mult(tr, tr);
           N >>= 1;
       }                        
       
       double finalX = l * id[0][2]; if (finalX < 0.001) finalX = 0.0;
       double finalY = l * id[1][2]; if (finalY < 0.001) finalY = 0.0;
       cout << finalX << " " << finalY << "\n";        
    }
    
	return 0;
}


