#include <iostream>

using namespace std;

int main(){

    int t, tc = 1;
    cin >> t;
    
    long long tn[302];
    tn[1] = 1;
    for( int i = 2; i <= 301; i++ ) tn[i] = tn[i-1]+i;
    
    while( t-- ){

        int n;
	cin >> n;
	long long ans = 0;
	for( int i = 1; i <= n; i++ ) ans += tn[i+1]*i;
	cout << tc++ << " " << n << " " << ans << "\n";
	
    }

    return 0;
}
