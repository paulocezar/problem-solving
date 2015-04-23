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
#include <utility>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define WDG 0
#define HBX 1
#define VBX 2

struct widget{
	int64 x, y;
	int tp, spc, bord;
	vector< widget* > packed;
	widget( int tt = 0, int64 xx = 0, int64 yy = 0 ){ tp = tt; x = xx; y = yy; spc = bord = 0;}
	void pack( widget* a ){ packed.pb( a ); }
	void setbor( int val ){ bord = val; }
	void setspc( int val ){ spc = val; }
	int64 getX(){
		int64 r = 0;
		switch( tp ){
			case WDG: r = x; break;
			case HBX:
			if( x != -1 ){ r = x; break; } 
			FORIT( pk, packed ) r += (*pk)->getX();
			if( SIZE(packed) ) r += (SIZE(packed)-1)*spc;
			if( SIZE(packed) ) r += 2*bord; break;
			case VBX:
			if( x != -1 ){ r = x; break; }
			FORIT( pk, packed ) r = MAX( r, (*pk)->getX() );
			if( SIZE(packed) ) r += 2*bord; break;
		}
		return (x = r);
	}
	int64 getY(){
		int64 r = 0;
		switch( tp ){
			case WDG: r = y; break;
			case HBX: 
			if( y != -1 ){ r = y; break; }
			FORIT( pk, packed ) r = MAX( r, (*pk)->getY() );
			if( SIZE(packed) ) r += 2*bord;
			break;
			case VBX:
			if( y != -1 ){ r = y; break; }
			FORIT( pk, packed ) r += (*pk)->getY();
			if( SIZE(packed) ) r += (SIZE(packed)-1)*spc;
			if( SIZE(packed) ) r += 2*bord;
			break;
		}
		return (y = r);
	}
};

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	map< string, widget > screen;
	
	int N;
	string cmd, aux, name1, name2;
	cin >> N;
	while( N-- ){
		
		cin >> cmd;
		
		if( cmd == "Widget" ){
			cin >> aux; int i = 0;
			name1 = "";
			while( aux[i] != '(' ) name1 += aux[i++];
			int xx = 0, yy = 0;
			i++;
			while( aux[i] != ',' ){ xx = 10*xx + ( aux[i]-'0' ); i++; }
			i++;
			while( aux[i] != ')' ){ yy = 10*yy + ( aux[i]-'0' ); i++; }
			screen[name1] = widget( WDG, xx, yy );
		}else if( cmd == "HBox" ){
			cin >> name1;
			screen[name1] = widget( HBX, -1, -1 );
		}else if( cmd == "VBox" ){
			cin >> name1;
			screen[name1] = widget( VBX, -1, -1 );
		}else{
			size_t p = cmd.find_first_of('.');
			name1 = cmd.substr( 0, p );
			if( cmd[p+1] == 'p' ){
				name2 = cmd.substr( p+6, SIZE(cmd)-p-7 );
				screen[name1].pack( &screen[name2] );
			}else{
				if( cmd[p+5] == 'b' ){
					int i = p+12;
					int xx = 0;
					while( cmd[i] != ')' ){ xx = 10*xx + (cmd[i]-'0'); i++; }
					screen[name1].setbor( xx );
					
				}else{
					int i = p+13;
					int xx = 0;
					while( cmd[i] != ')' ){ xx = 10*xx + (cmd[i]-'0'); i++; }
					
					screen[name1].setspc( xx );
				}
			}
		}
		
	}
	FORIT( wd, screen ) cout << wd->first << " " << (wd->second).getX() << " " << (wd->second).getY() << "\n";
	
 	return 0;
}

































