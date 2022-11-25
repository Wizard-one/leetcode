#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// #杨辉三角 #数组

int* getRow(int rowIndex, int* returnSize){
	int *ans;
	*returnSize=rowIndex+1;
	int last[rowIndex+1];//或者多创建一个变量，存储上一层
	ans=malloc((rowIndex+1)*(sizeof (int)));
	ans[0]=1;
	// printf("1\n");
	if (rowIndex==0)
	{	
		return ans;
	}
	ans[1]=1;
	// printf("1,1\n");
	last[0]=1;
	last[1]=1;
	for (size_t i = 2; i <=rowIndex; i++)
	{
		memcpy(last,ans,sizeof(int)*i);
		// ans[i]=1;
		// printf("%d,",ans[0]);
		for (size_t j = i; j > 0; --j)
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
	ans=getRow(4,&r);
	for (size_t j = 0; j < r; j++)
	{
		printf("%d,",ans[j]);
	}
}