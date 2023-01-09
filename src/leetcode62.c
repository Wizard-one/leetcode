#include <test.h>

/*  62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
 */

// #动态规划 time: O(mn) space: O(m) #组合

/* 就是求组合数 
从左上到右下 一共移动 m-1 n-1 次。 所以是在 m-1+n-1 中选择 m-1 向下

C m-1, m+n-2


当然也可以直接模拟选择的过程，每个点可到达路径数为f(i,j)

f(i,j) = f(i-1,j)+f(i,j-1)

从左向右，从上到下遍历只需维护 前一个 j f(i,j-1) 以及上一行 f(i-1,j)

边界条件为 f(i,0)=1, f(0,j)=1

 */

int uniquePaths(int m, int n){
	int path=1,*p_i_prev,p_j_prev=1;//f(i,j), f(i-1,j), f(i,j-1)
	p_i_prev=malloc(sizeof(int)*n);
	// 设置 f(i-1,j)
	for (size_t i = 0; i < n; i++)
	{
		p_i_prev[i]=1;
	}
	// 边界无需遍历 直接从1开始
	for (size_t i = 1; i < m; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			path=p_i_prev[j]+p_j_prev;
			p_i_prev[j]=path;
			p_j_prev=path;
		}
		// 重置左边界
		p_j_prev=1;
	}
	free(p_i_prev);
	return path;
}

int main(int argc, char const *argv[])
{
	int ans=uniquePaths(1,1);
	printf("%d",ans);
	return 0;
}
