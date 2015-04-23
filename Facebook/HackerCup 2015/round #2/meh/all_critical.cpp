#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int BITS = 20;
const int SUBSETS = 1<<BITS;

double expected[SUBSETS];
double prob[SUBSETS];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        double p; cin >> p;
        double q = 1.0 - p;
        
        expected[0] = 0.0;
        prob[0] = 1.0;
        
        for (int subset = 1; subset < SUBSETS; ++subset) {
            prob[subset] = 1.0;
            int ax = subset;
            for (int bit = 0; bit < BITS; ++bit) {
                if (ax & 1) prob[subset] *= p;
                else prob[subset] *= q;
                ax >>= 1;
            }
            expected[subset] = prob[subset];
            for (ax = subset; ax > 0; ax = (ax-1) & subset) {
                expected[subset] += (expected[ax] + 1) * prob[subset ^ ax];
            }
        }
        cout << expected[SUBSETS-1] << "\n";
    }
    

	return 0;
}

















