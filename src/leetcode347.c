#include <uthash.h>
#include <stdio.h>
#include <test.h>
/* 347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 */

// [[215]] #优先队列 #hash #排序 #堆排序
typedef struct numcount {
    int val;            /* we'll use this field as the key */
    int count;
    UT_hash_handle hh; /* makes this structure hashable */
}numcount;

/**
 * @brief 用于hash排序的函数
 * 
 * 升序, b>a 返回TRUE b放后面
 * 
 * @param a 放后面的
 * @param b 放前面的
 * @return int 
 */
int by_count(numcount *a,numcount*b)
{
	return b->count>a->count;
}

typedef struct count_val{
	int count;
	int val;
}count_val;


int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
	int *ans=malloc(sizeof(int)*k);
	*returnSize=k;
	numcount *CountTable=NULL;//统计每个数出现次数
	numcount *cur;
	// 建立一个统计每个数出现次数的hash表
	for (size_t i = 0; i < numsSize; i++)
	{
		HASH_FIND_INT(CountTable,&nums[i],cur);//查询hash表中是否有当前值
		if (!cur)//没有就先初始化
		{
			cur=malloc(sizeof(numcount));
			cur->count=1;
			cur->val=nums[i];
			HASH_ADD_INT(CountTable,val,cur);
		}
		else//有就计数++
		{
			cur->count++;
		}
	}
	// 制作一个小顶堆
	numcount *tmp;//小顶堆
	count_val *minheap,t;
	int i;
	minheap=malloc(sizeof(count_val)*(k+1));
	HASH_ITER(hh,CountTable,cur,tmp)
	{
		if(i<k)
		{
			// 当小顶堆节点数还未到达k个时，建立小顶堆
			minheap[++i].count=cur->count;
			minheap[i].val=cur->val;
			int child=i,parent=i/2;//从下向上调整堆
			while (parent>0)
			{
				
				if (minheap[parent].count<minheap[child].count)
				{
					// 子节点计数小于父节点
					break;
				}
				t=minheap[parent];
				minheap[parent]=minheap[child];
				minheap[child]=t;
				int temp;
				// 向上搜索父节点是否符合条件
				child=parent;//交换父子节点
				parent=parent/2;//父节点向上移动

			}
			
		}
		else
		{
			if (minheap[1].count<cur->count)
			{
				//小顶堆堆顶小于当前值，则堆顶弹出，将当前值插入堆顶
				minheap[1].count=cur->count;
				minheap[1].val=cur->val;
				int parent=1,child=parent*2;//从堆顶开始迭代调整
				while (child<=k)
				{
					if (child<k && minheap[child].count>minheap[child+1].count)
					{
						child=child+1;//选一个小的child
					}
					if (minheap[child].count>=minheap[parent].count)
					{
						//满足条件不用调整
						break;
					}
					t=minheap[parent];
					minheap[parent]=minheap[child];
					minheap[child]=t;
					// 向下搜索子节点是否符合条件
					parent=child;
					child*=2;
		
				}
				
			}
			
		}
	}
	for (size_t i = 0; i < k; i++)
	{
		ans[i]=minheap[i+1].val;
	}
	return ans;
}

int main(){
	int nums[]={5,1,-1,-8,-7,8,-5,0,1,10,8,0,-4,3,-1,-1,4,-5,4,-3,0,2,2,2,4,-2,-4,8,-7,-7,2,-8,0,-8,10,8,-8,-2,-9,4,-7,6,6,-1,4,2,8,-3,5,-9,-3,6,-8,-5,5,10,2,-5,-1,-5,1,-3,7,0,8,-2,-3,-1,-5,4,7,-9,0,2,10,4,4,-4,-1,-1,6,-8,-9,-1,9,-9,3,5,1,6,-1,-2,4,2,4,-6,4,4,5,-5},resize,*res,k=7;
	res=topKFrequent(nums,100,k,&resize);
	for (size_t i = 0; i < resize; i++)
	{
		printf("%d,",res[i]);
	}
}