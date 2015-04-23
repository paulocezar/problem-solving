#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int mat[1024][1024];

int dx[] = {-1, -1, -1,  0,  0, +1, +1, +1};
int dy[] = {-1,  0, +1, -1, +1, -1,  0, +1};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, M;
    while (cin >> N >> M) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> mat[i][j];
        bool p = false;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j) {
                int ct = 0, ct2 = 0;
                for (int dir = 0; dir < 8; ++dir) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                        ct++;
                        if (mat[i][j] > mat[ni][nj]) ct2++;
                    }
                }
                if (ct == ct2) { cout << (i+1) << " " << (j+1) << "\n"; p = true; }
            }
        
        if (!p) cout << "-1\n";
        cout << "\n";
    }
    

	return 0;
}

















