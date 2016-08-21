#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXNODES = 1<<21;

typedef struct item * pitem;

struct item {
  int prior, value, cnt;
  int occ[26], first[26], last[26];
  bool rev;
  pitem l, r;
};

int cnt(pitem it) {
  return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
  if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;

    int prev = 1 + cnt(it->l);
    for (int i = 0; i < 26; ++i) {
      it->occ[i] = 0, it->first[i] = 0, it->last[i] = 0;
      if (it->l) {
        it->occ[i] += it->l->occ[i];
        it->first[i] = it->l->first[i];
        it->last[i] = it->l->last[i];
      }

      if (it->r) {
        it->occ[i] += it->r->occ[i];
        int fo = it->r->first[i];
        int lo = it->r->last[i];

        if (fo) {
          fo += prev;
          lo += prev;
          if (!(it->first[i])) {
            it->first[i] = fo;
          }

          if (lo > it->last[i]) {
            it->last[i] = lo;
          }
        }
      }
    }
    it->occ[it->value]++;
    if (!(it->first[it->value]) || (prev < (it->first[it->value]))) {
      it->first[it->value] = prev;
    }
    if (prev > (it->last[it->value])) {
      it->last[it->value] = prev;
    }
  }
}

void push(pitem it) {
  if (it && it->rev) {
    it->rev = false;
    swap(it->l, it->r);
    for (int i = 0; i < 26; ++i) {
      swap(it->first[i], it->last[i]);
      it->first[i] = cnt(it) - it->first[i] + 1;
      it->last[i] = cnt(it) - it->last[i] + 1;
    }
    if (it->l) { it->l->rev = !(it->l->rev); }
    if (it->r) { it->r->rev = !(it->r->rev); }
  }
}

void merge(pitem &t, pitem l, pitem r) {
  push(l);
  push(r);

  if (!l || !r) {
    t = l ? l : r;
  } else if (l->prior > r->prior) {
    merge(l->r, l->r, r),  t = l;
  } else {
    merge(r->l, l, r->l),  t = r;
  }

  upd_cnt(t);
}

void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
  if (!t) {
    return void(l = r = 0);
  }
  push(t);
  int cur_key = add + cnt(t->l);
  if (key <= cur_key) {
    split(t->l, l, t->l, key, add),  r = t;
  } else {
    split(t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
  }
  upd_cnt(t);
}

void reverse(pitem t, int l, int r) {
  pitem t1, t2, t3;
  split(t, t1, t2, l-1);
  split(t2, t2, t3, r-l+1);
  t2->rev = !(t2->rev);
  merge(t, t1, t2);
  merge(t, t, t3);
}

int get_occ(pitem t, int l, int r, int val) {
  pitem t1, t2, t3;
  split(t, t1, t2, l-1);
  split(t2, t2, t3, r-l+1);
  int res = t2->occ[val];
  merge(t, t1, t2);
  merge(t, t, t3);
  return res;
}

pair<int,int> get_range(pitem t, int l, int r, int val) {
  pitem t1, t2, t3;
  split(t, t1, t2, l-1);
  split(t2, t2, t3, r-l+1);
  int fst = t2->first[val];
  int lst = t2->last[val];
  merge(t, t1, t2);
  merge(t, t, t3);
  if (!fst) fst = -1; else fst += l-1;
  if (!lst) lst = -1; else lst += l-1;
  return {fst, lst};
}

void insert(pitem &t, int value, int pos){
  pitem l, r;
  pitem nt = new item();
  nt->value = value;
  nt->prior = rand();
  nt->cnt = 1;
  nt->occ[value] = 1;
  nt->first[value] = 1;
  nt->last[value] = 1;
  split(t, l, r, pos-1);
  merge(t, l, nt);
  merge(t, t, r);
}

ostringstream out;
void print(pitem t) {
  if (!t) return;
  push(t);
  print(t->l);
  out << char(t->value+'a');
  print(t->r);
}


int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int L, N;
  cin >> L >> N;
  string s;
  cin >> s;

  pitem treap = NULL;

  for (int i = 1; i <= L; ++i) {
    insert(treap, s[i-1]-'a', i);
  }

  int op, l, r; string c;
  pair<int,int> ans;

  while (N--) {
    cin >> op;
    switch(op) {
      case 1:
        cin >> l >> r >> c;
        out << get_occ(treap, l, r, c[0]-'a') << "\n";
        break;
      case 2:
        cin >> l >> r >> c;
        ans = get_range(treap, l, r, c[0]-'a');
        if (ans.first == -1) { out << "-1\n"; }
        else { out << ans.first << " " << ans.second << "\n"; }
        break;
      case 3:
        cin >> l >> r;
        reverse(treap, l, r);
        break;
      case 4:
        cin >> l >> c;
        insert(treap, c[0]-'a', l);
        break;
    }
  }

  print(treap); out << "\n";

  cout << out.str();




  return 0;
}
