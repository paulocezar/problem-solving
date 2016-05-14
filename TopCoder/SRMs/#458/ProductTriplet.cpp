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

int64 get(int x0, int y1, int y2, int z1, int z2) {
    z1 = max(z1, x0*x0+1);
    if (z1 > z2) return 0;
    int a = max((z1+x0-1)/x0, y1);
    int b = min(z2/x0, y2);
    if (a <= b) return (b-a+1);
    return 0;
}

class ProductTriplet {
public:
    long long countTriplets( int minx, int maxx, int miny, int maxy, int minz, int maxz ) {
        int64 res = 0LL;
        
        int a = max(minx, miny);
        int b = min(maxx, maxy);
        
        // x = y = sqrt(z)
        
        a = max(a, int(ceil(sqrt(minz))));
        b = min(b, int(floor(sqrt(maxz))));
        if (a <= b) res += (b-a+1);
        
        //for (int64 x0 = a; x0 <= b && x0*x0 <= maxz; ++x0)
        //   if (minz <= x0*x0) res++;
        
        // x < sqrt(z), y > sqrt(z)
        for (int64 x0 = minx; x0 <= maxx && x0*x0 < maxz ;++x0)
            res += get(x0,miny, maxy, minz, maxz);
        
        // x > sqrt(z), y < sqrt(z)
        // x < sqrt(z), y > sqrt(z)
        for (int64 y0 = miny; y0 <= maxy && y0*y0 < maxz ;++y0)
            res += get(y0,minx, maxx, minz, maxz);
        
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
			int minx                  = 2;
			int maxx                  = 2;
			int miny                  = 3;
			int maxy                  = 3;
			int minz                  = 6;
			int maxz                  = 6;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int minx                  = 2;
			int maxx                  = 2;
			int miny                  = 3;
			int maxy                  = 3;
			int minz                  = 7;
			int maxz                  = 7;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int minx                  = 6;
			int maxx                  = 8;
			int miny                  = 4;
			int maxy                  = 5;
			int minz                  = 27;
			int maxz                  = 35;
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int minx                  = 1;
			int maxx                  = 458;
			int miny                  = 1;
			int maxy                  = 458;
			int minz                  = 1;
			int maxz                  = 458;
			long long expected__      = 2877;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int minx                  = 8176;
			int maxx                  = 184561;
			int miny                  = 1348;
			int maxy                  = 43168;
			int minz                  = 45814517;
			int maxz                  = 957843164;
			long long expected__      = 2365846085LL;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int minx                  = ;
			int maxx                  = ;
			int miny                  = ;
			int maxy                  = ;
			int minz                  = ;
			int maxz                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int minx                  = ;
			int maxx                  = ;
			int miny                  = ;
			int maxy                  = ;
			int minz                  = ;
			int maxz                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int minx                  = ;
			int maxx                  = ;
			int miny                  = ;
			int maxy                  = ;
			int minz                  = ;
			int maxz                  = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = ProductTriplet().countTriplets(minx, maxx, miny, maxy, minz, maxz);
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


