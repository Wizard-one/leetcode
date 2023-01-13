#include <test.h>


/* 给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。 */

// #位运算 #前缀

/* 
观察发现求的是二进制的公共前缀

例如 5 7
101
110
111

6 7
110
111

那只需要对两个边界同时右移然后记录次数再把左边界左移即可
 */
int rangeBitwiseAnd(int left, int right){
	int mv=0;
	while (left<right)
	{	
		mv++;
		left=left>>1;
		right=right>>1;
	}
	return left<<mv;
}

int main(int argc, char const *argv[])
{
	int ans=rangeBitwiseAnd(6,7);
	printf("%d",ans);
	return 0;
}
