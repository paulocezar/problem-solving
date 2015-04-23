#include <iostream>
#include <queue>

using namespace std;

struct task_t {
	int ini, end, repeat;
	task_t(int a = 0, int b = 0, int c = 0) : ini(a), end(b), repeat(c) {}
	bool operator < (const task_t &t) const {
		if (ini != t.ini) return ini > t.ini;
		return end > t.end;
	}
};

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	while (cin >> n >> m && (n || m)) {

		priority_queue< task_t > q;
		for (int i = 0; i < n; ++i) {
			int a, b; cin >> a >> b;
			q.push(task_t(a,b));
		}
		for (int i = 0; i < m; ++i) {
			int a, b, c; cin >> a >> b >> c;
			q.push(task_t(a,b,c));
		}

		bool ok = true;

		while (!q.empty()) {
			task_t cur = q.top(); q.pop();
			
			if (cur.repeat && ((cur.ini+cur.repeat) <= 1000000)) {
				q.push(task_t(cur.ini+cur.repeat, cur.end+cur.repeat, cur.repeat));
			}

			if (!q.empty()) {
				
				if (cur.end > q.top().ini) {
					ok = false;
					break;
				}		

			}
		}

		if (ok) cout << "NO CONFLICT\n";
		else cout << "CONFLICT\n";

	}

	return 0;
}