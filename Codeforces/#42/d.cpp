#include <iostream>

using namespace std;

int n, m;

void wp( int i, int j ){
	
	if( i == 1 && j == 1 ) { cout << "1 1\n"; return; }
	if( i > n ){ wp( n, j-1 ); return;   }
	if( i == 1 ){ wp( 2, j-1 ); return; }
	
	cout << i << " " << j << "\n";
	
	wp( (j&1)?(i-1):(i+1), j );

}

void wc( int i, int j ){
	
	if( i > n ) return;
	if( j > m ){ wc( i+1, m ); return;   }
	if( j == 1 ){ wc( i+1, 2 ); return; }
	
	cout << i << " " << j << "\n";
	
	wc( i, (i&1)?(j+1):(j-1) );

}

int main(){
	
	int i, j;

	cin >> n >> m;

	if( n == m && n == 1 ){
		cout << "0\n1 1\n1 1\n";
	}
	else if( n == 1 || m == 1 ){
		
		if( n == 2 || m == 2 ){
			if( n == 1 ) cout << "0\n1 1\n1 2\n1 1\n";
			else cout << "0\n1 1\n2 1\n1 1\n";
		} else {
			cout << "1\n" << n << " " << m << " 1 1\n";	
			if( n == 1 ) for( i = 1; i <= m; i++ ) cout << "1 " << i << "\n";
			else for( i = 1; i <= n; i++ ) cout << i << " 1\n";
			cout << "1 1\n";
		}
		
	}
	else if( n&1 && m&1 ){
		
		cout << "1\n" << n << " " << m << " 1 1\n";	
		for( i = 1; i <= n; i++ ){
			for( j = (i&1)?1:m; j > 0 && j <= m; (i&1)?(j++):(j--) )
			cout << i << " " << j << "\n";
		}
		cout << "1 1\n";

	} else if( m & 1 ){
		cout << "0\n";
		for( i = 1; i <= m; i++ )
			cout << "1 " << i << "\n";
		wc( 2, m );
		for( i = n; i; i-- )
			cout << i << " 1\n";
		
	} else {
		cout << "0\n";
		for( i = 1; i <= m; i++ )
			cout << "1 " << i << "\n";
		wp( 2, m );
	}

	return 0;
}

