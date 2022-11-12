#include <stdio.h>
#include <stdlib.h>
// 双指针
void reverseString(char* s, int sSize){
	int i=0,j=sSize-1;
	char t;
	while (i<j)
	{
		t=s[i];
		s[i]=s[j];
		s[j]=t;
		i++;
		j--;
	}
}
char * reverseWords(char * s){
	int i=0,j=0;
	while (s[i]!='\0')
	{
		if (s[i]==' ')
		{
			reverseString(s+j,i-j);
			j=i+1;
		}
		i++;
	}
	reverseString(s+j,i-j);
	return s;
}


void main(){
	char a[]="Let's take LeetCode contest",*b;
	b=reverseWords(a);
	printf("%s",b);
}