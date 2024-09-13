#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>


// Enum para representar os estados
typedef enum {
    S0,
    S1,
    S2,
    S3,
    S4,
    S5
} Estado;

//Enum para representar os símbolos
typedef enum {
    SIMBOLO_A,
    SIMBOLO_B,
    SIMBOLO_C,
    SIMBOLO_D,
    SIMBOLO_X
} Simbolo;

// Função de transição
Estado transicao(Estado, Simbolo);

// Função para verificar se uma cadeia é aceita
bool aceitar_cadeia(const char*);


int main() {
    
	setlocale(LC_ALL, "");
    char cadeia[100];
    
    printf("Digite uma sequência de dígitos concatene 'a, b ou c' com o caracter 'x' e que termine em 'd': ");
    scanf("%s", cadeia);
    
    if (aceitar_cadeia(cadeia));
		
    else {
        printf("\nCadeia rejeitada.\n");
    }
    
    system("pause");
    return 0;
}


Estado transicao(Estado estado_atual, Simbolo simbolo) {
    int i;
    switch (estado_atual) {
        case S0:
            switch (simbolo) {
                case SIMBOLO_A: printf("S1 "); for (i = 0; i<100000000; i++);  return S1;
                case SIMBOLO_B: printf("S2 "); for (i = 0; i<100000000; i++);  return S2;
                case SIMBOLO_C: printf("S3 "); for (i = 0; i<100000000; i++);  return S3;
                case SIMBOLO_D: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_X: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
            }
        case S1:
            switch (simbolo) {
                case SIMBOLO_A: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_B: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_C: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_D: printf("S4 "); for (i = 0; i<100000000; i++);  return S4;
                case SIMBOLO_X: printf("S0 "); for (i = 0; i<100000000; i++);  return S0;
            }
        case S2:
            switch (simbolo) {
                case SIMBOLO_A: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_B: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_C: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_D: printf("S4 "); for (i = 0; i<100000000; i++);  return S4;
                case SIMBOLO_X: printf("S0 "); for (i = 0; i<100000000; i++);  return S0;
            }
    	case S3:
            switch (simbolo) {
                case SIMBOLO_A: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_B: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_C: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_D: printf("S4 "); for (i = 0; i<100000000; i++);  return S4;
                case SIMBOLO_X: printf("S0 "); for (i = 0; i<100000000; i++);  return S0;
            }
        case S4:
            switch (simbolo) {
                case SIMBOLO_A: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_B: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_C: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_D: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
                case SIMBOLO_X: printf("XX "); for (i = 0; i<100000000; i++);  return S5;
            }
    }
    return S1;
}

// Função para verificar se uma cadeia é aceita
bool aceitar_cadeia(const char *cadeia) {
    Estado estado_atual = S0;
    
    for (int i = 0; cadeia[i] != '\0'; i++) {
        Simbolo simbolo;
        switch (cadeia[i]) {
            case 'a': simbolo = SIMBOLO_A; break;
            case 'b': simbolo = SIMBOLO_B; break;
            case 'c': simbolo = SIMBOLO_C; break;
            case 'd': simbolo = SIMBOLO_D; break;
            case 'x': simbolo = SIMBOLO_X; break;
            default: return false; // Caso receba um número diferente de 0, 1 ou 2
        }
        
        estado_atual = transicao(estado_atual, simbolo);
      	if (estado_atual == S5)
        	{
			printf("\n\nCadeia não aceita - Sequência de caracteres inválida", estado_atual+1);
			return false;
      		}
    }
    printf("\n\nCadeia Aceita - Estado Final: S%i\n\n", estado_atual+1);
    return true;
}