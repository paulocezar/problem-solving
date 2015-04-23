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

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef pair<int,int> point;

point dpixel[1000100];

int Q;

struct node_t {
	int key, pr, mn, mx, good;
	node_t *l, *r;
	node_t(int val=0) : key(val), pr(rand()), mn(val), mx(val), good(0), l(NULL), r(NULL) {}
	~node_t(){ if(l) delete l; if(r) delete r; }
};

void rotate_right(node_t* &t) {
	node_t* n = t->l;
	t->l = n->r;
	n->r = t;
	t = n;
}

void rotate_left(node_t* &t) {
	node_t* n = t->r;
	t->r = n->l;
	n->l = t;
	t = n;
}

void update(node_t* t) {
	if (!t) return;
    
    t->good = 0;
    t->mn = t->key;
    if (t->l) {
        t->mn = t->l->mn;
        t->good += t->l->good;
        int rng = (t->key) - (t->l->mx) - 1;
        if (rng >= Q) t->good += (rng-Q+1);
    }
    
    t->mx = t->key;
    if (t->r) {
        t->mx = t->r->mx;
        t->good += t->r->good;
        int rng = (t->r->mn) - (t->key) - 1;
        if (rng >= Q) t->good += (rng-Q+1);
    }
}

void fix(node_t* &t) {
	if (!t) return;
	update(t->l); update(t->r); update(t);
}

void insert(node_t* &t, int val) {
	if (!t) t = new node_t(val);
	else {
		if (val < t->key) insert(t->l, val);
		else insert(t->r, val);
	}
	
	if (t->l && (t->l->pr > t->pr)) rotate_right(t);
	else if (t->r && (t->r->pr > t->pr)) rotate_left(t);
	
	fix(t);
}

inline int p(node_t* t) { return (t ? (t->pr) : (-1)); }

void erase(node_t* &t, int val) {
	if (!t) return;
	if (t->key != val) erase(((val < t->key)?(t->l):(t->r)), val);
	else {
		if (!(t->l) && !(t->r)) { delete t; t = NULL; }
		else {
			(p(t->l) < p(t->r)) ? rotate_left(t) : rotate_right(t);
			erase(t, val);
		}
	}
	fix(t);
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
    
	ios::sync_with_stdio(false);
    int kases;
    cin >> kases;
    int W, H, P, N, X, Y, a, b, c, d;
    for (int kase = 1; kase <= kases; ++kase) {
        int64 res = 0;    
        cin >> W >> H >> P >> Q >> N >> X >> Y >> a >> b >> c >> d;
        
        dpixel[0] = point(X,Y);
        FOR(i, 1, N-1) {
            X = (dpixel[i-1].first*a + dpixel[i-1].second*b + 1) % W;
            Y = (dpixel[i-1].first*c + dpixel[i-1].second*d + 1) % H;
            dpixel[i] = point(X,Y);
        }
        
        sort(dpixel, dpixel+N);
        
        int lo = 0, hi = P-1;
        int l = 0, r = 0;

        node_t *treap = NULL;
        insert(treap, -1);
        insert(treap, H);
        
        map<int, int> cnt;
        int hp;
        
        while (hi < W) {
            while (r < N && dpixel[r].first <= hi) {
                hp = cnt[dpixel[r].second]++;
                if (!hp) insert(treap, dpixel[r].second);
                r++;
            }
            while (l < r && dpixel[l].first < lo) {
                hp = cnt[dpixel[l].second]--;
                if (hp == 1) erase(treap, dpixel[l].second);
                l++;
            }
            res += treap->good;
            lo++; hi++;
        }
        delete treap;
        cout << "Case #" << kase << ": " << res << "\n";
    }
    
	return 0;
}

















