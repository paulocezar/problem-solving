#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	
	int t, k, quant;
	vector<int> resp;
	
	int panquecas[35];
	int a, b, c;
	
	cin >> t;
	for( k = 1; k <= t; k++ ){
		
		cin >> quant;
		for( a = 0; a < quant; a++ ) cin >> panquecas[a];
			
		resp.clear();
		for( a = quant-1; a >= 0; a-- ){
			
			if( abs( panquecas[a] ) == (a+1) ){
				if( panquecas[a] < 0 ){ 
					panquecas[a] *= -1;
					resp.push_back(a+1);
					resp.push_back(1);
					resp.push_back(a+1);
				}
			} else {
				for( b = 0; b < quant; b++ ) if( abs(panquecas[b]) == (a+1) )	break;
				
				if( b != 0 ){
					resp.push_back(b+1);
					for( c = 0; c < b/2; c++ ){
						panquecas[c] ^= panquecas[b-c];
						panquecas[b-c] ^= panquecas[c];
						panquecas[c] ^= panquecas[b-c];
						panquecas[c] *= -1;
						panquecas[b-1] *= -1;
					}
					if( b % 2 == 0 ) panquecas[b/2] *= -1;
				}
				
				if( panquecas[0] < 0 ){ 
					panquecas[0] *= -1;
					resp.push_back(1);
				}
				
				resp.push_back(a+1);
				for( c=0; c < a/2; c++){
					panquecas[c] ^= panquecas[a-c];
					panquecas[a-c] ^= panquecas[c];
					panquecas[c] ^= panquecas[a-c];
					panquecas[c] *= -1;
					panquecas[a-1] *= -1;
				}
				if( a%2 == 0 ) panquecas[a/2] *= -1;
			}
				
				
		}
		cout << k << " " << resp.size();
		bool flg = true;
		for( size_t it = 0, sz = resp.size(); it < sz; it++ ){
			cout << " " << resp[it];
		}
		cout<< "\n";
	}
	
	
	return 0;
}