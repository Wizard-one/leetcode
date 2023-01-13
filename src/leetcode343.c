#include <test.h>

/*343. 整数拆分

给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。 */

// #动态规划 #数学 #求和 #路径搜索 time:O(n^2) space:O(n)

/* 这是一个求最大的问题，每一个n 唯一对应最大乘积，且不需要记录走过的路径，所以该问题适用动态规划

令 dp[n]: n的最大乘积

最基础的case: 
n prod
2 1
3 2
4 4

分析每一个case 的拆分方式:
2=1+1

3=1+1+1/ 1+2

4=1+3 / 2+2 / 3+1 

从4的拆分方式可以发现 4拆分为 1+3 时可以视为从 4 中选择1 然后重复 3 的拆分方式， 同理选择 2 重复 2的拆分方式

也就是"重复3 的拆分方式" 可以认为是一个重叠的子问题

至此画成一个多叉树

4
|    \  \
1     2  3
| |
3 重复3的拆分

第一个子树状态转移可以视为 选择了 1 然后 增加了一个 1*3 的分治与 1*dp[3]

进一步递推可以得到

dp[i]= \max_{1<=j<i} (max(dp[i-j]*j,(i-j)*j))

由于需要使用 i-j 所以需要2个指针同时没有状态压缩
*/

#define IMAX(a,b) ((a)>(b)?(a):(b))

int integerBreak(int n){
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	// 边界条件
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for (size_t i = 3; i <= n; i++)
	{
		for (size_t j = 1; j < i; j++)
		{
			// dp[i]= \max_{1<=j<i} (max(dp[i-j]*j,(i-j)*j))
			dp[i]=IMAX(dp[i],j*(i-j));
			dp[i]=IMAX(dp[i-j]*j,dp[i]);
		}
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int ans=integerBreak(10);
	printf("%d",ans);
	return 0;
}
