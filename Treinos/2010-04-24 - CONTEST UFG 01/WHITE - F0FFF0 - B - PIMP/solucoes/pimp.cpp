#include <iostream>
using namespace std;

int main () {
  int SC;
  cin >> SC;
  for( int S=1; S<=SC; S++ ){
    cout << "Teste #" << S << ":" << endl;
    
    int n;
    cin >> n;
    int cost[n][n];
    for( int i=0; i<n; i++ )
      for( int j=0; j<n; j++ )
	cin >> cost[i][j];
    
    int N = 1 << n;
    int best[1<<14] = {};
    for( int s=1; s<N; s++ ){
      best[s] = 1<<30;
      for( int i=0; i<n; i++ ) if( s & 1<<i ){
	int b = best[s ^ 1<<i];
	for( int j=0; j<n; j++ ) if( s & 1<<j )
	  b += cost[i][j];
		  best[s] = ( best[s] < b ) ? best[s] : b;
      }
    }
    
	  cout << "Voce foi oficialmente pimpado por apenas R$ " << best[N-1] << ".\n" << endl;
  }
}
