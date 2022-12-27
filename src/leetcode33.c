#include <test.h>

// #搜索 #二分法

/*33. 搜索旋转排序数组

整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
*/

/* 将数组分为左右两个部分，一个部分有序，一个部分无序，只有当target 落在在有序的部分内时才缩小范围 */
int search(int* nums, int numsSize, int target){
    int l=0,r=numsSize-1;
    int mid=(l+r)/2;
    while (l<=r)
    {
        if(target==nums[mid])
        {
            return mid;
        }
        // 有序的部分在 [0,mid]
        if(nums[0]<=nums[mid])
        {
            // target 在有序的部分范围内，缩小范围
            if (target>=nums[l] && target <nums[mid])
            {
                r=mid-1;
                mid=(l+r)/2;
            }
            else
            {
                // 否则在另一边搜索
                l=mid+1;
                mid=(l+r)/2;
            }
        }
        else
        {
            // 有序的部分在 [mid,r], target 在 mid,r 范围内，缩小范围
            if (target>nums[mid] && target <=nums[r])
            {
                l=mid+1;
                mid=(l+r)/2;
            }
            else
            {
                // 否则在另一边搜索
                r=mid-1;
                mid=(l+r)/2;
            }
        }

    }
    return -1;
}

int main(){
    int l[]={1,3};
    int ans=search(l,2,3);
    printf("%d",ans);
}