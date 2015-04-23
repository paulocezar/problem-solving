#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > edge;
vector<int> owe;
vector<bool> visited;

int dfs(int cur)
{
	if (visited[cur]) return 0;
	visited[cur] = true;
	int sum = owe[cur];
	for(int i=0;i<edge[cur].size();i++)
		sum += dfs(edge[cur][i]);
	return sum;
}

int main()
{
	int tests, n, m;
	bool flag;
	cin >> tests;
	
	while( tests-- ){
		cin >> n >> m;
		flag = true;
		edge.clear();
		edge.resize(n);
		owe.clear();
		owe.resize(n);
		visited.clear();
		visited.resize(n);
		for(int i=0;i<n;i++) cin >> owe[i];
		for(int i=0;i<m;i++) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for(int i=0;i<n;i++) {
			if (visited[i]) continue;
			int t = dfs(i);
			if (t != 0) {
				cout << "IMPOSSIVEL" << endl;
				flag = false;
				break;
			}
		}
		if( flag )
		cout << "POSSIVEL" << endl;
	}
	return 0;
}
