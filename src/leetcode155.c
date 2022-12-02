#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 30000
// #设计 #栈 [[232]] [[705]] [[707]]

typedef struct {
	int min;
	int top;
	int stack[MAX];
} MinStack;


MinStack* minStackCreate() {
	MinStack *st;
	st=malloc(sizeof(MinStack));
	st->min=INT_MAX;
	st->top=-1;
	return st;
}

void minStackPush(MinStack* obj, int val) {
	obj->top++;
	obj->stack[obj->top]=val;
	obj->min=(obj->min>val)?(val):obj->min;
}

void minStackPop(MinStack* obj) {
	// 如果最小值在栈顶则遍历整个栈来维护最小值
	if (obj->min==obj->stack[obj->top]&&obj->top>0)
	{
		obj->min=obj->stack[obj->top-1];
		for (size_t i = 0; i < obj->top-1; i++)
		{
			obj->min=(obj->min>obj->stack[i])?(obj->stack[i]):obj->min;
		}
	}
	else if(obj->top==0)
	{
		// 还需要维护回归空栈的情况
		obj->min=INT_MAX;
	}
	obj->stack[obj->top]=0;
	obj->top--;
}

int minStackTop(MinStack* obj) {
	return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj);
}

int main(){
	// ["MinStack","push","push","push",
	MinStack *obj=minStackCreate();
	minStackPush(obj,1);
	minStackPush(obj,1);
	minStackPush(obj,2147483647);
	int ans;
	// "top","pop","getMin"
	ans=minStackTop(obj);
	printf("%d\n",ans);
	minStackPop(obj);
	ans=minStackGetMin(obj);
	printf("%d\n",ans);
	// "pop","getMin","pop"
	minStackPop(obj);
	ans=minStackGetMin(obj);
	printf("%d\n",ans);
	minStackPop(obj);
	// "push","top","getMin"
	minStackPush(obj,2);
	ans=minStackTop(obj);
	printf("%d\n",ans);
	ans=minStackGetMin(obj);
	printf("%d\n",ans);
	// "push","top","getMin"
	minStackPush(obj,-2);
	ans=minStackTop(obj);
	printf("%d\n",ans);
	ans=minStackGetMin(obj);
	printf("%d\n",ans);
	// "pop","getMin"
	minStackPop(obj);
	ans=minStackGetMin(obj);
	printf("%d\n",ans);

}