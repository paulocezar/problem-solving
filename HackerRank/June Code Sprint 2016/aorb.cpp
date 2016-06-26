#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

inline int get_bit(int bit, int val) {
  return (val>>bit) & 1;
}

inline void unset_bit(int bit, int &val) {
  val &= (15 ^ (1<<bit));
}

inline void set_bit(int bit, int &val) {
  val |= (1<<bit);
}

inline int to_int(char hx) {
  if (isdigit(hx)) return int(hx-'0');
  return 10 + int(toupper(hx) - 'A');
}

inline char to_hex(int dc) {
  if (dc < 10) return '0' + dc;
  return 'A' + (dc - 10);
}

char get_dig(int dig, string &s) {
  return s[s.size() - 1 - dig];
}

void set_dig(int dig, string &s, char vl) {
  s[s.size() - 1 - dig] = vl;
}

void norm(string &s, int len) {
  int need = len - s.size();
  s = string(need, '0') + s;
}

int make_equal(string &a, string &b, string &c) {
  int digs = max(a.size(), max(b.size(), c.size()));
  norm(a, digs);
  norm(b, digs);
  norm(c, digs);
  int need = 0;
  for (int dig = digs-1; dig >= 0; --dig) {
    int aa = to_int(get_dig(dig, a));
    int bb = to_int(get_dig(dig, b));
    int cc = to_int(get_dig(dig, c));
    for (int i = 3; i >= 0; --i) {
      if ((get_bit(i, aa) | get_bit(i, bb)) == get_bit(i, cc)) continue;
      if (get_bit(i, cc)) {
        need++;
        set_bit(i, bb);
      } else {
        need += get_bit(i, aa) + get_bit(i, bb);
        unset_bit(i, aa);
        unset_bit(i, bb);
      }
    }
    set_dig(dig, a, to_hex(aa));
    set_dig(dig, b, to_hex(bb));
  }
  return need;
}

void minimize(string &a, string &b, string &c, int &has) {
  int digs = a.size();
  for (int dig = digs-1; has && dig >= 0; --dig) {
    int aa = to_int(get_dig(dig, a));
    if (aa) {
      int bb = to_int(get_dig(dig, b));
      int cc = to_int(get_dig(dig, c));
      for (int i = 3; has && i >= 0; --i) {
        if (get_bit(i, cc) && get_bit(i, aa)) {
          if (!get_bit(i, bb) && has >= 2) {
            has -= 2;
            unset_bit(i, aa);
            set_bit(i, bb);
          } else if (get_bit(i, bb)) {
            has--;
            unset_bit(i, aa);
          }
        }
      }
      set_dig(dig, a, to_hex(aa));
      set_dig(dig, b, to_hex(bb));
    }
  }
}

void print(string &s) {
  bool fl = false;
  int i = 0, sz = s.size();
  while (i < sz && s[i] == '0') i++;
  while (i < sz) { cout << s[i++]; fl = true; }
  if (!fl) cout << "0";
  cout << "\n";
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int Q;
  cin >> Q;

  while (Q--) {
    int K;
    cin >> K;
    string A, B, C;
    cin >> A >> B >> C;
    int need = make_equal(A, B, C);
    if (need <= K) {
      K -= need;
      minimize(A, B, C, K);
      print(A);
      print(B);
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
