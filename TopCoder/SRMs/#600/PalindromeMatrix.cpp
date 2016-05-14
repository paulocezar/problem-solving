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

int palindromic_line;

int solve(int i, int j, int mustbe, int columnCount) {
    if (2*i == N) {
        min(solve(0, j+1, 0, columnCount),
            min(solve(0, j+1, 1, columnCount-1),
                min(solve(0, j+1, 2, columnCount-1),
                    solve(0, j+1, 3, columnCount-2))));
    }
    if (2*j == M) {
        if (columnCount == 0) return 0;
        return 2e9;
    }
    
    int res = solve(i+1, j, mustbe, columnCount);
    
    if (palindromic_line & (1<<i)) {
        
    } else if (palindromic_line & (1<<(N-i-1))) {
        
    }
    
    return res;
}

class PalindromeMatrix {
public:
    int minChange( vector <string> A, int rowCount, int columnCount ) {
        
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string A[]                = {"0000"
,"1000"
,"1100"
,"1110"};
			int rowCount              = 2;
			int columnCount           = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string A[]                = {"0000"
,"1000"
,"1100"
,"1110"};
			int rowCount              = 3;
			int columnCount           = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string A[]                = {"01"
,"10"};
			int rowCount              = 1;
			int columnCount           = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string A[]                = {"1110"
,"0001"};
			int rowCount              = 0;
			int columnCount           = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string A[]                = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"};
			int rowCount              = 2;
			int columnCount           = 3;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string A[]                = {"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"};
			int rowCount              = 5;
			int columnCount           = 9;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string A[]                = {"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"};
			int rowCount              = 6;
			int columnCount           = 8;
			int expected__            = 31;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
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


