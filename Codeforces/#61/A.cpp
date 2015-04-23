/*
 *  Problema:
 *  Tecnica Utilizada:  
 *      
 *
 *  Dificuldade: 
 *      Complexidade:
 *                              O(  )
 */

#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef unsigned long long uint64;

using namespace std;

long long get( string val ){
        istringstream is( val );
        long long ret;
        is >> ret;
        return ret;
}

int main( int argc, char* argv[] ){

        ios::sync_with_stdio( false );
        
        string num;
        
        cin >> num;
        int sz = SIZE( num );
        if(num[0]=='-') sz--;
        if( sz > 19 ) cout << "BigInteger";
        else if( sz == 19 ){
                long long xx = get( num.substr( 0, SIZE(num)-1 ) );
                if( xx < -922337203685477580LL ) cout << "BigInteger";
                else if( xx == -922337203685477580LL && num[SIZE(num)-1] > '8' ) cout << "BigInteger";
                else if( xx > 922337203685477580LL ) cout << "BigInteger";
                else if( xx == 922337203685477580LL && num[SIZE(num)-1] > '7' ) cout << "BigInteger";
                else cout << "long";
        } else {
                long long x = get( num );
                if( x >= -128LL && x <= 127LL ) cout << "byte";
                else if( x >= -32768LL && x <= 32767LL ) cout << "short";
                else if( x >= -2147483648LL && x <= 2147483647LL ) cout << "int";
                else cout << "long";
        } 
        cout << "\n";
         
        return 0;
}