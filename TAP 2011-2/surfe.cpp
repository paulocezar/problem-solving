#include <map> 
#include <set> 
#include <list>
#include <stack>
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
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool dp[111][111];
string url[111];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t, n;
	string line, from, to;
	
	cin >> t;
	while( t-- ){ 
		cin >> n; REP( i, n ) REP( j, n ) dp[i][j] = false;
		
		map<string,int> urlid;
		int now = 0;
		
		REP( i, n ){
			cin >> line;
			//cout << "at " << line << endl;
			if( urlid.find(line) == urlid.end() ){ urlid[ line ] = now; url[ now++ ] = line; }
			int cur = urlid[line];
			
			getline( cin, line );
			while( line.find("<HTML>") == string::npos ) getline(cin,line);
			bool first = true;
			do{
				if( !first ) getline(cin,line);
				
				int bg = 0;
				while( line.find("<A HREF=\"", bg) != string::npos ){
					int from = line.find( "<A HREF=\"", bg )+9;
					int to = line.find( "\">", from );
					string link = line.substr( from,  to - from );
					if( urlid.find(link) == urlid.end() ){ urlid[ link ] = now; url[ now++ ] = link; }
					dp[cur][ urlid[link] ] = true;
					//cout << "\tlink to " << link << endl;
					cout << "Link de " << url[cur] << " para " << link << "\n";
					bg = to+3;
				}
				
				first = false;
			} while( line.find("</HTML>") == string::npos );
		}
		
		REP( k, now ) REP( i, now ) REP( j, now )
			dp[i][j] = (dp[i][j] || (dp[i][k] && dp[k][j]));
		
		while( getline(cin,from) ){
			if( from == "FIM" ) break;
			getline(cin,to);
			if( dp[ urlid[from] ][ urlid[to] ] ) cout << "Pode surfar de " << from << " ate " << to << "\n";
			else cout << "Nao pode surfar de " << from << " ate " << to << "\n";
		}
		
	}
	
	return 0;
}




















