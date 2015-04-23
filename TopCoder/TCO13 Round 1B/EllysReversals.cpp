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

#define MAXV 55
#define MAXE MAXV*MAXV

int prev_edge[MAXE], v[MAXE], w[MAXE], last_edge[MAXV];
int type[MAXV], label[MAXV], first[MAXV], mate[MAXV], nedges;
bool g_flag[MAXV], g_souter[MAXV];

void g_init() {
    nedges = 0;
    memset(last_edge, -1, sizeof last_edge);
}

void g_edge(int a, int b, bool rev = false) {
    prev_edge[nedges] = last_edge[a];
    v[nedges] = a;
    w[nedges] = b;
    last_edge[a] = nedges++;

    if(!rev) return g_edge(b, a, true);
}

void g_label(int v, int join, int edge, queue<int>& outer) {
    if(v == join) return;
    if(label[v] == -1) outer.push(v);

    label[v] = edge;
    type[v] = 1;
    first[v] = join;

    g_label(first[label[mate[v]]], join, edge, outer);
}

void g_augment(int _v, int _w) {
    int t = mate[_v];
    mate[_v] = _w;

    if(mate[t] != _v) return;
    if(label[_v] == -1) return;

    if(type[_v] == 0) {
        mate[t] = label[_v];
        g_augment(label[_v], t);
    } else if(type[_v] == 1) {
        g_augment(v[label[_v]], w[label[_v]]);
        g_augment(w[label[_v]], v[label[_v]]);
    }
}

int gabow(int n) {
    memset(mate, -1, sizeof mate);
    memset(first, -1, sizeof first);

    int ret = 0;
    for(int z = 0; z < n; ++z) {
        if(mate[z] != -1) continue;

        memset(label, -1, sizeof label);
        memset(type, -1, sizeof type);
        memset(g_souter, 0, sizeof g_souter);

        label[z] = -1; type[z] = 0;

        queue<int> outer;
        outer.push(z);

        bool done = false;
        while(!outer.empty()) {
            int x = outer.front(); outer.pop();

            if(g_souter[x]) continue;
            g_souter[x] = true;

            for(int i = last_edge[x]; i != -1; i = prev_edge[i]) {
                if(mate[w[i]] == -1 && w[i] != z) {
                    mate[w[i]] = x;
                    g_augment(x, w[i]);
                    ++ret;

                    done = true;
                    break;
                }

                if(type[w[i]] == -1) {
                    int v = mate[w[i]];
                    if(type[v] == -1) {
                        type[v] = 0;
                        label[v] = x;
                        outer.push(v);

                        first[v] = w[i];
                    }
                    continue;
                }

                int r = first[x], s = first[w[i]];
                if(r == s) continue;

                memset(g_flag, 0, sizeof g_flag);
                g_flag[r] = g_flag[s] = true;

                while(r != -1 || s != -1) {
                    if(s != -1) swap(r, s);
                    r = first[label[mate[r]]];
                    if(r == -1) continue;
                    if(g_flag[r]) break; g_flag[r] = true;
                }

                g_label(first[x], r, i, outer);
                g_label(first[w[i]], r, i, outer);

                for(int c = 0; c < n; ++c)
                    if(type[c] != -1 && first[c] != -1 && type[first[c]] != -1)
                        first[c] = r;
            }
            if(done) break;
        }
    }
    return ret;
}

bool used[55];

class EllysReversals {
public:
    int getMin( vector <string> words ) {
        
        int n = SIZE(words);
        g_init();
        
        REP(i, n) FOR(j,i+1,n-1) {
            
            bool ok = true;
            
            if (SIZE(words[i]) == SIZE(words[j])) {
                
                int ss = SIZE(words[i]);
                if ((ss & 1) && (words[i][ss-1] != words[j][ss-1])) {
                    ok = false;
                } else {
                    
                    REP(pp,ss) used[pp] = false;
                    
                    for (int p = 0; (p+1) < ss; p+=2) {
                        
                        bool match = false;
                        
                        for (int p2 = 0; (p2+1) < ss; p2+=2) if (!used[p2]) {
                            match = (words[i][p] == words[j][p2]) && (words[i][p+1] == words[j][p2+1]);
                            match = match || ((words[i][p+1] == words[j][p2]) && (words[i][p] == words[j][p2+1]));
                            if (match) {
                                used[p2] = true;
                                break;
                            }
                        }
                        
                        if (!match) {
                            ok = false;
                            break;
                        }   
                    }
                } 
                
            } else ok = false;
            
            if (ok) g_edge(i,j);

        }
        
        return n - 2*gabow(n);
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
			string words[]            = {"esprit", "god", "redotopc", "odcpoter", "dog"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"no", "zaphod", "just", "very", "improbable"};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string words[]            = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string words[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysReversals().getMin(vector <string>(words, words + (sizeof words / sizeof words[0])));
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


