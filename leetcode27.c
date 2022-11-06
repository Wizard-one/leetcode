#include <stdlib.h>
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int fidx;
    fidx=0;
    for(size_t i=0;i<numsSize;i++)
    {
        if(nums[i]!=val){
            nums[fidx]=nums[i];
            fidx++;
        }
    }
    return fidx;
}

int main(){
	int a[4]={3,2,2,3},k;
	k=removeElement(a,4,3);
	for (size_t i = 0; i < k; i++)
	{
		/* code */
		printf("%d,",a[i]);
	}
	printf("\n");
	return 0;
}