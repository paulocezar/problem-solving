#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int x[1<<17];
int v[1<<17];
int best[1<<17];

vector<int> gr[1<<17];

int N;

struct node_t {
	int key, pr, mx, mx2;
	
	node_t *l, *r;
	node_t(int k) : key(k), pr(rand()), l(NULL), r(NULL), mx(best[k]), mx2(best[k]) {}
	~node_t(){
		if(l) delete l;
		if(r) delete r;
	}	
};

void rotate_right(node_t* &t) {
	node_t *n = t->l;
	t->l = n->r;
	n->r = t;
	t = n;
}

void rotate_left(node_t* &t) {
	node_t *n = t->r;
	t->r = n->l;
	n->l = t;
	t = n;
}

void fix(node_t* t) {
	if(!t) return;
	t->mx = max(((t->l)?(t->l->mx2):0), best[t->key]);
	t->mx2 = max(t->mx, ((t->r)?(t->r->mx2):(0)));
}

void insert(node_t* &t, int val) {
	if (!t) t = new node_t(val);
	else {
		if (x[val] < x[t->key]) insert(t->l, val);
		else insert(t->r, val);
	}
	
	if (t->l && ((t->l->pr) > (t->pr))) rotate_right(t);
	else if (t->r && ((t->r->pr) > (t->pr))) rotate_left(t);
	
	fix(t->l); fix(t->r); fix(t);
}

inline int p(node_t* t) { return (t) ? (t->pr) : (-1); }

void erase(node_t* &t, int val) {
	if (!t) return;
	
	if (t->key != val) {
		if (x[val] < x[t->key]) erase(t->l, val);
		else erase(t->r, val);
	} else {
		if (!t->l && !t->r) {
			delete t; 
			t = NULL;
		} else {
			if (p(t->l) < p(t->r)) rotate_left(t);
            else rotate_right(t);
			erase( t, val );
		}
	}
	
	if (t) { fix(t->l); fix(t->r); } fix(t);
}

int query(node_t* t, int val) {	
	if (!t) return 0;
	if (x[val] < x[t->key]) return query(t->l, val);
	return max(t->mx, query(t->r, val));
}

int solve(int u, node_t* &treap) {
	best[u] = query(treap, u) + v[u];
	int ret = best[u];
	insert(treap, u);
	for (auto &v : gr[u]) {
		ret = max(ret, solve(v, treap));
	}
	erase(treap, u);
	return ret;			
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
	while (cin >> N) {
		for (int i = 1; i <= N; ++i) {
			cin >> x[i] >> v[i];
			gr[i].clear();
		}

		int ax;
		for (int i = 2; i <= N; ++i) {
			cin >> ax;
			gr[ax].push_back(i);
		}

		node_t* treap = NULL;

		cout << solve(1, treap) << "\n";
	}

	return 0;
}
