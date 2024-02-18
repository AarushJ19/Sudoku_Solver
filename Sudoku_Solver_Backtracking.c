#include <stdio.h>
#include <stdlib.h>

#define N 9

void print(int arr[N][N]) {
	int i,j;
	for(i=0; i<N; i++)
	{
		for(j=0;j<N;j++)
		{
printf("%d", arr[i][j]);
printf(",");
		}
		printf("\n");
	}	
}

int issafe(int grid[N][N], int row, int col, int num)
{
	int i,j;
	
	//for check of similar number in row
	for(i=0; i<=8; i++)
	{
		if(grid[row][i] == num)
		return 0;
	}
	
	//for check of similar number in a col
	for(i=0;i<=8;i++)
	{
		if(grid[i][col] == num)
		return 0;
	}
	
	int startrow = row - row%3;
	int	startcol = col - col%3;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++){
			if(grid[i+startrow][j+startcol]==num )
			{
				return 0;
			}
		}
	}
	
	return 1;
}

int solvesudoku(int grid[N][N], int row, int col)
{
	int num;
	 if(row == N-1 && col==N )
	 return 1;
	 
	 if(col==N)
	 {
	 	row++;
	 	col=0;
	 }
	 
	 if(grid[row][col] > 0)
	 {
	 	return solvesudoku(grid,row,col+1);
	  } 

	for( num=1; num<=N; num++)
	{
		if(issafe(grid,row,col,num)==1)
		{
			grid[row][col] = num;
			
			if(solvesudoku(grid,row,col+1)==1)
			{
			return 1;
		}
		}
		
		grid[row][col] = 0;
	}
	return 0;
}

int main() {
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
                       
                 
        if(solvesudoku(grid,0,0)==1){
        print(grid);
	 	}
        else{
        printf("no solution");
	    }
        return 0;
 
}


