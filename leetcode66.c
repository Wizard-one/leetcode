#include <math.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *ans;
	int up=0;
	ans=(int*)malloc((digitsSize+1)*sizeof(int));
	ans[digitsSize]=digits[digitsSize-1]+1;
	if (ans[digitsSize]>9)
	{
		up=1;
		ans[digitsSize]=0;
	}
	for (size_t i = digitsSize-1; i > 0; i--)
	{
		/* code */
		ans[i]=digits[i-1]+up;
		if (ans[i]>9)
		{
			up=1;
			ans[i]=0;
		}
		else
		{
			up=0;
		}
	}
	if (up==1)
	{
		ans[0]=1;
		*returnSize=digitsSize+1;
	}
	else
	{
		*returnSize=digitsSize;
		ans++;
	}	
	return ans;
}


int main(){
	int n[4]={9,9,9,9},*ans,en;
	ans=plusOne(n,4,&en);
	for (size_t i = 0; i < en; i++)
	{
		printf("%d,\n",ans[i]);
	}
	return 0;
}