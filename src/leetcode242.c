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
