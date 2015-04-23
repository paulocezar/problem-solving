#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define INF 0x3f3f3f3f3f3f3f3fll

using namespace std;

struct st { int lin, col; };

st vet[50*52];
int pos[52];

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int H, L;
	while (n--) {
		cin >> H >> L;
		
		int x;
		int maior = 0;
		for (int i = 0; i < H; ++i) {
			pos[i] = 0;
		
			for (int j = 0; j < L; ++j) {
				cin >> x;
				
				if (x != -1) {
					vet[x].lin = i;
					vet[x].col = j;
					
					maior = max(maior, x);
				}
			}
		}
		
		int ans = 0;
		
		for (int i = 1; i <= maior; ++i) {
			ans += 20 * vet[i].lin;
			
			ans += 5 * min(abs(pos[vet[i].lin] - vet[i].col), L - max(pos[vet[i].lin], vet[i].col) + min(pos[vet[i].lin], vet[i].col));
			
			
			pos[vet[i].lin] = vet[i].col;
		}
		
		cout << ans << '\n';
	}
	
	return 0;	
}






















