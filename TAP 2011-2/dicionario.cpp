#include <set>
#include <map> 
#include <vector> 
#include <string> 
#include <cstdio>
#include <cstdlib> 
#include <cstring> 
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;

using namespace std;

inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

struct node_t{
	map< int, node_t* > chld;
};

int atpref[26], atsuf[26];
char wrd[1001];

int main(){	
	
	int P, S;
	
	P = next_int();
	S = next_int();
	while( (P+S) ){
		
		node_t* pref = new node_t();
		int64 prefcnt = 0;
		
		memset( atpref, 0, sizeof(atpref) );
		memset( atsuf, 0, sizeof(atsuf) );

		for( int i = 0; i < P; i++ ){
			int sz = 0;
			while( (wrd[sz]=getchar_unlocked()) != '\n' ) sz++;
			
			int j = 0;
			
			node_t* node = pref;
			while( j < sz && node->chld[wrd[j]-'a'] != NULL ){ node = node->chld[ wrd[j]-'a' ]; j++; }
			while( j < sz ){
				node->chld[ wrd[j]-'a' ] = new node_t();
				if( j ) atpref[ wrd[j]-'a' ]++;
				node = node->chld[ wrd[j]-'a' ];
				prefcnt++;
				j++;
			}
		}
				
		node_t* suf = new node_t();
		int64 sufcnt = 0;
		
		for( int i = 0; i < S; i++ ){
			int sz = 0;
			while( (wrd[sz]=getchar_unlocked()) != '\n' ) sz++;
			int j = sz-1;
			
			node_t* node = suf;
			while( j >= 0 && node->chld[wrd[j]-'a'] != NULL ){ node = node->chld[ wrd[j]-'a' ]; j--; }
			while( j >= 0 ){
				node->chld[ wrd[j]-'a' ] = new node_t();
				node = node->chld[ wrd[j]-'a' ];
				if( j != sz-1 ) atsuf[ wrd[j]-'a' ]++;
				
				sufcnt++;
				j--;
			}
		}
		
		int64 ans = prefcnt*sufcnt;
		for( int i = 0; i < 26; i++ )  ans -= atpref[i]*atsuf[i];
		printf("%lld\n", ans );
		
		P = next_int();
		S = next_int();		
	}
		
	return 0;
}
