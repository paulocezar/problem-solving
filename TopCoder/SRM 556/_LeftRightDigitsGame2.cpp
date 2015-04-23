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

class LeftRightDigitsGame2 {
public:
    string minNumber( string digits, string lowerBound ) {
		int N = SIZE(digits);
		string s = "";
		REP(i,N) s += "X";
		queue<string> q;
		q.push(s);
		vector<string> cand;
		while(!q.empty()){
			string now = q.front(); q.pop();
			int i = 0;
			bool gr = false;
			while(i<N && now[i] != 'X') {
				if(now[i] > lowerBound[i]) gr = true;
				i++;
			}
			cout << now << endl;
			if(i==N) {
				if(gr || (now == lowerBound)) cand.PB(now);
				continue;
			}
			
			int j = N-1;
			while(now[j] != 'X') j--;
			int spos = j-i;
			
			char cnow = gr ? '0' : lowerBound[i];
			while(cnow <= '9'){
				
				int ii = i, jj = j;
				int pos = spos;
				string nnow = now;
				while(pos >= 0 && digits[pos] != cnow) {
					nnow[jj] = digits[pos];
					pos--;
					jj--;
				}
				if(pos >= 0) {
					nnow[ii] = cnow;
					q.push(nnow);
					break;
				} else cnow++;
			}
			
			if(i==0) {
				cnow = lowerBound[i]+1;
				while(cnow <= '9'){
					int ii = i, jj = j;
					int pos = spos;
					string nnow = now;
					while(pos >= 0 && digits[pos] != cnow) {
						nnow[jj] = digits[pos];
						pos--;
						jj--;
					}
					if(pos >= 0) {
						nnow[ii] = cnow;
						q.push(nnow);
						break;
					} else cnow++;
				}
			}
			
		}
		
		if(cand.empty()) return "";
		sort(ALL(cand));
		return cand[0];
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string digits             = "565";
			string lowerBound         = "556";
			string expected__         = "556";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string digits             = "565";
			string lowerBound         = "566";
			string expected__         = "655";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string digits             = "565";
			string lowerBound         = "656";
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string digits             = "9876543210";
			string lowerBound         = "5565565565";
			string expected__         = "5678943210";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string digits             = "8016352";
			string lowerBound         = "1000000";
			string expected__         = "1086352";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

	case 5: {
			string digits             = "36403829258";
			string lowerBound         = "83994503502";
			string expected__         = "84360329258";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string digits             = ;
			string lowerBound         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string digits             = ;
			string lowerBound         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
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


