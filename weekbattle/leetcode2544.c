#include <test.h>

/* 2544. 交替数字和

给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：

    最高有效位 上的数字分配到 正 号。
    剩余每位上数字的符号都与其相邻数字相反。

返回所有数字及其对应符号的和。
 */


/* 按位正序拆解，逆序合成 */
int alternateDigitSum(int n){
	int sum=0;
	int *nums,len=0;
	nums=malloc(sizeof(int)*10);
	while (n>0)
	{
		nums[len++]=n%10;
		n/=10;
	}
	len-=1;
	int flag=1;
	for (; len>=0; len--)
	{
		if (flag)
		{
			sum+=nums[len];
			flag=0;
		}
		else
		{
			sum-=nums[len];
			flag=1;
		}
	}
	return sum;
}