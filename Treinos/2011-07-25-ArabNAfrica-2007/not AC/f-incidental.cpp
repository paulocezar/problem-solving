#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct point_t{
	int x, y;
	point_t( int xx = 0, int yy = 0 ) : x(xx), y(yy) {}
};

#define MAXN 1001
point_t point[MAXN];

int main(){
	ios::sync_with_stdio( false );
	int tc = 1;
	string line;

	getline( cin, line );
	while( line[1] != '-' ){
		int n = 0;

		map< int, int > ctx, cty;
		while( line[1] != '-' ){
			int sig = 1;
			int i = 0;
			if( line[i] == '-' ) sig = -1, i++;						
			int x = 0;
			while( '0' <= line[i] && line[i] <= '9' ){ x = 10*x + (line[i]-'0'); i++; }
			x *= sig;
			sig = 1;
			while( line[i] != '-' && !( '0' <= line[i] && line[i] <= '9' ) ) i++;
			if( line[i] == '-' ) sig = -1, i++;
			int y = 0;
			while( (i < int(line.size())) &&  '0' <= line[i] && line[i] <= '9' ){ y = 10*y + (line[i]-'0'); i++; }
			y *= sig;
			
			point[n].x = x, point[n].y = y;
			n++;

			ctx[x]++;
			cty[y]++;
			getline( cin, line );		
		}		
		
		map< double, int > ct;
		for( int i = 0; i < n; i++ ){
			for( int j = i+1; j < n; j++ ){			
				if( (point[i].x != point[j].x) && (point[i].y != point[j].y) ){
					ct[ double(point[i].x-point[j].x)/double(point[i].y-point[j].y) ]++;
				}
			}
		}

		int ans = 1;
		for( __typeof( ctx.begin() ) it = ctx.begin(); it != ctx.end(); it++ ) ans = max( ans, it->second );
		for( __typeof( cty.begin() ) it = cty.begin(); it != cty.end(); it++ ) ans = max( ans, it->second );
		int aa = 0;		
		for( __typeof( ct.begin() ) it = ct.begin(); it != ct.end(); it++ ) aa = max( aa, it->second );
		cout << tc++ << ". " << max( ans, (1 + int(sqrt( 1 + 8*aa )) )/2 ) << "\n";

		getline( cin, line );
	}	
	
	return 0;
}

