#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int forward,back,fidx,bidx;
    forward=nums[0];
    fidx=0;
    for(size_t i=1;i<numsSize;i++)
    {
        back=nums[i];
        if(back!=forward){
            fidx++;
            nums[fidx]=back;
            forward=back;
        }
    }
    return ++fidx;
}

int main(){
	int a[3]={1,1,2},k;
	k=removeDuplicates(a,3);
	for (size_t i = 0; i < k; i++)
	{
		/* code */
		printf("%d,",a[i]);
	}
	printf("\n");
	return 0;
}