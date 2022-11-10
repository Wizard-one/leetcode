#include <stdlib.h>
#include <stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	*returnSize=numRows;
	int **ans;
	ans=malloc(numRows*(sizeof (int*)));
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	ans[0]=malloc(sizeof(int));
	ans[0][0]=1;
	(*returnColumnSizes)[0]=1;
	if (numRows==1)
	{	
		return ans;
	}
	ans[1]=malloc(2*sizeof(int));
	ans[1][0]=1;
	ans[1][1]=1;
	(*returnColumnSizes)[1]=2;
	if (numRows==2)
	{	
		return ans;
	}
	for (size_t i = 2; i < numRows; i++)
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