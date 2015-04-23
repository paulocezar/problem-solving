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

class ICPCBalloons {
public:
    int minRepaintings( vector <int> balloonCount, string balloonSize, vector <int> maxAccepted ) {
        int M = SIZE(maxAccepted);
        int N = SIZE(balloonCount);
        
        int med = 0, lrg = 0;
        vector<int> medium, large;
        
        REP(i, N) if (balloonSize[i] == 'M') {
            medium.PB(balloonCount[i]);
            med += balloonCount[i];
        } else {
            large.PB(balloonCount[i]);
            lrg += balloonCount[i];
        }
        
        int total = 0;
        REP(i, M) total += maxAccepted[i];
        
        if (total > (med+lrg)) return -1;
        
        sort(ALL(medium));
        sort(ALL(large));
        
        int res = -1;
        
        REP(mask,1<<M) {
            
            int m_ndd = 0, l_ndd = 0;
            vector<int> mm, ll;
            
            REP(i, M) if (mask & (1<<i)) {
                mm.PB(maxAccepted[i]);
                m_ndd += maxAccepted[i];
            } else {
                ll.PB(maxAccepted[i]);
                l_ndd += maxAccepted[i];
            }
            
            if (m_ndd > med || l_ndd > lrg) continue;
            
            sort(ALL(mm));
            sort(ALL(ll));
            
            int i = SIZE(mm)-1;
            int j = SIZE(medium)-1;
            
            int repaint = 0;
            while (i >= 0 && j >= 0) {
                repaint += max(0, mm[i]-medium[j]);
                i--;
                j--;
            }
            
            while (i >= 0) {
                repaint += mm[i];
                i--;
            }
            
            i = SIZE(ll)-1;
            j = SIZE(large)-1;
            
            while (i >= 0 && j >= 0) {
                repaint += max(0, ll[i]-large[j]);
                i--;
                j--;
            }
            
            while (i >= 0) {
                repaint += ll[i];
                i--;
            }
            
            if (res == -1) res = repaint;
            else res = min(res, repaint);
                            
            
                                    
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
			int balloonCount[]        = {100};
			string balloonSize        = "L";
			int maxAccepted[]         = {1,2,3,4,5};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int balloonCount[]        = {100};
			string balloonSize        = "M";
			int maxAccepted[]         = {10,20,30,40,50};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int balloonCount[]        = {5,6,1,5,6,1,5,6,1};
			string balloonSize        = "MLMMLMMLM";
			int maxAccepted[]         = {7,7,4,4,7,7};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int balloonCount[]        = {100,100};
			string balloonSize        = "ML";
			int maxAccepted[]         = {50,51,51};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int balloonCount[]        = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
			string balloonSize        = "MMMLLLMMLLMLMLM";
			int maxAccepted[]         = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int balloonCount[]        = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
			string balloonSize        = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL";
			int maxAccepted[]         = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
			int expected__            = 210;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int balloonCount[]        = ;
			string balloonSize        = ;
			int maxAccepted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int balloonCount[]        = ;
			string balloonSize        = ;
			int maxAccepted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int balloonCount[]        = ;
			string balloonSize        = ;
			int maxAccepted[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ICPCBalloons().minRepaintings(vector <int>(balloonCount, balloonCount + (sizeof balloonCount / sizeof balloonCount[0])), balloonSize, vector <int>(maxAccepted, maxAccepted + (sizeof maxAccepted / sizeof maxAccepted[0])));
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


