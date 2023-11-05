#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include <stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType*a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP*  php);