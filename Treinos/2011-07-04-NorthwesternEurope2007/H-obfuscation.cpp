#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

#define REP( i, a ) for( int i = 0; i < a; i++ )

using namespace std;

#define MAXN 1001
char dp[MAXN];

map< string, string > dict;
map<char, map<char, map<int, bool> > > has;
string s;

int size;

string enc( string ww ){
	if( int(ww.size()) > 2 ) sort( ww.begin()+1, ww.end()-1 );	
	return ww;
}

char solve( int pos ){

	if( pos == size ) return 1;
	
	if( dp[pos] == -1 ){
		dp[pos] = 2;
		
		string cur;
		int i = pos;
		while( i < size ){
			if (has[s[pos]][s[i]][i-pos+1]) {
				cur = enc( s.substr( pos, i-pos+1 ) );
				if( dict.find( cur ) != dict.end() ){
					char r = solve( i+1 );
					if( r == 3 || (r == 1 && dict[cur] == "?") ){ dp[pos] = 3; break; }
					else dp[pos] = min( dp[pos], r );
				}
			}
			i++;
		}
		
	}
	return dp[pos];
}

void build( int pos ){
	int i;
hell:
	if( pos == size ){ cout << "\n"; return; }
	i = pos+1;
	
	while( i < size && dp[i] != 1 ) i++;
	
	if( pos != 0 ) cout << " ";
	cout << dict[ enc( s.substr( pos, i-pos ) ) ]; 
	
	pos = i;
	goto hell;
}

int main(){
	ios::sync_with_stdio( false );
	
	int t, n;
	string wrd, wrd2;
	
	cin >> t;
	while( t-- ){
		dict.clear();
		has.clear();
		
		cin >> s;
		cin >> n;
		
		size = s.size();
		while( n-- ){
			cin >> wrd;
			wrd2 = enc( wrd );
			
			if( dict.find( wrd2 ) != dict.end() ) dict[wrd2] = "?";
			else dict[wrd2] = wrd;
			
			int sz = wrd.size();
			
			has[wrd[0]][wrd[sz-1]][sz] = true;
		}
		memset( dp, -1, sizeof(char)*( s.size()+1 ) );
		char r = solve( 0 );
		if( r == 1 ) build( 0 );
		else if( r == 2 ) cout << "impossible\n";
		else cout << "ambiguous\n";
	}
	
	
	return 0;
}
