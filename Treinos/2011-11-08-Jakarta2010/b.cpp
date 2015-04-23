#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

char seen[55];
int hand[26];
map< string, int > cardvalue;

void setvalues();

int main(){
	ios::sync_with_stdio(false);
	
	int t;
	string card;
	
	setvalues();
	cin >> t;
	while( t-- ){
		
		memset( seen, 0, sizeof( seen ) );
		
		for( int i = 0; i < 26; i++ ){
			cin >> card;
			hand[i] = cardvalue[card];
			seen[hand[i]] = 1;
		}
		
		sort( hand, hand+26 );
		int points = 0;
		for( int i = 0; i < 26; i++ ){
			int cur = hand[i];
			while( cur >= 0 && seen[cur] ) cur--;
			if( cur >= 0 ){
				points++;
				seen[cur] = 1;
			} else {
				cur = 51;
				while( seen[cur] ) cur--;
				seen[cur] = 1;
			}			
		}
		cout << points << "\n";
		
	}
	
	return 0;
}

void setvalues(){
	cardvalue.clear();
	cardvalue[ "2D" ] = 0;
	cardvalue[ "2C" ] = 1;
	cardvalue[ "2H" ] = 2;
	cardvalue[ "2S" ] = 3;	
	cardvalue[ "3D" ] = 4;	
	cardvalue[ "3C" ] = 5;	
	cardvalue[ "3H" ] = 6;	
	cardvalue[ "3S" ] = 7;	
	cardvalue[ "4D" ] = 8;	
	cardvalue[ "4C" ] = 9;	
	cardvalue[ "4H" ] = 10;	
	cardvalue[ "4S" ] = 11;	
	cardvalue[ "5D" ] = 12;	
	cardvalue[ "5C" ] = 13;	
	cardvalue[ "5H" ] = 14;	
	cardvalue[ "5S" ] = 15;	
	cardvalue[ "6D" ] = 16;	
	cardvalue[ "6C" ] = 17;	
	cardvalue[ "6H" ] = 18;	
	cardvalue[ "6S" ] = 19;	
	cardvalue[ "7D" ] = 20;	
	cardvalue[ "7C" ] = 21;	
	cardvalue[ "7H" ] = 22;	
	cardvalue[ "7S" ] = 23;	
	cardvalue[ "8D" ] = 24;	
	cardvalue[ "8C" ] = 25;	
	cardvalue[ "8H" ] = 26;	
	cardvalue[ "8S" ] = 27;	
	cardvalue[ "9D" ] = 28;	
	cardvalue[ "9C" ] = 29;	
	cardvalue[ "9H" ] = 30;	
	cardvalue[ "9S" ] = 31;	
	cardvalue[ "TD" ] = 32;	
	cardvalue[ "TC" ] = 33;	
	cardvalue[ "TH" ] = 34;	
	cardvalue[ "TS" ] = 35;	
	cardvalue[ "JD" ] = 36;	
	cardvalue[ "JC" ] = 37;	
	cardvalue[ "JH" ] = 38;	
	cardvalue[ "JS" ] = 39;	
	cardvalue[ "QD" ] = 40;	
	cardvalue[ "QC" ] = 41;	
	cardvalue[ "QH" ] = 42;	
	cardvalue[ "QS" ] = 43;	
	cardvalue[ "KD" ] = 44;	
	cardvalue[ "KC" ] = 45;	
	cardvalue[ "KH" ] = 46;	
	cardvalue[ "KS" ] = 47;	
	cardvalue[ "AD" ] = 48;	
	cardvalue[ "AC" ] = 49;	
	cardvalue[ "AH" ] = 50;	
	cardvalue[ "AS" ] = 51;
}