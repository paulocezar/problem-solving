#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int cnt[256];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream in("concatenation.in");
    ofstream out("concatenation.out");

    string a, b;
    in >> a >> b;
    
    int sa = a.size();
    int sb = b.size();

    for (int i = 0; i < (sb-1); ++i) cnt[b[i]]++;

    int64 ans = sb;
	for (int i = 1; i < sa; ++i) {
		ans += sb-cnt[a[i]];
	}
	out << ans << "\n";

	return 0;
}
