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

class BlurredDartboard {
public:
	int minThrows( vector <int> points, int P ) {
		int N = SIZE(points);
		int blurred = N;
		int blursum = (N * (N+1)) / 2;
		int mx = 0;
				
		bool seen[N+1];
		memset( seen, false, sizeof(seen) );
		REP( i, N ) if( points[i] != 0 ){
			seen[ points[i] ] = true;
			blurred--;
			blursum -= points[i];
			mx = max( mx, points[i] );
		}
				
		int ans = P;
		int lo = 1, hi = P;
		
		while( lo <= hi ){
			int mid = (lo+hi)/2;
				
			int64 blind = 0;
			if( blurred ) blind = mid / blurred;
			blind = blind * int64(blursum);

			int rem = 0;
			if( blurred ) rem = mid % blurred;
			else rem = mid;
			
			int64 opt1 = int64(rem) * int64(mx);
			int64 opt2 = 0;
			
			if( blurred ){
				while( rem ){
					FOR( i, 1, N ) if( !seen[i] && rem ){
						opt2 += i; rem--;
					}
				}	
			}
			
			blind += max( opt1, opt2 );
			
			int64 greedy = int64(mid) * int64(mx);
			
			int64 best = max( greedy, blind );
			
			if( best >= int64(P) ){
				ans = mid;
				hi = mid-1;
			} else {
				lo = mid+1;
			}
			
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
			int points[]              = {0, 3, 4, 0, 0};
			int P                     = 8;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int points[]              = {0, 0, 0, 0, 0};
			int P                     = 15;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int points[]              = {4, 7, 8, 1, 3, 2, 6, 5};
			int P                     = 2012;
			int expected__            = 252;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int points[]              = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
			int P                     = 2012;
			int expected__            = 307;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int points[]              = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
			int P                     = 1000000000;
			int expected__            = 84656087;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int points[]              = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int points[]              = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int points[]              = ;
			int P                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BlurredDartboard().minThrows(vector <int>(points, points + (sizeof points / sizeof points[0])), P);
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
