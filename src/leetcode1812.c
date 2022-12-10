#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*1812. 判断国际象棋棋盘中一个格子的颜色

k给你一个坐标 coordinates ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。下图是国际象棋棋盘示意图。
如果所给格子的颜色是白色，请你返回 true，如果是黑色，请返回 false 。

给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。
 */

/* 直接观察 */
bool squareIsWhite(char * coordinates){
	int c=coordinates[0]-'a',r=coordinates[1]-'1';
	if ((c+r)%2==0)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;	
}

int main(){
	char *a="a1";
	squareIsWhite(a);
}