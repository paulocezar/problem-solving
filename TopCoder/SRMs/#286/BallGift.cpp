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

int64 wins[33][16][16][16][16];
bool seen[33][16][16][16];

class BallGift {
public:
	void play( int N, int G, int R, int B ){
		if( seen[N][G][R][B] ) return;
		seen[N][G][R][B] = true;
		if( G+R+B == 0 ){
			wins[N][G][R][B][0] += 1LL;
			return;
		}
		if( G ){
			play( N, G-1, R, B );
			REP( i, N ) wins[ N ][ G ][ R ][ B ][ i ] += wins[ N ][ G-1 ][ R ][ B ][ (i-1+N)%N ];
		}
		if( R ){
			play( N, G, R-1, B );
			REP( i, N ) wins[ N ][ G ][ R ][ B ][ i ] += wins[ N ][ G ][ R-1 ][ B ][ N-1-i ]; 
		}
		if( B ){
			play( N-1, G, R, B-1 );
			FOR( i, 1, N-1 ) wins[ N ][ G ][ R ][ B ][ i ] += wins[ N-1 ][ G ][ R ][ B-1 ][ i-1 ];
		}
	}
	int bestPosition( int players, int green, int red, int black ) {
		FILL( wins, 0 ); FILL( seen, false );
		play( players, green, red, black );
		int64 ans = 0;
		REP( i, players ) ans = MAX( ans, wins[players][green][red][black][i] );
		REP( i, players ) if( wins[players][green][red][black][i] == ans ) return i;
		return 0;
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
			int players               = 4;
			int green                 = 3;
			int red                   = 0;
			int black                 = 0;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int players               = 4;
			int green                 = 0;
			int red                   = 1;
			int black                 = 0;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int players               = 4;
			int green                 = 1;
			int red                   = 1;
			int black                 = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int players               = 4;
			int green                 = 1;
			int red                   = 1;
			int black                 = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int players               = 4;
			int green                 = 2;
			int red                   = 2;
			int black                 = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int players               = ;
			int green                 = ;
			int red                   = ;
			int black                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int players               = ;
			int green                 = ;
			int red                   = ;
			int black                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int players               = ;
			int green                 = ;
			int red                   = ;
			int black                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallGift().bestPosition(players, green, red, black);
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
