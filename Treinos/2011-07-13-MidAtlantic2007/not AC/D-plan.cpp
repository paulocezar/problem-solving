#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

set< string > forbid;

int main(){
	
	string word;
	cin >> word;
	while( word != "EndOfInput" ){
		
		forbid.clear();
		
		while( word != "EndOfList" ){
			for( size_t i = 0, s = word.size(); i < s; i++ ) word[i] = toupper( word[i] );
			forbid.insert( word );
			cin >> word;
		}
		
		
		cin.ignore();
		string line;
		getline( cin, line );
		
		string text = "";
		
		while( line != "EndOfMsg" ){
			text += line;
			text += '\n';
			getline( cin, line );
		}
		
		string wrd = "";
		bool ok = true;
		vector< bool > end( text.size(), false );
		
		for( size_t i = 0, s = text.size(); i < s; i++ ){
			if( isalpha( text[i] ) || isdigit(text[i]) ) wrd += toupper( text[i] );
			else {
				if( ok && (forbid.find( wrd ) != forbid.end()) ) ok = false;
				if( (text[i] == '\n'&&text[i-1]=='\n') || text[i] == '.' || text[i] == '!' || text[i] == '?' ){
					end[i] = true;
					if( !ok ){
						if( text[i] != '\n' ) text[i] = '@';
						int j = i-1;
						while( j >= 0 && !end[j] ){
							if( text[j] != '\n' ) text[j] = '@';
							j--;
						}
						ok = true;
					}
				}
				wrd = "";
			}	
		}
		
		if( ok && (forbid.find( wrd ) != forbid.end()) ) ok = false;
		if( !ok ){
			if( text[ int(text.size())-1 ] != '\n' && !end[ int(text.size())-1 ] ) text[ int(text.size())-1 ] = '@';
			int j = int(text.size())-1;
			while( j >= 0 && !end[j] ){
				if( text[j] != '\n' ) text[j] = '@';
				j--;
			}
		}
		
		cout << text << "====\n";
		
		cin >> word;
	}

	return 0;
}

