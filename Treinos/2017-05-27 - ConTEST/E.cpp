#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	int t, r;
	char c;
	cin >> t;
	string str;
	for(int k = 1; k <= t; k++){
		cin >> str;
		int p1 = 0, p2 = 0;
		string ans = "Sim";
		stack < char > p;
		for(int i =0; i < str.size(); i += 2){
			if( str[i] == 'R' ){
				if( str[i+1] == '1' ){
					if( p.empty() || p.top() != '2' ){
						ans = "Nao";
						break;
					}
					p.pop();
				}
				else{
					if( p.empty() || p.top() != '1' ){
						ans = "Nao";
						break;
					}
					p.pop();
				}
			}
			else{
				p.push(str[i+1]);
			}
		}
		if( !p.empty() ) ans = "Nao";
		cout << "Caso " << k << ": " << ans << "\n";
	}
	return 0;
}
