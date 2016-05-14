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

class StringsAndTabs {
public:
    vector <string> transformTab( vector <string> tab, vector <int> stringsA, vector <int> stringsB, int d ) {
        
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string tab[]              = {"-----------------",
 "-------------0-1-",
 "---------0-2-----",
 "---0-2-3---------",
 "-3---------------",
 "-----------------"};
			int stringsA[]            = {28,23,19,14,9,4};
			int stringsB[]            = {9};
			int d                     = 0;
			string expected__[]       = {"-3-5-7-8-A-C-E-F-" };

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string tab[]              = {"-4457754-20024422-4457754-20024200-"};
			int stringsA[]            = {0};
			int stringsB[]            = {28,23,19,14,9,4};
			int d                     = 12;
			string expected__[]       = {"-----------------------------------", "-----------------------------------", "----00---------------00------------", "-223--32-0--02200-223--32-0--020---", "----------33---------------33---33-", "-----------------------------------" };

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string tab[]              = {"-----------------------------------",
 "-----------------------------------",
 "----00---------------00------------",
 "-223--32-0--02200-223--32-0--020---",
 "----------33---------------33---33-",
 "-----------------------------------"};
			int stringsA[]            = {28,23,19,14,9,4};
			int stringsB[]            = {33,28,24,31};
			int d                     = 12;
			string expected__[]       = {"-----------------------------------", "-001--10-----00---001--10-----0----", "---------2002--22---------2002-200-", "----00---------------00------------" };

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string tab[]              = {"-----0------2-2222--0-------0-",
 "----0------2---222---5-----55-",
 "---0------2-----22----9---999-",
 "--0------2-------2-----E-EEEE-",
 "-0------2---------------------",
 "0------2----------------------"};
			int stringsA[]            = {28,23,19,14,9,4};
			int stringsB[]            = {33,28,28};
			int d                     = 12;
			string expected__[]       = {"xxx-27-xx-049-999x--7777-777x-", "xxx----xx-------5x---------Cx-", "xxx3---xx0-----99x--------CCx-" };

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string tab[]              = {"012345---------",
 "---------UVWXYZ"};
			int stringsA[]            = {-2,2};
			int stringsB[]            = {0};
			int d                     = 0;
			string expected__[]       = {"xx0123---WXYZxx" };

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string tab[]              = {"0220----02--",
 "75--75----57",
 "------B9B9B9",
 "--242424----"};
			int stringsA[]            = {33,28,24,31};
			int stringsB[]            = {33,28,28};
			int d                     = 0;
			string expected__[]       = {"222222222222", "------------", "555555555555" };

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string tab[]              = ;
			int stringsA[]            = ;
			int stringsB[]            = ;
			int d                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string tab[]              = ;
			int stringsA[]            = ;
			int stringsB[]            = ;
			int d                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string tab[]              = ;
			int stringsA[]            = ;
			int stringsB[]            = ;
			int d                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = StringsAndTabs().transformTab(vector <string>(tab, tab + (sizeof tab / sizeof tab[0])), vector <int>(stringsA, stringsA + (sizeof stringsA / sizeof stringsA[0])), vector <int>(stringsB, stringsB + (sizeof stringsB / sizeof stringsB[0])), d);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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


