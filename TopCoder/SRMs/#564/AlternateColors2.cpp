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

int n, k;

bool calc[3][8][100001];
int64 dp[3][8][100001];

int64 solve(int nxt, int has, int pos, int lvl = 0) {
    
    if (pos == n+1) return (has==0);
    if (!(has & (1<<nxt))) return 0LL;
    
    if (calc[nxt][has][pos]) return dp[nxt][has][pos];
    calc[nxt][has][pos] = true;
    
    int64 &res = dp[nxt][has][pos];
    res = 0;
    
    if (pos == k && nxt) return res;
    
    if (has & (1<<nxt)) {
        
        int nnxt = (nxt+1)%3;
        while (!(has & (1<<nnxt))) nnxt = (nnxt+1)%3;
        
        //REP(i, lvl) cout << "\t";
        //cout << "put " << nxt << endl;
        
        res += solve(nnxt, has, pos+1, lvl+1);        
        //if (pos != n) {
            res += solve(nnxt, has ^ (1<<nxt), pos+1, lvl+1);        
            //}
    }
    
    return res;
}

class AlternateColors2 {
public:
    long long countWays(int _n, int _k) {
        n = _n;
        k = _k;
        
        FILL(calc,false);
        int64 res = 0;
        res += solve(0, 1|2|4 , 1);
        res += solve(0, 1|2 , 1);
        res += solve(0, 1|4 , 1);
        res += solve(0, 1 , 1);        
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int n                     = 1;
			int k                     = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int k                     = 3;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
        
		case 2: {
			int n                     = 6;
			int k                     = 4;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 6;
			int k                     = 1;
			long long expected__      = 21;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 1000;
			int k                     = 2;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 100000;
			int k                     = 100000;
			long long expected__      = 1666700000;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
        
		// custom cases

/*      case 6: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
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


