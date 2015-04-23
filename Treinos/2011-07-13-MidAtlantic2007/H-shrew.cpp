#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

int main() 
{
	ios::sync_with_stdio(false);
	
	string op;
	ull mask;
	string str;
	
	cin >> op;
	while (op != "X") {
		vector<ull> m, f, c, mf;
	
		cin >> str;
		const int size = str.size();		
		mask = 0;
		for (int i = 0; i < size; ++i) { mask <<= 1; mask |= (str[i] - '0'); } 
		
		if (op == "M") m.push_back(mask);
		else if (op == "F") f.push_back(mask);
		else c.push_back(mask);
	
		cin >> op;
		while (op != "X") {
			cin >> str;
			mask = 0;
			for (int i = 0; i < size; ++i) { mask <<= 1; mask |= (str[i] - '0'); }
		
			if (op == "M") m.push_back(mask);
			else if (op == "F") f.push_back(mask);
			else c.push_back(mask);
			
			cin >> op;
		}
		
		int szm = m.size();
		int szf = f.size();
		
		for (int i = 0; i < szm; ++i) {
			for (int j = 0; j < szf; ++j) {
				mf.push_back(m[i] | f[j]);
			}
		}

		szf = mf.size();
		szm = c.size();
		
		for (int i = 0; i < szm; ++i) {
			int mini = size;
			
			for (int j = 0; j < szf; ++j) {
				mini = min(mini, __builtin_popcountll(c[i] ^ mf[j]));
			}
			
			cout << "Child " << i+1 << " has a minimum of " << mini << " mutations.\n";
		}
		
	
		cin >> op;
	}
	
	return 0;
}

