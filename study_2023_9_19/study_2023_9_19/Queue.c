#include"Queue.h"

void QueueInit(Queue* pq)//初始化 
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}



void QueueDestroy(Queue* pq)//销毁
{
	assert(pq);
	//第一个结构体
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}


void QueuePush(Queue* pq, QDataType x)//插入数据
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));//扩大的是第一个结构体
	if (newnode == NULL)
	{
		perror("malloc");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->phead == NULL)
	{

		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


void QueuePop(Queue* pq)//队头出数据就是删队头
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)//返回对头数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

QDataType QueueBack(Queue* pq)//返回队尾数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}

int QueueSize(Queue* pq)//返回总的数据个数
{
	assert(pq);

	return pq->size;
}

bool QueueEmpty(Queue* pq)//是空的返回真
{
	assert(pq);

	return pq->phead == NULL && pq->ptail == NULL;
}