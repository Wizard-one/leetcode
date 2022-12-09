#include <test.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/**
 * @brief init list from int array
 * 
 * @param l int array
 * @param ns array length
 * @return struct ListNode* list head 
 */
struct ListNode* ListInit(int* l,int ns)
{
	struct ListNode * r,*rh;
	r=malloc(sizeof(struct ListNode));
	rh=r;
	r->next=NULL;
	for (size_t i = 0; i < ns; i++)
	{
		
		r->val=l[i];
		if (i==ns-1)
		{
			r->next=NULL;
			break;
		}
		
		r->next=malloc(sizeof(struct ListNode));
		r=r->next;
		r->next=NULL;
	}
	return rh;
}
/**
 * @brief print List
 * 
 * @param l input list
 */
void ListPrint(struct ListNode * l)
{
	while (l!=NULL)
	{
		printf("%d,",l->val);
		l=l->next;
	}
	printf("\n");
}

/**
 * @brief Create a Bi Tree object
 * 先序遍历创建
 * @param T Tree address
 * @param nums list use -1 mark NULL
 * @param idx list index
 */
void TreeInit(struct TreeNode **T,int *nums,int *idx)
{
	(*idx)++;
	if(nums[*idx]==-1)
		*T=NULL;
	else
	{
		*T=(struct TreeNode*)malloc(sizeof(struct TreeNode));
		if(! *T)
			exit(-1);
		(*T)->val=nums[(*idx)];
		TreeInit(&(*T)->left,nums,idx);
		TreeInit(&(*T)->right,nums,idx);
	}
}


/**
 * @brief 构建子树
 * 
 * @param hash 中序遍历的hash 表 key=tree node value; value=该value 对应的中序遍历idx 
 * @param preorder 先序遍历数组
 * @param preleft 先序遍历中左子树开始的位置
 * @param preright 先序遍历中右子树开始的位置
 * @param instart 中序遍历序列中一颗子树开始位置
 * @param inend 中序遍历序列中一颗子树结束位置
 * @return struct TreeNode* 
 */
struct TreeNode* subTree(int *hash,int* preorder,int preleft,int preright,int instart,int inend)
{
	if (preleft>preright)
	{
		return NULL;
	}
	struct TreeNode *root=malloc(sizeof(struct TreeNode));
	root->val=preorder[preleft];//先序遍历区间第一个节点为根节点
	int inroot=hash[root->val+3000];//中序遍历中定位到根节点idx
	int lnum=inroot-instart;//left subtree num
 	// 左子树创建:
	// 先序列表左子树开始位置显然就是当前根节点+1, 右子树开始位置就是左子树的数目+当前根节点位置
	// 中序列表开始位置不变，结束位置是当前根节点位置-1
	root->left=subTree(hash,preorder,preleft+1,preleft+lnum,instart,inroot-1);
	// 右子树创建:
	// 先序列表左子树开始位置是当前根节点+1+左子树长度, 右子树开始位置不变
	// 中序列表开始位置是当前根节点位置+1，结束位置不变
	root->right=subTree(hash,preorder,lnum+preleft+1,preright,inroot+1,inend);
	return root;
}

/**
 * @brief 使用先序遍历与中序遍历构造二叉树
 * 需要注意，二叉树val不能有重复
 * @param preorder 先序遍历表
 * @param inorder 先序遍历表
 * @param Size 二叉树总节点数
 * @return struct TreeNode* 
 */
struct TreeNode* TreeInit_prein(int* preorder,int* inorder, int Size){
	int hash[6000]={0};
	struct TreeNode*root;
	// 构建hash表降低搜索复杂度
	for (size_t i = 0; i < Size; i++)
	{
		hash[inorder[i]+3000]=i;
	}
	root=subTree(hash,preorder,0,Size-1,0,Size-1);
	return root;
}


/**
 * @brief 层序打印树
 * 
 * @param root 树根节点 
 */
void TreePrint(struct TreeNode* root)
{
	if (root==NULL)
	{
		printf("[]");
	}
	struct TreeNode **queue;
	queue=malloc(sizeof(struct TreeNode *)*2000);
	int front=0,rear=0;
	queue[front++]=root;
	while ((front)!=(rear))
	{
		int last=(front);//标记当前层位置
		int col=0;
		while ((rear)<last)	
		{
			root=queue[(rear)++];
			printf("%d,",root->val);
			if (root->left!=NULL)
				queue[(front)++]=root->left;
			if (root->right!=NULL)		
				queue[(front)++]=root->right;
		}
		printf("\n");
	}
}

/**
 * @brief 打印矩阵
 * 
 * @param mat 矩阵指针
 * @param matrixSize 矩阵row num
 * @param matrixColSize 矩阵col num
 */
void printmat(int **mat, int matrixSize, int* matrixColSize)
{
	for (size_t i = 0; i < matrixSize; i++)
	{
		for (size_t j = 0; j < matrixColSize[i]; j++)
		{
			printf("%d,",mat[i][j]);
		}
		printf("\n");
	}
}


void swapint(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

/**
 * @brief 将数组调整为大顶堆
 * 
 * @param nums 数组
 * @param s 大顶堆需要调整的节点
 * @param m 大顶堆的终止点
 */
void HeapAdjust(int * nums,int s, int m)
{
	int temp,j;
	temp=nums[s];
	// 根据完全二叉树的性质，遍历调整左右两个孩子
	// 数组起始点为0 左孩子一定是 2*s+1 ,右孩子是2*s+2
	// 终止条件为到达叶子节点，或者满足大顶堆条件
	for ( j = 2*s+1; j <=m; j*=2)
	{
		if (j<m&&nums[j]<nums[j+1])//从左右孩子中挑选一个大的
		{
			++j;
		}
		if (temp>=nums[j])//需要调整节点s 大于最大的child 满足大顶堆要求，break
		{
			break;
		}
		// 不然就是将调整节点s赋值为最大的孩子
		nums[s]=nums[j];
		// 将孩子作为下一个交换节点，检查交换后的孩子是否还满足大顶堆的要求
		s=j;
	}
	nums[s]=temp;//最终将原有调整节点的值放到交换之后的位置
}



/**
 * @brief 堆排序
 * 
 * 从小到大排序
 * 
 * @param nums 被排序数组
 * @param numsSize 数组大小
 */
void HeapSort(int* nums,int numsSize)
{
	int i;
	for ( i = numsSize/2; i >= 0; i--)
	{
		HeapAdjust(nums,i,numsSize-1);//创建大顶堆
	}

	for (i = numsSize-1; i > 0; i--)
	{
		// 将堆顶记录与未排序的最后一个记录交换
		swapint(&nums[0],&nums[i]);
		// 重新将0..i-1 调整为大顶堆
		HeapAdjust(nums,0,i-1);
	}
}

/**
 * @brief 将区间划分为 pivot 的左右区间
 * 
 * 区间划分为[low,pivot-1] 与 [pivot+1,high] 
 * [low,pivot-1]区间值都小于 pivot 
 * [pivot+1,high] 区间都大于 pivot
 * 
 * @param nums 
 * @param low 
 * @param high 
 * @return int 
 */
int Partition(int *nums,int low, int high)
{
	int pivotkey;
	pivotkey=nums[low];
	/* low or high 中的一个为 pivotkey */
	/* 到达终止条件 pivotkey左边都是小于pivotkey 右边都是大于pivotkey */
	while (low<high)
	{
		// 将high(右边)指针移动到 nums[high]<pivot 位置
		
		while (low<high&&nums[high]>=pivotkey)
		{
			high--;
		}
		// 此时将pivot交换到右侧，如此一来 pivot 的右侧都是大于他的
		swapint(&nums[low],&nums[high]);
		// 同理 将low指针移动到nums[low]>pivot
		while (low<high&&nums[low]<=pivotkey)
		{
			low++;
		}
		// 交换，让 pivot左侧都是小于他的，同时这也维护了右侧都是大于他的
		swapint(&nums[low],&nums[high]);
		// 此时未处理的就是 low->pivot->high 这个区间内的值，两端都是处理过的
	}
	
}

/**
 * @brief 快速排序实现
 * 
 * @param nums 排序数组
 * @param low 排序下界
 * @param high 排序上界
 */
void QSort(int *nums,int low,int high)
{
	int pivot;
	if (low<high)
	{
		// 区间排序并返回枢轴，一次排序并不能保证整个区间都严格递增，
		pivot=Partition(nums,low,high);
		// 所以需要对左右子区间再次进行递归排序
		QSort(nums,low,pivot-1);
		QSort(nums,pivot+1,high);
	}
}

/**
 * @brief 快排的封装
 * 
 * @param nums 数组
 * @param numsSize 数组大小
 */
void QuickSort(int *nums,int numsSize)
{
	QSort(nums,0,numsSize-1);
}