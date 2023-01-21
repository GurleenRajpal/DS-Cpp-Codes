// Number Of Balanced BTs
// Send Feedback
// You are given an integer h, find and print the count of all possible balanced binary trees of height h.
// This number can be huge, so return the output modulus 10^9 + 7.
// Input Format :
// The first line of input contains an integer, that denotes the value of the number of test cases. Let us denote it with the symbol T.
// Each test case consists of a single integer h, that denotes height of the binary tree, in a separate line.
// Output Format :
// For each test case, there is a single line of output, which prints the count of all possible
// balanced binary trees of height h, modulus 10^9 + 7. The output for each test case is printed in a separate line.
// Constraints :
// 1 <= T <= 10
// 1 <= h <= 20
// Time Limit: 1 second
// Sample Input 1:
// 1
// 2
// Sample Output 1:
// 3    
// Explanation:
// Following are the three balanced binary trees, that can be formed with height = 2.
// Alt Text

// Sample Input 2:
// 2
// 3
// 4
// Sample Output 2:
// 15
// 315

#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;

int f(int n){
    if(n<=1){
        return 1;
    }
    
    int a = f(n-1);
    int b = f(n-2);
    
    return (a%mod*a%mod+2*a%mod*b%mod)%mod;
    
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<f(n)%mod<<endl;
        
    }
    return 0;
}
