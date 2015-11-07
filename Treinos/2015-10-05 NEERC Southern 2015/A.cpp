#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool endswith(string a, string b) {
	if (a.size() > b.size()) return false;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < int(a.size()); ++i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

string normalize(string &email) {
	string res = email;
	for (char &c : res) c = tolower(c);
	if (endswith("@bmail.com", res)) {
		string id = "";
		for (char &c : res) {
			if (c == '.') continue;
			if (c == '+' || c == '@') break;
			id += c;
		}
		res = id + "@bmail.com";
	}
	return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    map<string, vector<string>> res;
    while (n--) {
    	string add;
    	cin >> add;
    	res[normalize(add)].push_back(add);
    }

    cout << res.size() << "\n";
    for (auto &entry : res) {
    	cout << entry.second.size();
    	for (auto &add : entry.second) {
    		cout << " " << add;
    	}
    	cout << "\n";
    }

	return 0;
}
