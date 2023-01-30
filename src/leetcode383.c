#include <stdio.h>
#include <stdbool.h>


/* 
383. 赎金信
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。 */

/* 简单hash表 */
// #字符串
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

bool canConstruct(char * ransomNote, char * magazine){
	int r[26]={0},m[26]={0};
	hash(r,ransomNote);
	hash(m,magazine);
	for (size_t i = 0; i < 26; i++)
	{
		if(r[i]>m[i])
			return false;
	}
	return true;
}

int main(){
	char *a="a",*b="ba";
	int ans;
	ans=canConstruct(a,b);
	printf("%d",ans);
}