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

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class CirclesGame {
public:
    string whoCanWin( vector <int> x, vector <int> y, vector <int> r ) {
        
        int n = SIZE(x);
        int xr = 0;
        
        REP(i, n) {
            int cnt = 1;
            int inside = 0;
            REP(j, n) {
                if (i == j) continue;
                int dx = x[i]-x[j];
                int dy = y[i]-y[j];
                int dist = dx*dx + dy*dy;
                if (dist <= r[j]*r[j]) {
                    if (dist == 0) {
                      if (r[i] < r[j]) cnt++;  
                      else inside++;
                    } else cnt++;
                } else {
                    if (dist <= r[i]*r[i]) inside++;    
                }
            }
            cout << inside << " " << cnt << "\n";
            if (!inside) xr ^= cnt;
        }
        
        if (xr) return "Alice";
        else return "Bob";
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int x[]                   = {0};
			int y[]                   = {0};
			int r[]                   = {1};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0, 3};
			int y[]                   = {0, 0};
			int r[]                   = {1, 1};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0, 0, 5};
			int y[]                   = {0, 0, 0};
			int r[]                   = {1, 2, 1};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0, 0, 0, 10, 10, 20};
			int y[]                   = {0, 0, 0, 0, 0, 0};
			int r[]                   = {1, 2, 3, 1, 2, 1};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {10,20,30,40,50,60,70,80};
			int y[]                   = {8,7,6,5,4,3,2,1};
			int r[]                   = {2,2,2,2,2,2,2,2};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {0, 3, 6, 9, 12, -4747, -4777};
			int y[]                   = {-5858, -5858, -5858, -5858, -5858, 777, 777};
			int r[]                   = {58, 1, 1, 1, 1, 44, 8};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int x[]                   = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097};
			int y[]                   = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746};
			int r[]                   = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int x[]                   = {0,0,2};
			int y[]                   = {0,0,0};
			int r[]                   = {100,1,1};
			string expected__         = "NAOSEI";

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			int r[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x[]                   = ;
			int y[]                   = ;
			int r[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CirclesGame().whoCanWin(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE


