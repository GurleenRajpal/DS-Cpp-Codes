// XOR of Natural Numbers
// Send Feedback
// You are given an integer N and asked to find the Xor of first N natural numbers.
// Input Format:
// The first line of input will contain T(number of test cases), each test case follows as.
// The only line of input contains an integer N.
// Output Format:
// For each test case print the Xor of first N natural number in a new line.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^9
// Sample Input:
// 1 
// 8
// Sample Output:
// 8

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // int ans = n;
        // for(int i=n-1; i>=1; i--){
        //     ans = ans^i;
        // }
        int ans;
        if(n%2==1){
            if(((n-1)/2)%2==0){
                ans = 1;
            }
            else{
                ans = 0;
            }
        }
        else{
            if((n/2)%2==0){
                ans = n;
            }
            else{
                ans = n+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
