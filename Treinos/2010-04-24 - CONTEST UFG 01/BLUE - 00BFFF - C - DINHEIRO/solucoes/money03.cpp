#include <cassert>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> adj[20000];
int balance[20000];
int visited[20000];

int dfs(int v) {
  int ans = balance[v];
  visited[v] = true;
  for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
    if (!visited[*it]) ans += dfs(*it);
  return ans;
}

int main(void) {
  int tests, n, m;
  
	scanf("%d", &tests );
	while( tests-- ){
		scanf("%d %d", &n, &m);

  assert(2 <= n && n <= 10000);
  assert(0 <= m && m <= 50000);
  
  int s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", balance + i);
    assert(-10000 <= balance[i] && balance[i] <= 10000);
    s += balance[i];
	  adj[i].clear();
  }
  assert(s == 0);

  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    assert(0 <= a && a < b && b < n);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  memset(visited, 0, sizeof(visited));

  bool ok = true;
  for (int i = 0; ok && i < n; ++i) 
    if (!visited[i]) ok = (dfs(i)==0);
  
  printf("%sPOSSIVEL\n", ok ? "" : "IM");
	}
  return 0;
}
