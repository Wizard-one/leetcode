#include <stdio.h>
#include <stdlib.h>
#include <test.h>

typedef struct MyLinkedList{
	int val;
	struct MyLinkedList *next;
} MyLinkedList;

// #哑节点
/* 
使用哑节点维护开头简单很多,但是还是很考验编程的完备性

链表非常重要的检测是当前节点是否为空
 */

/* 创建初始哑节点 */
MyLinkedList* myLinkedListCreate() {
	MyLinkedList *head=malloc(sizeof(MyLinkedList));
	head->next=NULL;
	return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
	MyLinkedList* cur=obj->next;
	for (size_t i = 0; i <index; i++)
	{
		if (!cur)//移动超出边界
		{
			return -1;
		}
		cur=cur->next;
	}
	//需要再次检测因为line26 cur值本身变了真实返回会使用，不然会发生段错误
	if (!cur)
	{
		return -1;
	}
	return cur->val;
}

/* 有哑节点在头上添加 */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	MyLinkedList *newhead=malloc(sizeof(MyLinkedList));
	newhead->val=val;
	newhead->next=obj->next;
	obj->next=newhead;
}


void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	MyLinkedList *cur=obj->next;
	if (!cur)//单独处理列表为空的情况
	{
		obj->next=malloc(sizeof(MyLinkedList));
		obj->next->val=val;
		obj->next->next=NULL;
		return;
	}
	while (cur->next)
	{
		cur=cur->next;
	}
	cur->next=malloc(sizeof(MyLinkedList));
	cur->next->val=val;
	cur->next->next=NULL;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	if (index<=0)
	{
		myLinkedListAddAtHead(obj,val);
	}
	else
	{
		MyLinkedList *cur=obj->next;
		for (size_t i = 0; i < index-1; i++)
		{
			if (!cur)
			{
				return;
			}
			cur=cur->next;
		}
		if(!cur)//需要再次检测，理由和myLinkedListGet类似
			return;
		MyLinkedList *t;
		t=cur->next;
		cur->next=malloc(sizeof(MyLinkedList));
		cur->next->val=val;		
		cur->next->next=t;
	}
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	if (index<0)
	{
		return;
	}
	else if (index==0)
	{
		obj->next=obj->next->next;
	}
	else
	{
		MyLinkedList *cur=obj->next;
		for (size_t i = 0; i < index-1; i++)
		{
			if (!cur)
			{
				return;
			}
			cur=cur->next;
		}
		MyLinkedList *t;
		if (cur&&cur->next)
		{
			t=cur->next;
			cur->next=cur->next->next;
			free(t);
		}
	}
}

void myLinkedListFree(MyLinkedList* obj) {
	MyLinkedList *cur;
	while (obj)
	{
		cur=obj;
		obj=obj->next;
		free(cur);
	}
}

int main(){
	int ans;
	MyLinkedList* obj = myLinkedListCreate();
	myLinkedListAddAtHead(obj, 7);
	myLinkedListAddAtHead(obj, 2);
	myLinkedListAddAtHead(obj, 1);
	ListPrint(obj); 
	myLinkedListAddAtIndex(obj, 3, 0);
	ListPrint(obj); 
	myLinkedListDeleteAtIndex(obj, 2);
	ListPrint(obj);
	myLinkedListAddAtHead(obj, 6);
	myLinkedListAddAtTail(obj, 4);
	ListPrint(obj);
	ans=myLinkedListGet(obj,4);
	printf("%d\n",ans);
	ans=myLinkedListGet(obj,0);
	printf("%d\n",ans);
	myLinkedListFree(obj);
}
