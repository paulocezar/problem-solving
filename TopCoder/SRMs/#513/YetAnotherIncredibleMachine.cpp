// Paste me into the FileEdit configuration dialog

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

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 MOD = 1000000009;

class YetAnotherIncredibleMachine {
public:
   int countWays( vector <int> platformMount, vector <int> platformLength, vector <int> balls ) {
		sort( ALL(balls) );
		int N = SIZE( platformMount );
		int64 ans = 1LL;
		REP( i, N ){
			int lend = platformMount[i] - platformLength[i];
			int rend = platformMount[i];
			int cur = 0;
			while( lend <= platformMount[i] ){
				if( !(upper_bound( ALL(balls), rend ) - lower_bound( ALL(balls), lend)) ) cur++;
				lend++, rend++;
			}
			ans = ans * cur;
			ans %= MOD;
		}
		return int(ans);
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
			int platformMount[]       = {7};
			int platformLength[]      = {10};
			int balls[]               = {3,4};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int platformMount[]       = {1,4};
			int platformLength[]      = {3,3};
			int balls[]               = {2,7};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int platformMount[]       = {4,4,4};
			int platformLength[]      = {10,9,8};
			int balls[]               = {1,100};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int platformMount[]       = {0};
			int platformLength[]      = {1};
			int balls[]               = {0};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int platformMount[]       = {100, -4215, 251};
			int platformLength[]      = {400, 10000, 2121};
			int balls[]               = {5000, 2270, 8512, 6122};
			int expected__            = 250379170;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int platformMount[]       = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 66, -1, -100, 4, 55, 678, 890, 12, 333, 25};
			int platformLength[]      = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000 };
			int balls[]               = {-1, -2, -3, -10, -11, -23, 0, 4, 6, 7, 453, 234, 543, 123, 567, 334, 6788, 234, 45, 56, 87, 22, 45, 987, 543, 234, 567, 87, 23, 3456, 76, -12, 345, 567, 54, 123, 456, 765, 678, 987, 234, 456, 8976, 54, -12 ,-234, 67, -9, 56 };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 6: {
			int platformMount[]       = {0};
			int platformLength[]      = {10};
			int balls[]               = {-12 };
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int platformMount[]       = ;
			int platformLength[]      = ;
			int balls[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
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
