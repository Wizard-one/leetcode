#include <test.h>
/* 
88. 合并两个有序数组

给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p1=m-1,p2=n-1;
	int tail=m+n-1;
	int cur;
	// 从后向前合并，某一个用完就只存另一个
	while (p1>=0||p2>=0)
	{
		if (p2>=0 && (p1<0 || nums1[p1]<=nums2[p2]) )//判断条件要考虑的完备
		{
			cur=nums2[p2--];
		}
		else if(p1>=0 && (p2<0 || nums1[p1]>nums2[p2]) )
		// p2 用完或者p1更大
		{
			cur=nums1[p1--];
		}
		nums1[tail--]=cur;
	}	
}

int main()
{
	int n1[]={1,2,3,0,0,0},n2[]={2,5,6},m=3,n=3,n1s=6;
	merge(n1,n1s,m,n2,n,n);
	ArrayPrint(n1,n1s);
}