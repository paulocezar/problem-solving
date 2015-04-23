/*
ID: knightp2
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

char enc[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };

int B;
string num;

bool palin(){ 
	int i = 0; int j = num.size()-1;
	while( i  < j ){
		if( num[i] != num[j] ) return false;
		num[i] ^= num[j]; num[j] ^= num[i]; num[i] ^= num[j];
		i++, j--;
	}
	return true;
}

bool palin( int a ){
	num = "";
	while( a ){
		num += enc[ a%B ];
		a /= B;
	}
	return palin();
}

int main() {
	
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    fin >> B;
	string num2;
	for( int n = 1; n <= 300; n++ ) if( palin( n*n ) ){
		num2 = "";
		int a = n;
		while( a ){ num2 += enc[ a%B ]; a /= B; } reverse( num2.begin(), num2.end() );
		fout << num2 << " " << num << "\n";
	}

    return 0;
}
