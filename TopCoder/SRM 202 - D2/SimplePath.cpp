// Paste me into the FileEdit configuration dialog

#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


struct segt_t{
	int x1, y1, x2, y2; bool h;
	
	segt_t( int xa = 0, int ya = 0, int xb = 0, int yb = 0 ){
		if( xa < xb ){
			x1 = xa;  y1 = ya;
			x2 = xb;  y2 = yb;
		} else if( xb < xa ){
			x1 = xb;  y1 = yb;
			x2 = xa;  y2 = ya;
		} else if( ya < yb ){
			x1 = xb;  y1 = ya;
			x2 = xa;  y2 = yb;	
		} else {
			x1 = xb;  y1 = yb;
			x2 = xa;  y2 = ya;
		}
		if( x1 != x2 ) h = true;
		else h = false;
	}
	bool intersect( segt_t& a ){
		
		if( h && !a.h ){   // horiz --- a / vert
			if( x1 <= a.x1 && a.x1 <= x2 && a.y1 < y1 && y1 < a.y2 ) return true;
			if( x1 < a.x1 && a.x1 < x2 && a.y1 <= y1 && y1 <= a.y2 ) return true;
		} else if( !h && a.h ){  // vert --- a / horiz
			if( a.x1 <= x1 && x1 <= a.x2 && y1 < a.y1 && a.y1 < y2 ) return true;
			if( a.x1 < x1 && x1 < a.x2 && y1 <= a.y1 && a.y1 <= y2 ) return true;
		} else if( h ){  // horiz
			if( y1 == a.y1 && !( (a.x1 >= x2) || (x1 >= a.x2) ) ) return true;
		} else {  // vert
			if( x1 == a.x1 && !( (a.y1 >= y2) || (y1 >= a.y2) ) ) return true;
		}
		return false;
	}
	bool sep( segt_t& a ){
		return (( x1 == a.x1 && y1 == a.y1 ) || ( x2 == a.x2 && y2 == a.y2 ) || ( x1 == a.x2 && y1 == a.y2 ) || ( x2 == a.x1 && y2 == a.y1 ) );
	}
};

class SimplePath {
public:
   int trouble( string direction, vector <int> length ) {
		
		int N = SIZE(direction);
		segt_t segt[N];
		
		int ox = 0, oy = 0;
		REP( i, N ){
			switch( direction[i] ){
				case 'N': segt[i] = segt_t( ox, oy, ox, oy+length[i] ); oy += length[i]; 
					break;
				case 'S': segt[i] = segt_t( ox, oy, ox, oy-length[i] ); oy -= length[i];
					break;
				case 'E': segt[i] = segt_t( ox, oy, ox+length[i], oy ); ox += length[i];
					break;
				case 'W': segt[i] = segt_t( ox, oy, ox-length[i], oy ); ox -= length[i];
					break;
			}
		}
		
		REP( i, N ) FOR( j, i+1, N ) if( segt[i].intersect(segt[j]) || ( j != i+1 && segt[i].sep(segt[j])) ) return i;
		return -1;
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
			string direction          = "NWSEEN";
			int length[]              = {5,5,3,2,5,2};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string direction          = "NWWS";
			int length[]              = {10,3,7,10};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string direction          = "NWES";
			int length[]              = {2,2,1,2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string direction          = "NWSE";
			int length[]              = {100,100,100,100};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string direction          = "EEEEEW";
			int length[]              = {1,1,1,1,1,10};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string direction          = "NNWSENW";
			int length[]              = {10, 10, 10, 20, 20, 20, 10};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string direction          = ;
			int length[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string direction          = ;
			int length[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SimplePath().trouble(direction, vector <int>(length, length + (sizeof length / sizeof length[0])));
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
