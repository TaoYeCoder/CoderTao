#include"Heap.h"
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}


void HeapDestroy(HP* php)
{
	free(php->a);
}


void Swap(HPDataType* p1, HPDataType* p2)
{  
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void AdjustUp(HPDataType*a,int child)
{
	int parent = (child - 1) / 2;
	while (0 < child)
	{
		if (a[child] < a[parent])
		{
			//1.先交换
			Swap(&a[child], &a[parent]);

			//2.向上调
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tem = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tem == NULL)
		{
			perror("realloc fale");
			return;
		}
		php->a = tem;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;

	//向上调整，要把结构体的数组和数组的最后一位元素传过去当孩子
	AdjustUp(php->a, php->size - 1);
}

AdjustDown(int* a, int n, int parent)
{
	int chile = parent * 2 + 1;
	while (chile < n)
	{
		if (a[chile + 1] < a[chile])
		{
			++chile;
		}

		if (a[parent] > a[chile])
		{
			Swap(&a[parent], &a[chile]);
			parent = chile;
			chile = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	--php->size;
	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{

}

bool HeapEmpty(HP* php)
{

}

int HeapSize(HP* php)
{

}