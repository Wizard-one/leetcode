#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
	*returnSize=0;
	int table[26]={0};
	int i=0,*ans;
	while (s[i]!='\0')
	{
		table[s[i]-'a']=i;//使用hash table 记录每个字符的终点
		i++;
	}
	ans=malloc(sizeof(int)*i);//最坏情况分组为字符串长度
	int st=0,ed=table[s[0]-'a'];//分段区间起始点与终止点, 分段尽可能的小
	i=0;
	while (s[i]!='\0')
	{
		// 当前分段终点不可能缩短，只可能在分段中间遇到结束点更加长的字符，此时就需要更新分段终点
		// 同样如果i==ed ed 比如不会更新 所以可以放在终止条件之前进行维护
		ed=fmax(ed,table[s[i]-'a']);
		if (i==ed)
		{
			// 遍历到分段终点说明分段不会继续扩张，维护新的起始点与终止点，以及返回结果
			ans[*returnSize]=ed-st+1;
			(*returnSize)++;
			st=ed+1;
 		}
		i++;
	}
	return ans;
}

int main()
{
	char *a="ababcbacadefegdehijhklij";
	int size,*ans;
	ans=partitionLabels(a,&size);
	for (size_t i = 0; i < size; i++)
	{
		printf("%d,",ans[i]);
	}
	

}