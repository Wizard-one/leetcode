#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void addchar(int c,char* ans,int up,int k)
{
	if (c>9)
	{
		up=1;
		ans[k]='0'+c-10;
	}
	else
	{
		ans[k]='0'+c;
		up=0;
	}
}

// #字符串
char * addStrings(char * num1, char * num2){
	char *ansFilp;
	int len1=strlen(num1),len2=strlen(num2),maxlen,minlen,up=0;
	maxlen=(len1>len2)?(len1):(len2);
	ansFilp=malloc((maxlen+2)*sizeof(char));
	memset(ansFilp,'\0',(maxlen+2)*sizeof(char));
	int   i=len1-1,j=len2-1,k=0;
	while (i>=0&&j>=0)
	{
		int current=num1[i]+num2[j]-2*'0'+up;
		addchar(current,ansFilp,up,k);
		i--;
		j--;
		k++;
	}
	if (i<0)
	{
		while (j>=0)
		{
			int current=num2[j]+up-'0';
			addchar(current,ansFilp,up,k);
			k++;
			j--;
		}
	}
	else if (j<0)
	{
		while (i>=0)
		{
			int current=num1[i]+up-'0';
			addchar(current,ansFilp,up,k);
			k++;
			i--;
		}
	}
	if (up==1)
	{
		ansFilp[k]='1';
	}
	char *ans;
	int newlen=strlen(ansFilp);
	ans=malloc(sizeof(char)*(newlen+1));
	for (i = 0; i < newlen; i++)
	{
		ans[newlen-i-1]=ansFilp[i];
	}
	ans[newlen]='\0';
	return ans;	
}

int main()
{
	char *a="11",*b="123",*ans;
	ans=addStrings(a,b);
	printf("%s",ans);
}

