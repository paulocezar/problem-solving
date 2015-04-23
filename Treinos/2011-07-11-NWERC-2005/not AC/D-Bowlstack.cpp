#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct st { int h, top, down; };

bool operator<(const st& a, const st& b)
{
	if (a.h != b.h) return a.h < b.h;
	if (a.top != b.top) return a.top < b.top;
	
	return a.down < b.down;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int tc;
	cin >> tc;

	int n;
	st vet[14];
	
	while (tc--) {
		cin >> n;
		
		for (int i = 0; i < n; ++i) cin >> vet[i].h >> vet[i].down >> vet[i].top;
		
		sort(vet, vet + n);
		
		double ans = 0;
		double curr;
		
		double cresc, cresatu, a, b;
		do {
			curr = vet[0].h;
			
			for (int i = 1; i < n; ++i) {
				cresc = (vet[i-1].top - vet[i-1].down) / double(vet[i-1].h);
				cresatu = (vet[i].top - vet[i].down) / double(vet[i].h);
				
				
				if (vet[i].down < vet[i-1].top) {
					a = (vet[i].down - vet[i-1].down) / cresc;
				}
				else {
					a = vet[i-1].h;
				}
				
				if (vet[i].top >= vet[i-1].top) {
					b = (vet[i-1].top - vet[i].down) / cresatu;
				}
				else {
					b = (vet[i].top - vet[i-1].down) / cresc;
				}
				
				if (a < 0.0) a = 0.0;
				if (b < 0.0) b = 0.0;
				
				if ((curr + vet[i].h - b) <= (a + vet[i].h)) {
					curr += vet[i].h - b;
				}
				else curr = a + vet[i].h;
			}
			
			ans = max(ans, curr);	
			
		} while (next_permutation(vet, vet + n));
		
		cout << int(ans) << "\n";
	}
	
	return 0;	
}
