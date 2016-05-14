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
#include <tr1/unordered_map>

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

vector<int> neededR, neededG, hasR, hasG, hasW;
int n, R, G, W;

tr1::unordered_map<int, int> cache[128][128];

int solve(int WasR, int WasG, int mask) {

    int curR = R, curG = G, curW = W;
    REP(i, n) if (!(mask & (1<<i))) {
        curR += hasR[i];
        curG += hasG[i];
        curW += hasW[i];
        curR -= neededR[i];
        curG -= neededG[i];
    }
    curR += WasR;
    curG += WasG;
    curW -= (WasR + WasG);
    
    int res = curR+curG+curW;
    if (cache[WasR][WasG].count(mask)) {
        res = cache[WasR][WasG][mask];
        return res;
    }
    
    REP(i, n) {
        if (mask & (1<<i)) {
            int needR = max(0, neededR[i]-curR);
            int needG = max(0, neededG[i]-curG);
            if ((needR+needG) <= curW) {
                res = max(res, solve(WasR+needR,WasG+needG,mask ^ (1<<i)));
            }
        }
    }
    
    cache[WasR][WasG][mask] = res;
    
    return res;
    
}

class KeyDungeonDiv1 {
public:
    int maxKeys( vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys ) {
        n = SIZE(doorR);
        R = keys[0], G = keys[1], W = keys[2];
        neededR = doorR;
        neededG = doorG;
        hasR = roomR;
        hasG = roomG;
        hasW = roomW;
        REP(i,128) REP(j,128) cache[i][j].clear();
        
        return solve(0, 0, (1<<n)-1);
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
			int doorR[]               = {1, 2, 3};
			int doorG[]               = {0, 4, 9};
			int roomR[]               = {0, 0, 10};
			int roomG[]               = {0, 8, 9};
			int roomW[]               = {1, 0, 8};
			int keys[]                = {3, 1, 2};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int doorR[]               = {1, 1, 1, 2};
			int doorG[]               = {0, 2, 3, 1};
			int roomR[]               = {2, 1, 0, 4};
			int roomG[]               = {1, 3, 3, 1};
			int roomW[]               = {1, 0, 2, 1};
			int keys[]                = {0, 4, 0};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int doorR[]               = {2, 0, 4};
			int doorG[]               = {3, 0, 4};
			int roomR[]               = {0, 0, 9};
			int roomG[]               = {0, 0, 9};
			int roomW[]               = {8, 5, 9};
			int keys[]                = {0, 0, 0};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int doorR[]               = {5, 3, 0, 0};
			int doorG[]               = {0, 1, 2, 1};
			int roomR[]               = {0, 9, 2, 4};
			int roomG[]               = {2, 9, 2, 0};
			int roomW[]               = {0, 9, 1, 1};
			int keys[]                = {1, 1, 0};
			int expected__            = 32;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int doorR[]               = {9,5,10,8,4,3,0,8,4,1,3,9};
			int doorG[]               = {9,10,0,8,9,4,3,8,1,8,10,4};
			int roomR[]               = {1,2,0,2,3,3,5,3,1,3,0,5};
			int roomG[]               = {5,2,5,0,5,2,3,4,0,0,5,2};
			int roomW[]               = {1,5,1,2,0,4,4,0,3,3,1,3};
			int keys[]                = {5,0,1};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int doorR[]               = ;
			int doorG[]               = ;
			int roomR[]               = ;
			int roomG[]               = ;
			int roomW[]               = ;
			int keys[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int doorR[]               = ;
			int doorG[]               = ;
			int roomR[]               = ;
			int roomG[]               = ;
			int roomW[]               = ;
			int keys[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int doorR[]               = ;
			int doorG[]               = ;
			int roomR[]               = ;
			int roomG[]               = ;
			int roomW[]               = ;
			int keys[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KeyDungeonDiv1().maxKeys(vector <int>(doorR, doorR + (sizeof doorR / sizeof doorR[0])), vector <int>(doorG, doorG + (sizeof doorG / sizeof doorG[0])), vector <int>(roomR, roomR + (sizeof roomR / sizeof roomR[0])), vector <int>(roomG, roomG + (sizeof roomG / sizeof roomG[0])), vector <int>(roomW, roomW + (sizeof roomW / sizeof roomW[0])), vector <int>(keys, keys + (sizeof keys / sizeof keys[0])));
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


