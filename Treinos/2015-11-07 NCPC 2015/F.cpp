#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char might_reach[2][1<<14];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int f;
    cin >> f;
   	
   	bool possible = true;

    for (int i = 0; i < f; ++i) {
    	int len, ni;
    	cin >> len >> ni;

    	int cur = 0, old = 1;
    	for (int pos = 0; pos <= len; ++pos) might_reach[old][pos] = 1;
			

		for (int j = 1; j <= ni; ++j) {
			int ti, tf, dur;
			cin >> ti >> tf;
			dur = tf-ti;
			if (possible) {
				char at_least_one = 0;
				for (int pos = 0; pos <= len; ++pos) {
					might_reach[cur][pos] = 0;
					if ((pos+dur) <= len) {
						might_reach[cur][pos] = might_reach[old][pos+dur];
					}
					if ((pos-dur) >= 0) {
						might_reach[cur][pos] |= might_reach[old][pos-dur];
					} 
					at_least_one |= might_reach[cur][pos];
				}
				if (!at_least_one) possible = false;
			}
			cur = 1-cur;
			old = 1-old;
		}


    	if (!possible) break;
    	
    }

    if (possible) cout << "possible\n";
    else cout << "impossible\n";

	return 0;
}
