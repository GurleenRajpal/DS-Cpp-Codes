//  Loot Houses
// Send Feedback
// A thief wants to loot houses. He knows the amount of money in each house. 
// He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
// Input format :

// The first line of input contains an integer value of 'n'. It is the total number of houses.

// The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

// Output format :

// Print the the maximum money that can be looted.

// Constraints :

// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec

// Sample Input 1 :

// 6
// 5 5 10 100 10 5

// Sample Output 1 :

// 110

// Sample Input 2 :

// 6
// 10 2 30 20 3 50

// Sample Output 2 :

// 90

// Explanation of Sample Output 2 :

// Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all 
// the other possible combinations would result in less than 90.

#include <iostream>
using namespace std;

int helper(int* arr, int n, int index, int* dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1) return dp[index];
    int pick = arr[index] + helper(arr, n, index+2, dp);
    int notPick = 0 + helper(arr, n, index+1, dp);
    
    return dp[index] = max(pick, notPick);
    
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    //base case
    
    
    //case 1 and case 2
    
    int* dp = new int[n];
    for(int i=0;i<n;i++){
        dp[i] = -1;
    }
    //return max of case 1 and case 2
    return helper(arr, n, 0, dp);
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}
