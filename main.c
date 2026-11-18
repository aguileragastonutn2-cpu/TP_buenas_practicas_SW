
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

void cargarMaquina(Maquina *m) {
	printf("\nNombre de la maquina: ");
	scanf(" %49[^\n]", m->nombreMaquina);
	
	printf("Tension: ");
	scanf("%f", &m->tension);
	
	printf("Corriente: ");
	scanf("%f", &m->corriente);
}

void mostrarMaximos(Maquina *m, int n) {
	int opcion, primero = -1, segundo = -1;
	
	printf("\n1. Tension\n2. Corriente\n");
	scanf("%d", &opcion);
	
	if (opcion != 1 && opcion != 2) return;
	
	for (int i = 0; i < n; i++) {
		float valor = opcion == 1 ? m[i].tension : m[i].corriente;
		
		if (primero == -1 || valor > (opcion == 1 ? m[primero].tension : m[primero].corriente)) {
			segundo = primero;
			primero = i;
		} else if (segundo == -1 || valor > (opcion == 1 ? m[segundo].tension : m[segundo].corriente)) {
			segundo = i;
		}
	}
	
	printf("Mayor: %.2f - %s\n",
		   opcion == 1 ? m[primero].tension : m[primero].corriente,
		   m[primero].nombreMaquina);
	
	if (segundo != -1) {
		printf("Segundo mayor: %.2f - %s\n",
			   opcion == 1 ? m[segundo].tension : m[segundo].corriente,
			   m[segundo].nombreMaquina);
	}
}

void buscarCaracter(Maquina *m, int n) {
	char letra;
	
	printf("Caracter a buscar: ");
	scanf(" %c", &letra);
	
	for (int i = 0; i < n; i++) {
		if (strchr(m[i].nombreMaquina, letra) != NULL)
			printf("%s contiene %c\n", m[i].nombreMaquina, letra);
	}
}

int main() {
	int n, opcion;
	Maquina *maquinas;
	
	printf("Cantidad inicial de maquinas: ");
	scanf("%d", &n);
	
	if (n <= 0) return 1;
	
	maquinas = malloc(n * sizeof(Maquina));
	
	if (maquinas == NULL) return 1;
	
	cargarMaquinas(maquinas, n);
	
	do {
		printf("\n1. Agregar maquina\n2. Mostrar maximos\n3. Buscar caracter\n4. Salir\n");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1: {
			Maquina *aux = realloc(maquinas, (n + 1) * sizeof(Maquina));
			
			if (aux != NULL) {
				maquinas = aux;
				cargarMaquina(&maquinas[n]);
				n++;
			}
			break;
		}
		case 2:
			mostrarMaximos(maquinas, n);
			break;
		case 3:
			buscarCaracter(maquinas, n);
			break;
		}
		
	} while (opcion != 4);
	
	free(maquinas);
	return 0;
}
