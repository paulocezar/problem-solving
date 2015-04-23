#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        
        int N; cin >> N; cin.ignore();
        vector<string> games(N);
        for (int i = 0; i < N; ++i) getline(cin, games[i]);
        
        int res = 0;
        
        for (int i = 1; i < N; ++i) {
            if (games[i] < games[i-1]) {
                swap(games[i], games[i-1]);
                res++;
            }
        }
        
        
        cout << res << "\n";
        
    }

	return 0;
}

















