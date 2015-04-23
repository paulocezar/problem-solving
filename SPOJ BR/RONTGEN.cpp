#include <iostream>
#include <cstring>

using namespace std;

int main(){

 char input[1004];
 int testCases = 0;

 scanf("%d", &testCases );
 scanf("%*c");

 while( testCases != 0  ){
	char firstSequence[2000000];
	char nextSequence[2000000];
	int  numSequences = 0, i = 0, indice = 0;

	cin.getline(input, 1003);
	sscanf( input, "%s %d", firstSequence, &numSequences );

	cout << firstSequence << endl ;

	for( i = 0; i < numSequences; i++ ){
		int j = 0;
		while( firstSequence[j] != '\0' ){
			int cont = 1;
			char conts[1001];
			char x = firstSequence[j];
			j++;
			while( firstSequence[j] == x ){
				cont++;
				j++;
			}
			sprintf(conts, "%d", cont);
			cont = 0;

			while( conts[cont] != '\0' ){
			nextSequence[indice++] = conts[cont];
			cont++;
			}
			nextSequence[indice++] = x;
		}
		nextSequence[indice] = '\0';
		cout << nextSequence << endl ;
		strcpy( firstSequence, nextSequence );
		indice = 0;
	}
 	cout << endl;
 testCases--;
}


 return 0;
}
