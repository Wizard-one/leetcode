#include <math.h>
#include <stdlib.h>
#include <stdio.h>
// #数组 #模拟
/*
66. 加一

给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
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