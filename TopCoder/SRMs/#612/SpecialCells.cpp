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

#define MAXV 128
#define MAXE (MAXV*MAXV)

int dist[MAXV], last_edge[MAXV], d_visited[MAXV], bg_prev[MAXV], pot[MAXV],
    capres[MAXV];
int prev_edge[MAXE], adj[MAXE], cap[MAXE], cost[MAXE], flow[MAXE];

int nedges;
priority_queue<pair<int, int> > d_q;

inline void bg_edge(int v, int w, int capacity, int cst, bool r = false) {
    prev_edge[nedges] = last_edge[v];
    adj[nedges] = w;
    cap[nedges] = capacity;
    flow[nedges] = 0;
    cost[nedges] = cst;
    last_edge[v] = nedges++;

    if(!r) bg_edge(w, v, 0, -cst, true);
}

inline int rev(int i) { return i ^ 1; }
inline int from(int i) { return adj[rev(i)]; }

inline void bg_init() {
    nedges = 0;
    memset(last_edge, -1, sizeof last_edge);
    memset(pot, 0, sizeof pot);
}

void bg_dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(d_visited, 0, sizeof d_visited);
    d_q.push(make_pair(dist[s] = 0, s));
    capres[s] = 0x3f3f3f3f;

    while(!d_q.empty()) {
        int v = d_q.top().second; d_q.pop();
        if(d_visited[v]) continue; d_visited[v] = true;

        for(int i = last_edge[v]; i != -1; i = prev_edge[i]) {
            if(cap[i] - flow[i] == 0) continue;
            int w = adj[i], new_dist = dist[v] + cost[i] + pot[v] - pot[w];

            if(new_dist < dist[w]) {
                d_q.push(make_pair(-(dist[w] = new_dist), w));
                bg_prev[w] = rev(i);
                capres[w] = min(capres[v], cap[i] - flow[i]);
            }
        }
    }
}

pair<int, int> busacker_gowen(int src, int sink) {
    int ret_flow = 0, ret_cost = 0;

    bg_dijkstra(src);
    while(dist[sink] < 0x3f3f3f3f) {
        int cur = sink;
        while(cur != src) {
            flow[bg_prev[cur]] -= capres[sink];
            flow[rev(bg_prev[cur])] += capres[sink];
            ret_cost += cost[rev(bg_prev[cur])] * capres[sink];
            cur = adj[bg_prev[cur]];
        }
        ret_flow += capres[sink];

        for(int i = 0; i < MAXV; ++i)
            pot[i] = min(pot[i] + dist[i], 0x3f3f3f3f);

        bg_dijkstra(src);
    }
    return make_pair(ret_flow, ret_cost);
}

class SpecialCells {
public:
    int guess( vector <int> x, vector <int> y ) {
        int N = SIZE(x);
        bg_init();
            
        set< pair<int, int> > special;
        
        int nx = 0, ny = 0;
        map<int, int> mx, my;
        map<int, int> ctx, cty;
        
        REP(i, N) {
            ctx[x[i]]++;
            cty[y[i]]++;
            
            if (!mx.count(x[i])) mx[x[i]] = ++nx;
            if (!my.count(y[i])) my[y[i]] = ++ny;
             
            special.insert(make_pair(x[i],y[i]));
        }
        
        FORIT(xval, mx) {
            bg_edge(0, xval->second ,ctx[xval->first],0);
        }
        
        FORIT(yval, my) {
            bg_edge((nx+yval->second), nx+ny+1,cty[yval->first],0);
        }
            
        REP(i, N) {
            bg_edge(mx[x[i]], nx+my[y[i]], 1, 1);
            REP(j, N) {
                if (special.insert(make_pair(x[i],y[j])).second) {
                    bg_edge(mx[x[i]], nx+my[y[j]], 1, 0);
                } 
            }
        }
        pair<int,int> reslt = busacker_gowen(0,nx+ny+1);
        return reslt.second;
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
			int x[]                   = {1,2};
			int y[]                   = {1,2};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {1,1,2};
			int y[]                   = {1,2,1};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {1,2,1,2,1,2};
			int y[]                   = {1,2,3,1,2,3};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
			int y[]                   = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1,100000};
			int y[]                   = {1,100000};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SpecialCells().guess(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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


