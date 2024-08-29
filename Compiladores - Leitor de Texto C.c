#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>



// Definição da estrutura para armazenar as palavras/tokens
typedef struct tokens {
    char token[256];
    struct tokens* next;
} tokens;

// Função para criar um novo nó de palavra
tokens* criartoken(const char* token) {
    tokens* novo = (tokens*)malloc(sizeof(tokens));
    if (novo == NULL) {
        perror("Memória insuficiente.");
        exit(EXIT_FAILURE);
    }
    strncpy(novo->token, token, sizeof(novo->token));
    novo->token[sizeof(novo->token) - 1] = '\0';
    novo->next = NULL;
    return novo;
}

// Função para adicionar um nó de palavra à lista
void appendtoken(tokens** head, const char* token) {
    tokens* novo = criartoken(token);
    if (*head == NULL) {
        *head = novo;
    } else {
        tokens* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novo;
    }
}

// Função para imprimir a lista de palavras
void printtokens(tokens* head) {
	setlocale(LC_ALL, "pt_BR.UTF-8");
    tokens* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->token);
        temp = temp->next;
    }
}

// Função para liberar a memória da lista de palavras
void freetokens(tokens* head) {
    tokens* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE *file;
    char filename[] = "Teste Compiladores.txt";
    char c;
    char token[256];
    int index = 0;
    tokens* tokenList = NULL;
	setlocale(LC_ALL, "pt_BR.UTF-8");
    // Abrir o arquivo
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Falha ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Ler o arquivo caractere por caractere
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c) || c == '.' || c == ',') {
            if (index > 0) {
                token[index] = '\0';
                appendtoken(&tokenList, token);
                index = 0;
            }
            if (c == '.' || c == ',') {
                token[index++] = c;
                token[index] = '\0';
                appendtoken(&tokenList, token);
                index = 0;
            }
        } else {
            token[index++] = c;
        }
    }
    if (index > 0) {
        token[index] = '\0';
        appendtoken(&tokenList, token);
    }

    fclose(file);

    // Imprimir o texto
    printtokens(tokenList);

    // Liberar memória
    freetokens(tokenList);

    return 0;

}
