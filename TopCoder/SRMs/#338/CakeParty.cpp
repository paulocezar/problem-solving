// Paste me into the FileEdit configuration dialog

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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int digs(int x){
	int sz = 1;
	while( x/10 ){
		sz++;
		x/=10;
	}
	return sz;
}

string lx( int fr, int to ){
	
	int szf = digs(fr);
	int szt = digs(to);
	ostringstream ot;
	if( szf == szt ) ot << fr;
	else{
		int nn = 1;
		while( digs(nn) <= szf ) nn *= 10;
		if( nn <= to ){
			ot << fr;
			string s1 = ot.str();
			ostringstream ot2;
			ot2 << nn;
			string s2 = ot2.str();
			return MIN(s1,s2);
		}
		ot << fr;
	}
	return ot.str();
}

class CakeParty {
public:
   string makeMove( vector <int> pieces ) {
		map<int,int> ct;
		REP( i, SIZE(pieces) ) ct[ pieces[i] ]++;
		int mx = ct.rbegin()->first;
		
		vector< string > idx;
		REP( i, SIZE(pieces) ) if( pieces[i] == mx ){
			ostringstream ot;
			ot << i;
			idx.PB( ot.str() );
		}
		sort(ALL(idx));
		
		if( ct[mx] == 1 ){
			ostringstream ot;
			if(SIZE(pieces)==1){
				ot << "CAKE " << idx[0] << " PIECES " << mx;
			} else {
				int mmx = (++ct.rbegin())->first;
				if( ct[mmx]&1 )
					ot << "CAKE " << idx[0] << " PIECES " << mx-mmx;
				else
					ot << "CAKE " << idx[0] << " PIECES " << lx(mx-mmx+1,mx);
			}
			return ot.str();
		}
		
		return ("CAKE " + idx[0] + " PIECES 1");
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
			int pieces[]              = {47};
			string expected__         = "CAKE 0 PIECES 47";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int pieces[]              = {3,3};
			string expected__         = "CAKE 0 PIECES 1";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int pieces[]              = {3,5};
			string expected__         = "CAKE 1 PIECES 2";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int pieces[]              = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			string expected__         = "CAKE 0 PIECES 1";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int pieces[]              = {3,3,112};
			string expected__         = "CAKE 2 PIECES 110";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int pieces[]              = {3,3,1};
			string expected__         = "CAKE 0 PIECES 1";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int pieces[]              = {4,7,4,7,4,7,4,7,47,47,47,47};
			string expected__         = "CAKE 10 PIECES 1";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int pieces[]              = {1,105,10,10};
			string expected__         = "CAKE 1 PIECES 100";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 8: {
			int pieces[]              = {1987654321,1987654320};
			string expected__         = "CAKE 0 PIECES 1";

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 9: {
			int pieces[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = CakeParty().makeMove(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
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
