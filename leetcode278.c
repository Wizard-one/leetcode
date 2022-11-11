#include <stdbool.h>
#include <stdlib.h>
//#easy #二分
// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
	if(version>=2)
	{
		return true;
	}
	else
		return false;
}

int firstBadVersion(int n) {
    int l=1,r=n;
	while (l<r)
	{
		if(isBadVersion((l+r)/2))
		{
			r=(l+r)/2;
		}
		else
		{
			l=(l+r)/2+1;
		}
	}
	return l;
}

int main(){
	firstBadVersion(3);
}