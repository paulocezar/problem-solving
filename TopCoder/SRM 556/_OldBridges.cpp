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

int cap[55][55], pa[55], fl[55];
vector<int> gr[55];

int s, t;

bool augment() {
  queue<int> q;
  q.push(s);
  for(int i = 0; i <= t; ++i) pa[i] = -1;
  pa[s] = s;
  fl[s] = 2e9;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    if (u == t) goto calc_flow;
    for(int i = 0; i < int(gr[u].size()); ++i) {
      int v = gr[u][i];
      if (cap[u][v] > 0 && pa[v] == -1) {
        pa[v] = u;
        q.push(v);
        fl[v] = min(fl[u], cap[u][v]);
      }
    }  
  }
  return false;
calc_flow:
  int u = t;
  while(u != s) {
    cap[pa[u]][u] -= fl[t];
    cap[u][pa[u]] += fl[t];
    u = pa[u];
  }
  return true;
}

int maxflow(){
  int flow = 0;
  while(augment()) {
	flow += fl[t];
  }

  return flow;
}

class OldBridges {
public:
    string isPossible( vector <string> bridges, int a1, int a2, int an, int b1, int b2, int bn ) {
		REP(i,55) gr[i].clear();
		
		int N = SIZE(bridges);
		s = 0;
		t = N+1;
		an *= 2;
		bn *= 2;
		FILL(cap,0);
		a1++;
		b1++;
		a2++;
		b2++;
		
		gr[s].PB(a1);
		gr[s].PB(b1);
		gr[a1].PB(s);
		gr[b1].PB(s);
		cap[s][a1] = an;
		cap[s][b1] = bn;
		
		gr[t].PB(a2);
		gr[t].PB(b2);
		gr[a2].PB(t);
		gr[b2].PB(t);
		cap[a2][t] = 2e9;
		cap[b2][t] = 2e9;
		
		REP(i,N) REP(j,N) {
			if(bridges[i][j] == 'O') {
				gr[i+1].PB(j+1);
				cap[i+1][j+1]+=2;
			}
			if(bridges[i][j] == 'N') {
				gr[i+1].PB(j+1);
				cap[i+1][j+1]+=2e9;
			}
		}
		
		return (maxflow() == (an+bn))?"Yes":"No";
		
		
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
			string bridges[]          = {"XOXX","OXOX","XOXO","XXOX"};
			int a1                    = 0;
			int a2                    = 1;
			int an                    = 1;
			int b1                    = 2;
			int b2                    = 3;
			int bn                    = 1;
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string bridges[]          = {"XOXX","OXOX","XOXO","XXOX"};
			int a1                    = 0;
			int a2                    = 2;
			int an                    = 1;
			int b1                    = 1;
			int b2                    = 3;
			int bn                    = 1;
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string bridges[]          = {"XOXO","OXOX","XOXO","OXOX"};
			int a1                    = 0;
			int a2                    = 2;
			int an                    = 1;
			int b1                    = 1;
			int b2                    = 3;
			int bn                    = 1;
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string bridges[]          = {"XNXO","NXOX","XOXO","OXOX"};
			int a1                    = 0;
			int a2                    = 2;
			int an                    = 1;
			int b1                    = 1;
			int b2                    = 3;
			int bn                    = 2;
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string bridges[]          = {"XOXOO","OXOXO","XOXOO","OXOXO","OOOOX"};
			int a1                    = 0;
			int a2                    = 2;
			int an                    = 2;
			int b1                    = 1;
			int b2                    = 3;
			int bn                    = 2;
			string expected__         = "Yes";

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string bridges[]          = {"XOOOX","OXOOX","OOXOX","OOOXN","XXXNX"};
			int a1                    = 0;
			int a2                    = 4;
			int an                    = 3;
			int b1                    = 1;
			int b2                    = 2;
			int bn                    = 2;
			string expected__         = "No";

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string bridges[]          = ;
			int a1                    = ;
			int a2                    = ;
			int an                    = ;
			int b1                    = ;
			int b2                    = ;
			int bn                    = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string bridges[]          = ;
			int a1                    = ;
			int a2                    = ;
			int an                    = ;
			int b1                    = ;
			int b2                    = ;
			int bn                    = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string bridges[]          = ;
			int a1                    = ;
			int a2                    = ;
			int an                    = ;
			int b1                    = ;
			int b2                    = ;
			int bn                    = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OldBridges().isPossible(vector <string>(bridges, bridges + (sizeof bridges / sizeof bridges[0])), a1, a2, an, b1, b2, bn);
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


