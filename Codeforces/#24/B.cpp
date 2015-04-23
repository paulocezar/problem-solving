#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>

using namespace std;

struct racer {
        string name;
        int pos[51];
};
int points[10];

int compOld( const void *a, const void *b ){
    
    racer *ra = (racer*)a;
    racer *rb = (racer*)b;
    int i, pa, pb;
    pa = pb = 0;
    for( i = 0; i < 10; i++ ){
         pa += (ra->pos[i]*points[i]);
         pb += (rb->pos[i]*points[i]);
    }
    if( pb - pa ) return pb - pa;
    i = 0;
    while( ( rb->pos[i] - ra->pos[i] ) == 0 ) i++;
    return rb->pos[i] - ra->pos[i];
    
}

int compNew( const void *a, const void *b ){

    racer *ra = (racer*)a;
    racer *rb = (racer*)b;
    int i, pa, pb;
    
    if( ( rb->pos[0] - ra->pos[0] ) ) return ( rb->pos[0] - ra->pos[0] );
    
    pa = pb = 0;
    for( i = 0; i < 10; i++ ){
         pa += (ra->pos[i]*points[i]);
         pb += (rb->pos[i]*points[i]);
    }
    if( pb - pa ) return pb - pa;
    i = 1;
    while( ( rb->pos[i] - ra->pos[i] ) == 0 ) i++;
    return rb->pos[i] - ra->pos[i];

}

int main(){
    
    racer racers[55];
    map< string, int > hash;
    int t, n, i, j, k, id = 0;
    
    string sname;
    points[0] = 25;
    points[1] = 18;
    points[2] = 15;
    points[3] = 12;
    points[4] = 10;
    points[5] = 8;
    points[6] = 6;
    points[7] = 4;
    points[8] = 2;
    points[9] = 1;
    
    scanf("%d", &t );
    for( i = 0; i < t; i++ ){
         scanf("%d", &n );
         for( j = 0; j < n; j++ ){
              cin >> sname;
              
              if( hash.find( sname ) != hash.end() ){
                  racers[hash[sname]].pos[j]++;
              }
              else{
                   
                   racers[id].name = sname;
                   for( k = 0; k < 51; k++ )
                        racers[id].pos[k] = 0;
                   racers[id].pos[j]++;
                   hash[sname] = id;
                   id++;

              }
         }
    }
    
    qsort( racers, id, sizeof( racer ), compOld );
    sname = racers[0].name;
    qsort( racers, id, sizeof( racer ), compNew );
    
    cout << sname << endl << racers[0].name << endl;       

    return 0;
}

