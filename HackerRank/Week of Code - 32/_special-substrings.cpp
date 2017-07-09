#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int MAXSZ = 1 << 19;

char s[2 * MAXSZ];
int tmp[2 * MAXSZ];

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

struct node_t {
  map<char, node_t*> chld;
};

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string ss;
  cin >> ss;

  auto end_at = manacher(ss);

  node_t* root = new node_t();

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int beg = i - end_at[i] + 1;

    auto cur = root;
    while ((beg <= i) && (cur->chld).count(ss[beg])) {
      cur = cur->chld[ss[beg++]];
    }
    while (beg <= i) {
      cur->chld[ss[beg]] = new node_t();
      cur = cur->chld[ss[beg++]];
      res++;
    }
    cout << res << "\n";
  }

  return 0;
}
