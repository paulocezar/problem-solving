#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    long long a;
    cin >> a;
    a %= 6LL;
    if ((a == 0LL) || (a == 1LL) || (a == 3LL)) cout << "yes\n";
    else cout << "no\n";

	return 0;
}

















