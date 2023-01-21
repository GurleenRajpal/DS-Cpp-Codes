//  Maximum Square Matrix With All Zeros
// Send Feedback
// Given an NxM matrix that contains only 0s and 1s, find out the size of the 
// maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
// Input format :

// The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. 
// They represent the 'rows' and 'columns' respectively.

// Second-line onwards, the next 'N' lines or rows represent the ith row values.

// Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).

// Output Format:

// Print the size of maximum square sub-matrix.

//  Constraints :

// 0 <= N <= 10^4
// 0 <= M <= 10^4

// Time Limit: 1 sec

// Sample Input 1:

// 3 3
// 1 1 0
// 1 1 1
// 1 1 1

// Sample Output 1:

// 1

// Sample Input 2:

// 4 4
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0

// Sample Output 2:

// 4


#include <iostream>
using namespace std;

int f(int** arr, int n, int m){
    if(n==0 && m==0){
        if(arr[n][m]==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    
    int k = 0;
    int value = 0;
    for(int i=n; i>=0; i--){
        for(int j=m; j>=0; j--){
            k = 0;
            if(arr[i][j]==0){
                k = 0;
                int lenx = 0;
                int leny = 0;
                for(int x = i; x>=0; x--){
                    if(arr[x][j]==1) break;
                    else lenx++;
                }
                for(int y=j; y>=0; y--){
                    if(arr[i][y]==1) break;
                    else leny++;
                }
                
                
                int len = min(lenx, leny);  
                
                // for(int x = i, y = j, z=0; x>=0 && y>=0 && z<len; x--, y--, z++){
                //     if(x==0 && y==0 && z<len && arr[x][y]==0){
                //         k+=1;
                //     }
                //     else if((x-1>=0) && (y-1>=0) && arr[x-1][y]==0 && arr[x][y-1]==0 && arr[x-1][y-1]==0){
                //         k+=1;
                //     }
                // }
                k += len;
            }
            value = max(value, k);
        }
    }
    return value;
    
}

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    // int** dp = new int*[n];
    // for(int i=0;i<n;i++){
    //     dp[i] = new int[m];
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         dp[i][j] = 0;
    //     }
    // }
    if(n==0 || m==0) return 0;
    int dp[n][m] = {0};
    int ans = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i][0]==0){
            dp[i][0] = 1;
        }
        ans = max(ans, dp[i][0]);
    }
    
    for(int j=0;j<m;j++){
        if(arr[0][j]==0){
            dp[0][j] = 1;
        }
        ans = max(ans, dp[0][j]);
    }
    
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]==0){
                dp[i][j] = 1 + min(dp[i-1][j], min (dp[i][j-1], dp[i-1][j-1]));
            }
            else{
                dp[i][j] = 0;
            }
            ans = max(dp[i][j], ans);
        }
    }
    
    return ans;
    
}



int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
