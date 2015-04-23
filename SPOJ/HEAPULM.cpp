#include <iostream>
#include <string>
#include <algorithm>

#define MAXN 51000
#define LG 16

using namespace std;

struct tnode{
   int mp, pos;
};

string lbl[MAXN];
int val[MAXN];
int idx[MAXN];
tnode M[1<<(LG+1)];

bool comp( const int &a, const int &b ){
  return lbl[a] < lbl[b];
}

void build( int node, int lo, int hi ){
     if( lo == hi ){
         M[node].mp = idx[lo];
         M[node].pos = lo;
     } else { 
         int mid = (lo+hi)/2;
         build( 2*node, lo, mid );
         build( 2*node+1, mid+1, hi );
         if( val[ M[2*node].mp ] > val[ M[2*node+1].mp ] ){
             M[node].mp = M[2*node].mp;
             M[node].pos = M[2*node].pos;
         } else { 
             M[node].mp = M[2*node+1].mp;
             M[node].pos = M[2*node+1].pos;
         }
     }
}

tnode get( int node, int lo, int hi, int i, int j ){
    
     tnode r1, r2, ans;
     ans.mp = -1;
     
     if(  i > hi || j < lo ) return ans;
     if(  lo >= i && hi <= j ) return M[node];
     
     r1 = get( 2*node, lo, (lo+hi)/2, i, j );
     r2 = get( 2*node+1, (lo+hi)/2+1, hi, i, j );
     
     if( r1.mp == -1 ) return r2;
     else if( r2.mp == -1 ) return r1;
     else{
     
         if( val[ r1.mp ] > val[ r2.mp ] ) return r1;
         else return r2;
          
     }
}

void printTreap( int n, int beg, int end ){
     
     if( beg > end ) return;

     tnode max = get( 1, 0, n-1, beg, end );
     
     cout << "(";
     printTreap( n, beg, max.pos-1 );
     cout << lbl[ max.mp ] << "/" << val[ max.mp ];
     printTreap( n, max.pos+1, end );
     cout << ")";
     
}

int main(){
    
    int n, i;
    ios::sync_with_stdio( false );
    
    while( cin >> n && n ){
           
           for( i = 0; i < n ; i++ ){
                getline( cin, lbl[i], '/' );
                cin >> val[i];
                lbl[i] = lbl[i].substr( 1 );
                idx[i] = i;
           }
           sort( idx, idx+n, comp );
           build( 1, 0, n-1 );
           printTreap( n, 0, n-1 );
           cout << "\n";
    }
    
    return 0;

}
