// Miser Man
// Send Feedback
// Jack is a wise and miser man. Always tries to save his money.
// One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) 
// and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, 
// fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
// 1. At every city, he has to change the bus.
// 2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
// You are to help Jack to go from A to B by spending the minimum amount of money.
// Input Format:
// First-line will contain T(number of the test case), each test case follows as.
// First-line will contain two space-separated integers N and M.
// Next, N rows will contain M space-separated integers denoting the elements of the grid.
// Each row lists the fares the M busses to go form the current city to the next city.
// Output Format:
// For each test case print the minimum amount of fare that Jack has to give in a newline.
// Constraints:
// 1 <= T <= 100
// 1 <= N, M <= 100
// 1 <= arr[i][j] <= 10^5
// Sample Input
// 1
// 5 5
// 1 3 1 2 6
// 10 2 5 4 15
// 10 9 6 7 1
// 2 7 1 5 3
// 8 2 6 1 9
// Sample Output
// 10
// Explanation:
// 1 -> 4 -> 1 -> 3 -> 1: 10
// This is marked and shown in the following image: 

#include<bits/stdc++.h>
using namespace std;

int f(int** maze, int row, int col, int n, int m){
    if(row==n-1 && col<m && col>=0){
        return maze[row][col];
    }
    if(row<0 || col<0 || row>=n || col>=m){
        return 1e9;
    }
    
    int path1 = maze[row][col] + f(maze, row+1, col, n, m);
    int path2 = maze[row][col] + f(maze, row+1, col+1, n, m);
    int path3 = maze[row][col] + f(maze, row+1, col-1, n, m);
    
    return min(path1, min(path2, path3));
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int** maze = new int*[n];
        int** dp = new int*[n];
        for(int i=0; i<n; i++){
            maze[i] = new int[m];
            //dp[i] = new int[m];
            for(int j=0; j<m; j++){
                cin>>maze[i][j];
                //dp[i][j] = -1;
            }
        }
        
        for(int i=0; i<n; i++){
            dp[i] = new int[m];
            for(int j=0; j<m; j++){
                dp[i][j] = -1;
            }
        }
        
        
        int ans  = 1e9;
        // for(int i=0; i<m; i++){
        //     ans = min(ans, f(maze, 0, i, n, m));
        // }
        for(int i=0; i<m; i++){
            dp[n-1][i] = maze[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int path1 = maze[i][j] + dp[i+1][j];
                int path2 = 1e9;
                if((j+1)<m){
                    path2 = maze[i][j] + dp[i+1][j+1];
                }
                int path3 = 1e9;
                if((j-1)>=0){
                    path3 = maze[i][j] + dp[i+1][j-1];
                }
    			dp[i][j] = min(path1, min(path2, path3));
            }
        }
        
        for(int i=0; i<m; i++){
            ans = min(ans, dp[0][i]);
        }
        
        
        cout<<ans<<endl;
    }
    return 0;
}
