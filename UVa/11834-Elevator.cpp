#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

int main() {
	ios::sync_with_stdio(false);

	int L, C, R1, R2;
	while (cin >> L >> C >> R1 >> R2 && (L || C || R1 || R2)) {


		if (((sqr(R1+R2-L) + sqr(R1+R2-C)) >= sqr(R1+R2)) && ((max(R1,R2)<<1) <= min(L,C)))
			cout << "S\n";
		else cout << "N\n";

	}

	return 0;
}