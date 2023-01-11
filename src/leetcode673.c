#include <test.h>

/* 673. 最长递增子序列的个数

给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。
 */

// [[300]] #动态规划 #计数 

/* 
300 的进化版本，返回的是子序列个数，总体思想一样，多维护一个计数数组cnt[i]

cnt[i] 的更新是在 len[i] 长度变更时进行重置， len[i] 长度不变时进行叠加cnt[j] 的结果

例如
idx:  0,1,2,3,4,5,6,7
nums: 0,1,0,3,2,5,2,4
len:  1,2,1,3,3,4,3,4

len[5]=4 此时需要叠加 cnt[3], cnt[4] 的结果， 因为 idx=5 前面3 有2个选择的可能性 所以需要分别叠加两个可能性的结果

 */
int findNumberOfLIS(int* nums, int numsSize){
	int last=nums[0],maxlen=1,maxcnt=0;
	int *len,*cnt;
	len=malloc(sizeof(int)*numsSize);
	cnt=malloc(sizeof(int)*numsSize);//统计以i结尾最长子序列的个数
	
	for (size_t i = 0; i < numsSize; i++)
	{
		len[i]=1;
		cnt[i]=1;
		for (size_t j = 0; j < i; j++)
		{
			if (nums[i]>nums[j])
			{
				// 以i 结尾的最长子序列必然是 0-j 最长子序列长度+1 与本身的比较
				if (len[i]<len[j]+1)
				{
					len[i]=len[j]+1;
					cnt[i]=cnt[j]; //重置计数，因为这边len[i] 更新了
				}
				else if (len[j]+1==len[i])
				{
					cnt[i]+=cnt[j]; //计数累加， 这边计数的累加是叠加上一种所有可能
				}
			}			
		}
		if(len[i]>maxlen)
		{
			// 维护最大长度与对应计数
			maxlen=len[i];
			maxcnt=cnt[i];
		}
		else if (len[i]==maxlen)
		{
			maxcnt+=cnt[i]; //最大计数之间的关系是相互平行的，所以叠加一次当前的结果
		}	
	}
	return maxcnt;
}

int main(int argc, char const *argv[])
{
	int l[]={0,1,0,3,2,5,2,4};
	int ans=findNumberOfLIS(l,8);
	printf("%d",ans);
	return 0;
}


