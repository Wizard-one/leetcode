#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//#栈 #链表 #队列
/* 232用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false

说明：

    你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

 */
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
