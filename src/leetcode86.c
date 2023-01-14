#include <test.h>
/*
86. 分隔链表

 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。

 */
void HeapAdjust(int * nums,int start, int end)
{
	int parent=start;//初始节点作为父节点
	// 数组起始点为0
	int child=start*2+1;// 左孩子是 2*s+1 //右孩子是2*s+2
	// 根据完全二叉树的性质，遍历调整左右两个孩子
	// 终止条件为到达叶子节点，或者满足大顶堆条件
	while (child<=end)
	{
		if (child<end&&nums[child]<nums[child+1])//从左右孩子中挑选一个大的
		{
			++child;
		}
		if (nums[parent]>=nums[child])//需要调整节点s 大于最大的child 满足大顶堆要求，break
		{
			return;
		}
		else
		{
			// 不然就是将父节点调整为最大的孩子
			swapint(&nums[parent],&nums[child]);
			//继续向下搜索
			parent=child;
			child=2*child+1;
		}
	}
}
// #双指针 #链表 #合并
/* 拆成两个链表处理，然后合并两个链表 */
struct ListNode* partition(struct ListNode* head, int x){
	// if(!head)
	// 	return NULL;
	struct ListNode* high,*low,*temp;
	high=malloc(sizeof(struct ListNode));//大于等于 x 一个链表
	low=malloc(sizeof(struct ListNode));//小于 x 一个链表
	high->next=NULL;
	low->next=NULL;
	struct ListNode* ph=high,*pl=low;
	while (head)
	{
		if (head->val>=x)
		{
			ph->next=head;
			ph=ph->next;
		}
		else
		{
			pl->next=head;
			pl=pl->next;
		}
		/* 断开原有链表next 的链接 */
		temp=head->next;
		head->next=NULL;
		head=temp;
	}
	// 链接low 与 high 链表
	pl->next=high->next;
	return low->next;
}


int main(int argc, char const *argv[])
{
	int l[]={1};
	struct ListNode *head=ListInit(l,1);
	head=partition(NULL,1);
	ListPrint(head);
	return 0;
}
