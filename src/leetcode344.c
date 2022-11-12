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

void main(){
	char a[6]={'H','a','n','n','a','h'};
	reverseString(a,6);
	printf("%s",a);
}