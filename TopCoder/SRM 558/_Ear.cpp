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

int r[333], rx[333], ry[333];

class Ear {
public:
    long long getCount( vector <string> redX, vector <string> blueX, vector <string> blueY ) {
       string ins = "";
       REP(i,SIZE(redX)) ins += redX[i];
       
       istringstream in(ins);
       int rrx = 0;
       while (in >> r[rrx]) ++rrx;
       
       ins = "";
       REP(i,SIZE(blueX)) ins += blueX[i];
       istringstream in2(ins);
       int bx = 0;
       while (in2 >> rx[bx]) ++bx;
       
       ins = "";
       REP(i,SIZE(blueY)) ins += blueY[i];
       istringstream in3(ins);
       int by = 0;
       while (in3 >> ry[by]) ++by;
       
       sort(r,r+rrx);
       
       int n = rrx;
       int m = bx;
       
       int64 res = 0;
       
       REP(i,m) REP(j,m) if (ry[j] < ry[i]) {
           int maxrA = rx[i], minrD = rx[i];
           int maxrB = rx[j], minrC = rx[j];
           int64 aa = ry[i]-ry[j], cc = rx[i]*ry[j]-rx[j]*ry[i];
           int k1 = -1, k2 = -1;
           
           REP(t,n) if (r[t]*aa+cc>0 && r[t]>minrD) {k2 = t; break;}
           RREP(t,n) if (r[t]*aa+cc<0 && r[t]<maxrA) {k1 = t; break;}
           if (k1 == -1 || k2 == -1) continue;
           int t1 = -1, t2 = -1;
           
           REP(t,n) if (r[t] > minrC) {t2 = t; break; }
           RREP(t,n) if (r[t] < maxrB) {t1 = t; break; }
           if (t1 == -1 || t2 == -1) continue;
           
           int res1 = 0, res2 = 0;
           FOR(t,0,k1) if (t1 > t) res1 += t1-t;
           RFOR(t,n-1,k2) if (t2 < t) res2 += t-t2;
           
           res += (int64)res1*res2;
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
			string redX[]             = {"3 2 8 7"};
			string blueX[]            = {"5 4"};
			string blueY[]            = {"2 4"};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string redX[]             = {"3 2 8 7"};
			string blueX[]            = {"2 8"};
			string blueY[]            = {"3 4"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string redX[]             = {"1 2 6 9"};
			string blueX[]            = {"3 6 8 5"};
			string blueY[]            = {"1 5 4 3"};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string redX[]             = {"10000"};
			string blueX[]            = {"10000 9999"};
			string blueY[]            = {"10000 9999"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string redX[]             = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
			string blueX[]            = {"15", "0 250 ", "349"};
			string blueY[]            = {"2 3 1"};
			long long expected__      = 12;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string redX[]             = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
			string blueX[]            = {"4", " ", "5", " ", "6", " 7 ", "8"};
			string blueY[]            = {"1", " 2 ", "3 4", " 5"};
			long long expected__      = 204;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
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


