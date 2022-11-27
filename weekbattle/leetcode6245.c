#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int pivotInteger(int n){
	int x=sqrt((n*n+n)/2);
	if (2*x*x==n*n+n)
	{
		return x;
	}
	else
	{
		return -1;
	}
}

int main(){
	printf("%d",pivotInteger(4));
}