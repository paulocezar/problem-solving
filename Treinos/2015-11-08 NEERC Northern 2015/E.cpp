#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream in("easy.in");
    ofstream out("easy.out");

    string xpr;
    in >> xpr;

    string ans = "";
	for (int i = 0, sz = xpr.size(); i < sz; ++i) {
		if (xpr[i] == '-') {
			ans += xpr[i];
			ans += xpr[i+1];
			int j = i+2;
			i+=2;
			while (j < sz) {
				switch (xpr[j]) {
					case '+':
					case '-':
						i = j-1;
						j = sz;
						break;
					case '0':
						ans += '+';
						ans += '0';
						i = j;
						j++;
						break;
					default:
						ans += '+';
						while ((j < sz) && ('0' <= xpr[j] && xpr[j] <= '9')) {
							ans += xpr[j];
							j++;
						}
						i = j - 1;
						j = sz;
						break;
				}
			}
		} else {
			ans += xpr[i];
		}
	}
	out << ans << "\n";

	return 0;
}
