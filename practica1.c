#include <stdio.h>

int clasificarEvento(char evento) ;
void actualizarMatriz(int *fila, int columna);
int detectarAtaque(int intentosFallidos);


int main() {

    int equipos[100] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3
    };

    char eventos[100] = {
        'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b',
        'a', 'b', 'b', 'b', 'b', 'b', 'b', 'c', 'c', 'd',
        'a', 'a', 'a', 'a', 'a', 'c',
        'b', 'b', 'c', 'c', 'c', 'c', 'c', 'd'
    };

    int totalEventos = 33;

    int matriz[4][4] = {0};

    int columna;
    int intentosFallidos;
    int resultadoAtaque;

for (int i = 0; i < totalEventos; i++) {

    columna = clasificarEvento(eventos[i]);
    actualizarMatriz(matriz[equipos[i]], columna);
}



for (int i = 0; i < 4; i++) {

    intentosFallidos = matriz[i][1] + matriz[i][2];

    resultadoAtaque = detectarAtaque(intentosFallidos);

    printf("PC-0%d: %d intentos fallidos - ", i + 1, intentosFallidos);

    if (resultadoAtaque == 1) {
        printf("Posible ataque\n");
    } else {
        printf("Normal\n");
    }
}



printf("Matriz de resultados:\n");

for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}

    return 0;

}





int clasificarEvento(char evento) {

        if (evento == 'a') {
    return 0;
}


	if (evento == 'b') {
    return 1;
}

	if (evento == 'c') {
    return 2;
}

	if (evento == 'd') {
    return 3;
}

}


void actualizarMatriz(int *fila, int columna) {
    (*(fila + columna))++;
}



int detectarAtaque(int intentosFallidos) {

    if (intentosFallidos > 3) {
        return 1;
    }

    return 0;
}


