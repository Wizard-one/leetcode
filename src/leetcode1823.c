#include <test.h>
#include <stdlib.h>
#include <stdio.h>

// #链表 #递归 #模拟

struct ListNode* pop(struct ListNode *head,int k,int n)
{
	if(head->next==head)
	{
		return head;
	}
	struct ListNode *cur=head;
	for (size_t i = 0; i < k-2; i++)
	{
		// 因为自己也是属于节点所以需要-2
		// 少移动一次到上一个节点方便修改链接关系
		cur=cur->next;
	}

	cur->next=cur->next->next;
	return pop(cur->next,k,n);
}

/* 找出游戏的获胜者
让第k个人出队,用环链表模拟这个过程,当头指向自身时结束.
 */
int findTheWinner(int n, int k){
	if (k==1)
	{
		// k==1 始终删除第一个元素,所以可以发现此时返回的一定是最后一个值
		return n;
	}
	
	struct ListNode *head,*cur;
	head=malloc(sizeof(struct ListNode));
	cur=head;
	for (size_t i = 1; i <n; i++)
	{
		cur->val=i;
		cur->next=malloc(sizeof(struct ListNode));
		cur=cur->next;
	}
	cur->val=n;//最后一个单独处理用于link head
	cur->next=head;
	head=pop(head,k,n);
	return head->val;
}

int main()
{
	int ans;
	ans=findTheWinner(3,1);
	printf("%d",ans);
}