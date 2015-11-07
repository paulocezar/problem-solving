#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int mod = 1e9 + 7;

struct treap {
    treap *lnk[2];
    int pri;
    int val, ends_with;
    int sum_leq, total_sum;
    treap(int val, int ew = 1) : val(val), ends_with(ew), sum_leq(ew), total_sum(ew) { pri = rand(); lnk[0] = lnk[1] = 0; }
    ~treap() { delete lnk[0]; delete lnk[1]; }
    void fix_augment() {
    	sum_leq = ends_with + (lnk[0] ? lnk[0]->total_sum : 0);
    	if (sum_leq >= mod) sum_leq -= mod;
        total_sum = sum_leq + (lnk[1] ? lnk[1]->total_sum : 0);
        if (total_sum >= mod) total_sum -= mod;
    }
};

void rotate(treap*& t, bool to_r) {
    treap* n = t->lnk[!to_r];
    t->lnk[!to_r] = n->lnk[to_r];
    n->lnk[to_r] = t;
    t->fix_augment(); n->fix_augment();
    t = n;
}

treap* find(treap* t, int val) {
    for(;; t = t->lnk[val > t->val]) if(!t || t->val == val) return t;
}

int count_leq(treap* t, int val) {
	int res = 0;
	for (;; t = t->lnk[val > t->val]) {

		if (t && t->val <= val) {
			res += t->sum_leq;
			if (res >= mod) res -= mod;
		}
		if (!t || t->val == val) break;
	}
	return res;
}

treap* insert(treap*& t, int val, int ew = 1) {
    if(!t) return t = new treap(val, ew);
    treap* n = insert(t->lnk[val > t->val], val, ew);
    if(n->pri > t->pri) rotate(t, val <= t->val); else t->fix_augment();
    return n;
}

void increase_ends(treap*& t, int val, int newseqs) {
    if(t->val == val) {
    	t->ends_with += newseqs;
    	if (t->ends_with >= mod) t->ends_with -= mod;
    	t->fix_augment();
    	return;
    }

    increase_ends(t->lnk[val > t->val], val, newseqs);
    t->fix_augment();
}


int a[1<<17];
int smallest_end[1<<17];
treap* possible_ends[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			possible_ends[i] = NULL;
		}
		possible_ends[n] = NULL;
		smallest_end[1] = a[0];

		possible_ends[0] = insert(possible_ends[0], 0);
		possible_ends[1] = insert(possible_ends[1], a[0]);

		int sz = 1;

		for (int i = 1; i < n; ++i) {
			int lo = 0, hi = sz;
			while (lo < hi) {
				int mid = (lo + hi + 1) >> 1;
				if (smallest_end[mid] < a[i]) {
					lo = mid;
				} else {
					hi = mid-1;
				}
			}

			int extends = count_leq(possible_ends[lo], a[i]);
cout << a[i] << " might be added at end of " << extends << " sequences of size " << lo << endl;
			if (lo == sz) {
				sz++;
				smallest_end[sz] = a[i];
				possible_ends[sz] = insert(possible_ends[sz], a[i], extends);
			} else {
				if (a[i] < smallest_end[lo+1]) {
					smallest_end[lo+1] = a[i];
				}
				treap* this_end = find(possible_ends[lo+1], a[i]);
				if (this_end) {
					increase_ends(possible_ends[lo+1], a[i], extends);
				} else {
					possible_ends[lo+1] = insert(possible_ends[lo+1], a[i], extends);
				}
			}
 		}
 		cout << sz << endl;
 		cout << (possible_ends[sz-1]->total_sum)%mod << "\n";
	}

	return 0;
}
