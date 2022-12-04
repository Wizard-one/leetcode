#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}
// #字符串 [[1249]] #栈

/* 20. 有效的括号
判断括号匹配是否有效
 */
bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) {
        // 字符串总长度为奇数当然非法
        return false;
    }
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) {
        char ch = pairs(s[i]);//返回匹配的右括号
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                // 右括号入栈时栈为空 或者栈顶与当前入栈的括号不匹配
                return false;
            }
            top--;//括号匹配就弹栈
        } else {
            // 输入的是左括号,入栈
            stk[top++] = s[i];
        }
    }
    return top == 0;
}

int main()
{
	char *s="[{}{]}";
	bool ans;
	ans=isValid(s);
	printf("%d",ans);
}