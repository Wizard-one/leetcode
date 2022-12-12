#include <stdlib.h>
#include <stdio.h>
/**118. 杨辉三角

给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 */
// #数组 #杨辉三角 #模拟 [[119]] time: O(numRows^2)
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	*returnSize=numRows;
	int **ans;
	ans=malloc(numRows*(sizeof (int*)));
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	for (size_t i = 0; i < numRows; i++)
	{
		ans[i]=malloc((i+1)*sizeof(int));
		ans[i][0]=1;
		ans[i][i]=1;
		(*returnColumnSizes)[i]=i+1;
		for (size_t j = 1; j < i; j++)
		{
			ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
		}
		
	}
	return ans;
}

int main()
{
	int **ans,r,*c;
	ans=generate(5,&r,&c);
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c[i]; j++)
		{
			printf("%d,",ans[i][j]);
		}
		printf("\n");
	}
}