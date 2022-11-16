#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#滑动窗 #hash表
bool checkEQ(int* t1,int* t2)
{
	for (size_t i = 0; i < 26; i++)
	{
		if (t1[i]!=t2[i])
		{
			return false;
		}
	}
	return true;
}

void GetTable(char *s,int len,int* table)
{
	for (size_t i = 0; i < len; i++)
	{
		table[s[i]-'a']++;
	}
}

bool checkInclusion(char * s1, char * s2){
	int n=strlen(s1),m=strlen(s2);
	if (m<n)
	{
		return false;
	}
	
	int f=n-1,p=0;
	int table1[26]={0},table2[26]={0};
	GetTable(s1,n,table1);
	GetTable(s2,n,table2);
	if (checkEQ(table1,table2))
	{
		return true;
	}
	while (s2[f]!='\0')
	{	
		if (checkEQ(table1,table2))
		{
			return true;
		}
		else
		{
			table2[s2[p]-'a']--;
			f++;
			p++;
			if(s2[f]!='\0')
				table2[s2[f]-'a']++;
		}
	}
	return false;
}

void test(char *s1,char *s2)
{
	bool ans;
	ans=checkInclusion(s1,s2);
	printf("%d",ans);
}

int main(){
	char *s1="ab",*s2="eidbaooo";
	char *s3="abca",*s4="rbabca",*s5="rbaac";
	char *s6="rbsasc";
	test(s1,s2);
	test(s1,s3);
	test(s1,s4);
	test(s1,s5);
	test(s1,s6);
	char *s="adc";
	char *s7="dcda";
	test(s,s7);
}