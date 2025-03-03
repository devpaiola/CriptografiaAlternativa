#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int valor;
    printf("Escolha entre criptografar ou descriptografar\n");
    printf("1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    scanf("%d", &valor);
    getchar();

    char str[100] = "";
    int num, index = 0;
    int multipliedMatrix[10][10] = {0};

    if (valor == 1) {
        printf("Criptografar\n");
        printf("Digite uma senha: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
    } else if (valor == 2) {
        printf("Descriptografar\n");
        printf("Digite os números criptografados (separados por espaço): ");
        
        char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);
        
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            multipliedMatrix[index / 10][index % 10] = atoi(token);
            index++;
            token = strtok(NULL, " ");
        }
    } else {
        printf("Valor invalido!\n");
        return 1;
    }

    int length = strlen(str);
    int n = ceil(sqrt(length));
    int newLength = n * n;

    char paddedStr[newLength + 1];
    strcpy(paddedStr, str);
    for (int i = length; i < newLength; i++) {
        paddedStr[i] = ' ';
    }
    paddedStr[newLength] = '\0';

    int matrix[n][n];
    int multipliedMatrixEnc[n][n];
    int indexEnc = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (int)paddedStr[indexEnc];
            multipliedMatrixEnc[i][j] = matrix[i][j] * matrix[i][j];
            indexEnc++;
        }
    }

    if (valor == 1) {
        printf("Texto criptografado:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d ", multipliedMatrixEnc[i][j]);
            }
            printf("\n");
        }
    } else if (valor == 2) {
        printf("Texto decodificado: ");
        for (int i = 0; i < index; i++) {
            char caractere = (char) sqrt(multipliedMatrix[i / 10][i % 10]);
            printf("%c", caractere);
        }
        printf("\n");
    }

    return 0;
}
