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

vector<int> ll, dd;
map< vector<int>, int > mem;

int solve(vector<int> cur) {
    
    if (!SIZE(cur)) return 0;
    if (mem.count(cur)) return mem[cur];
    
    int res = 0;
    int len = SIZE(cur);
    
    REP(i, len) {
        if (ll[cur[i]] <= len) {            
            int nlen = len - ll[cur[i]];
            vector<int> nxt(nlen);
            
            int j = (i + ll[cur[i]]) % len;
            int jj = 0;
            
            while (j < i) { nxt[jj] = cur[j]; jj++; j++; }
            
            j = i + ll[cur[i]];
            while (j < len) { nxt[jj] = cur[j]; jj++; j++; }
            
            res = max(res, dd[cur[i]] + solve(nxt));
        }
    }
    
    return (mem[cur] = res);
}

class SpellCards {
public:
    int maxDamage( vector <int> level, vector <int> damage ) {
        ll = level;
        dd = damage;
        vector<int> v;
        REP(i, SIZE(level)) v.PB(i);
        mem.clear();
        return solve(v);
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
			int level[]               = {1,1,1};
			int damage[]              = {10,20,30};
			int expected__            = 60;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int level[]               = {3,3,3};
			int damage[]              = {10,20,30};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int level[]               = {4,4,4};
			int damage[]              = {10,20,30};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int level[]               = {50,1,50,1,50};
			int damage[]              = {10,20,30,40,50};
			int expected__            = 60;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int level[]               = {2,1,1};
			int damage[]              = {40,40,10};
			int expected__            = 80;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int level[]               = {1,2,1,1,3,2,1};
			int damage[]              = {10,40,10,10,90,40,10};
			int expected__            = 170;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int level[]               = {1,2,2,3,1,4,2};
			int damage[]              = {113,253,523,941,250,534,454};
			int expected__            = 1918;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int level[]               = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int damage[]              = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int expected__            = 50;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int level[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int level[]               = ;
			int damage[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpellCards().maxDamage(vector <int>(level, level + (sizeof level / sizeof level[0])), vector <int>(damage, damage + (sizeof damage / sizeof damage[0])));
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


