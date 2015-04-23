#include <iostream>
#include <string>
#include <map>
#include <sstream>

#define MAXN 100111

using namespace std;

int words[MAXN];
int cnt[MAXN];

int main(){
	
	int t, i, wrd, ptr, doc = 1;
	int ini, end, pini, pend, nfound;
	string w, word;
	ios::sync_with_stdio( false );
	
	cin >> t; cin.ignore();
	while( t-- ){
		
		wrd = 1;
		ptr = 1;
		map< string, int > wrds;
				
		getline( cin, w );
		while( w != "END" ){
			for( i = 0; i < int(w.size()); i++ ){
				if( !( 'a' <= w[i] && w[i] <= 'z' ) ) w[i] = ' ';
			}
			istringstream in( w );
			while( in >> word ){
				if( wrds.find( word ) == wrds.end() ){
					wrds[word] = wrd;
					cnt[wrd] = 0;
					wrd++;
				}
				words[ptr] = wrds[word];
				ptr++;
			}
			getline( cin, w );
		}
		
		wrd--;
		ini = 1; end = ptr-1;
		pini = pend = 1;
		cnt[words[1]] = 1;
		nfound = 1;
		bool stop = false;
		
		while( pini < ptr ){
			
			if( nfound == wrd ){
				cnt[ words[pini] ]--;
				if( cnt[words[pini]] == 0 ) nfound--;
				pini++;
			} else if( pend+1 < ptr ){
				pend++;
				if( cnt[words[pend]] == 0 ) nfound++;
				cnt[words[pend]]++;
			} else stop = true;
			
			if( nfound == wrd ){
				if( (end-ini) > (pend-pini) ){
					ini = pini;
					end = pend;
				}
			}
			if( stop ) break;
			
		}
		
		if( nfound == wrd && pini < ptr ){
			if( (end-ini) > (pend-pini) ){
				ini = pini;
				end = pend;
			}
		}
		
		cout << "Document " << doc++ << ": " << ini << " " << end << "\n";
	}
	
	return 0;
}
