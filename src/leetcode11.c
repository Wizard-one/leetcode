// #双指针 #mid O(n)
/* 盛最多水的容器
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

最朴素的想法就是暴力解法，for i=0:end; for j=i:end O(n^2). 可以发现为了搜索最大面积我们使用了2个指针去遍历整个区间，那么就需要思考问题可不可以通过双指针的方法来一次削减多个搜索空间?

由于要求区间大小最大，自然而然就考虑区间长度取最长, hs, 那么面积就是

$A=min(l,r)*hs$ 

那么要获得$max A$  hs 只会不断变小, 也就是要让 min(l,r) 变大才能获得更大的A

这就是有了一个判断条件2个情况.
if h[l]>h[r]-> r-- else l++ 这就是始终移动小的边界，因为移动大的边界不一定让A变大，而移动小的边界一定让A变大。让两侧边界尽可能相同。

至此双指针的设计完成了。

那么相比暴力解法，双指针是如何更快的排除了搜索空间呢?
暴力搜索空间如下
[1,8,6,2]
    i
    1 8 6 2
  1 x x x x
  8   x x x
j 6     x x 
  2       x

双指针的搜索过程如下: 
	l
    1   8  6  2
  1 x   x  x  x
  8 1x  e  x  x
r 6 1x  2  x  x
  2 0   1 2x  x  

由于l!=r 的条件限制了 搜索终止于矩阵对角线，而双指针每走一步就排除了多个搜索的可能性。所以才是O(N)的
 */
#define IMAX(a,b) ((a)<(b)?(b):(a))
int maxArea(int* height, int heightSize){
	int l=0,r=heightSize-1,maxa=0;
	while (l!=r)
	{
		if (height[l]>height[r])
		{
			maxa=IMAX(maxa,(r-l)*height[r]);
			r--;
		}
		else
		{
			maxa=IMAX(maxa,(r-l)*height[l]);
			l++;
		}
	}
	return maxa;
}