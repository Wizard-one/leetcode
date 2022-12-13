#include <stdlib.h>
#include <stdio.h>


/* 120. 三角形最小路径和


给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

 */


// #动态规划 space: O(n) time: O(n^2)


/* 
可以发现层与层之间的最小路径和存在一个递推关系，所以应该使用动态规划，那么问题核心就转化为
- 层和层之间维护什么变量
- 该变量和最终目标有什么联系

最终目标为最小路径和，所以我们可以维护每一层到达每一个节点的最小路径和：f(r,c)

全局最小路径和为: min f(r_n,c) in c r_n为最后一行

根据移动关系：每一步只能移动到下一行中相邻的结点上，可以得出

f(r,c)=min(f(r-1,c),f(r-1,c-1))+tr(r,c)

初始条件为：
f(0,0)=tr(0,0)

边界条件为：
左边界只有一个到达路径:f(r,0)=f(r,0)+tr(r,0)
右边界只有一个到达路径:f(r,-1)=f(r,-1)+tr(r,-1)

可以发现不需要额外维护其他变量来存储上一层结果，故空间复杂度为O(n)
 */
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
	int path;//min f(r,c) in c
	int *f;//f(r,c)
	f=calloc(triangleSize,sizeof(int));
	f[0]=triangle[0][0];
	for (size_t r = 1; r < triangleSize; r++)
	{
		// f(r,c)=min(f(r-1,c),f(r-1,c-1))+tr(r,c)
		// B.C. 边界上只有一个到达路径
		f[triangleColSize[r]-1]=f[triangleColSize[r]-2]+triangle[r][triangleColSize[r]-1];
		for (size_t c = triangleColSize[r]-2; c >0 ; c--)
		{
			f[c]=IMIN(f[c]+triangle[r][c],f[c-1]+triangle[r][c]);
		}
		f[0]=f[0]+triangle[r][0];
	}
	path=f[0];
	for (size_t i = 1; i < triangleSize; i++)
	{
		path=IMIN(path,f[i]);
	}
	return path;
}


int main()
{
	int **tr,trrow=3,*trc;
	trc=malloc(sizeof(int)*trrow);
	tr=malloc(sizeof(int*)*trrow);
	for (size_t i = 0; i < trrow; i++)
	{
		trc[i]=i+1;
		tr[i]=malloc(sizeof(int)*trc[i]);
	}
	tr[0][0]=-1;
	tr[1][0]=2;
	tr[1][1]=3;
	int t[]={1,-1,-3};
	for (size_t i = 0; i < 3; i++)
	{
		tr[2][i]=t[i];
	}
	// int r4[]={4,1,8,3};
	// for (size_t i = 0; i < 4; i++)
	// {
	// 	tr[3][i]=r4[i];
	// }
	for (size_t i = 0; i < trrow; i++)
	{
		for (size_t j = 0; j < trc[i]; j++)
		{
			printf("%d,",tr[i][j]);
		}
		printf("\n");
		
	}
	printf("\n");
	int ans;
	ans=minimumTotal(tr,trrow,trc);
	printf("%d",ans);

}