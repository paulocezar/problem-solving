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


class EquilibriumPoints {
public:
	vector <double> getPoints( vector <int> x, vector <int> m ) {
		vector< double > ans;
	
	int N = SIZE(x);
	FOR( i, 1, N-1 ){
		double lo = x[i-1], hi = x[i];
		
		while( fabs(lo-hi) > EPS ){
			
			double mid = (lo+hi)/2.0;
			double acmL = 0.0, acmR = 0.0;
			
			REP( j, i )
				acmL += ( m[j]/SQR(mid-x[j]) );
			
			FOR( j, i, N-1 )
				acmR += ( m[j]/SQR(mid-x[j]) );
			
			if( acmL < acmR )
				hi = mid;
			else
				lo = mid;
			
		}
		ans.PB( lo );
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	static bool topcoder_fequ(const vector<double> &a, const vector<double> &b) { if (a.size() != b.size()) return false; for (size_t i=0; i<a.size(); ++i) if (!topcoder_fequ(a[i], b[i])) return false; return true; }
	double moj_relative_error(const vector<double> &expected, const vector<double> &result) { double ret = 0.0; for (size_t i=0; i<expected.size(); ++i) { ret = max(ret, moj_relative_error(expected[i], result[i])); } return ret; }
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <double> &expected, const vector <double> &received, clock_t elapsed) { 
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
			int x[]                   = {1, 2};
			int m[]                   = {1, 1};
			double expected__[]       = {1.5 };

			clock_t start__           = clock();
			vector <double> received__ = EquilibriumPoints().getPoints(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {1, 2};
			int m[]                   = {1, 1000};
			double expected__[]       = {1.0306534300317156 };

			clock_t start__           = clock();
			vector <double> received__ = EquilibriumPoints().getPoints(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {1, 2, 3};
			int m[]                   = {1, 2, 1};
			double expected__[]       = {1.4060952084922507, 2.5939047915077493 };

			clock_t start__           = clock();
			vector <double> received__ = EquilibriumPoints().getPoints(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {2, 3, 5, 7};
			int m[]                   = {3, 2, 7, 5};
			double expected__[]       = {2.532859446114924, 3.7271944335152813, 6.099953640852538 };

			clock_t start__           = clock();
			vector <double> received__ = EquilibriumPoints().getPoints(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int m[]                   = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = EquilibriumPoints().getPoints(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int m[]                   = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = EquilibriumPoints().getPoints(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int m[]                   = ;
			double expected__[]       = ;

			clock_t start__           = clock();
			vector <double> received__ = EquilibriumPoints().getPoints(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(m, m + (sizeof m / sizeof m[0])));
			return verify_case(casenum, vector <double>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
