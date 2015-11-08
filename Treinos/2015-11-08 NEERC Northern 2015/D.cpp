#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int64> gen(int64 num) {
	if (num == 0LL) return vector<int64>(0);
	if (num & 1LL) {
		int64 largest = 1LL;
		while (3LL*largest <= num) largest *= 3LL;
		auto ret = gen(num-largest);
		ret.push_back(largest);
		return ret;
	} else {
		auto ret = gen(num/2LL);
		for_each(ret.begin(), ret.end(), [](int64 &n) { n<<=1; });
		return ret;
	}
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
	ifstream in("distribution.in");
    ofstream out("distribution.out");
    int t;
    in >> t;
    while (t--) {
    	int64 num;
    	in >> num;

    	auto res = gen(num);
    	out << res.size();
    	char sep = '\n';
    	for (auto &v : res) {
    		out << sep << v;
    		sep = ' ';
    	}
    	out << "\n";
	}
	return 0;
}
