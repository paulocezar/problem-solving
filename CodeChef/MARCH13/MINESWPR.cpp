#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool chk[64][64];

int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m, k;
    char res;
    cin >> n >> m >> k;

    int xtra = k-m;
    int defused = 0;
    
    REP(i, n) REP(j, n) if (!chk[i][j] && defused < k && m) {
            
        cout << "S " << i << " " << j << endl;
        fflush(stdout);
        cin >> res;

        int ng = 0;
        REP(dir, 8) {
            int ii = i + dx[dir];
            int jj = j + dy[dir];
            if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
            if (!chk[ii][jj]) ng++;
        }
        
        if (res == 'M') {
            cout << "N " << i << " " << j << endl;
            defused++;
            m--;
        } else if (res == '0') {
            REP(dir,8) {
                int ii = i + dx[dir];
                int jj = j + dy[dir];
                if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                chk[ii][jj] = true;
            }
        } else if (int(res-'0') == ng) {
            REP(dir,8) {
                int ii = i + dx[dir];
                int jj = j + dy[dir];
                if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                if (!chk[ii][jj]) {
                    cout << "N " << ii << " " << jj << endl;
                    defused++;
                    m--;
                    chk[ii][jj] = true;
                }
            }
        } else {
            REP(dir,8) {
                if (!xtra) break;
                int ii = i + dx[dir];
                int jj = j + dy[dir];
                if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                if (!chk[ii][jj]) {
                    cout << "N " << ii << " " << jj << endl;
                    defused++;
                    chk[ii][jj] = true;
                    xtra--;
                }
            }
        } 
        chk[i][j] = true;
    }

    cout << "Done" << endl;
    fflush(stdout);
    
	return 0;
}





