#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int appendCharacters(char * s, char * t){
	int lent=strlen(t);
	int i=0,j=0;
	while (t[i]!='\0'&&s[j]!='\0')
	{
		if (t[i]==s[j])
		{
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	return lent-i;
}

int main(){
	char *a="z",*b="abcde";
	printf("%d",appendCharacters(a,b));
}