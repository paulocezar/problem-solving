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

class PastingPaintingDivOne {
public:
    vector<long long> countColors( vector <string> clipboard, int T ) {
        int n = SIZE(clipboard);
        int m = SIZE(clipboard[0]);
        vector<int64> res(3, 0LL);
        
        int doit = min(T, max(n,m));
                
        vector<string> plane(n);
        REP(i, n) {
            plane[i] = clipboard[i];
            REP(j, i) plane[i] += ".";
        }
        int len = m + n - 1;
            
            
        REP(x,doit-1) {
            plane.PB(""); int pos = SIZE(plane)-1;
            
            len++;
            REP(i, len) plane[pos] += ".";
            
            REP(i, n) {
                REP(j, m) {
                    if (clipboard[i][j] != '.' ) {
                        plane[x+i+1][x+j+1] = clipboard[i][j];
                    }
                }
            }
        }
        
        REP(i, SIZE(plane)) {
            REP(j, SIZE(plane[i])) {
                switch (plane[i][j]) {
                    case 'R': res[0]++; break;
                    case 'G': res[1]++; break;
                    case 'B': res[2]++; break;
                    case '.': break;
                } 
            }
        }
        
        int64 RR = 0LL, GG = 0LL, BB = 0LL;
        int ii = SIZE(plane) - n;
        bool first = true;
        while (ii < SIZE(plane)) {
            
            int jj = doit-1;
            int ej = first ? (SIZE(plane[ii])-1) : (jj);
            
            while (jj <= ej) {
                switch (plane[ii][jj]) {
                    case 'R': RR++; break;
                    case 'G': GG++; break;
                    case 'B': BB++; break;
                    case '.': break;
                }
                jj++;
            }
            ii++;
            first = false;
        }
        
        
        res[0] += int64(T-doit) * RR;
        res[1] += int64(T-doit) * GG;
        res[2] += int64(T-doit) * BB;
        
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
			string clipboard[]        = {
"..G",
"R..",
"BG."
};
			int T                     = 3;
			long long expected__[]    = {3, 4, 3};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string clipboard[]        = {
"R...",
"....",
"....",
"...R"
};
			int T                     = 2;
			long long expected__[]    = {4, 0, 0};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string clipboard[]        = {"RGB"};
			int T                     = 100000;
			long long expected__[]    = {100000, 100000, 100000};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string clipboard[]        = {"."};
			int T                     = 1000000000;
			long long expected__[]    = {0, 0, 0};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string clipboard[]        = {
"RB.",
".G."
}
;
			int T                     = 100;
			long long expected__[]    = {100, 1, 100};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string clipboard[]        = {
"..........G..........",
".........G.G.........",
"........G...G........",
".......G.....G.......",
"......G..B.B..G......",
".....G...B.B...G.....",
"....G...........G....",
"...G...R.....R...G...",
"..G.....RRRRRR....G..",
".G..........RR.....G.",
"GGGGGGGGGGGGGGGGGGGGG"
};
			int T                     = 1000000000;
			long long expected__[]    = {2000000018, 17000000048LL, 2000000005};

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string clipboard[]        = ;
			int T                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string clipboard[]        = ;
			int T                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string clipboard[]        = ;
			int T                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = PastingPaintingDivOne().countColors(vector <string>(clipboard, clipboard + (sizeof clipboard / sizeof clipboard[0])), T);
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


