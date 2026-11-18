#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float tension;
	float corriente;
	char nombreMaquina[50];
} Maquina;

void cargarMaquinas(Maquina *m, int n) {
	for (int i = 0; i < n; i++) {
		printf("\nNombre de la maquina: ");
		scanf(" %49[^\n]", m[i].nombreMaquina);
		
		printf("Tension: ");
		scanf("%f", &m[i].tension);
		
		printf("Corriente: ");
		scanf("%f", &m[i].corriente);
	}
}

void mostrarMaximos(Maquina *m, int n) {
	int opcion, primero = -1, segundo = -1;
	
	printf("\nBuscar maximos de:\n1. Tension\n2. Corriente\n");
	scanf("%d", &opcion);
	
	if (opcion != 1 && opcion != 2) {
		printf("Opcion invalida\n");
		return;
	}
	
	for (int i = 0; i < n; i++) {
		float valor = (opcion == 1) ? m[i].tension : m[i].corriente;
		
		if (primero == -1 || valor > (opcion == 1 ? m[primero].tension : m[primero].corriente)) {
			segundo = primero;
			primero = i;
		} else if (segundo == -1 || valor > (opcion == 1 ? m[segundo].tension : m[segundo].corriente)) {
			segundo = i;
		}
	}
	
	printf("\nMayor: %.2f - %s\n",
		   opcion == 1 ? m[primero].tension : m[primero].corriente,
		   m[primero].nombreMaquina);
	
	if (segundo != -1) {
		printf("Segundo mayor: %.2f - %s\n",
			   opcion == 1 ? m[segundo].tension : m[segundo].corriente,
			   m[segundo].nombreMaquina);
	}
}

int main() {
	int n;
	
	printf("Cantidad de maquinas: ");
	scanf("%d", &n);
	
	Maquina *maquinas = malloc(n * sizeof(Maquina));
	
	if (maquinas == NULL) {
		return 1;
	}
	
	cargarMaquinas(maquinas, n);
	mostrarMaximos(maquinas, n);
	free(maquinas);
	return 0;
}
