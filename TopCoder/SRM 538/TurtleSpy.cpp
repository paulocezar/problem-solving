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

class TurtleSpy {
public:
	double maxDistance( vector <string> commands ) {
		int n = SIZE(commands);
		int fwd = 0, bwd = 0;
		vector< int > turns;
		
		REP( i, n ){
			istringstream in(commands[i]);
			string cmd; int x;
			in >> cmd >> x;
			if( cmd[0] == 'l' ) turns.PB(360-x);
			else if( cmd[0] == 'r' ) turns.PB(x);
			else if( cmd[0] == 'f' ) fwd += x;
			else bwd += x;
		}
		
		int ang = SIZE(turns);
		int has[2][360];
		REP( i, 360 ) has[0][i] = 0;
		has[0][0] = 1;
		
		int old = 0, cur = 1;
	
		while( ang ){
			ang--;
			REP( i, 360 ) has[cur][i] = has[old][i];
			
			REP( i, 360 ) if( has[old][i] ){
				has[cur][(i+turns[ang])%360] = 1;
			}
			
			old = !old;
			cur = !cur;
		}
		
		int dif = 0;
		while( !has[old][180-dif] && !has[old][(180+dif)%360] ) dif++;
		
		double angle = ((dif)*acos(-1.0))/180.0;
		
		double x = (1.0*fwd) + cos( angle )*double(bwd);
		double y = sin( angle )*double(bwd);
		return sqrt(x*x + y*y);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string commands[]         = {"forward 100", "backward 100", "left 90" };
			double expected__         = 141.4213562373095;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string commands[]         = {"left 45", "forward 100", "right 45", "forward 100"};
			double expected__         = 200.0;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string commands[]         = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" };
			double expected__         = 40.58520737741619;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string commands[]         = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string commands[]         = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string commands[]         = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TurtleSpy().maxDistance(vector <string>(commands, commands + (sizeof commands / sizeof commands[0])));
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
