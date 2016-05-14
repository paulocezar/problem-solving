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

class TheAlmostLuckyNumbersDivTwo {
public:
   int find( int a, int b ) {
		int ans = 0;
		while( a <= b ){
			int aux = a;
			int cr = 0;
			while( aux ){
				if( aux % 10 != 4 && aux % 10 != 7 ) cr++;
				aux /= 10;
			}
			if( cr <= 1 ) ans++;
			a++;
		}
		return ans;
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
			int a                     = 4;
			int b                     = 7;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheAlmostLuckyNumbersDivTwo().find(a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 8;
			int b                     = 19;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheAlmostLuckyNumbersDivTwo().find(a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 28;
			int b                     = 33;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheAlmostLuckyNumbersDivTwo().find(a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 1234;
			int b                     = 4321;
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = TheAlmostLuckyNumbersDivTwo().find(a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int a                     = 1;
			int b                     = 1000000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheAlmostLuckyNumbersDivTwo().find(a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int a                     = ;
			int b                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheAlmostLuckyNumbersDivTwo().find(a, b);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheAlmostLuckyNumbersDivTwo().find(a, b);
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
