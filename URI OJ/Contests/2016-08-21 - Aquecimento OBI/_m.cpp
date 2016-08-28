#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXNODES = 1<<21;

struct node {
  int prior, value, sz;
  bool rev;
  int occ[26], first[26], last[26];
  node *l, *r;

  node(int val) {
    prior = rand();
    value = val;
    sz = 1;
    rev = false;
    memset(occ, 0, sizeof(occ));
    memset(first, 0, sizeof(first));
    memset(last, 0, sizeof(last));
    l = NULL; r = NULL;
  }
};

typedef node* pnode;

int get_size(pnode t) {
  return t == NULL ? 0 : t->sz;
}

void update(pnode t) {
  if (t == NULL) return;
  t->sz = get_size(t->l) + 1 + get_size(t->r);

  int pos = get_size(t->l) + 1;

  for (int i = 0; i < 26; ++i) {
    t->occ[i] = 0;
    t->first[i] = 0;
    t->last[i] = 0;

    if (t->l) {
      t->occ[i] = t->l->occ[i];
      t->first[i] = t->l->first[i];
      t->last[i] = t->l->last[i];
    }

    if (t->r) {
      t->occ[i] += t->r->occ[i];

      int fo = t->r->first[i];
      int lo = t->r->last[i];

      if (fo) {
        fo += pos;
        lo += pos;

        if (t->first[i] == 0) {
          t->first[i] = fo;
        }

        if (lo > t->last[i]) {
          t->last[i] = lo;
        }
      }
    }
  }

  t->occ[t->value]++;
  if ((t->first[t->value] == 0) || (pos < t->first[t->value])) {
    t->first[t->value] = pos;
  }
  if (pos > t->last[t->value]) {
    t->last[t->value] = pos;
  }
}

void push(pnode t) {
  if (t == NULL || t->rev == false) return;
  t->rev = false;
  swap(t->l, t->r);
  if (t->l) t->l->rev ^= true;
  if (t->r) t->r->rev ^= true;

  for (int i = 0; i < 26; ++i) {
    swap(t->first[i], t->last[i]);
    if (t->first[i]) {
      t->first[i] = get_size(t) - t->first[i] + 1;
      t->last[i] = get_size(t) - t->last[i] + 1;
    }
  }
}

void merge(pnode &t, pnode l, pnode r) {
  push(l); push(r);
  if (l == NULL) {
    t = r;
  } else if (r == NULL) {
    t = l;
  } else if (l->prior > r->prior) {
    merge(l->r, l->r, r);
    t = l;
  } else {
    merge(r->l, l, r->l);
    t = r;
  }
  update(t);
}

void split(pnode t, pnode &l, pnode &r, int pos, int add = 0) {
  push(t);
  if (t == NULL) {
    l = r = NULL;
    return;
  }
  int cur_pos = get_size(t->l) + 1 + add;
  if (pos <= cur_pos) {
    split(t->l, l, t->l, pos, add);
    r = t;
  } else {
    split(t->r, t->r, r, pos, add + get_size(t->l) + 1);
    l = t;
  }
  update(t);
}

void reverse(pnode t, int l, int r) {
  pnode a, b;
  split(t, t, a, l);
  split(a, a, b, r - l + 2);
  a->rev ^= true;
  merge(t, t, a);
  merge(t, t, b);
}

int get_occ(pnode t, int val) {
  if (t == NULL) return 0;
  return t->occ[val];
}

int get_occ(pnode t, int l, int r, int val) {
  int ans;
  pnode a, b;
  split(t, t, a, l);
  split(a, a, b, r - l + 2);
  ans = get_occ(a, val);
  merge(t, t, a);
  merge(t, t, b);
  return ans;
}

pair<int,int> get_range(pnode t, int val) {
  if (t == NULL) return {-1, -1};
  int fst = t->first[val];
  int lst = t->last[val];
  if (!fst) fst = -1, lst = -1;
  return {fst, lst};
}

pair<int,int> get_range(pnode t, int l, int r, int val) {
  pair<int,int> ans;
  pnode a, b;
  split(t, t, a, l);
  split(a, a, b, r - l + 2);
  ans = get_range(a, val);
  if (ans.first > 0) {
    ans.first += l-1;
    ans.second += l-1;
  }
  merge(t, t, a);
  merge(t, t, b);
  return ans;
}

void insert(pnode &t, int value, int pos){
  pnode a;
  pnode nt = new node(value);
  split(t, t, a, pos);
  merge(t, t, nt);
  merge(t, t, a);
}

ostringstream out;
void print(pnode t) {
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

  pnode treap = NULL;

  for (int i = 0; i < L; ++i) {
    merge(treap, treap, new node(s[i]-'a'));
  }

  int op, l, r; string c;
  pair<int,int> ans;

  while (N--) {
    cin >> op;
    switch(op) {
      case 1:
        cin >> l >> r >> c;
        if (l > r) swap(l, r);
        out << get_occ(treap, l, r, c[0]-'a') << "\n";
        break;
      case 2:
        cin >> l >> r >> c;
        if (l > r) swap(l, r);
        ans = get_range(treap, l, r, c[0]-'a');
        if (ans.first == -1) { out << "-1\n"; }
        else { out << ans.first << " " << ans.second << "\n"; }
        break;
      case 3:
        cin >> l >> r;
        if (l > r) swap(l, r);
        reverse(treap, l, r);
        break;
      case 4:
        cin >> l >> c;
        L++;
        insert(treap, c[0]-'a', l);
        break;
    }
  }

  print(treap); out << "\n";

  cout << out.str();




  return 0;
}
