#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int cnt[2][2];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
	int N, x, y;
	while (cin >> N && N) {
		int cx, cy, r1, r2;
		cin >> cx >> cy >> r1 >> r2;

		r1 *= r1;
		r2 *= r2;

		N <<= 1;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < N; ++i) {
			cin >> x >> y;
			int d = (x-cx)*(x-cx) + (y-cy)*(y-cy);
			if (d < r1) cnt[i&1][0]++;
			else if (d <= r2) cnt[i&1][1]++;
		}

		int sC = 10000*cnt[0][0] + cnt[0][1];
		int sP = 10000*cnt[1][0] + cnt[1][1];

		if (sC > sP) cout << "C > P\n";
		else if (sP > sC) cout << "P > C\n";
		else cout << "C = P\n";
	}    

	return 0;
}

















