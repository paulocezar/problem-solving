#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 a[1<<19];
int len1, len2, qnt1, qnt2;

map< int, int64> cached[1<<13];

int64 solve(int got1, int got2) {
	if (got1 == qnt1 && got2 == qnt2) return 0LL;
	if (cached[got1].count(got2)) return cached[got1][got2];
	int64 a1 = -1LL;
	int64 a2 = -1LL;

	int pos = got1*len1 + got2*len2 + got1 + got2;

	if (got1 < qnt1) {
		a1 = solve(got1+1, got2);
		if (len1) a1 += (a[pos+len1-1] - (pos ? a[pos-1] : 0));
	}

	if (got2 < qnt2) {
		a2 = solve(got1, got2+1) + (a[pos+len2-1] - (pos ? a[pos-1] : 0));
	}

	if ((a1 != -1LL) && (a2 != -1LL)) a1 = min(a1, a2);
	else if (a2 != -1LL) a1 = a2;
	cached[got1][got2] = a1;
	return a1;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a+n);
    
    for (int i = 0; i < n-1; ++i) a[i] = a[i+1] - a[i];
    for (int i = 1; i < n-1; ++i) a[i] += a[i-1];
    
    len1 = max(n / k - 1, 0);
	len2 = len1 + 1;
	qnt2 = n % k;
	qnt1 = k - qnt2;

	cout << solve(0, 0) << "\n";

	return 0;
}

















