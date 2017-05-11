/*	This program tests the heap functions used in the 
	text. It uses random numbers to build a heap. 
	It then presents a menu that allows the user to 
	insert to, delete from, and print the heap. The maximum
	heap size is 1023.
	   Written by: 
	   Date: 
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "09-heap.h"
const int maxSize = 11;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
char getAction  (void);
void printHeap (HEAP* heap, int idx, int recuo);

#define strMax 40

typedef struct
{
	short sequence;
	char year[strMax];
	char mileage[strMax];
	char name[strMax];
	int* prioridade;
} TABELA;




// A = Número total de milhas
// B = Número de anos no programa de passageiro frequente
// C = Número de ordem que representa a posição de chegada do cliente quando reservou o voo.
//	prioridade = A/1000 + B - C

int main (void)
{
//	Local Definitions 
	HEAP* heap;
	FILE* fpData;
	TABELA* pTabela, *dataPtr2;
	int*  dataPtr;
	int resultado;
	int vetor[11];

	short sequence;

	bool result;
	char action;
	int white_walker;
	int prioridade;
	int year;
	int mileage;
	

	//char s[] = "45";

//int num = atoi(s);
//printf("%d\n",num );

	heap = heapCreate(maxSize,compare);
	if (!heap)
	{
		printf("Que não vai dar o que?\n");
	}


	fpData = fopen("tabela.dat", "r");
	if (!fpData){
	    printf("\aErro na abertura do arquivo\n");
	    exit (100);
	}

	while (fscanf(fpData, " %hd", &sequence) == 1){
		int i = 0;

		pTabela = (TABELA*) malloc(sizeof(TABELA));
		dataPtr2 = (TABELA*) malloc(sizeof(TABELA));

		if (!(pTabela)){
			printf("\aSem memória para fazer construir a lista\n");
			exit (100);
		}

		pTabela->sequence = sequence;
		printf("-------------------------\n");
		printf("Sequence: %hd \n",pTabela->sequence);

		// Skip tabs and quote 
		
		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');

		//fscanf(fpData, " %40[^\"], %*c", pTabela->picture);
		fscanf(fpData, " %40[^\"], %*c", pTabela->year);
		year = atoi(pTabela->year);
		printf("Year: %d \n",year);

		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');

		//fscanf(fpData, " %40[^\"], %*c", pTabela->director);
		fscanf(fpData, " %40[^\"], %*c", pTabela->mileage);
		mileage = atoi(pTabela->mileage);
		printf("Mileage: %d \n",mileage);
		//printf("------------------------------\n");
		//scanf("%c",&c);  

		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');

		fscanf(fpData, " %40[^\"], %*c", pTabela->name);
		printf("Name: %s \n",pTabela->name);
		

		prioridade = mileage/1000 + year - sequence;

		//vetor[i] = prioridade;

		//dataPtr2->prioridade = prioridade;
		 pTabela->prioridade = (int*)malloc(sizeof(int));
		 *pTabela->prioridade = prioridade;

		printf("Prioridade: %d \n",prioridade);

		printf("------------------------------\n");

		// Insert into heap 
		
		resultado = heapInsert(heap,pTabela->prioridade);
		if (!resultado)
		{
			printf("Deu ruim\n");
		}
		else
		{
			printf("Deu bom\n");
		}

		while (fgetc(fpData) == '\n');
		i++;

	} // while 

	
	printHeap(heap,0,0);

	int resultadao;


	for (int i = 0; i < 11; i++)
	{
		//dataPtr = (int*)malloc(sizeof(int*));
		if (!dataPtr)
		{
			printf("Thiago caiu\n");
		}
		resultadao = heapDelete(heap,(void*)&dataPtr);
		vetor[i] = *dataPtr;
	}
		
	

	for (int i = 0; i < 11; i++)
	{
		printf("|%d|",vetor[i]);
	} 




	

	return 0;
}	// main 




int compare (void* arg1, void* arg2)
{
//	Local Declarations 
	int arguOne;
	int arguTwo;
	
//	Statements 
	arguOne = *(int*)arg1;
	arguTwo = *(int*)arg2;

	if (arguOne < arguTwo)
	    return -1;
	else if (arguOne == arguTwo)
	    return  0;
	else
	    return +1;
}	// compare 


void printHeap (HEAP* heap, int idx, int recuo)
{ int i;
  for (i=0; i < heap->size; i++){
      printf("%d\n",*(int*)(heap->heapAry[i]));
  }
   /*if (idx<heap->size)
  {  printHeap (heap, idx*2+1, recuo+4);
     printf("%d\n",*((int*)(heap->heapAry[idx])));
     printHeap (heap, idx*2+2, recuo+4);
  } */
  return;
}

/*	Results: (After heap automatically generated)

Begin Heap Test
array size is 15
End of heap creation

          34
     633
         124
 855
          83
     764
         533

Please enter action <P, I, D, U, Q>: u
Number of elements in heap:   7
Head is NOT full
Head is NOT emtpy

Please enter action <P, I, D, U, Q>: */
