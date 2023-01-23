//  Magic Grid Problem
// Send Feedback
// You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has 
// either a Hungarian horntail dragon that our intrepid hero has to defeat, or a flask of magic potion 
// that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points 
// from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j]. If his strength drops to 0 
//   or less at any point during his journey, Harry dies, and no magical stone can revive him.
// Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner 
//   cell (R,C). From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) 
//   or cell (i,j+1) and he can not move outside the magrid. Harry has used magic before starting his journey
//   to determine which cell contains what, but lacks the basic simple mathematical skill to determine what 
//   minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.
// Input Format :

// The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the
// first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 
// 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with S[i][j] < 0 contain 
// dragons, others contain magic potions.

// Output Format :

// Output T lines, one for each case containing the minimum strength Harry should start with from the cell 
// (1,1) to have a positive strength through out his journey to the cell (R,C).

// Constraints:

// 1 ≤ T ≤ 5

// 2 ≤ R, C ≤ 500

// -10^3 ≤ S[i][j] ≤ 10^3

// S[1][1] = S[R][C] = 0

// Sample Input

// 3
// 2 3
// 0 1 -3
// 1 -2 0
// 2 2
// 0 1
// 2 0
// 3 4
// 0 -2 -3 1
// -1 4 0 -2
// 1 -2 -3 0

// Sample Output

// 2
// 1
// 2


#include<bits/stdc++.h>
using namespace std;

int f(int si, int ei, int r, int c, int** grid){
    if(r==si && c==ei){
        return 1;
    }
    if(si>r || ei>c){
        return +1e9;
    }
    int path1 = f(si+1, ei, r, c, grid);
    if((si+1)<=r){
        path1 -= grid[si+1][ei];
    }

    int path2 = f(si, ei+1, r, c, grid);
    if((ei+1)<=c){
        path2 -= grid[si][ei+1];
    }
    if(path1<1){
        path1 = 1;
    }
    if(path2<1){
        path2 = 1;
    }
    
    return min(path1, path2);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int row, col;
        cin>>row>>col;
        int** grid = new int*[row];
        for(int i=0; i<row; i++){
            grid[i] = new int[col];
            for(int j=0; j<col; j++){
                cin>>grid[i][j];
            }
        }
        
        int** dp = new int*[row];
        for(int i=0;i<row; i++){
            dp[i] = new int[col];
            for(int j=0;j<col; j++){
                dp[i][j] = 0;
            }
        }
        dp[row-1][col-1] = 1;
        dp[row-2][col-1] = 1;
        dp[row-1][col-2] = 1;
        // int maxneg = 0;
        // int count = f(0, 0, row-1, col-1, grid);
        // if(count<0){
        //     count = 1;
        // }
        
        int count = 0;
        for(int i=col-3; i>=0; i--){
            if(grid[row-1][i+1]<0){
                dp[row-1][i] = dp[row-1][i+1] - grid[row-1][i+1];
            }
            else{
                dp[row-1][i] =max(1,dp[row-1][i+1] - grid[row-1][i+1]);
            }
            
        }
        for(int i=row-3; i>=0; i--){
            if(grid[i+1][col-1]<0){
                dp[i][col-1] = dp[i+1][col-1] - grid[i+1][col-1];
            }
            else{
                dp[i][col-1] =max(1, dp[i+1][col-1] - grid[i+1][col-1]);
            }
            
        }
        
        for(int i=row-2; i>=0; i--){
            for(int j=col-2; j>=0; j--){
                int v1, v2;
                if(grid[i+1][j]<0){
                    v1 = dp[i+1][j] - grid[i+1][j];
                }
                else{
                    v1 = max(1, dp[i+1][j] - grid[i+1][j]);
                }
                if(grid[i][j+1]<0){
                    v2 = dp[i][j+1] - grid[i][j+1];
                }
                else{
                    v2 = max(1,dp[i][j+1] - grid[i][j+1]);
                }
                // if(v1<1){
                //     v1 = 1;
                // }
                // if(v2<1){
                //     v2 = 1;
                // }
                dp[i][j] = min(v1, v2);
            }
        }
        int ans = dp[0][0];
        for(int i=0; i<row; i++){
            delete [] dp[i];
        }
        delete[] dp;
        cout<<ans<<endl;
        // cout<<count<<endl;
    }
    return 0;
}
