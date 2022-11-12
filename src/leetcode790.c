#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// 动态规划
int numTilings(int n){
	long long d[n+1][4];
	memset(d,0,sizeof(d));
	d[0][3]=1;
	for (size_t i = 1; i < n+1; i++)
	{
		d[i][0]=d[i-1][3];
		d[i][1]=d[i-1][0]+d[i-1][2];
		d[i][2]=d[i-1][1]+d[i-1][0];
		d[i][3]=d[i-1][1]+d[i-1][0]+d[i-1][2]+d[i-1][3];
	}
	return d[n][3];
}

int main()
{
	printf("%d",numTilings(4));
}