#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int n;
	while( cin >> n && n ){
	
		int num = 1, den = 1;
		int acum = 0;
		while( acum+(den) < n ){
			acum += den;
			den++;
		}
		while( acum < n ){
			acum++;
			num++;
			den--;	
		}
		num--;
		den++;
		cout << "Termo " << n << ": " << num << "/" << den << "\n";

	}	

	return 0;
}

