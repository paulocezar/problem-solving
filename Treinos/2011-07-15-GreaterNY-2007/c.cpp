#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int ds[][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main(){
	
	int t, r, c;
	string s;
	
 	cin >> t; cin.ignore();
	int tc = 1;
	while( t-- ){
		getline( cin, s );
		
		r = 0, c = 0;
		int p = 0;
		while( s[p] != ' ' ){
			r = 10*r + (s[p]-'0');
			p++;
		}
		p++;
		while( s[p] != ' ' ){
			c = 10*c + (s[p]-'0');
			p++;
		}
		p++;
		
		string ss[r];
		bool fill[r][c];
		int i, j;
		i = 0;
		while( i < r ){
			ss[i] = "";
			j = 0;
			while( j < c ){
				fill[i][j] = false;
				ss[i] += '0';
				j++;
			}
			i++;
		}
		i = 0, j = 0;
		
		int sz = int( s.size() );
		int dir = 0;
		while( p < sz ){
			int cur;
			if( s[p] == ' ' ) cur = 0;
			else cur = s[p]-'A'+1;
			
			for( int b = 4; b >= 0; --b ){
				
					if( cur & (1<<b) ) ss[i][j] = '1';
					fill[i][j] = true;
					
					if( b == 0 && p == sz-1 ) break;
					while( true ){
						if( (i+ds[dir][0]) >= r || (i+ds[dir][0]) < 0 || (j+ds[dir][1]) >= c || (j+ds[dir][1]) < 0 ) dir = (dir+1)%4;
						else if( fill[ i+ds[dir][0] ][j + ds[dir][1] ] || fill[ i+ds[dir][0] ][ j+ds[dir][1] ] ) dir = (dir+1)%4;
						else break;
					}
					
					i += ds[dir][0];
					j += ds[dir][1];
			}
			p++;
		}
		cout << tc++ << " ";
		for( i = 0; i < r; i++ ) cout << ss[i];
		cout << "\n";
	}
	
	return 0;
}