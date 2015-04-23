#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    ios::sync_with_stdio( false );
    char a, b, c, d;
    string lixo, dif[4];
    set< string > ct;
    
    cin >> n; 
    while( n-- ){
           cin.ignore();
           cin >> a >> b; cin.ignore(); cin >> c >> d; cin.ignore(); 

           dif[0] = dif[1] = dif[2] = dif[3] = "";
           dif[0] += a;
           dif[0] += b;
           dif[0] += c;
           dif[0] += d;
           
           dif[1] += b;
           dif[1] += d;
           dif[1] += a;
           dif[1] += c;
           
           dif[2] += d;
           dif[2] += c;
           dif[2] += b;
           dif[2] += a;
           
           dif[3] += c;
           dif[3] += a;
           dif[3] += d;
           dif[3] += b;
           
           sort( dif, dif+4 );
           ct.insert( dif[0] );
           if( n ) cin >> lixo;
           
    }
    cout << ct.size() << "\n";
    
    return 0;    
}
