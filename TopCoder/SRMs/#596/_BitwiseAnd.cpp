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

class BitwiseAnd {
public:
    vector<long long> lexSmallest( vector<long long> subset, int N ) {
        vector<long long> res;
                
        int M = SIZE(subset);
        for (int i = 0; i < M; ++i) {
            for (int j = i+1; j < M; ++j) {
                if (!(subset[i]&subset[j])) return res;
                for (int k = j+1; k < M; ++k) {
                    if (subset[i]&subset[j]&subset[k]) return res;
                }
            }
        }
        
        map<int, int> cnt;
        for (int i = 0; i < M; ++i) {
            res.push_back(subset[i]);
            for (int bit = 0; bit < 60; ++bit) {
                if (subset[i] & (1LL<<bit)) cnt[bit]++;
            }
        }
        
        if (!SIZE(res)) {
            res.push_back((1LL<<(N-1)) - 1LL);
            for (int bit = 0; bit < 60; ++bit) {
                if (res[0] & (1LL<<bit)) cnt[bit]++;
            }
        }
        
        while (SIZE(res) < N) {
            
            long long nxt = 0;
            for (int i = SIZE(res)-1; i >= 0; --i) {

                int bit;
                for (bit = 0; bit < 60; ++bit) {
                    if (res[i] & (1LL<<bit)) {
                        if (cnt[bit] < 2) break;
                    }
                }
                
                if (bit != 60) {
                    nxt |= (1LL<<bit);
                    cnt[bit]++;
                } else {
                    if (binary_search(ALL(subset), res[i])) {
                        res.clear();
                        return res;
                    }
                    for (bit = 0; bit < 60; ++bit) {
                        if (cnt[bit] == 0) { 
                            res[i] |= (1LL<<bit);
                            nxt |= (1LL<<bit);
                            cnt[bit]++;
                            break;
                        }
                    }
                    if (bit == 60) {
                        res.clear();
                        return res;
                    }
                }
                
            }
            
            if (nxt) {
                res.push_back(nxt);
                sort(ALL(res));
            } else {
                
                res.clear();
                return res;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, clock_t elapsed) { 
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
			long long subset[]        = {14, 20};
			int N                     = 3;
			long long expected__[]    = {14, 18, 20};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			long long subset[]        = {11, 17, 20};
			int N                     = 4;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			long long subset[]        = {99, 157};
			int N                     = 4;
			long long expected__[]    = {99, 157, 262, 296};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			long long subset[]        = {1152921504606846975LL};
			int N                     = 3;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			long long subset[]        = {};
			int N                     = 5;
			long long expected__[]    = {15, 113, 402, 676, 840};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			long long subset[]        = {1, 3, 5, 7, 9, 11};
			int N                     = 6;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long subset[]        = ;
			int N                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			long long subset[]        = ;
			int N                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			long long subset[]        = ;
			int N                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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


