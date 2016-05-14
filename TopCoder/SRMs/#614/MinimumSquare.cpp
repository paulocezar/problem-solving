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

class MinimumSquare {
public:
    long long minArea( vector <int> x, vector <int> y, int K ) {
        
        int N = SIZE(x);
        vector< pair<int, int> > pts(N);
        
        REP(i, N) pts[i].first = x[i], pts[i].second = y[i];        
        sort(ALL(pts));       
        
        long long res = -1LL;
             
        set< pair<int,int> > seen;
        
            for (int i = 0; i < N; ++i) {
            
                for (int j = i; j <= N; ++j) {
                    if (seen.insert(make_pair(pts[i].first, pts[j].first)).second) {
                        
                        vector<int> ycand;
                        for (int l = 0; l < N; ++l) {
                            if ((pts[i].first <= pts[l].first) && (pts[l].first <= pts[j].first)) {
                                ycand.push_back(pts[l].second);
                            }
                        } 
                        if (SIZE(ycand) >= K) {
                            sort(ALL(ycand));

                            int ylen = -1;
                            int xlen = pts[j].first - pts[i].first + 2;
                
                            for (int l = 0; (l+K) <= SIZE(ycand); ++l) {
                                if ((ylen == -1) || ((ycand[l+K-1]-ycand[l]+2) < ylen)) ylen = ycand[l+K-1]-ycand[l]+2;
                            }

                            int64 side = max(xlen, ylen);
                            int64 area = side*side;
                
                            if ((res == -1LL) || (area < res)) res = area;
                        }
                    }
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
			int x[]                   = {0, 3};
			int y[]                   = {0, 7};
			int K                     = 2;
			long long expected__      = 81;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-4, 3, 1};
			int y[]                   = {3 , -1, -2};
			int K                     = 2;
			long long expected__      = 16;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0, 0, 1, 1, 2, 2};
			int y[]                   = {0, 1, 0, 1, 0, 1};
			int K                     = 4;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
			int y[]                   = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
			int K                     = 3;
			long long expected__      = 4000000008000000004LL;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
			int y[]                   = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
			int K                     = 8;
			long long expected__      = 1695545329;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
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


