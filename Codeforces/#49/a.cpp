#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    string prefix, word, ans;
    int n, i;
    ios::sync_with_stdio( false );
    
    cin >> prefix;
    cin >> n;
    
    ans = "{";
    
    while( n-- ){
           cin >> word;
           if( word.size() >= prefix.size() ){
               for( i = 0; i < prefix.size() && prefix[i] == word[i]; i++ );
               if( i == prefix.size() && word < ans ) ans = word;
           }
    }
    if( ans == "{" ) cout << prefix;
    else cout << ans;
    cout << "\n";

    return 0;    
}
