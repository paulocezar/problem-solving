#include <list>
#include <queue>
#include <iostream>

using namespace std;

struct LockersDivTwo
{
	
	int lastOpened(int N){
		
		int out = 1;
		int cur = 2, inc = 2;
		list< int > open;
		queue< int > closed;
		list< int >::iterator it;
		
		while( cur <= N ) { open.push_back( cur ); cur += 2; }
		
		while( !open.empty && open.size() != 1 ){
			
			it = open.begin();
			while( it != open.end() ){
				closed.push( *it );
				
				int x = 0;
				while( x <= inc && it != open.end() ) it++, x++;
			}
			
			while( !closed.empty() ){
				open.remove( closed.front() ); closed.pop();
			}
			inc++;
		}
		if( !open.empty() ) out = *(open.begin());
		return out;
	}
	
};