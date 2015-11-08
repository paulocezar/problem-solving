#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

pair<int,int> prices[1<<16];

int max_jump[1<<16];
int64 reenter[1<<16];


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream in("journey.in");
    ofstream out("journey.out");

    int n; int64 t;
    in >> n >> t;

    for (int r = 1; r < n; ++r) {
    	in >> prices[r-1].first; prices[r-1].second = r;
    }

    sort(prices, prices+n-1);
    max_jump[0] = prices[0].second;
    for (int r = 1; r < (n-1); ++r) {
    	max_jump[r] = max(max_jump[r-1], prices[r].second);
    }

    for (int stop = 2; stop < n; ++stop) in >> reenter[stop];
    t -= n-1;

    int lo = 0, hi = n-2;
	while (lo <= hi) {
		int mid = (lo+hi)>>1;
		int window = max_jump[mid];

		queue<int64> q;
		deque<int64> qmin;
		q.push(0);
		qmin.push_back(0);

		int64 reached = 2e9;
		for (int stop = 2; stop <= n; ++stop) {
			int64 best = qmin.front() + reenter[stop];

			if (stop == n) reached = best;
			q.push(best);
			while (!qmin.empty() && (qmin.back() > best)) qmin.pop_back();
			qmin.push_back(best);

			if (int(q.size()) > window) {
				if (qmin.front() == q.front()) qmin.pop_front();
				q.pop();
			}
		}

		if (reached <= t) {
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}

	out << prices[lo].first << "\n";

	return 0;
}
