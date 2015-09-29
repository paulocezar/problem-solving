#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int idiom[1<<12], words;
vector<int> sentence[256];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N; cin.ignore();  
        
        map<string, int> idx;
        words = 0;
        
        string line;
        
        for (int i = 0; i < N; ++i) {
            sentence[i].resize(0);
            getline(cin, line);
            istringstream in(line);
            string word;
            while (in >> word) {
                if (!idx.count(word)) idx[word] = words++;
                sentence[i].push_back(idx[word]);
            }
        }
        
        int res = 2e9;
        for (int mask = (1<<(N-2))-1; mask >= 0; --mask) {
            for (int i = 0; i < words; ++i) idiom[i] = 0;
            for (auto val : sentence[0]) idiom[val] |= 1;
            for (auto val : sentence[1]) idiom[val] |= 2;
            for (int i = 0; i < N-2; ++i) {
                int idm = 2;
                if (mask & (1<<i)) idm = 1;
                for (auto val : sentence[i+2]) {
                    idiom[val] |= idm;
                }
            }
            int cur = 0;
            for (int i = 0; i < words; ++i) if (idiom[i] == 3) cur++;
            res = min(res, cur);
        }
        
        cout << "Case #" << tc << ": " << res << "\n";
        
    }

	return 0;
}

















