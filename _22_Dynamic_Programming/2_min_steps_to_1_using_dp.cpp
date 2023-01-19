// Code : Min Steps to 1 using DP
// Send Feedback
// Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to 
// get reduced to 1. You can perform any one of the following 3 steps:
// 1.) Subtract 1 from it. (n = n - ­1) ,
// 2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// 3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
// Input format :
// The first and the only line of input contains an integer value, 'n'.
// Output format :
// Print the minimum number of steps.
// Constraints :
// 1 <= n <= 10 ^ 6
// Time Limit: 1 sec
// Sample Input 1 :
// 4
// Sample Output 1 :
// 2 
// Explanation of Sample Output 1 :
// For n = 4
// Step 1 :  n = 4 / 2  = 2
// Step 2 : n = 2 / 2  =  1 
// Sample Input 2 :
// 7
// Sample Output 2 :
// 3
// Explanation of Sample Output 2 :
// For n = 7
// Step 1 :  n = 7 ­- 1 = 6
// Step 2 : n = 6  / 3 = 2 
// Step 3 : n = 2 / 2 = 1  

int countStepsToOne(int n)
{
	//Write your code here
    
 	int* ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    ans[0] = 0;
    ans[1] = 0;
    // ans[2] = 1;
    // ans[3] = 1;
    // if(n==1 || n==2 || n==3){
    //     return ans[n];
    // }
    for(int i=2; i<=n; i++){
        int k = i;
        int x1 = INT_MAX, x2 = INT_MAX, x3 = INT_MAX;
        x1 = ans[k-1];
        if(k%2==0){
            x2 = ans[k/2];
        }
        if(k%3==0){
            x3 = ans[k/3];
        }
        
        ans[k] =1+ min(x1, min(x2, x3));
    }
    return ans[n];
}
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
