#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//#字符串 #暴力解法 O(n^2)

/**
 * @brief 中心扩展寻找回文字符串边界
 * 
 * @param s 目标字符串
 * @param st 回文字符串起始点
 * @param ed 回文字符串终止点
 * @param len 目标字符串长度
 */
void expandCenter(char *s,int* st, int* ed,int len)
{
	while ((*st)>=0&&(*ed)<len&&(s[(*st)]==s[(*ed)]))
	{
		(*st)--;
		(*ed)++;
	}
	(*st)++;
	(*ed)--;
}
/* 寻找最长回文串

寻找回文中心然后尝试向左右扩展，如果遇到边界就停止扩展

 */
char * longestPalindrome(char * s){
	char *ans;
	int len=strlen(s);
	int st1,ed1,st2,ed2,st=0,ed=0;
	ans=malloc(sizeof(char)*len+1);
	for (int i = 0; i < len; i++)
	{
		st1=i;
		ed1=i;
		expandCenter(s,&st1,&ed1,len);//回文中心只有一个value例如aba
		st2=i;
		ed2=i+1;
		expandCenter(s,&st2,&ed2,len);//回文中心有2个字符例如abba
		if (ed-st<ed1-st1)//维护一个最长回文串的起点与终点
		{
			st=st1;
			ed=ed1;
		}
		if (ed-st<ed2-st2)
		{
			st=st2;
			ed=ed2;
		}
	}
	for (size_t i = 0; i < ed-st+1; i++)
	{
		ans[i]=s[st+i];
	}
	
	ans[ed-st+1]='\0';
	return ans;
}


int main(){
	char *s="bb",*ans;
	ans=longestPalindrome(s);
	printf("%s",ans);
}