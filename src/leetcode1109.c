#include <test.h>

/* 1109. 航班预订统计

这里有 n 个航班，它们分别从 1 到 n 进行编号。

有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。

请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。 */

// #数组 #子数组 #差分数组


/* 
需要对于原始数组的子数组进行频繁修改，所以可以使用差分数组进行解决
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
	(*returnSize)=n;
	int *ans=calloc(n,sizeof(int));
	int *diff=calloc(n,sizeof(int));
	int st,ed,len;
	// 维护差分diff数组
	for (size_t i = 0; i < bookingsSize; i++)
	{
		st=bookings[i][0]-1;
		ed=bookings[i][1]-1;
		len=bookings[i][2];
		diff[st]+=len;
		if (ed+1<n)
		{
			diff[ed+1]-=len;//在长度以内都需要对越过子区间的进行差分恢复
		}
	}
	// 通过差分数组恢复原始数组
	ans[0]=diff[0];
	for (size_t i = 1; i < n; i++)
	{
		ans[i]=ans[i-1]+diff[i];
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	int bookings[][3]={{1,2,10},{2,3,20},{2,5,25}},bosz=3,bocol=3,retsz,n=5;
	int **bopass;
	bopass=malloc(sizeof(int *)*bosz);
	for (size_t i = 0; i < bosz; i++)
	{
		bopass[i]=malloc(sizeof(int)*3);
		for (size_t j = 0; j < 3; j++)
		{
			bopass[i][j]=bookings[i][j];
		}
		
	}
	
	int *ans=corpFlightBookings(bopass,bosz,&bocol,n,&retsz);
	ArrayPrint(ans,n);

	return 0;
}
