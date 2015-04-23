#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t,k,a,tam,resp,max;
	string str;
	cin>>t;cin.ignore();
	for(k=1;k<=t;k++){
		getline(cin, str);
		tam=str.size();
		resp=0;
		max=0;
		for(a=0;a<tam;a++){
			if(str[a]=='[') resp++;
			else resp--;
			if(resp>max) max=resp;
		}
		cout<<k<<" "<< (1<<max) <<endl;
		
	}
	return 0;
}
