// Rat In A Maze Problem
// Send Feedback
// You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents 
// a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. 
// The rat can move in all the four directions: up, down, left and right.
// In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used 
// to move from source to destination cell.
// You have to print all the paths, following which rat can move from the top left cell to the bottom 
// right cell of the given binary matrix.
// Input Format
// The first line of input contains an integer, that denotes the value of N.
// Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
// Output Format :
// Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, 
// printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. 
// Please refer to sample test cases for more clarity.   
// Constraints
// 1 <= N <= 18
// 0 <= Number of cells with value 1 <= 15
// Time Limit: 1 second
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1

/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

void printOutput(int** output, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<output[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}

bool isSafe(int** input, int** output, int row,int col, int n){
    if(row<0 || row>n-1 || col>n-1 || col<0){
        return false;
    }
    if(input[row][col]==0){
        return false;
    }
    return true;
}
bool isPossible(int** output,int row, int col, int n ){
    if(row<0 || row>n-1 || col>n-1 || col<0){
        return false;
    }
    if(output[row][col]==1) return false;
    return true;
}

void getPath(int** input, int** output, int row, int col, int n){
    if(row==n-1 && col==n-1){
        output[row][col] = 1;
        printOutput(output, n);
        output[row][col] = 0;
        return;
    }
    
    if(isSafe(input, output, row, col, n)){
        output[row][col] = 1;
        
        if(isPossible(output, row-1, col, n)){
            getPath(input, output, row-1, col, n);
        }
        
        if(isPossible(output, row, col-1, n)){
            getPath(input, output, row, col-1, n);
        }
        
        if(isPossible(output, row+1, col, n)){
            getPath(input, output, row+1, col, n);
        }
        
        if(isPossible(output, row, col+1, n)){
            getPath(input, output, row, col+1, n);
        }
        output[row][col] = 0;
        
    }
    return;
}



int main() {

	// Write your code here
    
    int n;
    cin>>n;
    int** input = new int*[n];
    for(int i=0; i<n; i++){
        input[i] = new int[n];
        for(int j=0; j<n; j++){
            input[i][j] = 0;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int val;
            cin>>val;
            input[i][j] = val;
        }
    }
    
    int** output = new int*[n];
    for(int i=0; i<n; i++){
        output[i] = new int[n];
        for(int j=0; j<n; j++){
            output[i][j] = 0;
        }
    }
    
    getPath(input, output, 0, 0, n);
    
    
	return 0;
}
