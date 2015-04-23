#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define LESS -1
#define EQUAL 0
#define GREATER 1

/* 	gt[68] = gt[96] = 'X';
	lt[58] = lt[106] = 'Y';
	eq[77] = eq[87] = 'Z'; */
	
int val( int X ){
	int b, o, p;
	b = o = 0;
	p = 1;
	while( p <= X ){
		if( p & X ) o++;
		p <<=1;
		b++;
	}
	return o*500 + (b-o)*250;
}

inline bool hasMore( char c ){
	if( c == '.' || c == '\\' ) return false;
	return true;
}

int main(){
	
	string gt = "........||.../\\...\n........||../..\\..\n.../\\...||./....\\.\n../..\\..||/......\\\n./....\\.||\\______/\n/......\\||........\n\\______/||........\n";
	string lt = ".../\\...||........\n../..\\..||........\n./....\\.||.../\\...\n/......\\||../..\\..\n\\______/||./....\\.\n........||/......\\\n........||\\______/\n";
	string eq = "........||........\n.../\\...||.../\\...\n../..\\..||../..\\..\n./....\\.||./....\\.\n/......\\||/......\\\n\\______/||\\______/\n........||........\n";
	string right = "The figure is correct.\n";
	
	string linha[10];
	string result;
	
	int A, B, i, j, t, tst;
	ios::sync_with_stdio( false );
	
	cin >> t; cin.ignore();
	
	for( tst = 1; tst <= t; tst++ ){

		cin >> linha[0] >> linha[1] >> linha[2] >> linha[3] >> linha[4] >> linha[5] >> linha[6] >> linha[7];
		
		A = B = 0;
		
		if( linha[0][3] == linha[0][13] ){ /* A == B */
			i = 1;
			while( hasMore( linha[4][i] ) ) A += val( linha[4][i++] ); 
			i = 11;
			while( hasMore( linha[4][i] ) ) B += val( linha[4][i++] ); 
			
			if( A == B ){
				result = right;
			} else if( A > B ){
				
				result = gt;
				i = 1; j = 96;
				while( hasMore( linha[4][i] ) ) result[j++] = linha[4][i++]; 
				i = 11; j = 68;
				while( hasMore( linha[4][i] ) ) result[j++] = linha[4][i++]; 
				
			} else {
				result = lt;
				i = 1; j = 58;
				while( hasMore( linha[4][i] ) ) result[j++] = linha[4][i++]; 
				i = 11; j = 106;
				while( hasMore( linha[4][i] ) ) result[j++] = linha[4][i++]; 
			
			}
			
		} else if( linha[0][3] == '/' ){ /* A < B */
			i = 1;
			while( hasMore( linha[3][i] ) ) A += val( linha[3][i++] ); 
			i = 11;
			while( hasMore( linha[5][i] ) ) B += val( linha[5][i++] );
			
			if( A < B ){
				result = right;
			} else if( A > B ){
				result = gt;
				i = 1; j = 96;
				while( hasMore( linha[3][i] ) ) result[j++] = linha[3][i++]; 
				i = 11; j = 68;
				while( hasMore( linha[5][i] ) ) result[j++] = linha[5][i++];
			
			} else {
				result = eq;
				i = 1; j = 77;
				while( hasMore( linha[3][i] ) ) result[j++] = linha[3][i++]; 
				i = 11; j = 87;
				while( hasMore( linha[5][i] ) ) result[j++] = linha[5][i++];
			
			}
			
		} else{ /* A > B */
			i = 1;
			while( hasMore( linha[5][i] ) ) A += val( linha[5][i++] ); 
			i = 11;
			while( hasMore( linha[3][i] ) ) B += val( linha[3][i++] );			
			
			if( A > B ){
				result = right;
			} else if( A < B ){
				result = lt;
				i = 1; j = 58;
				while( hasMore( linha[5][i] ) ) result[j++] = linha[5][i++]; 
				i = 11; j = 106;
				while( hasMore( linha[3][i] ) ) result[j++] = linha[3][i++];			
			
			} else {
				result = eq;
				i = 1; j = 77;
				while( hasMore( linha[5][i] ) ) result[j++] = linha[5][i++]; 
				i = 11; j = 87;
				while( hasMore( linha[3][i] ) ) result[j++] = linha[3][i++];			
			
			}
			
		}
		
		cout << "Case " << tst << ":\n" << result;	
	}
	
	return 0;
}

