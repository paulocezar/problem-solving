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

int n;
vector< pair<int,int> > song;

int cache[55][55][55];
char cached[55][55][55];

int timespent(int cur, int last, int need) {
    
    if (cur == n) return (need ? INF : 0);
    if (!need) return 0;
    
    int &res = cache[cur][last][need];
    if (cached[cur][last][need]) return res;
    cached[cur][last][need] = 1;
    res = min(timespent(cur+1,last,need), song[cur].second + song[cur].first - song[last].first + timespent(cur+1,cur,need-1));
    return res;
    
}

class GUMIAndSongsDiv1 {
public:
    int maxSongs( vector <int> duration, vector <int> tone, int T ) {
        n = SIZE(duration);
        song.resize(n);
        REP(i, n) song[i] = MP(tone[i], duration[i]);
        sort(ALL(song));
        
        memset(cached,0,sizeof(cached));
        
        int lo = 1, hi = n;
        int res = 0;
        while (lo <= hi) {
            
            int mid = (lo+hi)>>1;
            
            int mn = 2e9;
            REP(first,n) mn = min(mn, song[first].second + timespent(first+1,first,mid-1));
            if (mn <= T) {
                res = mid;
                lo = mid+1;
            } else hi = mid-1;
            
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
			int duration[]            = {3, 5, 4, 11};
			int tone[]                = {2, 1, 3, 1};
			int T                     = 17;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int duration[]            = {100, 200, 300};
			int tone[]                = {1, 2, 3};
			int T                     = 99;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int duration[]            = {1, 2, 3, 4};
			int tone[]                = {1, 1, 1, 1};
			int T                     = 100;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int duration[]            = {9, 11, 13, 17};
			int tone[]                = {2, 1, 3, 4};
			int T                     = 20;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int duration[]            = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4, 67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97};
			int tone[]                = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59, 61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3};
			int T                     = 212;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int duration[]            = ;
			int tone[]                = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int duration[]            = ;
			int tone[]                = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int duration[]            = ;
			int tone[]                = ;
			int T                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GUMIAndSongsDiv1().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
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


