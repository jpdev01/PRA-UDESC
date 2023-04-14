#include <stdio.h>
#include <string.h>

void main() {
    char string1[100];
    char string2[100];

    printf("Informe a primeira String: ");
    scanf("%s", string1);

    printf("Informe a segunda String: ");
    scanf("%s", string2);

    int string1Size = strlen(string1);
    int string2Size = strlen(string2);

    int matriz[string1Size][string2Size];

    for (int index = 0; index < string1Size; index++) {
        matriz[index][0] = index;
    }
    for (int index = 0; index < string2Size; index++) {
        matriz[0][index] = index;
    }

    for (int string1IteratorIndex = 1; string1IteratorIndex < string1Size; string1IteratorIndex++) {
        for (int string2IteratorIndex = 0; string2IteratorIndex < string2Size; string2IteratorIndex++) {
            int custo = 0;

            if (string1[string1IteratorIndex] != string2[string2IteratorIndex]) {
                custo = 1;
            }

            int valor1 = matriz[string1IteratorIndex - 1][string2IteratorIndex] + 1;
            int valor2 = matriz[string1IteratorIndex][string2IteratorIndex - 1] + 1;
            int valor3 = matriz[string1IteratorIndex - 1][string2IteratorIndex - 1] + custo;

            int smallerValue = valor1;
            if (valor2 < smallerValue) {
                smallerValue = valor2;
            }
            if (valor3 < smallerValue) {
                smallerValue = valor3;
            }

            matriz[string1IteratorIndex][string2IteratorIndex] = smallerValue;
        }
    }

    int operationsCount = matriz[string1Size - 1][string2Size - 1];
    printf("Quantidade de operações necessárias: %d", operationsCount);
}