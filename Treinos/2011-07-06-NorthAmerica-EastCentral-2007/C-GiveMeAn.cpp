#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

#define GSZ 20
int guys[] = { 0, 2, 4, 6, 30, 32, 34, 36, 40, 42, 44, 46, 50, 52, 54, 56, 60, 62, 64, 66 };

long long vals[10];
long long pot[10];

int ans[10];

void solve( long long n ){
	
	if( n < 20 ){ 
		ans[0] = guys[n];
		return;
	}
	
	long long acum = 0;
	int pos = 0;
	while( acum < n ){
		acum += vals[pos];
		pos++;
	
	}
	
	pos--;
	ans[pos] = guys[n/pot[pos]];
	solve( n - (n/pot[pos])*pot[pos] );
	
}

int main()
{
	ios::sync_with_stdio(false);

	vals[0] = 19;    pot[0] = 1;
	vals[1] = 19*20; pot[1] = 20;
	
	for( int i = 2; i <= 6; i++ ){ 
		vals[i] = vals[i-1]*20;
		pot[i] = 20*pot[i-1];
	}
	vals[7] = vals[8] = 0;
	vals[9] = 20*vals[6]; pot[9] = 20*pot[6];
	
	int n;
	cin >> n;
	while( n ){
				
		memset( ans, 0, sizeof(ans) );
		solve( n );
		
		int i = 9;
		while( !ans[i] ) i--;
		cout << ans[i--]; 
		while( i >= 0 ){
			cout << "," << setw(3) << setfill('0') << ans[i];
			i--;
		}
		cout << "\n";
		
		cin >> n;
	}
	
	return 0;
}
