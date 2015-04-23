// Paste me into the FileEdit configuration dialog

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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class MagicianTour {
public:
   int bestDifference( vector <string> roads, vector <int> populations ) {

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
			string roads[]            = {"01","10"};
			int populations[]         = {15,20};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string roads[]            = {"0100",
 "1000",
 "0001",
 "0010"};
			int populations[]         = {2,4,2,4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string roads[]            = {"0010",
 "0001",
 "1000",
 "0100"};
			int populations[]         = {2,2,2,2};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string roads[]            = {"000",
 "000",
 "000"};
			int populations[]         = {6,7,15};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string roads[]            = {"0000",
 "0010",
 "0101",
 "0010"};
			int populations[]         = {8,10,15,10};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string roads[]            = {"010",
 "101",
 "010"};
			int populations[]         = {5,1,5};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string roads[]            = {
"01000000000000000000000000000000000",
"10100000000000000000000000000000000",
"01010000000000000000000000000000000",
"00101000000000000000000000000000000",
"00010100000000000000000000000000000",
"00001010000000000000000000000000000",
"00000101000000000000000000000000000",
"00000010100000000000000000000000000",
"00000001010000000000000000000000000",
"00000000101000000000000000000000000",
"00000000010100000000000000000000000",
"00000000001010000000000000000000000",
"00000000000101000000000000000000000",
"00000000000010100000000000000000000",
"00000000000001010000000000000000000",
"00000000000000101000000000000000000",
"00000000000000010100000000000000000",
"00000000000000001010000000000000000",
"00000000000000000100000000000000000",
"00000000000000000000000000000000000",
"00000000000000000000010000000000000",
"00000000000000000000101000000000000",
"00000000000000000000010100000000000",
"00000000000000000000001010000000000",
"00000000000000000000000101000000000",
"00000000000000000000000010100000000",
"00000000000000000000000001010000000",
"00000000000000000000000000101000000",
"00000000000000000000000000010100000",
"00000000000000000000000000001010000",
"00000000000000000000000000000101000",
"00000000000000000000000000000010100",
"00000000000000000000000000000001010",
"00000000000000000000000000000000101",
"00000000000000000000000000000000010"
};
			int populations[]         = {8,15,12,9,12,6,4,6,16,1,15,3,18,15,14,8,6,6,12,13,14,15,17,15,3,8,7,8,3,19,12,9,14,19,9};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string roads[]            = ;
			int populations[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string roads[]            = ;
			int populations[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string roads[]            = ;
			int populations[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
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
