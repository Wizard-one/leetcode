#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//#字符串 #暴力解法 O(n^2)

bool isPal(char *s,int st, int ed)
{
	int len=ed-st+1;
	for (size_t i = 0; i <=len/2; i++)
	{
		if (s[st+i]!=s[ed-i])
		{
			return false;
		}
	}
	return true;
}

char * longestPalindrome(char * s){
	char *ans;
	int maxlen=0,len=strlen(s);
	ans=malloc(sizeof(char)*len+1);
	for (int i = 0; i < len; i++)
	{
		for (int j = len-1; j >=i; j--)
		{
			bool flag=isPal(s,i,j);
			if (j-i+1>maxlen && flag)
			{
				maxlen=j-i+1;
				for (int k = 0; k < maxlen; k++)
				{
					ans[k]=s[i+k];
				}
			}
		}		
	}
	ans[maxlen]='\0';
	return ans;
}


int main(){
	char *s="ac",*ans;
	ans=longestPalindrome(s);
	printf("%s",ans);
}