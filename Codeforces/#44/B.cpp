#include <iostream>
#include <string>

using namespace std;

int main(){

	string m1, m2, m3;
	
	cin >> m1 >> m2 >> m3;
	if( m1[1] == '>' ){ m1[0] ^= m1[2]; m1[2] ^= m1[0]; m1[0] ^= m1[2]; }
	if( m2[1] == '>' ){ m2[0] ^= m2[2]; m2[2] ^= m2[0]; m2[0] ^= m2[2]; }
	if( m3[1] == '>' ){ m3[0] ^= m3[2]; m3[2] ^= m3[0]; m3[0] ^= m3[2]; }
	
	if( m1[0] == m2[0] ){
		cout << m1[0] << m3[0] << m3[2];
	}
	else if( m1[0] == m3[0] ){
		cout << m1[0] << m2[0] << m2[2];
	} else if( m2[0] == m3[0] ){
		cout << m2[0] << m1[0] << m1[2];
	} 
	else {
		cout << "Impossible";
	}
	cout << "\n";

	return 0;
}

