#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct FenceRepairing{
	
	double calculateCost(vector <string> boards){
		
		string fence = "";
		REP( i, SIZE(boards) ) fence += boards[i];
		
		vector< int > need;
		REP( i, SIZE(fence) ) if( fence[i] == 'X' )
			need.PB( i );
		
		int N = SIZE(need);
		double dp[N];
		REP( i, N ){
			dp[i] = 1.0 + ((i)?(dp[i-1]):(.0));
			int ii = i-1;
			while( ii >= 0 ){
				dp[i] = min( dp[i], (ii?(dp[ii-1]):(.0)) + sqrt(need[i]-need[ii]+1) );
				ii--;
			}
		}
		return dp[N-1];
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string boards[]           = {"X.X...X.X"};
			double expected__         = 3.0;

			clock_t start__           = clock();
			double received__         = FenceRepairing().calculateCost(vector <string>(boards, boards + (sizeof boards / sizeof boards[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string boards[]           = {"X.X.....X"};
			double expected__         = 2.732050807568877;

			clock_t start__           = clock();
			double received__         = FenceRepairing().calculateCost(vector <string>(boards, boards + (sizeof boards / sizeof boards[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string boards[]           = {"X.......", "......XX", ".X......", ".X...X.."};
			double expected__         = 5.0;

			clock_t start__           = clock();
			double received__         = FenceRepairing().calculateCost(vector <string>(boards, boards + (sizeof boards / sizeof boards[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string boards[]           = {".X.......X", "..........", "...X......", "...X..X...", "..........",
 "..........", "..X....XX.", ".........X", "XXX", ".XXX.....X"};
			double expected__         = 9.591663046625438;

			clock_t start__           = clock();
			double received__         = FenceRepairing().calculateCost(vector <string>(boards, boards + (sizeof boards / sizeof boards[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string boards[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FenceRepairing().calculateCost(vector <string>(boards, boards + (sizeof boards / sizeof boards[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string boards[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FenceRepairing().calculateCost(vector <string>(boards, boards + (sizeof boards / sizeof boards[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string boards[]           = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = FenceRepairing().calculateCost(vector <string>(boards, boards + (sizeof boards / sizeof boards[0])));
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

// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
