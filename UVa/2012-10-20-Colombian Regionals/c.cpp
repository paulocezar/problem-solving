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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool used[32][128][2];
bool seated[32][128];



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
	int R, C;
    while (cin >> R >> C && (R || C)) {
       int P;
       cin >> P;
       memset(used,false,sizeof(used));
       memset(seated,false,sizeof(seated));
       
       while (P--) {
           string pos, sd;
           cin >> pos >> sd;
           int i = pos[0]-'A';
           int j = pos[1]-'0';
           if (SIZE(pos) > 2) { j = 10*j + (pos[2]-'0'); }
           j--;
           
           if (sd[0] == '-') {
               used[i][j][0] = true;
               if (j) used[i][j-1][1] = true;
           } else {
               used[i][j][1] = true;
               if (j+1 < C) used[i][j+1][0] = true;
           }
       }
       
       int Z;
       cin >> Z;
       bool ok = true;
       while (Z--) {
           string pos; cin >> pos;
           
           int i = pos[0]-'A';
           int j = pos[1]-'0';
           if (SIZE(pos) > 2) { j = 10*j + (pos[2]-'0'); }
           j--;
           
           
           if (used[i][j][0] && used[i][j][1]) {
               ok = false;
           } else if (used[i][j][0] || used[i][j][1]) {
               
               if (used[i][j][0]) {
                   used[i][j][1] = true;
                   while (j+1 < C) {
                       used[i][j+1][0] = true;
                       if (seated[i][j+1]) {
                           if (used[i][j+1][1]) {
                               ok = false; break;
                           }
                           used[i][j+1][1] = true;
                           j++;
                       } else break;
                   }
               } else {
                   used[i][j][0] = true;
                   while (j) {
                       used[i][j-1][1] = true;
                       if (seated[i][j-1]) {
                           if (used[i][j-1][0]) {
                               ok = false; break;
                           }
                           used[i][j-1][0] = true;
                           j--;
                       } else break;
                   }
               }
               
           } else {
               seated[i][j] = true;
           }
           
       }
       
       if (ok) cout << "YES\n";
       else cout << "NO\n";
        
    }
	
	return 0;
}

















