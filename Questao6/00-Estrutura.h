/*	Data Structures for heap ADT	   Created by:	   Date:*/#include <stdbool.h>typedef struct{   void** heapAry;   int    last;   int    size;   int    (*compare) (void* argu1, void* argu2);   int    maxSize;} HEAP;//	Prototype Definitions HEAP* heapCreate (int maxSize,            int (*compare) (void* arg1, void* arg2));bool  heapInsert  (HEAP* heap, void*  dataPtr);bool  heapDelete  (HEAP* heap, void** dataOutPtr);int   heapCount   (HEAP* heap);bool  heapFull    (HEAP* heap);bool  heapEmpty   (HEAP* heap);void  heapDestroy (HEAP* heap);static void _reheapUp   (HEAP* heap, int childLoc);static void _reheapDown (HEAP* heap, int root);