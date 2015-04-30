#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

void divbytwo(string &num) {
    int c = 0;
    
    for (auto ch = num.rbegin(); ch != num.rend(); ++ch) {
        int v = 10*c + (*ch - '0');
        *ch = (v/2) + '0';
        c = v % 2;
    }
    while (num.back() == '0') num.pop_back();
}

void minusone(string &num) {
    for (auto &ch : num) {
        if (ch >= '1') { ch--; break; }
        ch = '9';
    }
    while (num.back() == '0') num.pop_back();
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;    
    
    while (T--) {
        
        string num;
        cin >> num;
        reverse(num.begin(), num.end());
    
        if (int(num[0]-'0') & 1) {
            divbytwo(num);
        } else {
            minusone(num);
            divbytwo(num);
            if (!(int(num[0]-'0') & 1)) minusone(num); 
        }
    
        reverse(num.begin(), num.end());
        cout << num << "\n";
        
        if (T) cout << "\n";
    }    

	return 0;
}

















