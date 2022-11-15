#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//#栈 #链表 #队列
typedef struct queue{
	int val;
	struct queue *next;
	struct queue *head;
	struct queue *tail;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue *que;
	que=malloc(sizeof(MyQueue));
	que->next=NULL;
	que->head=NULL;
	que->tail=que;
	que->val=0;
	return que;
}


bool myQueueEmpty(MyQueue* obj) {
	if (obj->head==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

/**
 * @brief 移动到尾部
 * 
 * @param obj 
 * @param x 
 */
void myQueuePush(MyQueue* obj, int x) {
	MyQueue*  que=myQueueCreate(),*cur;

	que->val=x;
	if (myQueueEmpty(obj))
	{
		obj->head=que;
		obj->next=que;
		que->head=que;
		obj->tail=myQueueCreate();
		obj->tail->next=que;
	}
	else
	{
		que->head=obj->head;
		obj->tail->next=que;
	}
	obj->tail=que;

}

int myQueuePop(MyQueue* obj) {
	int val=obj->head->val;
	obj->head=obj->head->next;
	return val;
}

int myQueuePeek(MyQueue* obj) {
	return obj->head->val;
}


void myQueueFree(MyQueue* obj) {
	MyQueue *head=obj;
	while (obj!=NULL)
	{
		obj=obj->next;
		free(head);
		head=obj;
	}
}


int main()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	int x = myQueuePeek(obj);
	int y = myQueuePop(obj);
	bool z = myQueueEmpty(obj);
	myQueueFree(obj);
	printf("%d,%d,%d",x,y,z);
}
