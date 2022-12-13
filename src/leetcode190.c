#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
/* 190. 颠倒二进制位
颠倒给定的 32 位无符号整数的二进制位。


 */
// #位运算 [[191]]
uint32_t reverseBits(uint32_t n) {
    uint32_t ans=0;//用0去承接结果
	// 一共长32位从1到32位一共移动31次
    for (size_t i = 0; i < 31; i++)
    {
		ans=ans|(n&1);//最低位保存到结果当中
		// printf("%u,%u\n",n&1,ans&1);
		ans=ans<<1;//结果左移
		n=n>>1;//原来的数右移
    }
	// 最后一位也要加上
	ans=ans|(n&1);
    return ans;
}

int main()
{
	uint32_t a=43261596;
	a=reverseBits(a);
	printf("\n%u",a);
}