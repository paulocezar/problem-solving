#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXN = 1<<17;

struct node {
  map<int,int> next;  // outgoing edges
  int len;            // length of this palindrome
  int link;           // longest proper suffix-palindrome
  int occ;            // occurrences of this
};

node tree[MAXN];

int last_node;        // node 1 - root with len -1, node 2 - root with len 0
int max_suff;         // max suffix palindrome

string s;

bool addLetter(int pos) {
  int cur = max_suff, curlen = 0;
  int letter = s[pos] - 'a';

  while (true) {
    curlen = tree[cur].len;
    if (((pos - 1 - curlen) >= 0) && (s[pos - 1 - curlen] == s[pos]))
      break;
    cur = tree[cur].link;
  }

  if (tree[cur].next.count(letter)) {
    max_suff
   = tree[cur].next[letter];
    return false;
  }

  last_node++;
  max_suff
 = last_node;
  tree[last_node].len = tree[cur].len + 2;
  tree[cur].next[letter] = last_node;

  if (tree[last_node].len == 1) {
    tree[last_node].link = 2;
    return true;
  }

  while (true) {
    cur = tree[cur].link;
    curlen = tree[cur].len;
    if (((pos - 1 - curlen) >= 0) && (s[pos - 1 - curlen] == s[pos])) {
      tree[last_node].link = tree[cur].next[letter];
      break;
    }
  }

  return true;
}

void init_tree() {
  last_node = 2; max_suff
 = 2;
  tree[1].len = -1; tree[1].link = 1;
  tree[2].len = 0; tree[2].link = 1;
}

const int64 BASE = 1e5 + 1;
const int64 MOD = 1e9 + 7;

int64 h[MAXN], pw[MAXN];

int64 calc_hash(int beg, int end) {
  return ((h[end+1] - (h[beg]*pw[end-beg+1])%MOD)%MOD + MOD) % MOD;
}

bool k_cmp(int a1, int b1, int a2, int b2, int a3 = 0, int b3 = 0) {
    return a1 != b1 ? a1 < b1 : (a2 != b2 ? a2 < b2 : a3 < b3);
}

int bucket[MAXN+1], tmp[MAXN];
template<class T> void k_radix(T keys, int *in, int *out,
                               int off, int n, int k) {
    memset(bucket, 0, sizeof(int) * (k+1));

    for(int j = 0; j < n; j++)
        bucket[keys[in[j]+off]]++;
    for(int j = 0, sum = 0; j <= k; j++)
        sum += bucket[j], bucket[j] = sum - bucket[j];
    for(int j = 0; j < n; j++)
        out[bucket[keys[in[j]+off]]++] = in[j];
}

int m0[MAXN/3+1];
vector<int> k_rec(const vector<int>& v, int k) {
    int n = v.size()-3, sz = (n+2)/3, sz2 = sz + n/3;
    if(n < 2) return vector<int>(n);

    vector<int> sub(sz2+3);
    for(int i = 1, j = 0; j < sz2; i += i%3, j++)
        sub[j] = i;

    k_radix(v.begin(), &sub[0], tmp, 2, sz2, k);
    k_radix(v.begin(), tmp, &sub[0], 1, sz2, k);
    k_radix(v.begin(), &sub[0], tmp, 0, sz2, k);

    int last[3] = {-1, -1, -1}, unique = 0;
    for(int i = 0; i < sz2; i++) {
        bool diff = false;
        for(int j = 0; j < 3; last[j] = v[tmp[i]+j], j++)
            diff |= last[j] != v[tmp[i]+j];
        unique += diff;

        if(tmp[i]%3 == 1) sub[tmp[i]/3] = unique;
        else sub[tmp[i]/3 + sz] = unique;
    }

    vector<int> rec;
    if(unique < sz2) {
        rec = k_rec(sub, unique);
        rec.resize(sz2+sz);
        for(int i = 0; i < sz2; i++) sub[rec[i]] = i+1;
    } else {
        rec.resize(sz2+sz);
        for(int i = 0; i < sz2; i++) rec[sub[i]-1] = i;
    }

    for(int i = 0, j = 0; j < sz; i++)
        if(rec[i] < sz)
            tmp[j++] = 3*rec[i];
    k_radix(v.begin(), tmp, m0, 0, sz, k);
    for(int i = 0; i < sz2; i++)
        rec[i] = rec[i] < sz ? 3*rec[i] + 1 : 3*(rec[i] - sz) + 2;

    int prec = sz2-1, p0 = sz-1, pret = sz2+sz-1;
    while(prec >= 0 && p0 >= 0)
        if(rec[prec]%3 == 1 && k_cmp(v[m0[p0]], v[rec[prec]],
                                     sub[m0[p0]/3], sub[rec[prec]/3+sz]) ||
           rec[prec]%3 == 2 && k_cmp(v[m0[p0]], v[rec[prec]],
                                     v[m0[p0]+1], v[rec[prec]+1],
                                     sub[m0[p0]/3+sz], sub[rec[prec]/3+1]))
            rec[pret--] = rec[prec--];
        else
            rec[pret--] = m0[p0--];
    if(p0 >= 0) memcpy(&rec[0], m0, sizeof(int) * (p0+1));

    if(n%3==1) rec.erase(rec.begin());
    return rec;
}

vector<int> karkkainen() {
    int n = s.size(), cnt = 1;
    vector<int> v(n + 3);

    for(int i = 0; i < n; i++) v[i] = i;
    k_radix(s.begin(), &v[0], tmp, 0, n, 256);
    for(int i = 0; i < n; cnt += (i+1 < n && s[tmp[i+1]] != s[tmp[i]]), i++)
        v[tmp[i]] = cnt;

    return k_rec(v, cnt);
}

vector<int> lcp(const vector<int>& sa) {
    int n = sa.size();
    vector<int> prm(n), ans(n-1);
    for(int i = 0; i < n; i++) prm[sa[i]] = i;

    for(int h = 0, i = 0; i < n; i++)
        if(prm[i]) {
            int j = sa[prm[i]-1], ij = max(i, j);
            while(ij + h < n && s[i+h] == s[j+h]) h++;
            ans[prm[i]-1] = h;
            if(h) h--;
        }
    return ans;
}

pair<int64, int> res[MAXN];

typedef pair<pair<int,int>,int> palindrome;

int M[1<<17][17];
vector<int> lc;

bool cmp(palindrome &p1, palindrome &p2) {
  if (p1.first.first != p2.first.first) {
    int l = tmp[p1.first.first];
    int r = tmp[p2.first.first];
    if (l > r) swap(l, r);
    r--;
    int len = r-l+1;
    int k = 0;
    while ((1<<k) <= len) k++;
    k--;
    int mn = min(lc[M[l][k]], lc[M[r-(1<<k)+1][k]]);
    if (p1.first.first+mn > p1.first.second) return true;
    if (p2.first.first+mn > p2.first.second) return false;
    return s[p1.first.first+mn] < s[p2.first.first+mn];
  }
  return p1.first.second < p2.first.second;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  cin >> s;

  for (int i = 0; i < q; ++i) {
    cin >> res[i].first; res[i].second = i;
  }

  init_tree();

  pw[0] = 1LL;
  h[0] = 0LL;
  vector<palindrome> palindromes;

  for (int i = 0; i < n; ++i) {
    pw[i+1] = (pw[i] * BASE) % MOD;
    h[i+1] = (h[i]*BASE + int64(s[i])) % MOD;

    if (addLetter(i)) {
      palindromes.emplace_back(make_pair(make_pair(i-tree[max_suff].len + 1, i), max_suff));
    }
    tree[max_suff].occ++;
  }

  for (int i = last_node; i >= 1; --i) tree[tree[i].link].occ += tree[i].occ;

  auto sa = karkkainen();
  lc = lcp(sa);

  for (int i = 0; i < n-1; ++i) {
    M[i][0] = i;
  }

  for (int j = 1; (1 << j) <= n-1; ++j) {
    for (int i = 0; i + (1 << j) - 1 < n-1; ++i) {
      if (lc[M[i][j - 1]] < lc[M[i + (1 << (j - 1))][j - 1]])
        M[i][j] = M[i][j - 1];
      else
        M[i][j] = M[i + (1 << (j - 1))][j - 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    tmp[sa[i]] = i;
  }

  sort(palindromes.begin(), palindromes.end(), cmp);

  sort(res, res+q);
  int j = 0;
  int64 seen = 0LL;
  for (auto &ntry : palindromes) {
    seen += tree[ntry.second].occ;
    while ((j < q) && (res[j].first <= seen)) {
      res[j].first = res[j].second;
      res[j].second = calc_hash(ntry.first.first, ntry.first.second);
      j++;
    }
  }

  while (j < q) {
    res[j].first = res[j].second;
    res[j].second = -1;
    j++;
  }
  sort(res, res+q);

  for (int i = 0; i < q; ++i) {
    cout << res[i].second << "\n";
  }

  return 0;
}
