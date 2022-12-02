#include <test.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * 498. 对角线遍历 
 * 就是直观的去模拟，主要难点是总结模拟规律,同时模拟的要足够简洁，
 * 总结的规律需要考虑是否有继续优化的空间再写代码不然维护起来会很复杂
 */
// #matrix
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
	int *res,m=matSize,n=matColSize[0],dianum,minlen,maxlen;
	*returnSize=m*n;
	res=malloc(sizeof(int)*(m*n));
	int filp=1;//用于标记向下遍历还是向上遍历
	dianum=n+m-1;//矩阵对角线遍历次数
	minlen=(m>n)?(n):(m);
	maxlen=(m<n)?(n):(m);
	int k=0;
	for (int r = 0; r < dianum; r++)
	{
		int i,j;
		if (filp)
		{
			// 自下而上遍历, i-- j++
			i=(r>m-1)?(m-1):(r);//当行到达边界则从边界开始
			j=(r>m-1)?r-m+1:0;//当列到达边界则从r-边界开始
			while (i>=0&&j<n)
			{
				res[k++]=mat[i][j];
				i--;
				j++;
			}
			filp=0;
		}
		else
		{
			// 自上而下遍历
			j=(r>n-1)?(n-1):(r);
			i=(r>n-1)?r-n+1:0;
			while (j>=0&&i<m)
			{
				res[k++]=mat[i][j];
				j--;
				i++;

			}
			filp=1;
		}
	}
	return res;	
}

int main(){
	int mat[2][3]={{1,2,3},{4,5,6}},**matp,n=2,nc[3]={3,3};
	matp=malloc(sizeof(int*)*n);
	for (size_t i = 0; i < n; i++)
	{
		matp[i]=malloc(sizeof(int)*nc[i]);
		for (size_t j = 0; j < nc[i]; j++)
		{
			matp[i][j]=mat[i][j];
		}
	}
	int anssize,*ans;
	ans=findDiagonalOrder(matp,n,nc,&anssize);
	for (size_t i = 0; i < anssize; i++)
	{
		printf("%d,",ans[i]);
	}
	
}