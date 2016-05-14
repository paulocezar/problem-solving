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

int encode( int r, int g, int b, int pos ){
	int res = r;
	res *= 100;
	res += g;
	res *= 100;
	res += b;
	res *= 100;
	res += pos;
	return res;
}

void decode( int x, int &r, int &g, int &b, int &pos ){
	pos = x%100;
	x /= 100;
	b = x%100;
	x /= 100;
	g = x%100;
	x /= 100;
	r = x;
}

int atmost, atleast;

bool check( int r1, int g1, int b1, int r2, int g2, int b2 ){
	return ((abs(r1-r2)<=atmost) && (abs(g1-g2)<=atmost) && (abs(b1-b2)<=atmost) && ((abs(r1-r2)>=atleast)||(abs(g1-g2)>=atleast)||(abs(b1-b2)>=atleast)));
}

class RandomColoring {
public:
	double getProbability( int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2 ) {
		
		map< int, double > seen;
		
		atmost = d2;
		atleast = d1;
		
		queue< int > q;
		q.push( encode(startR,startG,startB,0) );
		seen[ encode(startR,startG,startB,0) ] = 1.0;
		
		double all = 0.0, nok = 0.0;
		
		while( !q.empty() ){
			
			int R, G, B, pos, cur;
			cur = q.front(); q.pop();
			
			decode( cur, R, G, B, pos );
			
			if( pos == N-1 ){
				all += seen[ cur ];
				if( !check(R,G,B,startR,startG,startB) ) nok += seen[ cur ];
				continue;
			}
			
			REP( nr, maxR ) REP( ng, maxG ) REP( nb, maxB ){
				if( check(R,G,B,nr,ng,nb) ){
					int now = encode(nr,ng,nb,pos+1);
					if( !seen.count(now) ) q.push( now );
					seen[now] += seen[cur];
				}
			}
				
		}
		
		return nok/all;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int N                     = 2;
			int maxR                  = 5;
			int maxG                  = 1;
			int maxB                  = 1;
			int startR                = 2;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 0;
			int d2                    = 1;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int maxR                  = 5;
			int maxG                  = 1;
			int maxB                  = 1;
			int startR                = 2;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 0;
			int d2                    = 1;
			double expected__         = 0.22222222222222227;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 7;
			int maxR                  = 4;
			int maxG                  = 2;
			int maxB                  = 2;
			int startR                = 0;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 3;
			int d2                    = 3;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int maxR                  = 7;
			int maxG                  = 8;
			int maxB                  = 9;
			int startR                = 1;
			int startG                = 2;
			int startB                = 3;
			int d1                    = 0;
			int d2                    = 10;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 10;
			int maxR                  = 7;
			int maxG                  = 8;
			int maxB                  = 9;
			int startR                = 1;
			int startG                = 2;
			int startB                = 3;
			int d1                    = 4;
			int d2                    = 10;
			double expected__         = 0.37826245943967396;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 3;
			int maxR                  = 3;
			int maxG                  = 2;
			int maxB                  = 2;
			int startR                = 1;
			int startG                = 0;
			int startB                = 0;
			int d1                    = 1;
			int d2                    = 2;
			double expected__         = 0.09090909090909148;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int maxR                  = ;
			int maxG                  = ;
			int maxB                  = ;
			int startR                = ;
			int startG                = ;
			int startB                = ;
			int d1                    = ;
			int d2                    = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = RandomColoring().getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
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
