// N-Queen Problem
// Send Feedback
// You are given N, and for a given N x N chessboard, find a way to place N queens such 
// that no queen can attack any other queen on the chess board. A queen can be killed when it lies 
// in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
// Note: Don't print anything if there isn't any valid configuration.
// Input Format:
// The first line of input contains an integer, that denotes the value of N.     
// Output Format :
// In the output, you have to print every board configuration in a new line. Every configuration will 
// have N*N board elements printed row wise and are separated by space. The cells where queens are safe and 
// placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.
// Constraints :
// 1 <= N <= 10
// Time Limit: 1 second
// Sample Input 1:
// 4
// Sample Output 1 :
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& board){
    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(board[row][col]==1) return false;
        row--;
        col--;
    }
    
    row = x;
    col = y;
    
    while(col>=0){
        if(board[row][col]==1) return false;
        col--;
    }
    
    row = x;
    col = y;
    
    while(row<n && col>=0){
        if(board[row][col]==1) return false;
        row++;
        col--;
    }
    
    return true;
    
}


void solve(int index, vector<vector<int>>& board, vector<vector<int>>& ans){
    if(index==board.size()){
        vector<int> k;
        for(int i=0; i<index; i++){
            for(int j=0; j<index; j++){
                k.push_back(board[j][i]);
            }
        };
        ans.push_back(k);
        return;
    }
    int n = board.size();
    for(int i=0; i<n; i++){
        if(isSafe(i, index, n, board)){
            board[i][index] = 1;
            solve(index+1, board, ans);
            board[i][index] = 0;
        }
    }
    
    return;
    
}

int main(){
    
    // write your code here
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, board, ans);
    //reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
