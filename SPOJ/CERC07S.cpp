#include <bits/stdc++.h>

using namespace std;

typedef struct item * pitem;

struct item {
    int prior, cnt;
    bool rev;
    pitem l, r, p;
    void reset() {
        rev = false;
        cnt = 1;
        l = r = p = NULL;
    }
};

inline int cnt(pitem it) {
    return it ? it->cnt : 0;
}

void push(pitem it) {
    if (!it) return;
    if (it->l) it->l->p = it;
    if (it->r) it->r->p = it;
    if (it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

inline void upd_cnt(pitem it) {
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        push(it);
    }
}

void merge(pitem & t, pitem l, pitem r) {
    push(l);
    push(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split(pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key) {
        split(t->l, l, t->l, key, add),  r = t;
    } else {
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    }
    if (l) l->p = NULL;
    if (r) r->p = NULL;
    upd_cnt(l);
    upd_cnt(r);
}

void reverse(pitem t, int l, int r) {
    pitem t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r-l+1);
    if (t2) t2->rev ^= true;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void update_path(pitem t) {
    if (t->p) update_path(t->p);
    push(t);
}

int get_index(pitem t) {
    update_path(t);
    int idx = cnt(t->l);
    while (t->p) {
        if (t->p->r == t) idx += cnt(t->p->l) + 1;
        t = t->p;
    }
    return idx;
}

#define MAXN (1<<17)

pair<int,int> vet[MAXN];
item node[MAXN];

int main() {
    ios::sync_with_stdio(false);
 
    srand(time(NULL));
    for (int i = 0; i < MAXN; ++i) {
        node[i].prior = rand();
    }

    int N;
    while (cin >> N && N) {

        pitem treap = NULL;

        for (int i = 0; i < N; ++i) {
            cin >> vet[i].first; vet[i].second = i;
            node[i].reset();
            merge(treap, treap, &node[i]);
        }

        sort(vet, vet+N);
        for (int i = 0; i < N; ++i) {
            int idx = get_index(&node[vet[i].second]);
            
            pitem t1, t2, t3;
            split(treap, t1, t2, idx);
            split(t2, t2, t3, 1);
            if (t1) t1->rev ^= true;
            merge(treap, t1, t3);
            
            if (i) cout << " ";
            cout << idx+i+1;
        }
        cout << "\n";
    }

    return 0;
}