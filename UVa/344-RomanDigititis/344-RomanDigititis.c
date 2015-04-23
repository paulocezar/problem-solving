/* Problema 344 - Numerais Romanos */

 #include <stdio.h>

 struct lista {
         unsigned int input;
         struct lista* prox;
 };
 typedef struct lista Lista;
 
 int somaUnidades[10][5] = { {  1, 0, 0, 0, 0 },
                            {  3, 0, 0, 0, 0 },
                            {  6, 0, 0, 0, 0 },
                            {  7, 1, 0, 0, 0 },
                            {  7, 2, 0, 0, 0 },
                            {  8, 3, 0, 0, 0 },
                            {  10, 4, 0, 0, 0 },
                            {  13, 5, 0, 0, 0 },
                            {  14, 5, 1, 0, 0 },
                            {  140, 50, 150, 50, 10 } };

 int acrescimoDezenas[9][5] = { { 0, 0, 1, 0, 0 },
                                { 0, 0, 2, 0, 0 },
                                { 0, 0, 3, 0, 0 },
                                { 0, 0, 1, 1, 0 },
                                { 0, 0, 0, 1, 0 },
                                { 0, 0, 1, 1, 0 },
                                { 0, 0, 2, 1, 0 },
                                { 0, 0, 3, 1, 0 },
                                { 0, 0, 1, 0, 1 } };  
                                
 Lista* criaLista ();
 Lista* insereNumero(Lista* l, int i);
 void imprimeResultado ( int input );                          


main(){
       
       Lista* entrada;
       Lista* t;
       int input;
       
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
        
       for (t=entrada; t!=NULL; t=t->prox)
         imprimeResultado( t->input );          
 
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
  
  void imprimeResultado ( int input ){
       
       int dezenas = input / 10;
       int unidades = input % 10;
       int aux1, aux2;
       int somaDezenas[] = { 0, 0, 0, 0, 0 };
       int aux[] = { 0, 0, 0, 0, 0 };
       int saida[] = { 0, 0, 0, 0, 0 };
       
       if ( input < 10 ){
            
         for ( aux1 = 0; aux1<5; aux1++ )
           saida[aux1] = somaUnidades[input-1][aux1];     
       
       } else {
              
              for ( aux1 = 0; aux1<5; aux1++ )
              saida[aux1] =  dezenas * somaUnidades[8][aux1];
              
        
              for ( aux1 = 0; aux1<5; aux1++ ){
                  for ( aux2 = 0; aux2<(dezenas-1); aux2++ ){
                      somaDezenas[aux1] = somaDezenas[aux1] + acrescimoDezenas[aux2][aux1];
                 }
              }

              
              for ( aux1 = 0; aux1<5; aux1++ )
                  somaDezenas[aux1] = 10 * somaDezenas[aux1];    

        
              for ( aux1 = 0; aux1<5; aux1++ )
                  saida[aux1] = saida[aux1] + somaUnidades[unidades-1][aux1];
              
        
              for ( aux1 = 0; aux1<5; aux1++ )
                  aux[aux1] = ( unidades+1 ) * acrescimoDezenas[dezenas-1][aux1];
                  
        
              for ( aux1 = 0; aux1<5; aux1++ )
                  saida[aux1] = saida[aux1] + somaDezenas[aux1] + aux[aux1];
 
       }
       
       printf(" %d: %d i, %d v, %d x, %d l, %d c .\n", input,
        saida[0], saida[1], saida[2], saida[3], saida[4] );
             
       return;
    
  } 
   
