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

bool calc[55][55];
double mem[55][55];


double solve(vector<int> &L, int lo, int hi) {
    
    int N = hi - lo + 1;
    if (N < 2) return 0.0;
    
    double &res = mem[lo][hi];
    if (calc[lo][hi]) return res;
    calc[lo][hi] = true;
    res = 0.0;
    
    double p = 1.0 / double(N);
    
    for (int pivot = lo; pivot <= hi; ++pivot) {
        
        int pos = 0;
        while (L[pos] != pivot) ++pos;
        
        int cost = 0;
        REP(i,pos) {
            if (lo <= L[i] && L[i] <= hi && L[i] > pivot) ++cost;
        }
        
        FOR(i,pos+1,SIZE(L)-1) {
            if (lo <= L[i] && L[i] <= hi && L[i] < pivot) ++cost;
        }
        
        res += p * (cost + solve(L,lo,pivot-1) + solve(L,pivot+1,hi));
        
    }
    return res;
}

class QuickSort {
public:
    double getEval( vector <int> L ) {
        int n = SIZE(L);
        map<int,int> ax;
        REP(i,n) ax[ L[i] ] = 0;
        memset(calc,false,sizeof(calc));
        n = 0;
        FORIT(el,ax) el->second = ++n;
        REP(i,n) L[i] = ax[ L[i] ];
        return solve(L,1,n);
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
			int L[]                   = {1,2,3,4,5};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = QuickSort().getEval(vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int L[]                   = {1,2,4,3,5,6};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = QuickSort().getEval(vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int L[]                   = {3,2,1};
			double expected__         = 2.6666666666666665;

			clock_t start__           = clock();
			double received__         = QuickSort().getEval(vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int L[]                   = {50,40,30,20,10,15,25,35,45};
			double expected__         = 11.07698412698413;

			clock_t start__           = clock();
			double received__         = QuickSort().getEval(vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int L[]                   = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = QuickSort().getEval(vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int L[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = QuickSort().getEval(vector <int>(L, L + (sizeof L / sizeof L[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int L[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = QuickSort().getEval(vector <int>(L, L + (sizeof L / sizeof L[0])));
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


