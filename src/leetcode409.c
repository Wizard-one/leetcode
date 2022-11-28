#include <stdlib.h>
#include <stdio.h>

// #字符串 #hash
int longestPalindrome(char * s){
	int table[57]={0},i=0;//A-z 中间一共58位，还有几个符号
	while (s[i]!='\0')
	{
		table[s[i]-'A']++;
		i++;
	}
	int count=0,ord=-1;
	for (i = 0; i < 57; i++)
	{
		if (table[i]%2==0)
		{
			count+=table[i];
		}
		else
		{
			count+=table[i]-1;
			ord=i;
		}
	}
	if (ord!=-1)
	{
		count++;
	}
	return count;
}
