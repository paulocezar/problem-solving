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

char nextchar(istream& s) {
  char c = 0;
  char ret = '?';
  s >> c;
  
  if(c < 0x80) ret = c;
  else if(c < 0xE0)
  {
    s >> c;
    ret = '+';
  }
  else if(c < 0xF0)
  {
    s >> c;
    s >> c;
    ret = '+';
  }
  else if(c < 0xF8)
  {
     s >> c;
     s >> c;
     s >> c;
     ret = '+';
  }

  return ret;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t; cin.ignore();
    
    FOR(tc, 1, t) {
        
        string ss;
        while (ss.empty()) getline(cin, ss);
        
        istringstream in(ss);
        int a = 0, b = 0;
        
        char c = nextchar(in);
        while (true) {
            if (isdigit(c)) {
                a = 10*a + (c-'0');
                c = nextchar(in);
            } else { 
                while (!isdigit(c) && c != '\0') c = nextchar(in);
                break;
            }
        }
     
        while (c != '\0') {
            if (isdigit(c)) b = 10*b + (c-'0');
            c = nextchar(in);
        }
        
        cout << "Case " << tc << ": " << (0.5 * a + 0.05 * b) << "\n";
    }
	 
	return 0;
}

















