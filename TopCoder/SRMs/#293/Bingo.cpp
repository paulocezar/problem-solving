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

class Bingo {
public:
	string winner( vector <string> card, vector <string> calls ) {
		vector< int > winin;
		
		int mask = (1<<5)-1;
		winin.PB( mask );
		REP( i, 4 ){ mask <<= 5; winin.PB(mask); }
		mask = ((1<<4) | (1<<9) | (1<<14) | (1<<19) | (1<<24));
		winin.PB( mask );
		REP( i, 4 ){ mask >>= 1; winin.PB(mask); }
		mask = (1 | (1<<6) | (1<<12) | (1<<18) | (1<<24));
		winin.PB( mask );
		mask = ((1<<4) | (1<<8) | (1<<12) | (1<<16) | (1<<20));
		winin.PB( mask );
		
		
		map< string, int > wut;
		map< int, string > tuw;
		string bingo = "BINGO";
		
		int who = 1;
		FOR( i, 1, 5 ){
			int pos = 0;
			int j = 0;
			while( j < 5 ){
				while( card[i][pos] == ' ' ) pos++;
				if( card[i][pos] != 'F' ){
					string now = "";
					now += bingo[j];
					while( '0' <= card[i][pos] && card[i][pos] <= '9' ){ now += card[i][pos]; pos++; }
					wut[now] = who;
					tuw[who] = now;
				} else pos++;
				who <<= 1;
				j++;
			}
		}
		
		int cur = 1<<12;
		
		map< int, int > when;
		tuw[1<<12] = "";
		when[1<<12] = 1337;
		
		REP( i, SIZE(calls)-1 ){
			cur |= wut[calls[i]];
			when[ wut[calls[i]] ] = i;
			
			int won = -1;
			vector< int > xxx;
			
			REP( j, SIZE(winin) ) if( (winin[j]&cur) == winin[j] ){
				if( won == -1 ){
					won = winin[j];
					int aux = won;
					while( aux ){
						xxx.PB( when[aux&-aux] );
						aux -= (aux&-aux);
					}
					sort( ALL(xxx) );
				} else {
					vector< int > yyy;
					int aux = winin[j];
					while( aux ){
						yyy.PB( when[aux&-aux] );
						aux -= (aux&-aux);
					}
					sort( ALL(yyy) );
					int i = 0;
					while( xxx[i] == yyy[i] ) i++;
					if( xxx[i] > yyy[i] ){
						won = winin[j];
						xxx = yyy;
					}
				}
			}
			if( won != -1 ){
				string ans = "";
				
				REP( i, 5 ){
					if( i && xxx[i] != 1337) ans += ',';
					
					int aux = won;
					while( aux ){
						if( when[aux&-aux] == xxx[i] ) ans += tuw[aux&-aux];
						aux -= (aux&-aux);
					}
					
				}
				
				return ans;
			} 
		}
		
		return "YOU LOSE";
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
			string card[]             = { "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"};
			string calls[]            = {"B12","B3","I16","N40","B2","O70","B1","B9","O71","B4","B7","B11","O68","BINGO"};
			string expected__         = "B12,B3,B1,B9,B4";

			clock_t start__           = clock();
			string received__         = Bingo().winner(vector <string>(card, card + (sizeof card / sizeof card[0])), vector <string>(calls, calls + (sizeof calls / sizeof calls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string card[]             = { "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"};
			string calls[]            = {"B12","B3","I16","N40","B2","O70","B1","B9","BINGO"};
			string expected__         = "YOU LOSE";

			clock_t start__           = clock();
			string received__         = Bingo().winner(vector <string>(card, card + (sizeof card / sizeof card[0])), vector <string>(calls, calls + (sizeof calls / sizeof calls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string card[]             = { "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"};
			string calls[]            = {"O63","G48","I23","B9","B1","B4","B3","B7","B12","G49","BINGO"};
			string expected__         = "O63,G48,I23,B12";

			clock_t start__           = clock();
			string received__         = Bingo().winner(vector <string>(card, card + (sizeof card / sizeof card[0])), vector <string>(calls, calls + (sizeof calls / sizeof calls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string card[]             = ;
			string calls[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Bingo().winner(vector <string>(card, card + (sizeof card / sizeof card[0])), vector <string>(calls, calls + (sizeof calls / sizeof calls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string card[]             = ;
			string calls[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Bingo().winner(vector <string>(card, card + (sizeof card / sizeof card[0])), vector <string>(calls, calls + (sizeof calls / sizeof calls[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string card[]             = ;
			string calls[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = Bingo().winner(vector <string>(card, card + (sizeof card / sizeof card[0])), vector <string>(calls, calls + (sizeof calls / sizeof calls[0])));
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
