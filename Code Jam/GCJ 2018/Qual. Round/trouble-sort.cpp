#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int kase = 1; kase <= T; ++kase)
  {
    int N;
    cin >> N;

    vector<vector<int>> split(2);
    split[0].reserve((N+1) / 2);
    split[1].reserve((N+1) / 2);
    for (int i = 0; i < N; ++i)
    {
      int x; cin >> x;
      split[i&1].push_back(x);
    }

    for (auto& p : split) sort(p.begin(), p.end());

    vector<int> sorted(N);
    int idx = 0;
    for (int v : split[0]) { sorted[idx] = v; idx += 2; }
    idx = 1;
    for (int v : split[1]) { sorted[idx] = v; idx += 2; }

    for (idx = 1; idx < N; ++idx)
    {
      if (sorted[idx-1] > sorted[idx]) break;
    }

    cout << "Case #" << kase << ": ";
    if (idx == N) cout << "OK\n";
    else cout << idx-1 << "\n";

  }



  return 0;
}
