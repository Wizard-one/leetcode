#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #字符串 #栈 

char * minRemoveToMakeValid(char * s){
	int len=strlen(s),top=0,*stackidx;
	char *ans,*stack;
	stack=malloc(sizeof(char)*len);//记录入栈的括号是什么
	stackidx=malloc(sizeof(int)*len);//记录入栈括号的idx
	memset(stackidx,-1,sizeof(int));//将入栈idx统一设置为-1
	ans=malloc(sizeof(char)*len+1);//结果存放多一位'\0'
	for (size_t i = 0; i < len; i++)
	{
		if (s[i]=='(')
		{
			stackidx[top]=i;//假定一切'('入栈时都为非法字符
			stack[top]='(';
			top++;
		}
		else if (s[i]==')')
		{
			if(top!=0 && stack[top-1]=='(')//如果存在'('与')'匹配将'('弹栈
			{
				stack[top-1]=0;
				stackidx[top-1]=-1;
				top--;
			}			
			else { 
				// 其他情况都是让')'入栈,因为必然非法
				stack[top]=')';
				stackidx[top]=i;
				top++;
			}
		}		
	}
	int k=0,bottom=0;
	// 字符串存放
	for (size_t i = 0; i < len; i++)
	{
		// 从栈底开始搜索,当前索引为栈内的非法字符
		if (i==stackidx[bottom])
		{
			bottom++;//跳过存储,从栈底出队
		}
		else
		{
			ans[k++]=s[i];//其他情况都存储,例如i<stackidx[bottom]说明前面都是合法字符 i>stackidx[bottom] 说明没有非法字符了
		}
	}
	ans[k++]='\0';
	return ans;
}

int main(){
	char *s="))((",*ans;
	ans=minRemoveToMakeValid(s);
	printf("%s",ans);
}