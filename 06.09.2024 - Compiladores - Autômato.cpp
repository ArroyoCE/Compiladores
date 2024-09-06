#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>


// Enum para representar os estados
typedef enum {
    S1,
    S2,
    S3
} Estado;

//Enum para representar os símbolos
typedef enum {
    SIMBOLO_0,
    SIMBOLO_1,
    SIMBOLO_2
} Simbolo;

// Função de transição
Estado transicao(Estado, Simbolo);

// Função para verificar se uma cadeia é aceita
bool aceitar_cadeia(const char*);


int main() {
	setlocale(LC_ALL, "");
    char cadeia[100];
    
    printf("Digite uma sequência de dígitos composta apenas por 0, 1 e 2: ");
    scanf("%s", cadeia);
    
    if (aceitar_cadeia(cadeia));
		
    else {
        printf("Cadeia rejeitada.\n");
    }
    
    system("pause");
    return 0;
}


Estado transicao(Estado estado_atual, Simbolo simbolo) {
    switch (estado_atual) {
        case S1:
            switch (simbolo) {
                case SIMBOLO_0: return S2;
                case SIMBOLO_1: return S3;
                case SIMBOLO_2: return S1;
            }
        case S2:
            switch (simbolo) {
                case SIMBOLO_0: return S1;
                case SIMBOLO_1: return S2;
                case SIMBOLO_2: return S3;
            }
        case S3:
            switch (simbolo) {
                case SIMBOLO_0: return S1;
                case SIMBOLO_1: return S3;
                case SIMBOLO_2: return S2;
            }
    }
    return S1;
}

// Função para verificar se uma cadeia é aceita
bool aceitar_cadeia(const char *cadeia) {
    Estado estado_atual = S1;
    
    for (int i = 0; cadeia[i] != '\0'; i++) {
        Simbolo simbolo;
        switch (cadeia[i]) {
            case '0': simbolo = SIMBOLO_0; break;
            case '1': simbolo = SIMBOLO_1; break;
            case '2': simbolo = SIMBOLO_2; break;
            default: return false; // Caso receba um número diferente de 0, 1 ou 2
        }
        
        estado_atual = transicao(estado_atual, simbolo);
    }
    printf("Cadeia Aceita - Estado Final: S%i", estado_atual+1);
    
    return true;
}
