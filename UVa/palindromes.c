#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 22

char line[MAXS];
char mirror[MAXS];
char revert[91];
char *ptr;

char isPalindrome(){
     
     int i = 0, j = strlen( line )-1;
     for( ; i < j; i++, j-- )
          if( line[i] != line[j] ) return 0;
          
     return 1;
     
     
}

char isMirror(){

     int i = 0;
     ptr = line;
     
     while( *ptr ){
            mirror[i++] = revert[*ptr];
            ptr++;
     }
     mirror[i--] = 0;
     
     ptr = line;
     while( *ptr ){
            if( mirror[i--] != *ptr ) return 0;
            ptr++;
     }
     
     return 1;
     
}

int main(){
    
    char pal, mir;
    revert['A'] = 'A'; revert['M'] = 'M'; revert['Y'] = 'Y';
    revert['B'] = '-'; revert['N'] = '-'; revert['Z'] = '5';
    revert['C'] = '-'; revert['O'] = 'O'; revert['1'] = '1';
    revert['D'] = '-'; revert['P'] = '-'; revert['2'] = 'S';
    revert['E'] = '3'; revert['Q'] = '-'; revert['3'] = 'E';
    revert['F'] = '-'; revert['R'] = '-'; revert['4'] = '-'; 	
    revert['G'] = '-'; revert['S'] = '2'; revert['5'] = 'Z';
    revert['H'] = 'H'; revert['T'] = 'T'; revert['6'] = '-'; 	
    revert['I'] = 'I'; revert['U'] = 'U'; revert['7'] = '-'; 	
    revert['J'] = 'L'; revert['V'] = 'V'; revert['8'] = '8';
    revert['K'] = '-'; revert['W'] = 'W'; revert['9'] = '-'; 	
    revert['L'] = 'J'; revert['X'] = 'X'; 		

    while( gets( line ) ){
    
           if( !line[0] ) continue;
           
           pal = isPalindrome();
           mir = isMirror();
           
           
           if( pal && mir )
               printf("%s -- is a mirrored palindrome.\n\n", line );
           else if( pal )
               printf("%s -- is a regular palindrome.\n\n", line );
           else if( mir )
               printf("%s -- is a mirrored string.\n\n", line );
           else
               printf("%s -- is not a palindrome.\n\n", line );
    
    }
    
    return 0;
}
