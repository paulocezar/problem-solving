#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    
    char code[256];
    int i;
    ios::sync_with_stdio( false );
    string inp, cyp, line;
    list< string > text;
    
    for( i = 0; i < 256; i++ )
         code[i] = i;
    
    cin >> inp;
    cin >> cyp;
    
    for( i = 0; inp[i]; i++ )
         code[inp[i]] = cyp[i];
         
    cin.ignore();
    
    while( getline( cin, line ) ){
           
       if( line == "End of text!!!" ) break;
       
       i = 0;
       while( line[i] ){
              line[i] = code[line[i]];
              i++;
       }
       text.push_back( line );
       
    }
    
    cout << cyp << "\n";
    cout << inp << "\n";
    list< string >::iterator it = text.begin();
    while( it != text.end() ){
           cout << *it << "\n";       
           it++;
    }
    

    return 0;    
}
