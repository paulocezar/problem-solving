#include <set>
#include <string> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int comp_val[32];

bool mycomp(string a, string b) {
    int i = 0;
    int sa = a.size();
    int sb = b.size();

    while ((i < sa) && (i < sb)) {
        if (a[i] != b[i]) return (comp_val[a[i]-'A'] < comp_val[b[i]-'A']);
        i++;
    }
    
    if (sa == sb) return false;
    if (i == sa) return true;
    return false;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int tc = 0;
    int N;
    while (cin >> N && N) {
        tc++;
        vector<string> word(N);
        string alph; cin >> alph;
        for (int i = 0; i < int(alph.size()); ++i) {
            comp_val[alph[i]-'A'] = i;
        }
        
        for (int i = 0; i < N; ++i) cin >> word[i];

        sort(word.begin(), word.end(), mycomp);
        cout << "year " << tc << "\n";
        for (int i = 0; i < N; ++i) cout << word[i] << "\n";
    }
    

	return 0;
}

















