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

int a[3], win[301][301][301];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    REP(i,n) cin >> a[i];
    
    
    REP(i,a[0]+1) {
        REP(j,a[1]+1) {
            REP(k,a[2]+1) {
                if (win[i][j][k]) continue;
                
                int t = 1;
                while (i+t <= a[0]) {
                    win[i+t][j][k] = 1;
                    t++;
                }
                t = 1;
                while (j+t <= a[1]) {
                    win[i][j+t][k] = 1;
                    t++;
                }
                t = 1;
                while (k+t <= a[2]) {
                    win[i][j][k+t] = 1;
                    t++;
                }
                
                if (n == 2) {
                    t = 1;
                    while ((i+t <= a[0]) && (j+t <= a[1])) {
                        win[i+t][j+t][k] = 1;
                        t++;
                    }
                } else if (n ==3) {
                    t = 1;
                    while ((i+t <= a[0]) && (j+t <= a[1]) && (k+t <= a[2])) {
                        win[i+t][j+t][k+t] = 1;
                        t++;
                    }
                }
                
            }
        }
    }
    
    if (win[a[0]][a[1]][a[2]]) cout << "BitLGM\n";
    else cout << "BitAryo\n";
    
	return 0;
}

















