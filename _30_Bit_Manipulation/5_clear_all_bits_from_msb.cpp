// Clear All Bits From MSB
// Send Feedback
// You are given two integers N and i. You need to clear all bits from MSB to ith bit (start i from right to left) and return the updated N.
// Counting of bits starts from 0 from right to left.
// Input Format :
// First line of input will contain T(number of test cases), each test case follows as.
// Line1: contain two space-separated integers N and i.
// Output Format :
// Updated N for each test case in a newline.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^9
// 1 <= i <= 30
// Sample Input 1 :
// 1
// 15 2
// Sample Output 1 :
// 3

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n, i;
        cin>>n>>i;
//         int k = (int)log2(n);
        
//         int x = 0;
//         // int x = 1<<(i+1);
//         for(int j=i; j<31 ; j++){
//             x = x + (1<<(j));
//         }
//         // cout<<x<<endl;
//         // x = x-1;
//         x = ~x;
//         int ans = n&x;
        
        int mask = (1<<i)-1;
        cout<<(n&mask)<<endl;
    }
    return 0;
}
