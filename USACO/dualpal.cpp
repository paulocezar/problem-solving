/*
ID: knightp2
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool palin( int a ){
	
	int nd = 2;
	int b = 2;
	string num, num2;
	
	while( nd && b <= 10 ){
		int aa = a;
		num = "";
		while( aa ){
			num += (aa%b) + '0';
			aa /= b;
		}
		while( num.size() > 1 && *num.end() == '0' ) num.erase( num.end() );
		num2 = num; reverse( num2.begin(), num2.end() );
		
		if( num == num2 ) nd--;
		b++;
	}
	return nd == 0;
}

int main() {
	
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int N, S;
    fin >> N >> S;
    
	S++;
	while( N-- ){
		
		while( !palin(S) ) S++;
		fout << S << "\n";
		S++;
		
	}

	return 0;
}
