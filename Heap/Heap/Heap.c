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


void AdjustDwon(HPDataType*a,int child)
{
	int parent = (child - 1) / 2;
	while (0 < child)
	{
		if (a[child] < a[parent])
		{
			HPDataType* tem = a[child];
			a[child] = a[parent];
			a[parent] = tem;
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
	AdjustDwon(php->a, php->size - 1);
}