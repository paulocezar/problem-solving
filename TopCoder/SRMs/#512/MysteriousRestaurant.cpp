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

int cost( char c ){ if( '0' <= c && c <= '9' ) return c-'0'; if( 'A' <= c && c <= 'Z' ) return 10+c-'A'; return 36+c-'a'; }

int nd[50][7][8];
int types, mony, days_open;

bool cango( int day ){
	int week = day/7; 
	int until = day%7;
	int spent = 0;
	REP( i, until ){
		int mn = INF;
		REP( tp, types ) mn = MIN( mn, nd[tp][i][week] );
		spent += mn;
		if( spent > mony ) return false;    
	}
	if( week ){
		FOR( i, until, 7 ){
			int mn = INF;
			REP( tp, types ) mn = MIN( mn, nd[tp][i][week-1] );
			spent += mn;
			if( spent > mony ) return false;
		}
	}
	
	return true;
}

class MysteriousRestaurant {
public:
   int maxDays( vector <string> prices, int budget ) {
		mony = budget;
		types = SIZE(prices[0]);
		days_open = SIZE(prices);
		
		REP( i, types ) REP( j, 7 ) REP( k, 8 ) nd[i][j][k] = INF;
		
		REP( i, types ) REP( j, MIN(7, days_open) ){
			nd[i][j][0] = cost( prices[j][i] );
			int nxt = j+7;
			while( nxt < days_open ){
				nd[i][j][nxt/7] = nd[i][j][(nxt/7)-1] + cost( prices[nxt][i] );
				nxt += 7;
			}
		}
		
		int ans = days_open;
		while( !cango( ans ) ) ans--;
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
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06"};
			int budget                = 13;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06", "91"};
			int budget                = 20;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string prices[]           = {"SRM", "512"};
			int budget                = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string prices[]           = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
			int budget                = 256;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
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
