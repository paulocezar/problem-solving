#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int k=1,tam;
	string str;
	int a,b,c;
	char ch;
	
	for(cin>>str; str != "0"; cin >> str){
		str = "9"+str;
		tam = str.size();
		
		for(a = tam-1; a>=1; a--){
			ch = str[a];
			if(ch > str[a-1]){
				str[a-1]+=10;
				//Diminuindo o proximo numero em uma unidade, e aumentando esse em 10 unidades
				for(b = a-2; b >= 0; b--){
					str[b] = str[b]-1;
					if(str[b] >= '0') break;
					else str[b] = str[b]+10;
				}
			}
			str[a-1] -= (ch-'0');
		}
		if(str[1]=='0'){
			cout << (k++) << ". " << "IMPOSSIBLE\n";
		} else {
			cout << (k++) << ". " << str.substr(1) << endl;
			
		}
	}
	return 0;
}

