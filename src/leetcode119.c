#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// #杨辉三角 #数组 [[118]]
/* 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。 */

/* 多存上一层变量,或者倒序遍历,这样节省空间同时减少了变量的维护 */
int* getRow(int rowIndex, int* returnSize){
	int *ans;
	*returnSize=rowIndex+1;
	ans=malloc((rowIndex+1)*(sizeof (int)));
	memset(ans, 0, sizeof(int) * (*returnSize));//要预先置零,倒序存储会访问到上层最后一个元素之外的一个元素
	ans[0]=1;
	for (int i = 1; i <=rowIndex; i++)
	{
		// ans[i]=1;
		// printf("%d,",ans[0]);
		for (int j = i; j > 0; --j)
		// 倒着存，这样不会覆盖
		{
			ans[j]+=ans[j-1];
			// printf("%d,",ans[j]);
		}
		// printf("%d\n",ans[i]);
	}
	return ans;
}

int main()
{
	int *ans,r,*c;
	ans=getRow(1,&r);
	for (size_t j = 0; j < r; j++)
	{
		printf("%d,",ans[j]);
	}
}