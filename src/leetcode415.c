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

// #字符串 #模拟 [[43]]
/* 
位数短的使用补零的技巧
 */
char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char* ans = (char*)malloc(sizeof(char) * (fmax(i, j) + 3));
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = (i >= 0 ? num1[i] - '0' : 0);
        int y = (j >= 0 ? num2[j] - '0' : 0);
        int result = x + y + add;
        ans[len++] = '0' + result % 10;
        add = result / 10;
        i--, j--;
    }
    // 计算完以后的答案需要翻转过来
    for (int i = 0; 2 * i < len; i++) {
        int t = ans[i];
        ans[i] = ans[len - i - 1], ans[len - i - 1] = t;
    }
    ans[len++] = 0;
    return ans;
}


int main()
{
	char *a="11",*b="123",*ans;
	ans=addStrings(a,b);
	printf("%s",ans);
}

