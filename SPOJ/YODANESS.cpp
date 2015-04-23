#include <iostream>
#include <string>
#include <map>
#include <cstring>

#define MAXN 31000

using namespace std;

int bit[MAXN];
int MAXVAL;

void up( int idx ){
     while( idx <= MAXVAL ){
            bit[idx]++;
            idx += idx & (-idx);
     }
}

int get( int idx ){
    int sum = 0;
    while( idx ){
      sum += bit[idx];
      idx -= idx & (-idx);
    }
    return sum;
}

int main(){    
    
    int t, i, ans;
    string wrd;
    ios::sync_with_stdio( false );
    
    cin >> t;
    while( t-- ){
    
           cin >> MAXVAL;
           memset( bit, 0, sizeof( int ) * (MAXVAL+2) );
           map< string, int > idx;
           for( i = 1; i <= MAXVAL; i++ ){
                cin >> wrd;
                idx[wrd] = i;
           }
           
           ans = 0;
           for( i = 1; i <= MAXVAL; i++ ){
                cin >> wrd;
                ans += ( i - get( idx[wrd] ) - 1 );
                up( idx[wrd] );
           }
           cout << ans << "\n";
    }

    return 0;
}
