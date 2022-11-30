#include <test.h>
#include <stdlib.h>
#include <stdio.h>


// #双指针 #链表
/* 
寻找链表相交位置

核心在于让每个指针经过路径长度相同，那就pa将A 遍历完成之后转向B pb 将b 遍历完成后转向A 这样两者经过的路径必然等长。

也就是说pa, pb同时到达链表终点，那向后回溯他们也同时到达相交位置。
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *pa=headA,*pb=headB;
	while (pa!=pb)//两者直指向同一个地址即可返回
	{
		if (!pa)
		{
			pa=headB;
		}
		else
			pa=pa->next;
		if (!pb)
		{
			pb=headA;
		}
		else
			pb=pb->next;
	}
	return pa;
	
}

int main(){
	struct ListNode *ha,*hb;
	int l[1]={3},lb[1]={2};
	ha=ListInit(l,1);
	hb=ListInit(lb,1);
	hb->next=ha;
	getIntersectionNode(ha,hb);
}