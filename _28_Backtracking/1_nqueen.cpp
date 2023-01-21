// N-Queen Problem
// Send Feedback
// You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A 
// queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
// Note: Don't print anything if there isn't any valid configuration.
// Input Format:
// The first line of input contains an integer, that denotes the value of N.     
// Output Format :
// In the output, you have to print every board configuration in a new line. Every configuration will 
// have N*N board elements printed row wise and are separated by space. The cells where queens are safe and 
//   placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample 
//   test cases for more clarity.
// Constraints :
// 1 <= N <= 10
// Time Limit: 1 second
// Sample Input 1:
// 4
// Sample Output 1 :
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
// Explanation:
// The first and second configuration are shown in the image below. Here, 1 denotes the placement of a 
// queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other. 

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **board, int row, int col, int n){
    
    int i = row;
    int j = col;
    
    while(i>=0 && j>=0){
        if(board[i][j]==1) return false;
        i--;
        j--;
    }
    
    i = row;
    j = col;
    
    while(j>=0){
        if(board[i][j]==1) return false;
        j--;
    }
    
    i = row;
    j = col;
    
    while(i<n && j>=0){
        if(board[i][j]==1) return false;
        i++;
        j--;
    }
    
    i = row;
    j = col;
    
    while(i>=0){
        if(board[i][j]==1) return false;
        i--;
    }
    
    i = row;
    j = col;
    
    while(i>=0 && j<n){
        if(board[i][j]==1) return false;
        i--;
        j++;
    }
    
    return true;
    
}

void nqueen(int** board, int row, int n){
    if(row==n){
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    // if(col==(n-1){
    //     row = row+1;
    //     col = 0;
    // }
    
	
    for(int i=0; i<n; i++){
        if(isSafe(board, row, i, n)){
            board[row][i] = 1;
            nqueen(board, row+1, n);
            board[row][i] = 0;
        }
    }
    
}

int main(){
    
    // write your code here
    int n;
    cin>>n;
    
    vector<vector<int>> ans;
    int** board = new int*[n];
    for(int i=0; i<n; i++){
        board[i] = new int[n];
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    
    nqueen(board, 0, n);
    
    
    return 0;
}
