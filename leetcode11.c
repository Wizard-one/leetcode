// #双指针 #mid
#define IMAX(a,b) ((a)<(b)?(b):(a))
int maxArea(int* height, int heightSize){
	int l=0,r=heightSize-1,maxa=0;
	while (l!=r)
	{
		if (height[l]>height[r])
		{
			maxa=IMAX(maxa,(r-l)*height[r]);
			r--;
		}
		else
		{
			maxa=IMAX(maxa,(r-l)*height[l]);
			l--;
		}
	}
	return maxa;
}