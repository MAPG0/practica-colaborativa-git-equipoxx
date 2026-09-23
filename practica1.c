#include <stdio.h>

int clasificarEvento(char evento) ;
void actualizarMatriz(int *fila, int columna);
int detectarAtaque(int intentosFallidos);
void mostrarResultados(int matriz[4][4], int equipos[], char eventos[], int totalEventos);


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
    
    //implementacion mia Quiet, evita que se intente acceder a una columna que no existe
    if (columna != -1) {
            actualizarMatriz(matriz[equipos[i]], columna);
    }
    
}


mostrarResultados(matriz, equipos, eventos, totalEventos);


	// imprime el log de los eventos como lo pide la practica, veremos que se trabaja con los dos arreglos , fusionados desde el mismo indice.
	for (int i = 0; i < totalEventos; i++) {
        printf("Evento %d: PC-0%d - %c\n",
               i + 1,
               equipos[i] + 1,eventos[i]);
               
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
	return -1; //solo si el evento no es reconocido como tal
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
void mostrarResultados(int matriz[4][4], int equipos[], char eventos[], int totalEventos) {

    int intentosFallidos;
    int resultadoAtaque;

    printf("\nResultados:\n");

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


    printf("\nMatriz de resultados:\n");
    printf("        a b c d\n");

    for (int i = 0; i < 4; i++) {

        printf("PC-0%d: ", i + 1);

        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }


    printf("\nLog de eventos:\n");

    for (int i = 0; i < totalEventos; i++) {

        printf("Evento %d: PC-0%d - %c\n",
               i + 1,
               equipos[i] + 1,
               eventos[i]);
    }
}


