#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	map<int, string> dtr;
	map<char, int> rtd;
	
	dtr[1] = "I"; dtr[5] = "V"; dtr[10] = "X"; dtr[50] = "L"; dtr[100] = "C"; dtr[500] = "D"; dtr[1000] = "M";
	dtr[4] = "IV"; dtr[9] = "IX"; dtr[40] = "XL"; dtr[90] = "XC"; dtr[400] = "CD"; dtr[900] = "CM"; 
	
	rtd['I'] = 1; rtd['V'] = 5; rtd['X'] = 10; rtd['L'] = 50; rtd['C'] = 100; rtd['D'] = 500; rtd['M'] = 1000; 
	
	int qtd;
	cin >> qtd;
	
	string str;
	int ans;
	int sz;
	int tc = 1;
	while (qtd) {
		ans = 0;
		
		while (qtd--) {
			cin >> str;
			sz = str.size();
		
			char last = str[0];
			for (int i = 1; i < sz; ++i) {
				if (last != -1 && rtd[last] < rtd[str[i]] && 10 * rtd[last] >= rtd[str[i]]) {
					ans += rtd[str[i]] - rtd[last];
					last = -1;
				}
				else {
					ans += rtd[last];
					last = str[i];
				}			
			}
			
			ans += (last != -1) ? rtd[last] : 0;
		}
		
		string rans;
		map<int, string>::reverse_iterator rit;
		
		while (ans > 0) {
			rit = dtr.rbegin();
			
			while (rit->first > ans && rit != dtr.rend()) ++rit;
			
			sz = ans / rit->first;
			ans -= rit->first * sz;
			
			while (sz--) rans += rit->second;
		}
		
		string cas;
		int tc2 = tc++;
		while (tc2 > 0) {
			rit = dtr.rbegin();
			
			while (rit->first > tc2 && rit != dtr.rend()) ++rit;
			
			sz = tc2 / rit->first;
			tc2 -= rit->first * sz;
			
			while (sz--) cas += rit->second;
		}
		
		cout << "Case " << cas << ": "<< rans << '\n';
		cin >> qtd;
	}
	
	return 0;
}