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

vector< int > pt, sk;

int dp[80][110][1<<3];

int solve( int t, int luck, int mask ){
	if( t == 75 || mask == 0 ) return 0;
	int &r = dp[t][luck][mask];
	if( r == -1 ){
		r = 0;
		REP( i, 3 ) if( mask & (1<<i) ){
			FOR( x, 0, min(luck,sk[i]-1) ){
				if( t+sk[i]-x <= 75 )
					r = max( r, pt[i] - (1<<(i+1))*(sk[i]-x) + solve( t+sk[i]-x, luck-x, mask ^ (1<<i) ) );
			}
		}
	}
	return r;
}

class SRMCodingPhase {
public:
   int countScore( vector <int> points, vector <int> skills, int luck ) {
		pt = points;
		sk = skills;
		FOR( tm, 0, 75 ) FOR( lk, 0, luck ) FOR( mk, 0, (1<<3)-1 )
			dp[tm][lk][mk] = -1;
		return solve( 0, luck, (1<<3)-1 );
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
			int points[]              = {250, 500, 1000};
			int skills[]              = {10, 25, 40};
			int luck                  = 0;
			int expected__            = 1310;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int points[]              = {300, 600, 900};
			int skills[]              = {30, 65, 90};
			int luck                  = 25;
			int expected__            = 680;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int points[]              = {250, 550, 950};
			int skills[]              = {10, 25, 40};
			int luck                  = 75;
			int expected__            = 1736;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int points[]              = {256, 512, 1024};
			int skills[]              = {35, 30, 25};
			int luck                  = 0;
			int expected__            = 1216;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int points[]              = {300, 600, 1100};
			int skills[]              = {80, 90, 100};
			int luck                  = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
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
