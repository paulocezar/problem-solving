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

class VolumeGuess {
public:
	int correctVolume( vector <string> queries, int numberOfBoxes, int ithBox ) {
		
		vector< int > box;
		set< int > seen;
		
		int n = SIZE(queries);
		
		int x[n], y[n], r[n];
		
		REP( i, n ){
			REP( j, SIZE(queries[i])) if( queries[i][j] == ',' ) queries[i][j] = ' ';
			istringstream in(queries[i]);
			in >> x[i] >> y[i] >> r[i];
			x[i]--; y[i]--;
			if( seen.insert(r[i]).second ) box.PB( r[i] );
		}
		
		sort(ALL(box));
		box.PB( box.back()+1 );
		
		do{
			
			REP( i, n ) if( min(box[x[i]],box[y[i]]) != r[i] ) goto next;
			break;
			
			next:;
		} while( next_permutation(ALL(box)) );
		
		return box[ithBox-1];
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
			string queries[]          = {"1,2,10","1,3,10","2,3,20"};
			int numberOfBoxes         = 3;
			int ithBox                = 1;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = VolumeGuess().correctVolume(vector <string>(queries, queries + (sizeof queries / sizeof queries[0])), numberOfBoxes, ithBox);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string queries[]          = {"1,02,10","2,3,010","1,3,20"};
			int numberOfBoxes         = 3;
			int ithBox                = 2;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = VolumeGuess().correctVolume(vector <string>(queries, queries + (sizeof queries / sizeof queries[0])), numberOfBoxes, ithBox);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string queries[]          = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"};
			int numberOfBoxes         = 4;
			int ithBox                = 1;
			int expected__            = 31;

			clock_t start__           = clock();
			int received__            = VolumeGuess().correctVolume(vector <string>(queries, queries + (sizeof queries / sizeof queries[0])), numberOfBoxes, ithBox);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string queries[]          = {"1,2,31","1,3,9","1,4,31","2,4,32","3,4,9","3,2,9"};
			int numberOfBoxes         = 4;
			int ithBox                = 3;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = VolumeGuess().correctVolume(vector <string>(queries, queries + (sizeof queries / sizeof queries[0])), numberOfBoxes, ithBox);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string queries[]          = ;
			int numberOfBoxes         = ;
			int ithBox                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VolumeGuess().correctVolume(vector <string>(queries, queries + (sizeof queries / sizeof queries[0])), numberOfBoxes, ithBox);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string queries[]          = ;
			int numberOfBoxes         = ;
			int ithBox                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VolumeGuess().correctVolume(vector <string>(queries, queries + (sizeof queries / sizeof queries[0])), numberOfBoxes, ithBox);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string queries[]          = ;
			int numberOfBoxes         = ;
			int ithBox                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = VolumeGuess().correctVolume(vector <string>(queries, queries + (sizeof queries / sizeof queries[0])), numberOfBoxes, ithBox);
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
