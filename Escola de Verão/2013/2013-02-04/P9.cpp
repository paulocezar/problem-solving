#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define MAXN 1000000
int a[MAXN];

struct node_t {
	int key, pr, sz;
	node_t *l, *r;
	node_t(int k) : key(k), pr(rand()), sz(1), l(NULL), r(NULL) {}
	void walk() {
		if (l) l->walk();
		cout << " " << key;
		if (r) r->walk();
	}
};

void fix(node_t* t){
	if (!t) return;
	t->sz = 1 + ((t->l)?(t->l->sz):0) + ((t->r)?(t->r->sz):0);
}

void merge(node_t* &t, node_t* l, node_t* r) {
	if (!l || !r) t = l ? l : r;
	else if (l->pr > r->pr) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	fix(t);
}

void split(node_t* t, node_t* &l, node_t* &r, int key) {
	if (!t) return void(l = r = NULL);
	if (key < t->key) split(t->l, l, t->l, key), r = t;
	else split(t->r, t->r, r, key), l = t;
	fix(t);
}

void insert(node_t* &t, int val) {
	node_t *a, *b;
	split(t,a,b,val);
	merge(a,a,new node_t(val));
	merge(t,a,b);
}

node_t *tr[MAXN];

int main(){
    ios::sync_with_stdio(false);
	
	int n; cin >> n;
	REP(i, n) cin >> a[i];

	tr[0] = new node_t(a[0]);
	int last = 0;
	
	FOR(i, 1, n-1) {
		int lo = 0, hi = last;
		int pos = last+1;
		while (lo <= hi) {
			int mid = (lo+hi)>>1;
			if (a[mid] >= a[i]) {
				pos = mid;
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		if (pos == last+1) {
			tr[pos] = new node_t(a[i]);
			a[pos] = a[i];
			last++;
		} else {
			insert(tr[pos], a[i]); 
			a[pos] = a[last];
			int j = pos+1;
			while (j <= last) {
				merge(tr[pos], tr[pos], tr[j]);
				j++;
			}
			last = pos;
		}
	}
	last++;	
	cout << last << "\n";
	REP(i, last) {
		cout << tr[i]->sz;
		tr[i]->walk();
		cout << "\n";
	}
	return 0;
}
