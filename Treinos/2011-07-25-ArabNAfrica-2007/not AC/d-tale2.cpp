#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	string str,aux;
	set<int> trocou;
	int tam,a,b;
	
	for(getline(cin, str); str != "EOF"; getline(cin, str)){
		tam = str.size();
		trocou.clear();
		
		//Trocando dd por p
		a = str.find("dd");
		while(a != -1){
			trocou.insert(a);
			aux = str.substr( 0, a ) + "p" + str.substr( a+2 );
			str = aux;
			a = str.find("dd");
		}
		
		//Trocando pink por floyd
		tam = str.size();
		for(a=0;a<=tam-4;a++){
			if(str[a] == 'p' && str[a+1] == 'i' && str[a+2] == 'n' && str[a+3] == 'k' && trocou.find(a) == trocou.end()){
				aux = str.substr( 0, a ) + "floyd" + str.substr( a + 4 );
				str = aux;
				tam = str.size();
			}
		}
		/*a = str.find("pink");
		while(a != -1){
			aux = str.substr( 0, a ) + "floyd" + str.substr( a + 4 );
			str = aux;
			a = str.find("pink");
		}*/
		
		//Trocando ei por ie, desde que nao seja cei
		tam = str.size();
		if(str[0]=='e' && str[1] == 'i'){
			str[0] = 'i';
			str[1] = 'e';
		}
		for(a = 0; a <= tam-3; a++){
			if(str[a] != 'c' && str[a+1] == 'e' && str[a+2] == 'i'){
				str[a+1] = 'i';
				str[a+2] = 'e';
			}
		}
		
		tam = str.size();
		for(a=0;a<tam;a++){
			if(str[a] == ' ' || (str[a] >= 'a' && str[a] <= 'z')) cout << str[a];
		}
		cout << endl;
	}
	
	return 0;
}

