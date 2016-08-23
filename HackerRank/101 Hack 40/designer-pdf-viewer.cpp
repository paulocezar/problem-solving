#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    vector<int> h(26);
    for (int &x : h) cin >> x;
    string s;
    cin >> s;
    int mx = 0;
    for (char c : s) mx = max(mx, h[c-'a']);
    cout << mx * s.size() << "\n";


    return 0;
}
