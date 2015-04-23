#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > vet;
vector<vector<int> > pos;
int N, L;

int solve(int pos = 0)
{
	int bulls = vet[pos][N-2];
	int cows  = vet[pos][N-1];
	
	
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	int x;
	while (N) {
		pos.clear();
		vet.clear();
		
		cin >> x;
		L = 0;
		while (x != -1) {
			vet[L].push_back(x);
			for (int i = 1; i < N+2; ++i) {
				cin >> x;
				vet[L].push_back(x);
			}
			L++;
		}
		for (int i = 1; i < N+2; ++i) cin >> x;
		
		pos.resize(N);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 10; ++j) pos[i].push_back(j);
		}
	
		solve();
	
		cin >> N;
	}

	return 0;
}

