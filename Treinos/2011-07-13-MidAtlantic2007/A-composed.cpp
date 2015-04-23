#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

string ans[] = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };

int main(){

	map< string, int > val;
	val[ "A" ] = 0;
	val[ "A#" ] = val[ "Bb" ] = 1;
	val[ "B" ] = val[ "Cb" ] = 2;
	val[ "C" ] = val[ "B#" ] = 3;
	val[ "C#" ] = val[ "Db" ] = 4;
	val[ "D" ] = 5;
	val[ "D#" ] = val[ "Eb" ] = 6;
	val[ "E" ] = val[ "Fb" ] = 7;
	val[ "F" ] = val[ "E#" ] = 8;
	val[ "F#" ] = val[ "Gb" ] = 9;
	val[ "G" ] = 10;
	val[ "G#" ] = val[ "Ab" ] = 11;
	
	string line, note;
	
	getline( cin, line );
	while( line != "***" ){
		int n;
		cin >> n; cin.ignore();
		
		vector< int > notes;
		istringstream in(line);
		while( in >> note ) notes.push_back( val[note] );
		for( size_t i = 0; i < notes.size(); i++ ){
			notes[i] += n;
			while( notes[i] < 0 ) notes[i] += 12;
			notes[i] %= 12;
		}
		
		if( notes.size() > 0 ) cout << ans[ notes[0] ];
		for( size_t i = 1; i < notes.size(); i++ ) cout << " " << ans[ notes[i] ];
		cout << "\n";
		
		getline( cin, line );	
	}	

	return 0;
}

