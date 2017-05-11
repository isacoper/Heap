
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
#include <time.h>	   

#include "09-heap.h"
const int maxSize = 15;
const int array100 = 100;
const int array200 = 200;
const int array500 = 500;
const int array1000 = 1000;
const int array2000 = 2000; 

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
void printHeap (HEAP* heap, int idx, int recuo);

//----- Pra essa questão eu tive que criar um contador na estrutura e adicionar ele no
// _reheapUp para ver quantas trocas são efetuadas.

int main (void)
{
//	Local Definitions 
	HEAP *heap1,*heap2,*heap3,*heap4;
	int*  dataPtr;

	bool result;
	char action;
	int bldLooper;

	int ary1[array100];

	printf("----------CRIANDO HEAP 1----------\n");
	printf("Inserindo valores.....100%%\n");
	printf("Aplicando Reheap-Up....\n");

	heap1 = heapCreate(array100,compare);
	if (!heap1)
	{
		printf("Não foi possível criar o Heap\n");
		exit(100);
	}

	srand(time(NULL));

	int contador = 0;

	for (int i = 1; i <= array100; i++)
	{
		dataPtr = (int*)malloc(sizeof(int));
		if (!dataPtr)
		{
			printf("Overflow\n");
			exit(101);
		}

		*dataPtr = rand() % 999 + 1;
		heapInsert(heap1,dataPtr);
		contador++;
	}
	printf("100%%...\n");
	printf("\n-------HEAP 1 CRIADO------------\n");
	
	printHeap (heap1, 0, 0);
	printf("\n Inserções: %d\n",contador);
	printf("Número de trocas efetuadas: %d\n",heap1->contador);

	return 0;
}	// main 

/*	================== compare ================= 
	This function compares two integers identified
	by pointers to integers.
	   Pre    arguPtr and listPtr are pointers to DATA
	   Return -1: arg1 value <  arg2 
	          -0: arg1 value == arg2
	          +1: arg1 value >  arg2
*/
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

/*	================== getAction ================== 
	Get and return a valid action from keyboard.
	   Pre  nothing 
	   Post valid action read and returned 
*/

void printHeap (HEAP* heap, int idx, int recuo)
{ int i;
  for (i=0; i<heap->size; i++){
      printf("|%d|,",*(int*)(heap->heapAry[i]));
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
