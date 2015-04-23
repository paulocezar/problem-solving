#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef struct{
	string dir;
	list< 

int main(){

	int i, ct, t, n, m;
	string path, token;
	size_t pos, lastPos;
	
	scanf("%d", &t );
	for( ct = 1; ct <= t; ct++ ){

		scanf("%d %d", &n, &m );
		
		for( i = 0; i < n; i++ ){
			cin >> path;
			
			path = path.substr( 1, path.length() );
			lastPos = 0;
			
			pos = path.find_first_of( "/", lastPos);
			while( pos != string::npos ){
				
				token = path.substr( lastPos, pos );
				
				lastPos = pos + 1;
				pos = path.find_first_of( "/", lastPos);
			}
			token = path.substr( lastPos, path.length() );

		}
		
		for( i = 0; i < m; i++ ){

		}
		
	}

	return 0;
}

