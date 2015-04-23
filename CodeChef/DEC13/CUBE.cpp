#include <iostream>
#include <string>

using namespace std;

int sum[44][44][44];

inline int get(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sum[x2][y2][z2]
          - sum[x1-1][y2][z2]
          - sum[x2][y1-1][z2]
          - sum[x2][y2][z1-1]
          + sum[x1-1][y1-1][z2]
          + sum[x1-1][y2][z1-1]
          + sum[x2][y1-1][z1-1]
          - sum[x1-1][y1-1][z1-1];
}

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, P;
        cin >> N >> P;
        
        string sa, sb;
        cin >> sa >> sb;
        
        int pos = 0;
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int k = 1; k <= N; ++k) {
                    sum[i][j][k] =    sum[i][j][k-1]
                                    + sum[i][j-1][k]
                                    + sum[i-1][j][k]
                                    - sum[i-1][j-1][k]
                                    - sum[i-1][j][k-1]
                                    - sum[i][j-1][k-1]
                                    + sum[i-1][j-1][k-1]
                                    + ((sa[pos] == sb[pos])?1:0);
                    pos++;
                }
            }
        }
        
        int cnt = 0;
        
        for (int S = N; S > 0; --S) {
            
            int total = S*S*S;
            
            for (int x1 = 1, x2 = S; x2 <= N; ++x1, ++x2) {
                for (int y1 = 1, y2 = S; y2 <= N; ++y1, ++y2) {
                    for (int z1 = 1, z2 = S; z2 <= N; ++z1, ++z2) {
                        
                        int matches = get(x1,y1,z1,x2,y2,z2);
                        if (100*matches >= P*total) cnt++;
                        
                    }
                }    
            }
            
            
            if (cnt) {
                cout << S << " " << cnt << "\n";
                break;
            }            
        }
        
        if (!cnt) cout << "-1\n";
        
                
    }

    return 0;
}


