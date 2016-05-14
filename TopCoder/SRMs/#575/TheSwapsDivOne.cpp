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

double id[2222][2222], tr[2222][2222], ax[2222][2222];
    
class TheSwapsDivOne {
public:
    double find( vector <string> sequence, int k ) {
        string s = "";
        REP(i,SIZE(sequence)) s += sequence[i];
        
        int n = SIZE(s);
        if (n == 1) return double(s[0]-'0');
        
        double swp = 1.0 / double(n - 1);
        REP(i, n) REP(j, n) {
            id[i][j] = ((i==j) ? 1.0 : 0.0);
            tr[i][j] = ((i==j) ? 0.0 : swp);
        }
        
        while (k > 0) {
            if (k & 1) {
                REP(i, n) REP(j, n) {
                    ax[i][j] = 0.0;
                    REP(z, n) ax[i][j] += id[i][z] * tr[z][j];
                }
                REP(i, n) REP(j, n) id[i][j] = ax[i][j];
            }
            REP(i, n) REP(j, n) {
                ax[i][j] = 0.0;
                REP(z, n) ax[i][j] += tr[i][z] * tr[z][j];
            }
            REP(i, n) REP(j, n) tr[i][j] = ax[i][j];
            k >>= 1;
        }
        
        double res = 0.0;
        double subst = double(n * (n+1)) / 2.0;
        REP(i, n) {
            REP(j, n) {
                double pick = (double(j+1) * double(n-j)) / subst;
                res += pick * id[i][j] * double(s[i]-'0');
            }
        }
        return res;
        
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
			string sequence[]         = {"4", "77"};
			int k                     = 1;
			double expected__         = 10.0;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string sequence[]         = {"4", "77"};
			int k                     = 47;
			double expected__         = 10.0;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string sequence[]         = {"1", "1", "1", "1", "1", "1", "1"};
			int k                     = 1000000;
			double expected__         = 3.0;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string sequence[]         = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"};
			int k                     = 7;
			double expected__         = 98.3238536775161;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string sequence[]         = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string sequence[]         = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string sequence[]         = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
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


