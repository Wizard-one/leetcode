#include <stdio.h>
#include <stdlib.h>
#include <test.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// #数组 #模拟
// 模拟就是照着他说的来
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
	int **res;
	res=malloc(sizeof(int *)*n);
	(*returnColumnSizes)=malloc(sizeof(int)*n);
	*returnSize=n;
	for (size_t i = 0; i < n; i++)
	{
		res[i]=malloc(sizeof(int)*n);
		(*returnColumnSizes)[i]=n;
	}
	int target=1;
	int t=0,r=n-1,l=0,b=n-1;//定义边界
	while (target<=n*n)
	{
		// top define
		for (size_t i = l; i <=r; i++)
		{
			res[t][i]=target++;
		}
		t++;
		// right define
		for (size_t i = t; i <=b; i++)
		{
			res[i][r]=target++;
		}
		r--;
		// bottom define
		for (int i = r; i >=l; i--)
		{
			res[b][i]=target++;
		}
		b--;
		// left define
		for (int i = b; i >=t; i--)
		{
			res[i][l]=target++;
		}
		l++;
	
	}
	return res;
}

int main(){
	int **ans,r,*c;
	ans=generateMatrix(3,&r,&c);
	printmat(ans,r,c);
}