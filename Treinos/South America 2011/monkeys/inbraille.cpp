#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	map< char, string > mm[3];
	map< string, int > mmm;
	
	mm[0]['1'] = "*.";
	mm[1]['1'] = "..";
	mm[2]['1'] = "..";
	
	mm[0]['2'] = "*.";
	mm[1]['2'] = "*.";
	mm[2]['2'] = "..";
	
	mm[0]['3'] = "**";
	mm[1]['3'] = "..";
	mm[2]['3'] = "..";
	
	mm[0]['4'] = "**";
	mm[1]['4'] = ".*";
	mm[2]['4'] = "..";
	
	mm[0]['5'] = "*.";
	mm[1]['5'] = ".*";
	mm[2]['5'] = "..";
	
	mm[0]['6'] = "**";
	mm[1]['6'] = "*.";
	mm[2]['6'] = "..";
	
	mm[0]['7'] = "**";
	mm[1]['7'] = "**";
	mm[2]['7'] = "..";
	
	mm[0]['8'] = "*.";
	mm[1]['8'] = "**";
	mm[2]['8'] = "..";
	
	mm[0]['9'] = ".*";
	mm[1]['9'] = "*.";
	mm[2]['9'] = "..";
	
	mm[0]['0'] = ".*";
	mm[1]['0'] = "**";
	mm[2]['0'] = "..";
	
	mmm["*....."] = 1;
	mmm["*.*..."] = 2;
	mmm["**...."] = 3;
	mmm["**.*.."] = 4;
	mmm["*..*.."] = 5;
	mmm["***..."] = 6;
	mmm["****.."] = 7;
	mmm["*.**.."] = 8;
	mmm[".**..."] = 9;
	mmm[".***.."] = 0;
										
	
	int D;
	char wut;
	while( cin >> D && D ){
		cin >> wut;
		if( wut == 'B' ){
			string ans[D];
			for( int i = 0; i < D; i++ ) ans[i] = "";
			
			for( int lvl = 0; lvl < 3; lvl++ ){
				for( int i = 0; i < D; i++ ){
					string now;
					cin >> now;
					ans[i] += now;
				}
			}
			
			for( int i = 0; i < D; i++ )
				cout << mmm[ ans[i] ];
			cout << "\n";
			
		} else {
			string msg;
			cin >> msg;
			for( int lvl = 0; lvl < 3; lvl++ ){
				for( int i = 0; i < D; i++ ){
					if( i ) cout << " ";
					cout << mm[lvl][ msg[i] ];
				}
				cout << "\n";
			}
		}
	}
	return 0;
}

