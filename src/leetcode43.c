#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// #字符串 #模拟 #数学 O(mn) [[415]]
/* 
乘法可以视为两个序列按位卷积,最优的方法是FFT

最朴素的想法就是模拟竖式乘法,但是没能在规定时间内写出来
 */
char * multiply(char * num1, char * num2){
	int *ansi;//将临时结果存在一个数组中
	char *ans;//最终结果转换为字符串
	int l1=strlen(num1),l2=strlen(num2);//获取长度
	ansi=malloc(sizeof(int)*(l1+l2));//最终结果长度不超过两者长度之和 例如 9*9=81
	memset(ansi,0,sizeof(int)*(l1+l2));
	ans=malloc(sizeof(char)*(l1+l2+1));//最后存一个'\0'
	if (num1[0]=='0'||num2[0]=='0')
	{
		// 单独处理输入0的情况
		ans[0]='0';
		ans[1]='\0';
		return ans;
	}
	for (int i = l1-1; i >= 0; i--)
	{
		int n1,n2;
		n1=num1[i]-'0';
		for (int j = l2-1; j >=0; j--)
		{
			n2=num2[j]-'0';
			ansi[i+j+1]+=n2*n1;//num[i]*num[j] 结果从ans末尾开始存储 这就对应存储到 i+j+1处, 因为 l1-1+l2-1+1=l1+l2-1
			ansi[i+j]+=ansi[i+j+1]/10;//存在进位直接存放到上一位
			ansi[i+j+1]=ansi[i+j+1]%10;//当前位保存就是求余的结果
		}
	}
	int len=0;
	// 去除开头0
	if (ansi[0]==0)
	{
		for (size_t i = 1; i < l1+l2; i++)
		{
			ans[i-1]=ansi[i]+'0';
			len++;
		}
	}
	else
	{
		for (size_t i = 0; i < l1+l2; i++)
		{
			// 将数组转换为字符串
			len++;
			ans[i]=ansi[i]+'0';
		}
	}
	
	ans[len++]='\0';
	return ans;
	
}

int main(){
	char *a="1",*b="4",*ans;
	ans=multiply(a,b);
	printf("%s",ans);

}