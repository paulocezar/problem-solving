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

class DropCoins {
public:
	int getMinimum( vector <string> board, int K ) {
		map< int, int > seen;
		int N = SIZE(board);
		int M = SIZE(board[0]);
		
		int prep[N+1][M+1];
		for( int i = 0; i < N; i++ )
			for( int j = 0; j < M; j++ )
				prep[i][j] = (i?prep[i-1][j]:0)+(j?prep[i][j-1]:0)-((i&&j)?prep[i-1][j-1]:0)+(board[i][j]=='o');
		
		priority_queue< pair<int,int> > q;
		q.push( MP( 0, 3 + 10*(0) + 1000*(N-1) + 100000*(0) + 10000000*(M-1) ) );
		while( !q.empty() ){
			int dis = -q.top().first;
			int state = q.top().second; q.pop();
			
			if( dis > seen[state] ) continue;
			
			int align = state%10; state/=10;
			int i1 = state%100; state /= 100;
			int i2 = state%100; state /= 100;
			int j1 = state%100; state /= 100;
			int j2 = state;
			int cur = prep[i2][j2]-(i1?prep[i1-1][j2]:0)-(j1?prep[i2][j1-1]:0)+((i1&&j1)?prep[i1-1][j1-1]:0);
			if( cur == K ) return dis;
			
			for( int ni1 = i1+1; ni1 <= i2; ni1++ ){
				int rem = prep[ni1-1][j2]-(i1?prep[i1-1][j2]:0)-(j1?prep[ni1-1][j1-1]:0)+((i1&&j1)?prep[i1-1][j1-1]:0);
				if( rem > 0 ){
					if( cur-rem >= K ){
						int cost = ni1-i1;
						if( !(align&2) ) cost += N-(i2-i1+1);
						 
						int nstate = (2|(align&1)) + 10*(ni1) + 1000*(i2) + 100000*(j1) + 10000000*(j2);
						if( seen.find(nstate) == seen.end() || (dis+cost < seen[nstate]) ){
							seen[nstate] = dis+cost;
							q.push( MP( -seen[nstate], nstate ) );
						}	
					}
					break;
				}
			}
			
			for( int ni2 = i2-1; ni2 >= i1; ni2-- ){
				int rem = prep[i2][j2]-(prep[ni2][j2])-(j1?prep[i2][j1-1]:0)+(j1?prep[ni2][j1-1]:0);
				if( rem > 0 ){
					if( cur-rem >= K ){
						int cost = i2-ni2;
						if( align&2 ) cost += N-(i2-i1+1);
						 
						int nstate = (align&1) + 10*(i1) + 1000*(ni2) + 100000*(j1) + 10000000*(j2);
						if( seen.find(nstate) == seen.end() || (dis+cost < seen[nstate]) ){
							seen[nstate] = dis+cost;
							q.push( MP( -seen[nstate], nstate ) );
						}	
					}
					break;
				}
			}
			
			for( int nj1 = j1+1; nj1 <= j2; nj1++ ){
				int rem = prep[i2][nj1-1]-(i1?prep[i1-1][nj1-1]:0)-(j1?prep[i2][j1-1]:0)+((i1&&j1)?prep[i1-1][j1-1]:0);
				if( rem > 0 ){
					if( cur-rem >= K ){
						int cost = nj1-j1;
						if( !(align&1) ) cost += M-(j2-j1+1);
						 
						int nstate = ((align&2)|1) + 10*(i1) + 1000*(i2) + 100000*(nj1) + 10000000*(j2);
						if( seen.find(nstate) == seen.end() || (dis+cost < seen[nstate]) ){
							seen[nstate] = dis+cost;
							q.push( MP( -seen[nstate], nstate ) );
						}	
					}
					break;
				}
			}
			
			for( int nj2 = j2-1; nj2 >= j1; nj2-- ){
				int rem = prep[i2][j2]-(i1?prep[i1-1][j2]:0)-(prep[i2][nj2])+(i1?prep[i1-1][nj2]:0);
				if( rem > 0 ){
					if( cur-rem >= K ){
						int cost = j2-nj2;
						if( align&1 ) cost += M-(j2-j1+1);
						 
						int nstate = (align&2) + 10*(i1) + 1000*(i2) + 100000*(j1) + 10000000*(nj2);
						if( seen.find(nstate) == seen.end() || (dis+cost < seen[nstate]) ){
							seen[nstate] = dis+cost;
							q.push( MP( -seen[nstate], nstate ) );
						}	
					}
					break;
				}
			}
			
			
			
			
		}
		
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
			string board[]            = {".o.."
,"oooo"
,"..o."}
;
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
;
			int K                     = 12;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"...."
,".oo."
,".oo."
,"...."}
;
			int K                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
;
			int K                     = 12;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
;
			int K                     = 58;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
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
