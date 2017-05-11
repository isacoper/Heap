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
const int maxSize = 10;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
char getAction  (void);
void printHeap (HEAP* heap, int idx, int recuo);
const int array = 10;

int main (void)
{
//	Local Definitions 
	HEAP* heap, *heap2;
	int*  dataPtr, *dataPtr2;

	bool result;
	char action, action2;
	int white_walker, white_walker2;
	
//	Statements 
	heap = heapCreate (array, compare);
	if (!heap)
	   printf("Impossível criar o heap\n"), exit (100);

	srand(time(NULL));
	
	// Fill half the heap with random numbers 
	for (white_walker = 0; white_walker <= array - 1 ; white_walker++)
	    {
	     dataPtr  = (int*)malloc(sizeof (int));
	     if (!dataPtr)
	        printf("Overflow\n"), exit (101);
	     
	     *dataPtr = rand() % 999 + 1;
	     heapInsert (heap, dataPtr);
	    } // for 
	
	printHeap (heap, 0, 0);

	// List built. Test by inserting & deleting data 
	do
	    {
	    action = getAction ();
	    switch (action)
	       {
	        case 'I': 
	           dataPtr = (int*)malloc(sizeof (int*));
	           if (!dataPtr)
	               printf("Out of memory on insert\n"), exit(200);
	           printf("Insira um número: ");
	           scanf ("%d", dataPtr);
	           result = heapInsert3 (heap, dataPtr);
	           if (result)
	               printf("%d Inserido\n", *dataPtr);
	           else
	               printf("Heap full on insert\a\n"), exit(201);
	           break; // case I 

	         case 'D': 
	            result = heapDelete (heap, (void*)&dataPtr);
	            if (result) 
	                printf("%d deleted.\n", *dataPtr);
	            else
	                  printf("Heap Empty. No delete\a\n");
	            break;  // case D 
	        case 'P': 
	            printHeap (heap, 0, 0);
	            printf("\nNúmero de trocas: %d \n",heap->contador);
	            break;
	       	case 'U':
	       	    printf("Number of elements in heap: %3d\n",
	       	            heapCount (heap));
	       	    if (heapFull(heap))
	       	        printf("Heap is FULL\n");
	       	    else
	       	        printf("Head is NOT full\n");
	       	    if (heapEmpty(heap))
	       	        printf("Heap is EMPTY\n");
	       	    else
	       	        printf("Head is NOT emtpy\n");
	       	    break;
	        case 'Q': break;
	        default : 
	            printf ("Impossible error 100.\a\a\n"); 
	           exit   (100);
	       } // switch 
	} while (action != 'Q');



 	heap2 = heapCreate(array,compare);
	if (!heap2)
	   printf("Impossível criar o heap\n"), exit (100);
	srand(time(NULL));

	for (white_walker2 = 0; white_walker2 <= array - 1; white_walker2++)
	    {
	     dataPtr2  = (int*)malloc(sizeof (int));
	     if (!dataPtr2)
	        printf("Overflow in main\n"), exit (101);
	     
	     *dataPtr2 = rand() % 999 + 1;
	     heapInsert2(heap2, dataPtr2);
	    } //

	    for (int i = array/2 - 1 ; i >= 0; i--)
	    {
	    	_reheapDown(heap2,i);
	    }

	    printHeap(heap2,0,0);

	    do
	    {
	    action2 = getAction ();
	    switch (action2)
	       {
	        case 'I': 
	           dataPtr2 = (int*)malloc(sizeof (int*));
	           if (!dataPtr2)
	               printf("Sem memória para inserção\n"), exit(200);
	           printf("Entre com um número: ");
	           scanf ("%d", dataPtr2);
	           result = heapInsert(heap2,dataPtr2);
	            
		          if (result)
	               printf("%d Inserido\n", *dataPtr2);
	           else
	               printf("Heap2 full on insert\a\n"), exit(201);
	           break; // case I 

	         case 'D': 
	            result = heapDelete (heap2, (void*)&dataPtr2);
	            if (result) 
	                printf("%d Deletado.\n", *dataPtr2);
	            else
	                  printf("Heap2 Vazio\a\n");
	            break;  // case D 
	        case 'P': 
	            printHeap (heap2, 0, 0);
	            printf("\nNúmero de trocas: %d \n",heap2->contador2);
	            // /heap2->contador2 = 0;

	            break;
	       	case 'U':
	       	    printf("Number of elements in heap2: %3d\n",
	       	            heapCount (heap2));
	       	    if (heapFull(heap2))
	       	        printf("Heap2 is FULL\n");
	       	    else
	       	        printf("Head is NOT full\n");
	       	    if (heapEmpty(heap2))
	       	        printf("Heap is EMPTY\n");
	       	    else
	       	        printf("Head is NOT emtpy\n");
	       	    break;
	        case 'Q': break;
	        default : 
	            printf ("Impossible error 100.\a\a\n"); 
	           exit   (100);
	       } // switch 
	} while (action2 != 'Q');
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
char getAction (void)
{
//	Local Definitions 
	char action;

	int  OK = 0;

//	Statements 
	do
	   {
	    printf("\nPlease enter action <P, I, D, U, Q>: ");
	    scanf (" %c", &action);
	    action = toupper(action);
	    switch (action)
	       {
	        case 'P':
	        case 'I':
	        case 'D':
	       	case 'U':
	        case 'Q': OK = 1;
	                  break;
	        default:  
	          printf("< %c > action invalid: ",action);
	          printf("Please re-enter\a\a\n" ); 
	          break;
	       } // switch 
	   } while (!OK);
	return action;
}	// getAction 

void printHeap (HEAP* heap, int idx, int recuo)
{ int i;
  for (i=0; i<heap->size; i++){
      printf("|%d| ",*(int*)(heap->heapAry[i]));
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
