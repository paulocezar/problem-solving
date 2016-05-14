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

class TheJackpotDivTwo {
public:
   vector <int> find( vector <int> money, int jackpot ) {
		priority_queue< int > q;
		REP( i, SIZE(money) ) q.push( -money[i] );
		while( jackpot ){
			int u = -q.top(); q.pop();
			q.push( -( u+1 ) );
			jackpot--;
		}
		int i = 0;
		while( !q.empty() ){ money[i++] = -q.top(); q.pop(); }
		return money;
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

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int money[]               = {1, 2, 3, 4};
			int jackpot               = 2;
			int expected__[]          = {2, 3, 3, 4 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int money[]               = {4, 7};
			int jackpot               = 1;
			int expected__[]          = {5, 7 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int money[]               = {1};
			int jackpot               = 100;
			int expected__[]          = {101 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int money[]               = {21, 85, 6, 54, 70, 100, 91, 60, 71};
			int jackpot               = 15;
			int expected__[]          = {21, 21, 54, 60, 70, 71, 85, 91, 100 };

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int money[]               = ;
			int jackpot               = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int money[]               = ;
			int jackpot               = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int money[]               = ;
			int jackpot               = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheJackpotDivTwo().find(vector <int>(money, money + (sizeof money / sizeof money[0])), jackpot);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
