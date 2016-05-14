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

class FoxAndChess {
public:
    string ableToMove( string begin, string target ) {
        
        int n = SIZE(begin);
        
        REP(i, n) {
            if (begin[i] == target[i]) continue;
            
            if (begin[i] == '.' && target[i] == 'R') {
                return "Impossible";
            } else if (begin[i] == '.' && target[i] == 'L') {
                int j = i;
                while (j < n && begin[j] == '.') j++;
                if (j == n || begin[j] == 'R') return "Impossible";
                begin[j] = '.';
                begin[i] = 'L';
            } else if (begin[i] == 'R' && target[i] == 'L') {
                return "Impossible";
            } else if (begin[i] == 'R' && target[i] == '.') {
                int j = i;
                while (j < n && begin[j] == 'R') j++;
                if (j == n || begin[j] == 'L')  return "Impossible";
                begin[j] = 'R';
                begin[i] = '.';
            } else if (begin[i] == 'L' && target[i] == 'R') {
                return "Impossible";
            } else if (begin[i] == 'L' && target[i] == '.') {
                return "Impossible";
            }
            
        }
        
        return "Possible";
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
			string begin              = "R...";
			string target             = "..R.";
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string begin              = "..R.";
			string target             = "R...";
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string begin              = ".L.R.R.";
			string target             = "L...R.R";
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string begin              = ".L.R.";
			string target             = ".R.L.";
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string begin              = "LRLLRLRLLRLLRLRLRL";
			string target             = "LRLLRLRLLRLLRLRLRL";
			string expected__         = "Possible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string begin              = "L";
			string target             = ".";
			string expected__         = "Impossible";

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string begin              = ;
			string target             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string begin              = ;
			string target             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string begin              = ;
			string target             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndChess().ableToMove(begin, target);
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


