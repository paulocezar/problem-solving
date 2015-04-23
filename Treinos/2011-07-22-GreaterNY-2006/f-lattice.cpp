#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cont;

int gcd(int x, int y){
	int aux;
	while(y){
		aux = x;
		x = y;
		y = aux%y;
	}
	return x;	
}

void pre(){
	cont.push_back(1);
	
	for(int i = 1; i <= 1000; i++){
		for(int j = i; j <= 1000; j++){
			if(gcd(i, j) == 1){
				cont.push_back(j);
				//cout << i << " " << j << endl;
				//cin.get();
			}
		}
	}
		
	sort(cont.begin(), cont.end());
}

int main(){
	ios::sync_with_stdio(false);
	
	pre();
	
	int c, n;
	cin >> c;
	
	for(int i = 1; i <= c; i++){
		cin >> n;
		vector<int>::iterator up = upper_bound(cont.begin(), cont.end(), n);
		cout << i << " " << n << " " << 2*(int)(up - cont.begin()) - 1 << "\n";
	}
}
