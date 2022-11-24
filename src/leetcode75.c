#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

// #双指针
void sortColors(int* nums, int numsSize){
	int p0=0,p1=0,p2=numsSize-1;
	// 2 一定是放到结尾的 所以p2直接指向结尾
	for (size_t i = 0; i <= p2; i++)
	{
		if (nums[i]==0)
		{
			swap(&nums[p0],&nums[i]);
			p0++;
			p1++;//p1
		}
		else if (nums[i]==1)
		{
			swap(&nums[p1],&nums[i]);
			p1++;
		}
		else if (nums[i]==2)
		{
			swap(&nums[p2],&nums[i]);
			if (p2>0 && i>=0)
			{
				p2--;
				i--;
			}
			else
			{
				break;
			}
		}
		for (size_t j = 0; j < numsSize; j++)
		{
			printf("%d,",nums[j]);
		}
		printf("\n");
		
	}
}


int main(){
	int nums[]={2,0,1},l=3;
	sortColors(nums,l);
	for (size_t i = 0; i < l; i++)
	{
		printf("%d,",nums[i]);
	}
	
}