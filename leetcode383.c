#include <stdio.h>
#include <stdbool.h>

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