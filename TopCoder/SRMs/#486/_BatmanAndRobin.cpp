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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;

struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

struct pt{
	double x, y;
	
	pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	
	double length() { return sqrt(x*x + y*y); }
	double length2() { return x*x + y*y; }
	
	pt normalize(){
		return (*this)/length();
	}
	
	pt operator - (pt p){ return pt(x - p.x, y - p.y); }
	pt operator + (pt p){ return pt(x + p.x, y + p.y); }
	pt operator * (double k){ return pt(x * k, y * k); }
	pt operator / (double k){ return pt(x / k, y / k); }
	bool operator < (const pt& p) const{
		if(fabs( x - p.x ) >= EPS) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p){
		return ( fabs(x - p.x) < EPS && fabs(y - p.y) < EPS );
	}
};

double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }

int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
bool cw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) > 0; }
bool ccw(pt a, pt b, pt c){	return cmp(signed_area(a, b, c)) < 0; }
bool colinear(pt a, pt b, pt c){ return !cmp(signed_area(a, b, c)); }

pt refer;
bool cmp_angle(pt p1, pt p2){
	double det = signed_area(refer, p1, p2); 
	if(fabs(det) < EPS){
		return (dist(refer, p1) >= dist(refer, p2));
	}
	return (det > EPS);
}

void convex_hull(polygon in, polygon& hull){
	hull.clear();
	
	if(in.size() < 3){ hull = in; return; }
	
	int pos = 0;
	for(int i = 1; i < SIZE(in); i++) if(in[i] < in[pos]) pos = i;
	swap(in[0], in[pos]);
	refer = in[0];
	
	sort(in.begin() + 1, in.end(), cmp_angle);
	in.resize(unique(in.begin(), in.end()) - in.begin());
	
	hull.push_back(in[0]); hull.push_back(in[1]);
	
	in.push_back(in[0]); //isto evita pontos colineares no final do poligono
	for(int i = 2; i < SIZE(in); ){
		if(hull.size() > 2 && side_sign(hull[hull.size() - 2], hull[hull.size() - 1], in[i]) <= 0){
			hull.pop_back();
		}
		else hull.push_back(in[i++]);
	}
	//tira a duplicata
	hull.pop_back();
}

double trap(pt& a, pt& b){ return 0.5*(b.x - a.x)*(b.y + a.y); }

double area(polygon& poly){
	double ret = 0.0;
	for(int i = 0; i < SIZE(poly); i++){
		ret += trap(poly[i], poly[(i+1)%poly.size()]);
	}
	return fabs(ret);
}


class BatmanAndRobin {
public:
    double minArea( vector <int> x, vector <int> y ) {
        
        int n = SIZE(x);
        if (n <= 4) return 0.0;
        
        polygon px, a, b;
        
        
        REP(i,n) px.PB(pt(x[i],y[i]));
        convex_hull(px,b);
        
        double res = area(b);
                
        REP(i,n) {
            FOR(j,i+1,n-1) {
                
                pt p1(x[i],y[i]), p2(x[j],y[j]);
                
                a.clear();
                REP(i,n) {
                    if (side_sign(p1,p2,px[i]) >= 0) a.PB(px[i]);
                }
                convex_hull(a,b);
                double r1 = area(b);
                
                a.clear();
                REP(i,n) {
                    if (side_sign(p1,p2,px[i]) < 0) a.PB(px[i]);
                }
                convex_hull(a,b);
                double r2 = area(b);                        
                
                res = min(res,max(r1,r2));
            }
        }
        return res;
        
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
			int x[]                   = {100,100,90,90,-100,-100,-90,-90};
			int y[]                   = {100,90,100,90,-100,-90,-100,-90};
			double expected__         = 100.0;

			clock_t start__           = clock();
			double received__         = BatmanAndRobin().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-1000,-1000,1000,1000,1000,-1000};
			int y[]                   = {-1000,1000,-1000,1000,0,0};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = BatmanAndRobin().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-1000,-1000,1000,1000,0};
			int y[]                   = {-1000,1000,-1000,1000,0};
			double expected__         = 1000000.0;

			clock_t start__           = clock();
			double received__         = BatmanAndRobin().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {-904,-812,-763,-735,-692,-614,-602,-563,-435,-243,-87,-52,-28,121,126,149,157,185,315,336,390,470,528,591,673,798,815,837,853,874};
			int y[]                   = {786,10,-144,949,37,-857,-446,-969,-861,-712,5,-972,-3,-202,-845,559,-244,-542,-421,422,526,-501,-791,-899,-315,281,-275,467,743,-321};
			double expected__         = 1067472.0;

			clock_t start__           = clock();
			double received__         = BatmanAndRobin().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BatmanAndRobin().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BatmanAndRobin().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BatmanAndRobin().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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


