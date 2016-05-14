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

class ArcadeManao {
public:
    int shortestLadder( vector <string> level, int coinRow, int coinColumn ) {
        int N = SIZE(level);
        int M = SIZE(level[0]);
        
        int id[N][M];
        int cur = 0;
        
        REP(i, N) REP(j, M) {
            id[i][j] = -1;
            if (level[i][j] == 'X') {
                if (j && (id[i][j-1] != -1)) id[i][j] = id[i][j-1];
                else id[i][j] = cur++;
            }            
        }
        
        int source = id[N-1][0];
        int sink = id[coinRow-1][coinColumn-1];
        vector< pair<int,int> > gr[cur];
        
        REP(i, N) REP(j, M) {
            if (id[i][j] == -1) continue;
            
            REP(ii, N) {
                if (id[ii][j] == -1) continue;
                gr[id[i][j]].PB(MP(id[ii][j],abs(i-ii)));
            }
                       
        }
        bool seen[cur];
        
        int lo = 0, hi = N;
        int res = N;
        
        while (lo <= hi) {
            int mid = (lo+hi)>>1;
            
            REP(i,cur) seen[i] = false;
            seen[source] = true;
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                
                REP(i, SIZE(gr[u])) {
                    int v = gr[u][i].first;
                    if (seen[v]) continue;
                    if (gr[u][i].second > mid) continue;
                    q.push(v);
                    seen[v] = true;
                }
                
            }
            
            if (seen[sink]) {
                res = mid;
                hi = mid-1;
            } else lo = mid+1;
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
			string level[]            = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
			int coinRow               = 2;
			int coinColumn            = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string level[]            = {"XXXX",
 "...X",
 "XXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string level[]            = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
			int coinRow               = 1;
			int coinColumn            = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string level[]            = {"X"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string level[]            = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
			int coinRow               = 1;
			int coinColumn            = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string level[]            = ;
			int coinRow               = ;
			int coinColumn            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ArcadeManao().shortestLadder(vector <string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
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


