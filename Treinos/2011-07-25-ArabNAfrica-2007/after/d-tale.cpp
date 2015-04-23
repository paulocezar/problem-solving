#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
	char str[ 100 ];
	
	while( true ){
		fgets( str, 100, stdin );
				
		for( int i = 0, sz = strlen( str ); i < sz; i++ ){
			switch( str[i] ){
				case 'd':
					if( (i+1 < sz) && (str[i+1] == 'd') ){ putchar( 'p' ); i++; }
					else putchar( 'd' );
					break;
				case 'p':
					if( (i+3 < sz) && ( (str[i+1] == 'i') && (str[i+2] == 'n') && (str[i+3] == 'k') ) ){ printf( "floyd" );  i+=3; }
					else putchar( 'p' );
					break;
				case 'e':
					if( (i+1 < sz) && (str[i+1] == 'i') ){
						if( i == 0 || str[i-1] != 'c' ) { printf("ie"); i++; }
						else putchar( 'e' );
					} else putchar( 'e' );
					break;
				case 'E': if( (i+2 < sz) && ( (str[i+1] == 'O') && (str[i+2] == 'F') ) ) return 0;
				default: if( isspace(str[i]) || ('a' <= str[i] && str[i] <= 'z') ) putchar( str[i] );
			}		
		}
	}
	
	return 0;
}

