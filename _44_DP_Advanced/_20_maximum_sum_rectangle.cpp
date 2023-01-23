// Maximum Sum Rectangle
// Send Feedback
// Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// First line contains 2 numbers n and m denoting number of rows and number of columns. Next 
// n lines contain m space separated integers denoting elements of matrix nxm.
// Output Format:
// Output a single integer, maximum sum rectangle for each test case in a newline.
// Constraints
// 1 <= T <= 50
// 1<=n,m<=100
// -10^5 <= mat[i][j] <= 10^5
// Sample Input
// 1
// 4 5
// 1 2 -1 -4 -20
// -8 -3 4 2 1
// 3 8 10 1 3
// -4 -1 1 7 -6
// Sample Output
// 29

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        int** a = new int*[m];
        for(int i=0; i<m; i++){
            a[i] = new int[n];
            for(int j=0; j<n; j++){
                cin>>a[i][j];
            }
        }
		
        int* sum = new int[m];
        for(int i=0; i<m; i++){
            sum[i] = 0;
        }
        int best = 0;
        
        for(int l=0; l<n; l++){
            for(int i=0; i<m; i++){
            	sum[i] = 0;
        	}
            for(int r=l; r<n; r++){
                for(int i=0; i<m; i++){
                    sum[i] = sum[i]+a[i][r];
                }
               	int current_sum = 0;
                int best_sum = 0;
                for(int i=0; i<m; i++){
                    current_sum = current_sum + sum[i];
                    if(best_sum<current_sum){
                        best_sum = current_sum;
                    }
                    if(current_sum<0){
                        current_sum = 0;
                    }
                }
                best = max(best_sum, best);
            }
        }
        cout<<best<<endl;
        
    }
    return 0;
}
