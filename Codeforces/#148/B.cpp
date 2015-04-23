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

string ss, s;
int print[16];
bool valid[128];

void execute(int from, int to) {    
    
    FOR(pos,from,to) {
        valid[pos] = true;
        s[pos] = ss[pos];
    }
    
    int prv = -1;
    int cp = from;
    int dp = +1;
    
    while (true) {
      if (cp < from || cp > to) return;
      if (!valid[cp]) { 
          cp += dp;
          continue;
      }
      //cout << cp << ' ' << dp << " - ";
      
      if ('0' <= s[cp] && s[cp] <= '9') {
          print[s[cp]-'0']++;
          //cout << s[cp];
          if (s[cp] == '0') {
              valid[cp] = false;
          } else {
              s[cp]--;
          }
          prv = -1;
      } else if (s[cp] == '<'){
          if (prv != -1) valid[prv] = false;
          prv = cp;
          dp = -1;
      } else {
          if (prv != -1) valid[prv] = false;
          prv = cp;
          dp = +1;
      }
      //cout << endl;
      cp += dp;
    }
    
    
}



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
	int n, q;
    cin >> n >> q;
    cin >> ss;
    s = ss;
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        FILL(print,0);
        execute(a,b);
        REP(i,10) {
            if (i) cout << ' ';
            cout << print[i];
        }
        cout << "\n";
    }
    
	
	return 0;
}

















