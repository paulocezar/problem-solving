#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>

using namespace std;

struct orientacao_t {

	int f, c;
	int v[4];
	
	orientacao_t() {}

	orientacao_t(int frente, int costas, int vizinhos[] ): f( frente ), c( costas )
	{	
		for( int i = 0; i < 4; i++ ) v[i] = vizinhos[i];

	}

	bool operator == ( const orientacao_t &o ) const {
		/* se as faces da frente e de tras sao iguais, verifica os vizinhos.. */
		if( f == o.f && c == o.c  ){
			if( v[0] == o.v[0] && v[1] == o.v[1] && v[2] == o.v[2] && v[3] == o.v[3] ) return true;
			if( v[0] == o.v[1] && v[1] == o.v[2] && v[2] == o.v[3] && v[3] == o.v[0] ) return true;
			if( v[0] == o.v[2] && v[1] == o.v[3] && v[2] == o.v[0] && v[3] == o.v[1] ) return true;
			if( v[0] == o.v[3] && v[1] == o.v[0] && v[2] == o.v[1] && v[3] == o.v[2] ) return true;
		}
		/* se a frente de um e igual as costas do outro, os vizinhos 0 e 2 sao invertidos.. e verifica se tem como rotacionar. */
		if( f == o.c && c == o.f  ){
			if( v[2] == o.v[0] && v[1] == o.v[1] && v[0] == o.v[2] && v[3] == o.v[3] ) return true;
			if( v[2] == o.v[1] && v[1] == o.v[2] && v[0] == o.v[3] && v[3] == o.v[0] ) return true;
			if( v[2] == o.v[2] && v[1] == o.v[3] && v[0] == o.v[0] && v[3] == o.v[1] ) return true;
			if( v[2] == o.v[3] && v[1] == o.v[0] && v[0] == o.v[1] && v[3] == o.v[2] ) return true;
		}
		return false;
	}
	
	void operator = ( const orientacao_t &o ) {
		f = o.f;
		c = o.c;
		for( int i = 0; i < 4; i++ ) v[i] = o.v[i];
	}

};

struct cubo_t {

	orientacao_t orientacao[3];
	
	cubo_t(){}

	cubo_t( int a, int b, int c, int d, int e, int f ){
	
		int v[4];
		/* Uma orientacao tem 'a' como face da frente, os vizinhos no sentido horario comecando da esquerda estao em 'v' */
		v[0] = e; v[1] = d; v[2] = c; v[3] = b;
		orientacao[0] = orientacao_t( a, f, v );

		/* Uma orientacao tem 'b' como face da frente, os vizinhos no sentido horario comecando da esquerda estao em 'v' */
		v[0] = e; v[1] = a; v[2] = c; v[3] = f;
		orientacao[1] = orientacao_t( b, d, v );
		
		/* Uma orientacao tem 'c' como face da frente, os vizinhos no sentido horario comecando da esquerda estao em 'v' */
		v[0] = d; v[1] = a; v[2] = b; v[3] = f;
		orientacao[2] = orientacao_t( e, c, v );
	}

	/*
	    se sao iguais retorna false.. 
			x < y == false && y < x == false => x == y
	 */
	bool operator == ( const cubo_t &c ) const {
		for( int i = 0; i < 3; i++ )
			for( int j = 0; j < 3; j++ )
				if( orientacao[i] == c.orientacao[j] ) return true;
		return false;
	}
	
	void operator = ( const cubo_t &c ) {
		orientacao[0] = c.orientacao[0];
		orientacao[1] = c.orientacao[1];
		orientacao[2] = c.orientacao[2];
	}

};

int main(){

	int n;
	int a, b, c, d, e, f;
	bool find;
	
	list< cubo_t >::iterator i;
	
	while( true ){

		scanf("%d", &n );
		if( n == 0 ) return 0;
		list< cubo_t > cubos;
		
		while( n-- ){
			
			scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f );
			cubo_t cubo( a, b, c, d, e, f );
			
			find = false;
			for( i = cubos.begin(); i != cubos.end(); i++ )
				if( *i == cubo ){ find = true; break; }
			
			if( !find )
				cubos.push_back( cubo );
		
		}
		cout << cubos.size() << endl;
		
	}

	return 0;
}

