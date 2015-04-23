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

string tostr(int64 x) {
    ostringstream ot;
    ot << x;
    return ot.str();
}

uint64 toint(string x) {
    uint64 res = 0ULL;
    REP(i,SIZE(x)) res = 10ULL*res + uint64(x[i]-'0');
    return res;
}

#define NTRNS 5
uint64 put[NTRNS] = {0ULL,1ULL,2ULL,5ULL,8ULL};
uint64 rput[NTRNS] = {0ULL,1ULL,5ULL,2ULL,8ULL};
uint64 pw[20];

class MirrorNumber {
public:
    int count( string A, string B ) {
        uint64 a = toint(A);
        uint64 b = toint(B);
        
        pw[0] = 1ULL;
        FOR(i,1,19) pw[i] = 10ULL * pw[i-1];
        
        queue< pair<uint64,int> > q;
        
        q.push(MP(0ULL,1));
        q.push(MP(1ULL,1));
        q.push(MP(8ULL,1));
        
        q.push(MP(00ULL,2));
        q.push(MP(11ULL,2));
        q.push(MP(25ULL,2));
        q.push(MP(52ULL,2));
        q.push(MP(88ULL,2));
        
        vector<uint64> mirror;
        while (!q.empty()){
            uint64 val = q.front().first;
            int digs = q.front().second;
            q.pop();
            
            if (val > b) continue;
            if (((val/10ULL)*10ULL) != val) mirror.PB(val);
            if (digs+2 > SIZE(B)) continue;
            
            REP(i,NTRNS) {
                q.push( MP((pw[digs]*put[i] + val)*10ULL + rput[i],digs+2));
            }            
        }
        
        sort(ALL(mirror));
        if (a == 0ULL) return (upper_bound(ALL(mirror), b)-1) - mirror.begin() + 2;
        else return (upper_bound(ALL(mirror),b)-1) - (upper_bound(ALL(mirror),a-1ULL)) + 1;
        
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
			string A                  = "0";
			string B                  = "10";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MirrorNumber().count(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string A                  = "0";
			string B                  = "100";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MirrorNumber().count(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string A                  = "143";
			string B                  = "23543";
			int expected__            = 54;

			clock_t start__           = clock();
			int received__            = MirrorNumber().count(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 3: {
			string A                  = "0";
			string B                  = "1000000000000000000";
			int expected__            = 3124999;

			clock_t start__           = clock();
			int received__            = MirrorNumber().count(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 4: {
			string A                  = "1";
			string B                  = "10";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MirrorNumber().count(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 5: {
			string A                  = "200000000000000004";
			string B                  = "200000000000000005";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MirrorNumber().count(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
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


