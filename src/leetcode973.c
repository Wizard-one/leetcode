#include <test.h>

/*973. 最接近原点的 K 个点


给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，并且是一个整数 k ，返回离原点 (0,0) 最近的 k 个点。

这里，平面上两点之间的距离是 欧几里德距离（ √(x1 - x2)2 + (y1 - y2)2 ）。

你可以按 任何顺序 返回答案。除了点坐标的顺序之外，答案 确保 是 唯一 的。
*/

// #优先队列 #排序 [[347]] [[215]] #堆排序 

/* 
使用长度为k的大顶堆来维护，先计算距离，然后建立一个长度为k的大顶堆

对于后序的元素i
- i distance.d > 堆顶 说明堆内所有元素都小于i不用入堆
- 否则弹出堆顶，同时调整堆
 */

/* 做一个结构体用来存储距离与点 */
typedef struct distance
{
	int d;
	int p[2];
}distance;

void swap(distance* a,distance *b)
{
	distance temp;
	temp=*a;
	*a=(*b);
	*b=temp;
}


int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes){
	distance *table,*kclose;
	(*returnSize)=k;
	table=malloc(sizeof(distance)*pointsSize);
	/* 预先计算距离 */
	for (size_t i = 0; i < pointsSize; i++)
	{
		table[i].p[0]=points[i][0];
		table[i].p[1]=points[i][1];
		table[i].d=table[i].p[0]*table[i].p[0]+table[i].p[1]*table[i].p[1];
	}
	kclose=malloc(sizeof(distance)*(k+1));
	int child,parent;
	distance temp;

	for (size_t i = 0; i < pointsSize; i++)
	{
		if (i<k)
		{
			// 向后插入元素建堆
			kclose[i+1]=table[i];
			child=i+1;
			parent=child/2;
			while (parent>0)
			{
				// 堆的调整就是从下向上的
				if (kclose[child].d<=kclose[parent].d)//大顶堆条件，父大于子
					break;
				swap(&kclose[child],&kclose[parent]);
				child=parent;
				parent=parent/2;
			}
		}
		else
		{
			if (kclose[1].d>table[i].d)//新入元素小于堆顶，入堆
			{
				kclose[1]=table[i];//删除堆顶元素
				child=2,parent=1;
				while (child<=k)
				{
					// 从上而下调整堆
					if (child<k && kclose[child].d<kclose[child+1].d)//左右child找个大的
						child++;					
					if (kclose[child].d<=kclose[parent].d)
						break;
					swap(&kclose[child],&kclose[parent]);
					parent=child;
					child=child*2;
				}
				
			}
			
		}
	}
	// 答案输出
	int **ans;
	ans=malloc(sizeof(int*)*k);
	*returnColumnSizes=malloc(sizeof(int)*k);
	for (size_t i = 0; i < k; i++)
	{
		ans[i]=malloc(sizeof(int)*2);
		(*returnColumnSizes)[i]=2;
		ans[i][0]=kclose[i+1].p[0];
		ans[i][1]=kclose[i+1].p[1];
	}
	return ans;
}

int main()
{
	int **input,mat[3][2]={{3,3},{5,-1},{-2,4}},row=3,col[3]={2,2,2};
	input=malloc(sizeof(int*)*row);
	for (size_t i = 0; i < row; i++)
	{
		input[i]=malloc(sizeof(int)*2);
		for (size_t j = 0; j < 2; j++)
		{
			input[i][j]=mat[i][j];
		}
	}
	int retrow,*retcol,**ans;
	ans=kClosest(input,row,col,2,&retrow,&retcol);
	MatPrint(ans,retrow,retcol);
	
}