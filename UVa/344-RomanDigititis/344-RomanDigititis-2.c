/* Problema 344 - Numerais Romanos */

 #include <stdio.h>

 struct lista {
         unsigned int input;
         struct lista* prox;
 };
 typedef struct lista Lista;
 
 int somas[10][5] = { {  1, 0, 0, 0, 0 },
                     {  3, 0, 0, 0, 0 },
                     {  6, 0, 0, 0, 0 },
                     {  7, 1, 0, 0, 0 },
                     {  7, 2, 0, 0, 0 },
                     {  8, 3, 0, 0, 0 },
                     {  10, 4, 0, 0, 0 },
                     {  13, 5, 0, 0, 0 },
                     {  14, 5, 1, 0, 0 },
                     {  140, 50, 150, 50, 10 } };

 int acrescimos[9][5] = { { 0, 0, 1, 0, 0 },
                                { 0, 0, 2, 0, 0 },
                                { 0, 0, 3, 0, 0 },
                                { 0, 0, 1, 1, 0 },
                                { 0, 0, 0, 1, 0 },
                                { 0, 0, 1, 1, 0 },
                                { 0, 0, 2, 1, 0 },
                                { 0, 0, 3, 1, 0 },
                                { 0, 0, 1, 0, 1 } };
                                
 int acrescimoCentenas[1][5] = { { 0, 0, 0, 0, 1 } };  
                                
 Lista* criaLista ();
 Lista* insereNumero(Lista* l, int i);
 int *calculaCaracteres ( int input );                          


main(){
       
       Lista* entrada;
       Lista* t;
       int input;
       int *output;
       
       entrada = criaLista ();
       
       printf("Digite um numero de 1 a 100 para descobrir quantos caracteres\n");
       printf("i, v, x, l e c sao necessarios para enumerar esse numero de\n");
       printf("paginas em algorismos romanos. Voce pode consultar mais de um numero\n");
       printf("por vez, basta digitar e apertar enter, quando tiver terminado de\n");
       printf("inserir os numeros que deseja entre com o numeral 0 ( zero ).\n\n");
       
       do{
            scanf("%d", &input );            
            if ( input == 0 )
               break;
            
            entrada = insereNumero( entrada, input );

          } while ( input != 0 );
       printf("\n\n");
        
       for (t=entrada; t!=NULL; t=t->prox) {
         output = calculaCaracteres ( t->input );
         printf(" %d: %d i, %d v, %d x, %d l, %d c .\n", t->input,
        output[0], output[1], output[2], output[3], output[4] );
       }
                  
 
 system("PAUSE");
 return 0;       
 }
 
  
  Lista* criaLista (){
        return NULL;
  }
  
  Lista* insereNumero(Lista* l, int i){
         Lista* novo = (Lista*) malloc(sizeof(Lista));
         novo->input = i;
         novo->prox = l;
         return novo;
  }
  
  int *calculaCaracteres ( int input ){
       
       int mult = input / 10;
       int resto = input % 10;
       int aux1, aux2;
       int somaAux[] = { 0, 0, 0, 0, 0 };
       int aux[] = { 0, 0, 0, 0, 0 };
       int saida[] = {  0, 0, 0, 0, 0 };
       if ( input < 10 ){
            
         for ( aux1 = 0; aux1<5; aux1++ )
           saida[aux1] = somas[input-1][aux1];     
       
       } else {
              
              for ( aux1 = 0; aux1<5; aux1++ )
              saida[aux1] =  mult * somas[8][aux1];
              
        
              for ( aux1 = 0; aux1<5; aux1++ ){
                  for ( aux2 = 0; aux2<(mult-1); aux2++ ){
                      somaAux[aux1] = somaAux[aux1] + acrescimos[aux2][aux1];
                 }
              }

              
              for ( aux1 = 0; aux1<5; aux1++ )
                  somaAux[aux1] = 10 * somaAux[aux1];    

        
              for ( aux1 = 0; aux1<5; aux1++ )
                  saida[aux1] = saida[aux1] + somas[resto-1][aux1];
              
        
              for ( aux1 = 0; aux1<5; aux1++ )
                  aux[aux1] = ( resto+1 ) * acrescimos[mult-1][aux1];
                  
        
              for ( aux1 = 0; aux1<5; aux1++ )
                  saida[aux1] = saida[aux1] + somaAux[aux1] + aux[aux1];
 
       }
       
                                  
       return saida;
    
  } 
   
