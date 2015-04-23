#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>

#define MAXN 1001
#define MAXS 21

using namespace std;

struct team {
       
	string name;
	int win;
	int swin;
	int slose;
	int points;
	int balance;
	
	bool operator < ( const team &t ) const {
         
         if( win > t.win ) return true;
    	 else if( win < t.win ) return false;
         
         if( balance > t.balance ) return true;
         else if( balance < t.balance ) return false;
         
         if( points > t.points ) return true;
         else if( points < t.points ) return false;
         
         if( name < t.name ) return true;
         else return false;    
   }
	
};

int main(){
	
    int n, p, i, t1, t2, s1, s2, p1, p2;
	team teams[MAXN];
    char _t1[MAXS], _t2[MAXS], c;


		map< string, int > hash;
		
	while( 1 ){
        scanf("%d", &n );
        if( n == 0 ) return 0;
		getchar();

		for( i = 0; i < n; i++ ){
			getline( cin, teams[i].name );

			hash[teams[i].name] = i;

			teams[i].win = 0;
			teams[i].swin = 0;
			teams[i].slose = 0;
			teams[i].points = 0;
		}

		scanf("%d", &p);
		getchar();

		for( i = 0; i < p; i++ ){

			scanf("%[^-] %[^:]", _t1, _t2);
			getchar();
            
            
            t1 = hash[_t1];
			t2 = hash[_t2+1];

			s1 = s2 = 0;

			while( true ){
                        
				scanf("%d-%d", &p1, &p2);
				c = getchar();
                
                if( p1 > p2 ){
					teams[t1].swin++;
					teams[t2].slose++;

					s1++;
				}
				else{
					teams[t2].swin++;
					teams[t1].slose++;

					s2++;
				}

				teams[t1].points += p1;
				teams[t2].points += p2;

				if(c == '\n') break;
			}

			if( s1 > s2 ) teams[t1].win++;
			else teams[t2].win++;
			
		}

		for( i = 0; i < n; i++ )
			teams[i].balance = teams[i].swin - teams[i].slose;
             
        sort( teams, teams + n );

		for( i = 0; i < n; i++ )
             printf("%-20s%5d%5d%10d\n", teams[i].name.c_str(), teams[i].win, teams[i].balance, teams[i].points );

	}
	
	return 0;
}

