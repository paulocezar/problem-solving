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

int barbie[1024], ken[2024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    for (int kase = 1; kase <= cases; ++kase) {
        int N;
        cin >> N;
        double val;
        for (int i = 0; i < N; ++i) {
            cin >> val;
            barbie[i] = 1000000 * val;
        }
        for (int i = 0; i < N; ++i) {
            cin >> val;
            ken[i] = 1000000 * val;
        }
        sort(barbie, barbie+N);
        sort(ken, ken+N);
        
        int qnt1 = 0;
        int i = 0, j = 0;
        while ((i < N) && (j < N)) {
            if (ken[j] > barbie[i]) i++, j++, qnt1++;
            else j++;
        }
        qnt1 = N-qnt1;
        
        int qnt2 = 0;
        i = N-1, j = N-1;
        while ((i >= 0) && (j >= 0)) {
            if (barbie[i] > ken[j]) i--, j--, qnt2++;
            else j--;
        }
         
        cout << "Case #" << kase << ": " << qnt2 << " " << qnt1 << "\n";              
    }

	return 0;
}

















