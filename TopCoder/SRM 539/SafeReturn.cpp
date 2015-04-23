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

#define MAXN 77

vector< int > gr[MAXN];
bool seen[MAXN];		
int NN, m[MAXN], m1[MAXN], in[MAXN];

int dfs( int u ){
	if( u < 0 ) return 1;
	if( seen[u] ) return 0;
	seen[u] = true;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		int v = gr[u][i];
		if( !in[ v ] ) continue;
		
		if( dfs( m1[ v ] ) ){
			m[u] = v;
			m1[ v ] = u;
			return 1;
		}
	}
	return 0;
}

int dfsExp( int u ){
	for( int i = 1; i <= NN; i++ ) seen[i] = false;
	return dfs( u );
}

int bipMatch(){
	for( int i = 1; i <= NN; i++ ) m[i] = -1;
	for( int i = 1; i <= NN; i++ ) m1[i] = -1;
	int aug, ans = 0;
	do{
		aug = 0;
		bool first = true;
		for( int i = 1; i <= NN; i++ ) if( m[i] < 0 ){
			if( first ) aug += dfsExp( i );
			else aug += dfs( i );
			first = false;
		}
		ans += aug;
	} while( aug );
	return ans;
}


class SafeReturn {
public:
	int minRisk( int N, vector <string> streets ) {
		int T = SIZE(streets);
		int dist[T][T];
		
		REP( i, T ) REP( j, T ){
			if( streets[i][j] == '-' ) dist[i][j] = INF;
			else dist[i][j] = (streets[i][j]-'0');
		}
		
		REP( k, T ) REP( i, T ) REP( j, T )
			dist[i][j] = min( dist[i][j], dist[i][k]+dist[k][j] );
		
		FOR( i, 1, N ){
			gr[i].clear();
			in[i] = 0;
		}
		
		FOR( i, 1, N ) FOR( j, 1, N ) if( i != j ){
			if( dist[0][j]+dist[j][i] == dist[0][i] && (dist[0][i] != INF) ){
				gr[i].PB( j ); in[j]++; 
			}
		}
		
		NN = N;
		return N-bipMatch();
		
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
			int N                     = 3;
			string streets[]          = {"-234",
 "2---",
 "3---",
 "4---"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			string streets[]          = {"-12",
 "1-1",
 "21-"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			string streets[]          = {"-----7",
 "--1---",
 "-1-5--",
 "--5-1-",
 "---1-3",
 "7---3-"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 2;
			string streets[]          = {"-11",
 "1-1",
 "11-"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			string streets[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
      case 5: {	
			int N                     = 5;
			string streets[]          = {"-11--4","1--1--","1--1--","-11-1-","---1-1","4---1-"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int N                     = ;
			string streets[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SafeReturn().minRisk(N, vector <string>(streets, streets + (sizeof streets / sizeof streets[0])));
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
