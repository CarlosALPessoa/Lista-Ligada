#include <stdio.h>
#define Max 50
#define Inutil -1

typedef int Ch;

typedef struct{
	Ch chave;
}Entrada;

typedef struct{
	Entrada valor;
	int praprox;
}Armazem;

typedef struct{
	Armazem A[Max];
	int inicie;
	int dispo; 
}List;

void mylist(List* ListaDeValores)
{
	int comecepor = ListaDeValores->inicie;
	printf("Lista: \"");
	
	while(comecepor != Inutil)
	{
		printf("%d", ListaDeValores->A[comecepor].valor);
		
		comecepor = ListaDeValores->A[comecepor].praprox;
		
		if(comecepor == Inutil)
		{
			printf("\"\n");
		}
		else
		{
			printf(" ");
		}
	}
	return;
}

int auxFun(List* posicaoValor)
{
	//quero saber se n aponto para o final
	int posicao = posicaoValor->dispo;
	
	//Ex.:Programa, quero a posicao proxima se nao apontar para o final
	if(posicao != Inutil)
	{
		//Se for vdd, quero q vc me passe ela pra salvar e poder, se eu quiser,
		//add outros elementos
		posicaoValor->dispo = posicaoValor->A[posicao].praprox;
	}
	
	return posicao;
}

void InsiraValor(List* listagemValue, Armazem* valores)
{
	if(listagemValue->dispo == Inutil) return; //Se n tem disponivel n precisa continuar
	
	int anterior = Inutil;
	int Atual = listagemValue->inicie;//Para n ler a lista toda novamente(Poupar tempo)
	Ch chv = valores->valor.chave;//Elemento atual
	
	/*While serve para ajustar os ponteiros
		saber se o atual possui anterior, e se possuir, quero q ele aponte para ele
		Afirmar q o valor atual tem anteriores*/
	while(chv > listagemValue->A[Atual].valor.chave && Atual != Inutil)
	{
		anterior = Atual;//q valia -1, agora vale 0, por exemplo
		Atual = listagemValue->A[Atual].praprox; //atual valia 0, agora vale 1
	}
	
	//Se o valor n foi encontrado antes, algo está errado,
	//nao quero encaixar ele na lista
	if(chv == listagemValue->A[Atual].valor.chave && Atual != Inutil) return;
	
	//Agora, se nd foi resultado em verdade, quero saber onde encaixar meu valorparametro
	Atual = auxFun(listagemValue);
	listagemValue->A[Atual].valor.chave = chv;
	
	/*
		Nao quero q meu 1º elemento seja o final da lista,
		Caso haja outro elemento menor q o 1º colocado
		q seu substituto aponte.
		
		Outra, n quero ler a minha lista toda do inicio, portanto, q comece o prox
		elemento a ser inserido.
	*/
	if(anterior == Inutil)
	{
		listagemValue->A[Atual].praprox = listagemValue->inicie;
		//Diz q o primeiro elemento aponta para o último, sendo ele o unico
		listagemValue->inicie = Atual; 
		//Ex.: Antes era -1 agora começa a verificar da posicao 0, bom para exibir lista
	}
	else
	/*Tbm para reajustar o ponteiro, diz q o ultimo elemento
		inserido aponta agora para o final da lista
		e o anterior a ele aponta para ele*/
	{
		listagemValue->A[Atual].praprox = listagemValue->A[anterior].praprox; //aponta para o final
		listagemValue->A[anterior].praprox = Atual;//o elemento anterior aponta para o atual
	}
	
	return;
}

int CEs(List* ContElementos)
{
	int EspBranco = ContElementos->inicie;
	int tam = 0;
	
	while(EspBranco != Inutil)
	{
		tam++;
		EspBranco = ContElementos->A[EspBranco].praprox;
		//Passa o ponteiro do proximo elemento.
	}
	return tam;
}

void iniciar(List* listagem)
{
	int contador;
	printf("Proximos elementos:\n");
	for(contador = 0; contador < Max - 1; contador++)
	{
		listagem->A[contador].praprox = contador + 1;
		printf("%d ", listagem->A[contador].praprox);
	}
	printf("\n");
	listagem->A[Max - 1].praprox = Inutil; //ultimo é invalido
	listagem->inicie = Inutil; //nao há valores
	listagem->dispo = 0; //local disponivel é A[0]
	return;
}

