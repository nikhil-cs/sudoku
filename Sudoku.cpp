#include<stdio.h>
using namespace std;
//I used "0" as value for unassgined location


/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
   
bool findUnassignedLocation(int grid[9][9], int &row, int &col)
{
	for(row=0;row<9;row++)
	{
		for(col=0;col<9;col++)
		{
			if(grid[row][col] == 0)
				return true;
		}
	}
	return false;
}

//check whether num is present in specified row or not
bool usedInRow(int grid[9][9], int row, int num)
{
	for(int col=0;col<9;col++)
		if(grid[row][col]==num)
			return true;
	return false;
}

//check whether num is present in specified column or not
bool usedInCol(int grid[9][9], int col, int num)
{
	for(int row=0;row<9;row++)
		if(grid[row][col]==num)
			return true;
	return false;
}

//check whether num is present in specified box or not
bool usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
	for(int row=0;row<3;row++)
		for(int col=0 ; col<3; col++)
			if(grid[row+boxStartRow][col+boxStartCol] == num)
				return true;
	return false;
}

//return boolean to indicate whether it will safe to assign "num" to given location or not
bool isSafe(int grid[9][9], int row, int col, int num)
{
	//check if num is not placed already in row,col and currnt 3*3 box
	return  !usedInRow(grid,row,num)&&
			!usedInCol(grid,col,num)&&
			!usedInBox(grid, row-row%3 , col-col%3 , num);
			
}

/*Takes partialy filled grid and attempts to assign values to
all unassigned location in such a way to meet the requirements
for Sudoku solution*/
bool solveSudoku(int grid[9][9])
{
	int row, col;
	
	//If there is no unassigned location, we are done
	if(!findUnassignedLocation(grid,row,col))
		return true;
		
	//consider digits 1 to 9
	for(int num=1; num<=9; num++)
	{
		if(isSafe(grid,row,col,num))
		{
			//make tentative assignment
			grid[row][col] = num;
			
			//return if success
			if(solveSudoku(grid))
				return true;
				
			//failure, unmake & try agailn
			grid[row][col] = 0;
		}
	}
	
	return false; //this triggers backtracking
}
int main()
{
	int grid[9][9];/* = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};*/
    printf("Enter values of partilay solved grid\n");               
	for (int row = 0; row < 9; row++)
	    {
	       for (int col = 0; col < 9; col++)
	            scanf("%d", &grid[row][col]);
	    }
                      
    if(solveSudoku(grid) == true)
    {
    	for (int row = 0; row < 9; row++)
	    {
	       for (int col = 0; col < 9; col++)
	             printf("%2d", grid[row][col]);
	        printf("\n");
	    }
	}
	else
		printf("No solution exists");
	return 0;
}

