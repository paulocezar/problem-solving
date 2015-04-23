#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int getnum(string s) {
    int res = 0;
    //for (auto ch : s) if (ch != '.') res = 10*res + (ch-'0');
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '.') res = 10*res + (s[i]-'0');
    }
    return res;
}

string getstr(int x) {
    if (x == 0) return "0";
    string res = ""; int cnt = 0;
    while (x) {
        if (cnt == 3) res += '.', cnt = 0;
        res += char((x%10) + '0');
        cnt++;
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int C;
    while (cin >> C && C) {
        string x, a, b;
        int sumA = 0, sumB = 0;
        while (C--) {
            cin >> x >> a >> b;
            sumA += getnum(a);
            sumB += getnum(b);
        }
        cout << getstr(sumA+sumB) << " " << getstr(sumA) << " " << getstr(sumB) << "\n";
    }
    

	return 0;
}

















