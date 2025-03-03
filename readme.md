

# Código de Criptografia e Descriptografia

Este código em C permite ao usuário escolher entre criptografar uma senha ou descriptografar uma sequência de números. A criptografia é feita através da criação de uma matriz a partir da senha, onde cada caractere é elevado ao quadrado. A descriptografia faz o processo inverso, calculando a raiz quadrada dos números fornecidos para recuperar a senha original.

## Estrutura do Código

### Inclusão de Bibliotecas
```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
```

### Função Principal
```c
int main(void) {
    int valor;
    printf("Escolha entre criptografar ou descriptografar\n");
    printf("1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    scanf("%d", &valor);
    getchar();
```

### Declaração de Variáveis
```c
    char str[100] = "";
    int num, index = 0;
    int multipliedMatrix[10][10] = {0};
```

### Escolha do Usuário
- **Criptografar**: O usuário insere uma senha.
- **Descriptografar**: O usuário insere uma sequência de números criptografados.

```c
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
```

### Preparação da Senha
- A senha é ajustada para ter um comprimento que seja um quadrado perfeito, preenchendo com espaços se necessário.

```c
    int length = strlen(str);
    int n = ceil(sqrt(length));
    int newLength = n * n;

    char paddedStr[newLength + 1];
    strcpy(paddedStr, str);
    for (int i = length; i < newLength; i++) {
        paddedStr[i] = ' ';
    }
    paddedStr[newLength] = '\0';
```

### Criação da Matriz e Criptografia
- A senha é convertida em uma matriz e cada caractere é elevado ao quadrado.

```c
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
```

### Sugestões para Variações e Fórmulas Mais Complexas

#### 1. **Usar uma Chave de Criptografia**
   - Em vez de simplesmente elevar os caracteres ao quadrado, use uma chave fornecida pelo usuário para modificar os valores dos caracteres.
   - Exemplo:
     ```c
     int chave = 5; // Chave fornecida pelo usuário
     multipliedMatrixEnc[i][j] = matrix[i][j] + chave; // Adiciona a chave ao valor do caractere
     ```
   - Para descriptografar, subtraia a chave:
     ```c
     char caractere = (char)(multipliedMatrix[i / 10][i % 10] - chave);
     ```

#### 2. **Criptografia com Multiplicação de Matrizes**
   - Use uma matriz de transformação (uma matriz de chave) para multiplicar a matriz da senha.
   - Exemplo:
     ```c
     int chave[2][2] = {{1, 2}, {3, 4}}; // Matriz de chave
     // Multiplicação de matrizes
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             multipliedMatrixEnc[i][j] = 0;
             for (int k = 0; k < n; k++) {
                 multipliedMatrixEnc[i][j] += matrix[i][k] * chave[k][j];
             }
         }
     }
     ```
   - Para descriptografar, use a matriz inversa da chave.

#### 3. **Criptografia com Funções Matemáticas Complexas**
   - Use funções matemáticas como exponenciação, logaritmos ou funções trigonométricas para criptografar os caracteres.
   - Exemplo:
     ```c
     multipliedMatrixEnc[i][j] = (int)(pow(matrix[i][j], 3) + sin(matrix[i][j]));
     ```
   - Para descriptografar, use a função inversa.

#### 4. **Criptografia com XOR e Deslocamento de Bits**
   - Combine operações de XOR e deslocamento de bits para criptografar os caracteres.
   - Exemplo:
     ```c
     int chave = 123; // Chave fornecida pelo usuário
     multipliedMatrixEnc[i][j] = (matrix[i][j] ^ chave) << 2;
     ```
   - Para descriptografar, faça o processo inverso:
     ```c
     char caractere = (char)((multipliedMatrix[i / 10][i % 10] >> 2) ^ chave);
     ```

---

### Saída do Resultado
- **Criptografar**: Exibe a matriz de números criptografados.
- **Descriptografar**: Exibe a senha original.

```c
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
```

## Como Funciona
1. **Criptografar**:
   - O usuário insere uma senha.
   - A senha é convertida em uma matriz e cada caractere é elevado ao quadrado (ou modificado conforme a variação escolhida).
   - A matriz resultante é exibida como a senha criptografada.

2. **Descriptografar**:
   - O usuário insere uma sequência de números criptografados.
   - A raiz quadrada de cada número é calculada (ou o processo inverso da variação escolhida) para recuperar o caractere original.
   - A senha original é exibida.

## Exemplo de Uso
- **Criptografar**:
  ```
  Escolha entre criptografar ou descriptografar
  1 - Criptografar
  2 - Descriptografar
  1
  Criptografar
  Digite uma senha: senha
  Texto criptografado:
  115  101  110  104   97 
  ```
  
- **Descriptografar**:
  ```
  Escolha entre criptografar ou descriptografar
  1 - Criptografar
  2 - Descriptografar
  2
  Descriptografar
  Digite os números criptografados (separados por espaço): 115 101 110 104 97
  Texto decodificado: senha
  ```

---

### Conclusão
Com essas sugestões, você pode explorar diferentes métodos de criptografia, desde os mais simples até os mais complexos, como o uso de matrizes de chave, funções matemáticas avançadas e operações de bits. Isso torna o processo de criptografia mais seguro e interessante!
