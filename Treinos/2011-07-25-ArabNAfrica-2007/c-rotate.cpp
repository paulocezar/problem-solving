#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int n,na;
	int a,b,c,d,k=1,j=1;
	int mat[1001][1001], correto[1001][1001];
	int quant[1001];
	int str[4000], strcorreto[4000];
	int start,add;
	
	for(cin>>n; n != 0; cin>>n){
		na = (n+1)/2;
		c = 1;
		for(a=0;a<n;a++){
			for(b=0;b<n;b++){
				cin>>mat[a][b];
				correto[a][b] = c++;
			}
		}
		start = (n%2 == 0? 2 : 1);
		for(a=0;a<na;a++){
			quant[na-1-a] = start;
			start+=2;
		}
		add = 0;
		for(a=0;a<na;a++){
			if(quant[a] == 1){
				
			}
			d = 0;
			c = quant[a];
			for(b = 0; b < c; b++){
				str[d] = mat[add][add+b];
				strcorreto[d++] = correto[add][add+b];
			}
			if(c == 1){
				goto check;
			}
			for(b = 1; b <= c-2; b++){
				str[d] = mat[add+b][add+c-1];
				strcorreto[d++] = correto[add+b][add+c-1];
			}
			for(b = quant[a]-1; b >= 0; b--){
				str[d] = mat[add+c-1][add+b];
				strcorreto[d++] = correto[add+c-1][add+b];
			}
			for(b = quant[a]-2; b >= 1; b--){
				str[d] = mat[add+b][add];
				strcorreto[d++] = correto[add+b][add];
			}
			
			check:
			for(b = 0; b < d; b++){
				if(str[b] == strcorreto[0]) break;
			}
			if(b == d) break;
			for(c = 0; c < d; c++){
				if(strcorreto[c] != str[(b+c)%d]) break;
			}
			if(c != d) break;
			add++;
		}
		if(a == na){
			cout << (j++) << ". YES\n";
		} else {
			cout << (j++) << ". NO\n";
		}
	}
	
	return 0;
}

