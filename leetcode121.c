#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
	int ma=0,mi=prices[0];
	for (size_t i = 0; i < pricesSize; i++)
	{
		mi=fmin(prices[i],mi);
		ma=fmax(prices[i]-mi,ma);
	}
	return ma;
}

int main(){
	int a[6]={7,1,5,3,6,4},d;
	d=maxProfit(a,6);
	printf("%d\n",d);
	return 0;
}