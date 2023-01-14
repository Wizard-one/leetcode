#include <test.h>
/*23. 合并K个升序链表
 给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。 */

// #优先队列 #链表 #hard #堆排序 #双指针 #哑节点
/* 一看就是一个使用优先队列来进行lists内的最小值，所以使用链表头作为排序key建一个小顶堆，
合并时实时从小顶堆的头弹出元素，当堆顶next==NULL 时 放到堆底同时调整堆大小 */
void ListHeapAdjust(struct ListNode** nums,int start, int end)
{
	int parent=start;//初始节点作为父节点
	// 数组起始点为0
	int child=start*2+1;// 左孩子是 2*s+1 //右孩子是2*s+2
	// 根据完全二叉树的性质，遍历调整左右两个孩子
	// 终止条件为到达叶子节点，或者满足大顶堆条件
	while (child<=end)
	{
		if (child<end&&nums[child]->val>nums[child+1]->val)//从左右孩子中挑选一个大的
		{
			++child;
		}
		if (nums[parent]->val<=nums[child]->val)//需要调整节点s 大于最大的child 满足大顶堆要求，break
		{
			return;
		}
		else
		{
			// 不然就是将父节点调整为最大的孩子
			struct ListNode* temp=nums[child];
			nums[child]=nums[parent];
			nums[parent]=temp;
			//继续向下搜索
			parent=child;
			child=2*child+1;
		}
	}
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
	if (listsSize==0)
	{
		return NULL;
	}
	
	struct ListNode* dummy,*cur;
	dummy=malloc(sizeof(struct ListNode));
	dummy->next=NULL;
	cur=dummy;
	int quelen=0;
	// 为了方便链表的维护，排除中间存在NULL的情况
	struct ListNode** newlists;
	newlists=malloc(sizeof(struct ListNode*)*listsSize);
	for (int i = 0; i <listsSize; i++)
	{	
		if (lists[i])
		{
			newlists[quelen]=lists[i];
			quelen++;
		}
	}
	/* 建立小顶堆 */
	for (int i = quelen/2; i >=0; i--)
	{
		ListHeapAdjust(newlists,i,quelen-1);
	}
	// 从lists 中弹出堆顶
	while (quelen>0)
	{
		cur->next=newlists[0];
		newlists[0]=newlists[0]->next;
		// 堆顶元素用完放到堆底
		if (!newlists[0])
		{
			newlists[0]=newlists[quelen-1];
			newlists[quelen-1]=NULL;
			quelen--;
		}
		// 从顶开始调整堆
		ListHeapAdjust(newlists,0,quelen-1);
		cur=cur->next;
	}
	return dummy->next;
}

#define N 4
int main(int argc, char const *argv[])
{
	int l[][N]={{},{-1,5,11},{},{6,10}},ns[]={0,3,0,2};
	struct ListNode **lists;
	lists=malloc(sizeof(struct ListNode*)*N);
	for (size_t i = 0; i < N; i++)
	{
		if (ns[i]==0)
		{
			lists[i]=NULL;
		}
		else
			lists[i]=ListInit(l[i],ns[i]);
	}
	struct ListNode *ans=mergeKLists(lists,N);
	ListPrint(ans);
	return 0;
}
