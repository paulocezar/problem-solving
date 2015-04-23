#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

vector< pair< string, int > > cmd;
int n, x, y, z, val, sz;
int rot, precisa;

bool solve( int state, int pos )
{
	
	if( pos == sz ) return ( state == 2 && rot < n && val == z );
	
	switch( state ){
		case 0:
		
			if( cmd[pos].first == "CC" ){
				if( rot >= n && val == x ){
					precisa = n + (y-val)%n + ( ((y-val)<0)?n:0 );
					rot = 0;
					return solve( 1, pos );
				} else {
					rot = 0;
					val = val + cmd[pos].second; val = val%n;
					return solve( 0, pos+1 );
				}	
			} else {
				rot += cmd[pos].second;
				val = val - cmd[pos].second; val = val%n + ( (val<0)?n:0 );
				return solve( 0, pos+1 );
			}
			
		case 1:
		
			if( cmd[pos].first == "CC" ){
				
				val = val + cmd[pos].second; val = val%n;
				rot += cmd[pos].second;
				
				if( rot < precisa ) return solve( 1, pos+1 );
				else if( rot == precisa ){
					rot = 0;
					return solve( 2, pos+1 );
				} else {
					rot = 0;
					return solve( 0, pos+1 );
				}
				
			} else {
				
				rot = cmd[pos].second;
				val = val - cmd[pos].second; val = val%n + ( (val<0)?n:0 );
				return solve( 0, pos+1 );
			
			}
			
		case 2:

			if( cmd[pos].first == "CC" ){
				rot = 0;
				val = val + cmd[pos].second; val %= n;
				return solve( 0, pos+1 );
			} else {
				
				if( val == z ) return solve( 0, pos );
				else {
					
					rot += cmd[pos].second;
					val = val - cmd[pos].second; val = val%n + ( (val<0)?n:0 );
					
					if( rot >= n ){
						rot -= n;
						return solve( 0, pos+1 );
					} else return solve( 2, pos+1 );
				
				}
			}
		
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);

	int t = 1;
	
	cin >> n;
	while( n ){
		
		cin >> x >> y >> z;
		
		cmd.clear();
		
		string scmd;
		cin >> scmd;
		while( scmd != "?" ){
			cin >> val;
			cmd.push_back( make_pair( scmd, val ) );
			cin >> scmd;
		}
		sz = int( cmd.size() );
		
		val = 0; rot = 0;
		cout << "Case " << t++ << ": ";
		if( solve( 0, 0 ) ) cout << "Open\n";
		else cout << "Closed\n";
		
		cin >> n;
	}
	
	return 0;
}
