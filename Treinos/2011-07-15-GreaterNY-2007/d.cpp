#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int ds[][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main(){
	
	int t, r, c;
	string s;
	
 	cin >> t;
	int tc = 1;
	while( t-- ){
		cin >> r >> c >> s;
				
		string ss[r];
		
		int i, j, p;
		i = 0; p = 0;
		while( i < r ){
			ss[i] = "";
			j = 0;
			while( j < c ){
				ss[i] += s[p++];
				j++;
			}
			i++;
		}
		cout << tc++ << " "; 
		int dir = 0;
		int rm = r*c;
		i = 0, j = 0;
		string ans = "";
		while( rm >= 5 ){
			int cur = 0;
			
			for( int b = 0; b < 5; ++b ){
				cur = 2*cur + (ss[i][j]-'0');
				ss[i][j] = -1;
				rm--;
				if( rm == 0 ) break;
				while( true ){
					if( (i+ds[dir][0]) >= r || (i+ds[dir][0]) < 0 || (j+ds[dir][1]) >= c || (j+ds[dir][1]) < 0 ) dir = (dir+1)%4;
					else if( ss[ i+ds[dir][0] ][j + ds[dir][1] ] == -1 || ss[ i+ds[dir][0] ][ j+ds[dir][1] ] == -1 ) dir = (dir+1)%4;
					else break;
				}
				i += ds[dir][0];
				j += ds[dir][1];
			}
			if( cur == 0 ) ans += ' ';
			else ans += char('A'+cur-1);
			p++;
		}
		int sz = int(ans.size()) - 1;
		while( sz >= 0 && ans[sz] == ' ' ) sz--;
		i = 0;
		while( i <= sz ) cout << ans[i++];
		cout << "\n";
	}
	
	return 0;
}