#include <iostream>
#include <set>
#include <queue>
#include <tr1/unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {

		tr1::unordered_set<int> seen;
		queue<int> q;

		int n; cin >> n;
		int res = 0;
		while (n--) {
			int x; cin >> x;
			while (seen.count(x)) {
				seen.erase(q.front());
				q.pop();
			}
			q.push(x);
			seen.insert(x);
			res = max(res, int(seen.size()));
		}
		cout << res << "\n";
	}

	return 0;
}