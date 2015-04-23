#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    
    ios::sync_with_stdio( false );
    
    string line;
    string s = "";
    
    while( cin >> line ){
           s += line;
    }
    istringstream in( s );
    
    int count = -1;
    list< int > q;
    vector< int > ans;
    
    while( getline( in, line, '>' ) ){
           
           if( line == "<table" ){
                q.push_front( count );
                count = 0;
           }
           else if( line == "</table" ){
                ans.push_back( count );
                count = q.front();
                q.pop_front();    
           }
           else if( line == "<td" ){
                count++;
           }                      
           
    }
    
    sort( ans.begin(), ans.end() );
    cout << ans[0];
    for( int i = 1; i < ans.size(); i++ )
         cout << " " << ans[i]; 
    cout << "\n";
    
    return 0;    
}
