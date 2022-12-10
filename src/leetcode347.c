#include <uthash.h>
#include <stdio.h>

/* 347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 */

// [[215]] #优先队列 #hash #排序
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
	/* 对出现频次进行排序 */
	HASH_SORT(CountTable,by_count);
	numcount *tmp;
	int i=0;
	// 获取前k个高频元素
	HASH_ITER(hh,CountTable,cur,tmp){
		if(i<k)
		{
			ans[i]=cur->val;
			i++;
		}
	}
	return ans;
}

int main(){
	int nums[]={1,1,1,2,2,3},resize,*res,k=2;
	res=topKFrequent(nums,6,k,&resize);
	for (size_t i = 0; i < resize; i++)
	{
		printf("%d,",res[i]);
	}
}