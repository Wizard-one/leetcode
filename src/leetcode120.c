#include <stdlib.h>
#include <stdio.h>
#define IMIN(a,b) ((a)<(b)?(a):(b))

// #动态规划 space: O(n) time: O(n^2)
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
	int path;//min f(r,c) in r
	int prevrowc=triangle[0][0];//f(r-1,c)
	int prevrowc1;//f(r-1,c-1)
	int *f;//f(r,c)
	f=calloc(triangleSize,sizeof(int));
	if (triangleSize==1)
	{
		return triangle[0][0];
	}
	else if (triangleSize==2)
	{
		prevrowc+=triangle[1][1];
		prevrowc1=triangle[1][0]+triangle[0][0];
		return IMIN(prevrowc1,prevrowc);
	}
	prevrowc+=triangle[1][1];
	prevrowc1=triangle[1][0]+triangle[0][0];
	f[0]=prevrowc1;
	f[1]=prevrowc;
	for (size_t r = 2; r < triangleSize; r++)
	{
		f[triangleColSize[r]-1]=f[triangleColSize[r]-2]+triangle[r][triangleColSize[r]-1];
		for (size_t c = triangleColSize[r]-2; c >0 ; c--)
		{
			f[c]=IMIN(f[c]+triangle[r][c],f[c-1]+triangle[r][c]);
		}
		f[0]=f[0]+triangle[r][0];
		for (size_t c = 0; c<triangleColSize[r]; c++)
		{
			printf("%d,",f[c]);
		}
		printf("\n");
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