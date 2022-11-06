#include <stdlib.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* res;
    int a;
    res=malloc(2*sizeof(int));
    for(size_t i=0;i<numsSize;i++)
    {
        a=nums[i];
        for(size_t j=i;j<numsSize;j++)
        {
            if((target-a)==nums[j])
            {
                res[0]=i;
                res[1]=j;
                break;
            }
        }
    }
    return res;
}
void main(){
	int a[4]={2,7,11,15};
	int t=9;
	int *res;
	res=twoSum(a,4,t,&t);
	for (size_t i = 0; i < 2; i++)
	{
		printf("%d,",res[i]);
	}
	printf("\n");
}