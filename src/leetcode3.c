#include <stdio.h>
#include <stdlib.h>
//#fail hash 表没做好

// #hash #字符串
#define IMAX(a,b) ((a)>(b)?(a):(b))
/* 无重复字符的最长子串
 */

// 要看清楚字符串的范围，如果范围包含大小写字母，空格，符号，那不如直接将hash表设置为129 存储ASCII码所有范围的字符。
int hash(char s)
{
	if (s>='a'&&s<='z')
	{
		return s-'a';
	}
	else if (s>='A'&&s<='Z')
	{
		return 26+s-'A';
	}
	else if (s>='0'&&s<='1')
	{
		return 52+s-'0';
	}
	else if(s==' ')
	{
		return 62;
	}
	return -1;
}

int lengthOfLongestSubstring(char * s){
	int lenmax=0,len=0,f=0,b=0,k=0;
	int table[63]={0};
	while (s[f]!='\0')
	{
		k=hash(s[f]);
		table[k]++;
		for (size_t i = b; i <=f; i++)
		{
			if (table[hash(s[i])]>1)
			{
				len=f-b;
				lenmax=IMAX(len,lenmax);
				table[hash(s[b])]=0;
				b++;
			}
		}
		f++;
	}
	len=f-b;
	lenmax=IMAX(len,lenmax);
	return lenmax;
		
}

int main(){
	int ans;
	char *t3="pwwkew";
	ans=lengthOfLongestSubstring(t3);
	printf("%d",ans);
}