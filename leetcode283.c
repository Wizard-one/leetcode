#include <stdio.h>
#include <stdlib.h>
// #双指针
void moveZeroes(int* nums, int numsSize){
	int count=1,t;
	for (size_t i = 0; i < numsSize-1; i++)
	{
		for (size_t j = 0; j < numsSize-1; j++)
		{
			if (nums[j]==0)
			{
				t=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=t;
			}
		}
	}
}

int main(){
	int a[]={0,1,0,3,5};
	moveZeroes(a,5);
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d,",a[i]);
	}
	
}