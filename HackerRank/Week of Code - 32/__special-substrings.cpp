#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXSZ = 1 << 19;

char s[2 * MAXSZ];

bool k_cmp(int a1, int b1, int a2, int b2, int a3 = 0, int b3 = 0) {
    return a1 != b1 ? a1 < b1 : (a2 != b2 ? a2 < b2 : a3 < b3);
}

int bucket[MAXSZ+1], tmp[2 * MAXSZ];
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

int m0[MAXSZ/3+1];
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

vector<int> karkkainen(const string& ss) {
    int n = ss.size(), cnt = 1;
    vector<int> v(n + 3);

    for(int i = 0; i < n; i++) v[i] = i;
    k_radix(ss.begin(), &v[0], tmp, 0, n, 256);
    for(int i = 0; i < n; cnt += (i+1 < n && ss[tmp[i+1]] != ss[tmp[i]]), i++)
        v[tmp[i]] = cnt;

    return k_rec(v, cnt);
}

vector<int> lcp(const string& ss, const vector<int>& sa) {
    int n = sa.size();
    vector<int> prm(n), ans(n-1);
    for(int i = 0; i < n; i++) prm[sa[i]] = i;

    for(int h = 0, i = 0; i < n; i++)
        if(prm[i]) {
            int j = sa[prm[i]-1], ij = max(i, j);
            while(ij + h < n && ss[i+h] == ss[j+h]) h++;
            ans[prm[i]-1] = h;
            if(h) h--;
        }
    return ans;
}

vector<int> manacher(const string& ss) {
  s[0] = '#';
  int n = 1;
  for (char c : ss) {
    s[n++] = c;
    s[n++] = '#';
  }

  for (int i = 0; i < n; ++i) {
    tmp[i] = 0;
  }

  int cur = 1;
  while (cur < n) {
    while ((cur > tmp[cur]) &&
           (cur+tmp[cur]+1 < n) &&
           (s[cur-tmp[cur]-1] == s[cur+tmp[cur]+1]))
      tmp[cur]++;

    int j = 1;
    while ((cur+j < n) && (j < tmp[cur]-tmp[cur-j])) {
      tmp[cur+j] = tmp[cur-j];
      j++;
    }

    if (cur+j < n)
      tmp[cur+j] = tmp[cur]-j;
    cur += j;
  }
  vector<int> r(ss.size());

  for (int i = 0; i < n; ++i) {
    int end, sz;
    if (i & 1) {
      end = (i / 2) + ((tmp[i]-1)/2);
      sz = tmp[i];

    } else {
      end = (i/2) + (tmp[i]/2) - 1;
      sz = tmp[i];
    }
    while (sz > 0) {
      r[end] = max(r[end], sz);
      sz -= 2;
      end--;
    }
  }
  return r;
}

int M[MAXSZ][20];

int start_at[MAXSZ];

int get_lcp(int i, int j) {
  if (i == j) return start_at[i];
  if (i > j) swap(i, j); j--;
  int len = j - i + 1;
  int k = 0;
  while (len) {
    k++; len /= 2;
  }
  k--;

  return min(M[i][k], M[j - (1<<k) + 1][k]);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string ss;
  cin >> ss;

  auto sa = karkkainen(ss);
  auto end_at = manacher(ss);
  auto lc = lcp(ss, sa);

  for (int i = 0; i < n; ++i) start_at[i] = 0;

  for (int i = 0; i < (n-1); i++)
    M[i][0] = lc[i];

  for (int j = 1; (1 << j) <= (n-1); ++j)
    for (int i = 0; (i + (1 << j) - 1) < (n-1); ++i)
      M[i][j] = min(M[i][j-1], M[i + (1 << (j - 1))][j - 1]);

  for (int i = 0; i < n; ++i) {
    tmp[sa[i]] = i;
  }

  set<int> active;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int beg = i - end_at[i] + 1;

    auto it = active.lower_bound(tmp[beg]);
    int cur_lc = 0;
    while (it != active.end()) {
      int nxt = get_lcp(tmp[beg], *it);
      if (nxt < cur_lc) break;
      cur_lc = nxt;
      it++;
    }

    it = active.lower_bound(tmp[beg]);
    while (it != active.begin()) {
      it--;
      int nxt = get_lcp(tmp[beg], *it);
      if (nxt < cur_lc) break;
      cur_lc = nxt;
    }

    start_at[tmp[beg]] = max(start_at[tmp[beg]], end_at[i]);
    res += max(0, end_at[i] - cur_lc);
    active.insert(tmp[beg]);
    cout << res << "\n";
  }

  return 0;
}
