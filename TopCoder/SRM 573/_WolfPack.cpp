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

const int64 mod = 1000000007LL;

int64 fat[100001];
int64 ifat[100001];

int64 mpw(int64 a, int64 b) {
    int64 res = 1LL;
    while (b > 0LL) {
        if (b & 1LL) { res *= a; res %= mod; }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

int64 comb(int n, int k) {
    return ((((fat[n] * ifat[k])%mod) * ifat[n-k])%mod);
}

class WolfPack {
public:
    int calc( vector <int> x, vector <int> y, int m ) {
        int N = SIZE(x);
        
        fat[0] = 1LL;
        ifat[0] = 1LL;
        
        FOR(i,1,m) {
            fat[i] = (int64(i) * fat[i-1]) % mod;
            ifat[i] = mpw(fat[i],mod-2LL);
        }
        
        map< pair<int,int>, int > cnt;
        
        REP(i, N) {
            cnt[MP(x[i],y[i]+m)]++;
            cnt[MP(x[i],y[i]-m)]++;
            cnt[MP(x[i]+m,y[i])]++;
            cnt[MP(x[i]-m,y[i])]++;
        }
        
        int dx = 1;
        while (dx < m) {
            int dy = m-dx;
            REP(i, N) {
                cnt[MP(x[i]+dx,y[i]+dy)]++;
                cnt[MP(x[i]+dx,y[i]-dy)]++;
                cnt[MP(x[i]-dx,y[i]+dy)]++;
                cnt[MP(x[i]-dx,y[i]-dy)]++;
            }
            dx++;
        }
        int64 res = 0LL;
        
        FORIT(point,cnt) {
            if (point->second == N) {
                int px = (point->first).first;
                int py = (point->first).second;
                
                int64 cur = 1LL;
                REP(i, N) {
                    int dx = abs(px-x[i]);
                    int dy = abs(py-y[i]);
                    int fr = m - dx - dy;
                    cur *= ((comb(m,dy))%mod); cur %= mod;
                    
                }
                res += cur;
            }
        }
        
        
        return int(res);
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
			int x[]                   = {3,5};
			int y[]                   = {0,0};
			int m                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,0};
			int y[]                   = {0,1};
			int m                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0,2,4};
			int y[]                   = {0,0,0};
			int m                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {7,8};
			int y[]                   = {8,7};
			int m                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {-2,-2,-2,0,0,0,2,2,2};
			int y[]                   = {-2,0,2,-2,0,2,-2,0,2};
			int m                     = 1000;
			int expected__            = 387540818;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolfPack().calc(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), m);
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


