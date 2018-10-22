#include<iostream>
using namespace std;
bool checkRow(int arr[9][9],int row,int num)  //Objective: To find whether a number is present in specified row
{                                            //Input:sudoku represented by arr[9][9],row and number to be searched in that row
                                            //Return Value:boolen value       
    for (int i=0;i<9;i++)
    {
        if(arr[row][i]==num)             //Approach: number is linearly searched in that row  
        {
        return true;                                           
        }
	}
    return false;
}

bool checkCol(int arr[9][9], int col, int num)   //Objective: To find whether a number is present in specified column
{ 												//Input:sudoku represented by arr[9][9],row and number to be searched in that row
    for (int row = 0; row < 9; row++)          //Return Value:boolen value  
    {                                             
		if(arr[row][col] == num) 
        return true;                          //Approach: number is linearly searched in that row
	}
    return false; 
} 

bool UsedInBox(int arr[9][9], int boxStartRow, int boxStartCol, int num) //Objective: To find whether a number is present in specified block
{ 																		//Input:sudoku represented by arr[9][9],block starting row and staring column and 
																	   //number to be searched in that row
    for(int row = 0; row < 3; row++) 								  //Return Value:boolen value  
        for (int col = 0; col < 3; col++) 
            if (arr[row+boxStartRow][col+boxStartCol] == num)  //Approach: number is linearly searched in that block
                return true; 
    return false; 
} 
  
bool FindUnassignedLocation(int arr[9][9], int &row, int &col) //Objective:To find a location filled with 0
{                                                             //Input:arr[9][9],row,column
    for (row = 0; row < 9; row++) 							 //Return value:boolen value (if true then reflect row and col which contains 0)
        for (col = 0; col < 9; col++) 
            if (arr[row][col] == 0) 
                return true;                               //Approach:0 is linearly searched in arr[9][9] 
    return false; 
} 

bool SolveSudoku(int arr[9][9]) 
{ 
    int row, col;  
    if (!FindUnassignedLocation(arr,row,col)) //entire sudoku filled with numbers 1 to 9
    return true;  
  
    for (int num = 1; num <= 9; num++) 
    {  
        if (!checkRow(arr, row, num) && 
           !checkCol(arr, col, num) && 
           !UsedInBox(arr, row - row%3 , col - col%3, num) ) //a number that is not in same row column or in that block
        { 
        arr[row][col] = num; /* Do the same thing again recursively. If we go through all of the recursions, and in the end 
			                return true, then all of our number placements on the Soduko grid are valid and we have fully solved*/
		

  		if (SolveSudoku(arr))  
            return true; 
  		else
		arr[row][col] = 0; /*we have places an invalid number somewhere.make it 0 first and then try diffrent
		                   number for that particular location*/
		} 
    } 
    return false;/* backtrack if all possible numbers are tried for that location but solution is not correct
	              try a different number for the previous unassigned locations.*/
	
} 
  
void display(int arr[9][9])                           //Objective:To display sudoku
{                                                     //Input:arr[9][9]
	for(int i = 0; i < 9; i++)                        //Return value:none
    {  cout<<"\n";
     	for (int j = 0; j < 9; j++)
        {
	   	cout << arr[i][j] << " ";
   		}
	}
}
int main()
{
	int arr[9][9]=
	{
    { 0, 0, 8, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 6, 9, 2, 0, 0, 0, 3 },
    { 9, 0, 0, 0, 0, 6, 0, 0, 0 },
    { 2, 6, 0, 0, 0, 7, 0, 0, 0 },
    { 0, 1, 0, 5, 9, 4, 0, 6, 0 },
    { 0, 0, 0, 6, 0, 0, 0, 1, 9 },
    { 0, 0, 0, 3, 0, 0, 0, 0, 4 },
    { 6, 0, 0, 0, 1, 8, 5, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 0, 0 },
    };
  	display(arr);
  	cout<<"\n\n\n";
  	
	if (!SolveSudoku(arr))
    cout<<"No solution exists";
	else
    display(arr);      
	return 0;
}
