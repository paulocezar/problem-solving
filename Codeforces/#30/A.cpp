#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int64;

using namespace std;

int n;
int64 mpow( int64 a ){
	int64 res = 1;
	for( int i = 0; i < n; i++ ) res *= a;
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	int64 A, B;
	cin >> A >> B >> n;
	for( int64 x = 0; x <= 1001; x++ ){
		if( A*mpow(x) == B ){ cout << x << "\n"; return 0; }
		if( A*mpow(-x) == B ){ cout << -x << "\n"; return 0; }
	}
	cout << "No solution\n";
	return 0;
}
