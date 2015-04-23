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
#include <bitset>
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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int seen[1<<20], seen_now;

int nxt_id;
struct node_t{
	int id;
	bool nd;
	node_t* chld[2];
	
	node_t() { chld[0] = chld[1] = NULL; id = nxt_id++; nd = false; }
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n1, n2;
	while(cin >> n1 >> n2) {
		
		nxt_id = 0;
		node_t* trie1 = new node_t();
		
		REP(j,n1){
			string x;
			cin >> x;
			node_t* cur = trie1;
			REP(i,SIZE(x)) {
				x[i] -= '0';
				if(cur->chld[x[i]] == NULL) cur->chld[x[i]] = new node_t();
				cur = cur->chld[x[i]];
			}
			cur->nd = true;
		}
		
		nxt_id = 0;
		node_t* trie2 = new node_t();
		
		REP(j,n2){
			string x;
			cin >> x;
			node_t* cur = trie2;
			REP(i,SIZE(x)) {
				x[i] -= '0';
				if(cur->chld[x[i]] == NULL) cur->chld[x[i]] = new node_t();
				cur = cur->chld[x[i]];
			}
			cur->nd = true;
		}
		
		seen_now++;
		
		queue< pair<node_t*,node_t*> > q;
		q.push( MP(trie1,trie2) );
		seen[0] = seen_now;
		
		node_t *t1, *t2, *nt1, *nt2;
		bool ok = false;
		while(!q.empty()) {
			t1 = q.front().first;
			t2 = q.front().second;
			q.pop();
			
			REP(chr,2) {
				nt1 = t1->chld[chr];
				nt2 = t2->chld[chr];
				if(nt1 != NULL && nt2 != NULL) {
					if(nt1->nd && nt2->nd) {
						ok = true;
						goto hell;
					}
					int stt = ((nt1->id)<<10) | (nt2->id);
					if (seen[stt] != seen_now){
						seen[stt] = seen_now;
						q.push(MP(nt1,nt2));
					}
					if(nt1->nd) nt1 = trie1;
					if(nt2->nd) nt2 = trie2;
					stt = ((nt1->id)<<10) | (nt2->id);
					if (seen[stt] != seen_now){
						seen[stt] = seen_now;
						q.push(MP(nt1,nt2));
					}
				}
			}
			
		}
	hell:	
		if(ok) cout << "S\n";
		else cout << "N\n";
		
	}
	

	return 0;
}


























