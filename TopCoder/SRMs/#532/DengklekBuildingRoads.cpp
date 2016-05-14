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

const int MOD = 1000000007;
int dp[8][30][30][1<<9];

int NN, MM, KK;

int solve( int dist, int pos, int built, int mask ){
	
	if( built == MM ) return (mask == 0);
	if( pos == NN ) return 0;
	if( dist == KK ) return ((mask&1)?(0):solve( 0, pos+1, built, mask >> 1 ));
	
	if( dp[dist][pos][built][mask] != -1 ) return  dp[dist][pos][built][mask];
	
	int ans = solve( dist+1, pos, built, mask );
	
	if( 0 <= (pos+dist+1) && (pos+dist+1) < NN ){
		int nxt = mask;
		int trans = (1 | (1<<(dist+1)));
		int cur = 1;
		while( built+cur <= MM ){
			nxt ^= trans;
			ans += solve( dist+1, pos, built+cur, nxt );
			ans %= MOD;
			cur++;
		}
	}
	
	 dp[dist][pos][built][mask] = ans;
	return ans;
}

class DengklekBuildingRoads {
public:
	int numWays( int N, int M, int K ) {
		NN = N; MM = M; KK = K;
		REP( i, K ) REP( j, N ) REP( k, M ) REP( l, 1<<(K+1) ) dp[i][j][k][l] = -1;
		return solve( 0, 0, 0, 0 );
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
			int N                     = 3;
			int M                     = 4;
			int K                     = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 4;
			int M                     = 3;
			int K                     = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			int M                     = 1;
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			int M                     = 0;
			int K                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 10;
			int M                     = 20;
			int K                     = 5;
			int expected__            = 26964424;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int N                     = 30;
			int M                     = 30;
			int K                     = 8;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekBuildingRoads().numWays(N, M, K);
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
