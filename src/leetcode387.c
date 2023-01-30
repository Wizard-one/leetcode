#include <stdio.h>
// #hash #string
// 387. 字符串中的第一个唯一字符
int firstUniqChar(char * s){
	int ord[26]={0},i=0,v;
	while (s[i]!='\0')
	{
		v=s[i]-'a';
		ord[v]++;
		i++;
	}
	i=0;
	while(s[i]!='\0')
	{
		v=s[i]-'a';
		
		if (ord[v]==1)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int main(){
	char *a="loveleetcode";
	int ans;
	ans=firstUniqChar(a);
	printf("%d",ans);
}