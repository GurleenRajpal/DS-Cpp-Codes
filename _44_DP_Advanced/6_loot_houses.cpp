//  Loot Houses
// Send Feedback
// A thief wants to loot houses. He knows the amount of money in each house. He 
// cannot loot two consecutive houses. Find the maximum amount of money he can loot.
// Input Format :

// The first line of input contains a single integer N denoting the total number of houses.

// The second line of input contains N single space-separated integers, denoting 
// the amount of money in every i-th house.

// Output Format :

// The only line of output will print the maximum amount of loot that is possible.

// Input Constraints

// 0 <= N <= 10^5
// 0 <= A[i] <= 10^4

// Where N is the total number of houses.
// A[i] represents the money present in the i-th house.

// Time limit: 1sec

// Sample Input 1:

// 6
// 5 5 10 100 10 5

// Sample Output 1 :

// 110

// Sample Input 2:

// 4
// 10 2 3 11

// Sample Output 2 :

// 21

// Explanation to Sample Input 2:

// Since the thief cant loot two consecutive houses, the ways in which he may loot are:

// 1. [10, 3]: a total loot of 13
// 2. [10, 11]: a total loot of 21
// 3. [2, 11]: a total loot of 13
// 4. [10]: a total loot of 10
// 5. [2]: a total loot of 2
// 6. [3]: a total loot of 3
// 7. [11]: a total loot of 11

// We can't neglect the option to loot just either of the houses if it yields the maximum loot.

// From all the possible seven ways, the second option yields the maximum loot amount and hence the answer.

#include<bits/stdc++.h>
using namespace std;

int f(int* a, int n, int* dp){
    if(n==0){
        return a[0];
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1)return dp[n];
    
    int pick = a[n]+f(a, n-2, dp);
    int notPick = f(a, n-1, dp);
    
    return dp[n]=max(pick, notPick);
    
}

int main(){
    
    // write your code here
    int n;
    cin>>n;
    int a[n];
    int* dp = new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i]=-1;
    }
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans = f(a, n-1, dp);
    cout<<ans<<endl;
    return 0;
}
