#include <iostream>
#include <string>

using namespace std;

int main(){

	int tam;
	string num;



	do{

	scanf("%d", &tam);
	cin.get();
	getline (cin, num);

		if( tam == 0 && num == "0")
			break; 


		for( int c = 1; c <= 5; c++ ){

			switch( c ){
				case 1: for( int i = 0; i < num.size(); i++ ){
						switch( num[i] ){
							case '2':
							case '3':
							case '5':
							case '6':
							case '7':
							case '8':
							case '9':
							case '0': printf(" ");
								  for( int j = 0; j < tam; j++ )
									printf("-");
								  printf(" ");
								break;
							case '1': printf(" ");
								  for( int k = 0; k < tam; k++ )
									printf(" "); 
								  printf(" ");
								  break;
							case '4': printf(" ");
								for( int j = 0; j < tam; j++ )
									printf(" ");
								printf(" ");
								break;
						}
						if( i != num.size()-1) printf(" ");
					}
					printf("\n");
					break;

				case 2: for( int i = 0; i < tam; i++ ){

					for( int j = 0; j < num.size(); j++ ){
						switch( num[j] ){
							case '1': printf(" ");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
									printf("|");
								  break;
							case '2':
							case '3':
							case '7': printf(" ");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf("|");
								  break;
							case '4':
							case '8':
							case '9':
							case '0': printf("|");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf("|");
								  break;
							case '6': 
							case '5': printf("|");
								for( int k = 0; k < tam; k++ )
									printf(" ");
								printf(" ");
								break;
						}
						if( i != num.size()-1) printf(" ");
					} printf("\n");
					}
					break;

				case 3: for( int i = 0; i < num.size(); i++ ){
						switch( num[i] ){
							case '2':
							case '3': 
							case '4':
							case '5':
							case '6':
							case '8':
							case '9': printf(" ");
								for( int j = 0; j < tam; j++ )
									printf("-");
								printf(" ");
								break;
							case '1': printf(" ");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf(" ");
								  break;
							case '0':printf(" ");
								for( int j = 0; j < tam; j++ )
									printf(" ");
								printf(" ");
								break;
							case '7': printf(" ");
								for( int j = 0; j < tam; j++ )
									printf(" ");
								printf(" ");
								break;
						}
						if( i != num.size()-1) printf(" ");
					} printf("\n");
					break;

				case 4: for( int i = 0; i < tam; i++ ){
					for( int j = 0; j < num.size(); j++ ){

						switch( num[j] ){
							case '1': printf(" ");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf("|");
								  break;
							case '2': printf("|");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf(" ");
								  break;
							case '3':
							case '4':
							case '5':
							case '7':
							case '9': printf(" ");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf("|");
								  break;

							case '6':
							case '8':
							case '0': printf("|");
								  for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf("|");
								  break;
						}
						if( i != num.size()-1) printf(" ");
					} printf("\n");
					} 
					break;

				case 5: for( int i = 0; i < num.size(); i++ ){

						switch( num[i] ){
							case '1': printf(" ");
								 for( int k = 0; k < tam; k++ )
									printf(" ");
								  printf(" ");
								  break;
							case '2':
							case '3':
							case '5':
							case '6':
							case '8':
							case '0':
							case '9': printf(" ");
								for( int j = 0; j < tam; j++ )
									printf("-");
								printf(" ");
								break;


							case '4':
							case '7': printf(" ");
								for( int j = 0; j < tam; j++ )
									printf(" ");
								printf(" ");
								break;
						}
						if( i != num.size()-1) printf(" ");
					} printf("\n");
					break;

			}

		}

	} while ( true );

 return 0;
}
