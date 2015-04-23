/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>

#define MAXW 100

using namespace std;

string acronym;

int numWords;
int acronymSZ;

string word[MAXW];
int wsz[MAXW];
int memo[MAXW][MAXW][MAXW];

map< int, map< int, map< int, bool > > > solved;

int play( int cur_word, int cur_pos, int cur_lt ){

	int ans = 0;	
	int pos = cur_pos;
	
	if( cur_word >= numWords || cur_pos >= wsz[cur_word] || cur_lt >= acronymSZ ) return 0;
	if( solved[cur_word][cur_pos][cur_lt] ) return memo[cur_word][cur_pos][cur_lt];
	
	if( cur_word == numWords-1 ){
		
		while( cur_pos < wsz[cur_word] ){

			if( word[cur_word][cur_pos] == acronym[cur_lt] ){

				if( cur_lt < acronymSZ-1 ) ans += play( cur_word, cur_pos+1, cur_lt+1 );
				else ans++;
			
			}

			cur_pos++;
		}
		
		solved[cur_word][pos][cur_lt] = true;
		return ( memo[cur_word][pos][cur_lt] = ans );
	}
			
	while( cur_pos < wsz[cur_word] ){
		
		if( word[cur_word][cur_pos] == acronym[cur_lt] ){
			
			ans += play( cur_word, cur_pos+1, cur_lt+1 );
			ans += play( cur_word+1, 0, cur_lt+1 );
		}
		
		cur_pos++;
	}
	
	solved[cur_word][pos][cur_lt] = true;
	return ( memo[cur_word][pos][cur_lt] = ans );
}

int solve(){	
	solved.clear();
	return play( 0, 0, 0 );
}

int main(){

	int n, i, ans;
	string wrd, line;
	ios::sync_with_stdio( false );

	while( true ){
		
		cin >> n;
		if( n == 0 ) break;
			
		set< string > insig;
		
		while( n-- ){
			cin >> wrd;
			insig.insert( wrd );
		}
		
		cin.ignore();
		while( true ){
			
			getline( cin, line );
			if( line == "LAST CASE" ) break;
			
			istringstream in( line );
			in >> acronym;
			numWords = 0;
			while( in >> wrd ){				
				if( insig.find( wrd ) == insig.end() ){
					word[numWords] = wrd;
					wsz[numWords++] = wrd.size();
				}
			}
			
			ans = 0;
			
			acronymSZ = acronym.size();
			if( acronymSZ >= numWords ){
				for( i = 0; i < acronymSZ; i++ ) acronym[i] += ( 'a'-'A');
				ans = solve();
				for( i = 0; i < acronymSZ; i++ ) acronym[i] += ( 'A'-'a');
			}
			
			if( ans > 0 ) cout << acronym << " can be formed in " << ans << " ways\n";
			else cout << acronym << " is not a valid abbreviation\n";

		}	
	
	}
	
	return 0;
}
