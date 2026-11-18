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

int main() {
	int n;
	
	printf("Cantidad de maquinas: ");
	scanf("%d", &n);
	
	Maquina *maquinas = malloc(n * sizeof(Maquina));
	
	if (maquinas == NULL) {
		return 1;
	}
	
	cargarMaquinas(maquinas, n);
	
	free(maquinas);
	return 0;
}
