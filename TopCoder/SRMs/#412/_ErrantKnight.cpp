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

bool calc[4004][4004];
bool res[4004][4004];

int cdx[2] = {2,1};
int cdy[2] = {1,2};

bool win(int dx, int dy) {
    
    if (dx > dy) swap(dx,dy);
    bool &ans = res[dx][dy];
    if (calc[dx][dy]) return ans;
    calc[dx][dy] = true;
    ans = false;
    

    REP(dir,2) {
        
        int odx = dx;
        int ody = dy;
        
        int ndx = odx - cdx[dir];
        int ndy = ody - cdy[dir];
        
        while ((ndx*ndx + ndy*ndy) < (odx*odx + ody*ody)) {
            if (!win(abs(ndx), abs(ndy))) { return (ans = true); }
            odx = ndx - cdx[dir];
            ody = ndy - cdy[dir];
            swap(odx,ndx);
            swap(ody,ndy);
        }
        
    }
    
    return ans;    
}

class ErrantKnight {
public:
    string whoWins( vector <int> x, vector <int> y ) {
        string ret = "";
        
        REP(i,SIZE(x)) 
            if (win(abs(x[i]),abs(y[i]))) ret += "W";
            else ret += "B";
        
        return ret;
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
			int x[]                   = {1,1,2,2,9,3};
			int y[]                   = {0,1,0,1,5,3};
			string expected__         = "BWWWWB";

			clock_t start__           = clock();
			string received__         = ErrantKnight().whoWins(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,7};
			int y[]                   = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7};
			string expected__         = "BWBBBBBWWWWWWWWWWWWWWWWBWWWWWWWBWWWWWWWBWWWWWWWWWB";

			clock_t start__           = clock();
			string received__         = ErrantKnight().whoWins(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-10};
			int y[]                   = {0};
			string expected__         = "B";

			clock_t start__           = clock();
			string received__         = ErrantKnight().whoWins(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ErrantKnight().whoWins(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ErrantKnight().whoWins(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ErrantKnight().whoWins(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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


