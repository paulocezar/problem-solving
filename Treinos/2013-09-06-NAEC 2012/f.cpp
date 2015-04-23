#include <iostream>
#include <string>
#include <cctype>
#include <tr1/unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        int k, w;
        cin >> k >> w;
        cin.ignore();
        
        int complete = 0, mx = 0;
        tr1::unordered_set<int> seen;
        
        for (int li = 0; li < k; ++li) {
            string line = "", rawline;
            getline(cin, rawline);
            for (int i = 0; i < int(rawline.size()); ++i) {
                if (isdigit(rawline[i])) line += rawline[i];
                else if (line.size() && isdigit(line[line.size()-1])) line += " ";
            }
            
            
            vector<int64> numbers;
            for (int i = 0; i < int(line.size()); ++i) {
                int64 val = 0LL;
                int j = i;
                int mj = min(int(line.size()), j+17);
                while (j < mj) {
                    if (line[j] == ' ') break;
                    
                    val = 10LL*val + (line[j]-'0');
                    numbers.push_back(val);
                    j++;
                }
            }
            sort(numbers.begin(), numbers.end());
            numbers.erase( unique( numbers.begin(), numbers.end() ), numbers.end());
            
            for (int i = 0; i < int(numbers.size()); ++i) {
                if (numbers[i] <= (complete+w)) {
                    seen.insert(numbers[i]);
                    if (numbers[i] > mx) mx = numbers[i];
                    while (seen.count(complete+1)) complete++;
                }
            }
            
        }
        cout << "Case "<< kase << ": "<< complete << " " << mx << "\n";
        
    }
    
    return 0;
}