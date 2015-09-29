#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> zero = {0};

bool is_palindrome(vector<int> &digits) {
    int j = digits.size() - 1;
    int i = 0;
    while (i < j) {
        if (digits[i] != digits[j]) return false;
        i++;
        j--;
    }
    return true;
}

vector<int> digits_at_base(int n, int base) {
    if (!n) return zero;
    vector<int> res;
    while (n) {
        res.push_back(n%base);
        n /= base;
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        bool print = false;
        for (int base = 2; base <= 16; ++base) {
            vector<int> digits = digits_at_base(n, base);
            if (is_palindrome(digits)) {
                if (print) cout << " ";
                cout << base;
                print = true;
            }
        }
        if (print) cout << "\n";
        else cout << "-1\n";
    }

	return 0;
}

















