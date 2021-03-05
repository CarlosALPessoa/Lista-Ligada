#include <stdio.h>
#include "Iniciador.c"

/*Estruturas utilizadas

typedef int Ch

typedef struct{
	Ch chave;
}Entrada;

typedef struct{
	Entrada valor;
	int praprox;
}Armazem;

typedef struct{
	Armazem A[Max];
	int inicie;//usado pelo CDs
	int dispo; //usado para alocacao
}List;
*/

int main()
{
	List lista;
	iniciar(&lista);
	printf("Numero de elementos da lista = %i\n", CEs(&lista));
	
	int i;
	printf("Insira 3 valores:\n");
	scanf("%d", &i);
	Armazem valor1 = {i};//Na Estrutura Armazem, consta o int valor de tipo Estrutura para chave
	scanf("%d", &i);
	Armazem valor2 = {i};
	scanf("%d", &i);
	Armazem valor3 = {i};

	
	InsiraValor(&lista, &valor1);
	InsiraValor(&lista, &valor2);
	InsiraValor(&lista, &valor3);
	
	printf("Numero de elementos da lista = %i\n", CEs(&lista));
	mylist(&lista);
	
	
	return 0;
}
