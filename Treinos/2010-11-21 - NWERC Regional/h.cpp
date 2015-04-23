#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int sell[ 1010 ];
int buy[ 1010 ];

int main(){

	int t, n, x, y, last;
	string type, shares, at;

	cin >> t;
	while( t-- ){
		
		cin >> n;
		priority_queue< int > a, b;
		last = -1;

		memset( sell, 0, sizeof( sell ) );
		memset( buy, 0, sizeof( buy ) );

		while( n-- ){
			
			cin >> type >> x >> shares >> at >> y;

			if( type == "buy" )
			{		
		
				if( buy[y] == 0 ) b.push( y );
				buy[y] += x;
			
			} else {

				if( sell[y] == 0 ) a.push( -y );
				sell[y] += x;
			
			}
				
			while( !(a.empty() || b.empty()) && b.top() >= -a.top() )
			{
					x = -a.top();
					y = b.top();

					if( sell[x] == 0 ) a.pop();
					if( buy[y] == 0 ) b.pop();
					if( sell[x] == 0 || buy[y] == 0 ) continue;
					last = x;

					if( sell[x] >= buy[y] ){
						sell[x] -= buy[y];
						buy[y] = 0;
					} else {
						buy[y] -= sell[x];
						sell[x] = 0;
					}
			
			}
			
			while( !a.empty() && sell[-a.top()] == 0 ) a.pop();
			while( !b.empty() && buy[b.top()] == 0 ) b.pop();


			if( !a.empty() ) cout << -a.top();
			else cout << "-";

			if( !b.empty() ) cout << " " << b.top();
			else cout << " -";
		
			if( last != -1 ) cout << " " << last << "\n";
			else cout << " -\n";

		}
	

	}

	return 0;
}

