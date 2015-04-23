#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    
    int T, M, N, i;
    string s;
    string ss;

    scanf("%d", &T );
    
    while( T-- ){
           scanf("%d %d", &M, &N );
           scanf("%*c");
           
           map< string, string > dicionario;
           map< string, string >::iterator it;
           
           for( i = 0; i < M; i++ ){
                getline( cin, s );
                getline( cin, ss );
                dicionario.insert( pair<string,string>(s, ss) );
           }
                     
           for( i = 0; i < N; i++ ){
                if( i != 0 )
                    printf("\n");
                    
                getline( cin, s );
                
                size_t ini = 0;
                size_t fim = s.find(' ', 0 );
                
                while( fim != string::npos ){

                  ss = s.substr( ini, fim - ini );

                  it = dicionario.find( ss );
                   if( it != dicionario.end() )
                       cout << it->second << " ";
                   else
                       cout << ss << " ";
                
                  ini = fim;
                  fim = s.find(" ", ini+1 );  
                  ini++;     

                }

                fim = s.length();
                ss = s.substr( ini, fim - ini);
                
                it = dicionario.find( ss );
                
                if( it != dicionario.end() )
                    cout << it->second;
                else
                    cout << ss;
                
           }
           
           printf("\n\n");
    }    
    
    return 0;
}
