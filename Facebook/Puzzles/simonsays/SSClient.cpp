#include <iostream>

#include "gen/SimonSays.h"
#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>

using namespace std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using namespace boost;

int main(int argc, char **argv){
	
	shared_ptr<TTransport> socket( new TSocket( "thriftpuzzle.facebook.com", 9030 ) );
	shared_ptr<TTransport> transport( new TBufferedTransport( socket ) );
	shared_ptr<TProtocol> protocol( new TBinaryProtocol(transport) );
	
	SimonSaysClient client( protocol );
	
	try{
		
		transport->open();
		client.registerClient( "paulocezar.ufg@gmail.com" );
		
		string ans = "";
		vector< Color::type > colors;
		
		while( !client.endTurn() ){
			client.startTurn( colors );
			cout << "new turn started..\n";
			
			for( int i = 0; i < colors.size(); i++ ){
				cout << "\tsending " << colors[i] << endl; 
				client.chooseColor( colors[i] );
			}
		}
		
		client.winGame( ans );	
		cout << "\nYou win: " << ans << endl;
		transport->close();
	} catch( std::exception& e) {
		cout << "Exception: " << e.what() << '\n';
	}

	return 0;
}
