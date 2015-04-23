#include <set>
#include <string> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int val(string up, string dw) {
    int ret = 0;
    int us = up.size();
    
    for (int i = 0; i < us; ++i) {
        
        int ii = i;
        int j = 0;
        while (ii < us) {
            if (up[ii] != dw[j]) break;
            ii++, j++;
        }
        
        ret <<= 1;
        if (ii == us) ret |= 1;
    }
    
    return ret;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    
    string s1, s2;
    while (cin >> s1 && (s1[0] != '$')) {
        cin >> s2;
        
        int aa = val(s1, s1);
        int ab = val(s1, s2);
        int bb = val(s2, s2);
        int ba = val(s2, s1);
        
        int num = (bb-ba);
        int den = (aa-ab)+(bb-ba);
        int gg = __gcd(num, den);
        
        num /= gg;
        den /= gg;
        
        cout << num << "/" << den << "\n";
    }
       

	return 0;
}

















