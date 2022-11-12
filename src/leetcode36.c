#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
	int row[9][9]={0};
	int col[9][9]={0};
	int cell[3][3][9]={0};
	int num;
	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < boardColSize[i]; j++)
		{
			char c=board[i][j];
			if (c!='.')
			{
				num=c-'0'-1;
				row[i][num]++;
				col[j][num]++;
				cell[i/3][j/3][num]++; 
				if (row[i][num]>1||col[j][num]>1||cell[i/3][j/3][num]>1)
				{
					return false;
				}
			}
		}
	}
	return true;	
}

int main()
{
	char **a;
	a=(char **){{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	int c[9]={9};
	bool ans;
	ans=isValidSudoku(a,9,c);
	printf("%d",ans);

}
