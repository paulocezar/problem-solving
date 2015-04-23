#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int N, S;
	while (cin >> N >> S) {

		int x;
		int sum = 0;
		int res = 0;
		queue<int> q;

		for (int i = 0; i < N; ++i) {
			cin >> x;
			q.push(x);
			sum += x;
			while (sum >= S) {
				if (!res || res > int(q.size())) res = q.size();
				sum -= q.front(); q.pop();
			}
		}

		cout << res << "\n";
	}

	return 0;
}