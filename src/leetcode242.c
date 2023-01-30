#include <stdio.h>
#include <stdbool.h>
/* 242. 有效的字母异位词

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 */

/* 直接hash表 */
void hash(int * ord,char * str)
{
	int i=0,v;
	while (str[i]!='\0')
	{
		v=str[i]-'a';
		ord[v]++;
		i++;
	} 
}

bool isAnagram(char * s, char * t){
	int r[26]={0},m[26]={0};
	hash(r,s);
	hash(m,t);
	for (size_t i = 0; i < 26; i++)
	{
		if(r[i]!=m[i])
			return false;
	}
	return true;
}
