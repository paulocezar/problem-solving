#include <set>
#include <string> 
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, P;
    while (cin >> N  && N) {
        cin >> P;
        vector<int> miss;
        if (P & 1) miss.push_back(P+1);
        else {
            miss.push_back(P-1); P--;
        }
        
        miss.push_back(N-P);
        miss.push_back(N-P+1);
        
        sort(miss.begin(), miss.end());
        cout << miss[0] << " " << miss[1] << " " << miss[2] << "\n";
    }    

	return 0;
}

















