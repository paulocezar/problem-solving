#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){

    int t, c, tc = 1;
    string s1, s2, s, ss;
    cin >> t;

    while( t-- ){
		cin >> c;
		cin >> s1 >> s2 >> s;
		set< string > seen;
		
		int step = 0;
		do {
			step++;
			ss = "";
			
			for( int i = 0; i < c; i++ ){ ss += s2[i]; ss += s1[i]; }
			s1 = ss.substr( 0, c );
			s2 = ss.substr( c );
			
			if( seen.find( ss ) != seen.end() ){step = -1; break;}
			seen.insert( ss );
		} while( s != ss );
		
		cout << tc++ << " " << step << "\n";
    }

    return 0;
}
