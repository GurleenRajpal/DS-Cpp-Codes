// Sudoku Solver
// Send Feedback
// Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values 
// lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
// You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
// Input Format:
// There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
// Output Format:
// The first and only line of output contains boolean value, either true or false, as described in problem statement.
// Constraints:
// The cell values lie in the range: [0, 9]
// Time Limit: 1 second 
// Note:
// Input are given in a way that backtracking solution will work in the provided time limit.
// Sample Input 1:
// 9 0 0 0 2 0 7 5 0 
// 6 0 0 0 5 0 0 4 0 
// 0 2 0 4 0 0 0 1 0 
// 2 0 8 0 0 0 0 0 0 
// 0 7 0 5 0 9 0 6 0 
// 0 0 0 0 0 0 4 0 1 
// 0 1 0 0 0 5 0 8 0 
// 0 9 0 0 7 0 0 0 4 
// 0 8 2 0 4 0 0 0 6
// Sample Output 1:
// true

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int sudoku[9][9], int row, int col, int num){
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==num) return false;
        if(sudoku[i][col]==num) return false;
    }
    
    int pi = row%3;
    int pj = col%3;
    
    int startRow = row - row % 3, startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[i + startRow][j + startCol] == num)
                return false;
    
    return true;
    
}


bool solver(int sudoku[9][9], int row, int col){
    if(row==8 && col==9){
        return true;
    }
    
    if(col==9){
        row++;
        col = 0;
    }
    
    if(sudoku[row][col]>0){
        return solver(sudoku, row, col+1);
    }
    
    for(int i=1;i<=9; i++){
        if(isSafe(sudoku, row, col, i)){
            sudoku[row][col] = i;
            if(solver(sudoku, row, col+1)){
                return true;
            }
        }
        sudoku[row][col] = 0;
    }
    return false;
}


int main(){
    
    // write your code here
    int n = 9;
    
    int sudoku[9][9] = {0};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>sudoku[i][j];
        }
    }
    
   if(solver(sudoku, 0, 0)){
       cout<<"true"<<endl;
   }
   else{
       cout<<"false"<<endl;
   }
    
    
    return 0;
}
