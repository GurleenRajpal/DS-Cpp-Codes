// Divisors Of Factorial
// Send Feedback
// Given a number, find the total number of divisors of the factorial of the number.
// Since the answer can be very large, print answer modulo 10^9+7.
// Input Format:
// The first line contains T, number of test cases.
// T lines follow each containing the number N.
// Output Format:
// Print T lines of output each containing the answer.
// Constraints
// 1 <= T <= 500
// 0 <= N <= 50000
// Sample Input:
// 3
// 2
// 3
// 4
// Sample Output:
// 2
// 4
// 8

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    vector<bool> v(50001, true);
    
    v[0] = false;
    v[1] = false;
    
    for(int i=2; i*i<=50001; i++){
        if(!v[i]){
            continue;
        }
        for(int j=i*i; j<=50001; j+=i){
            if(j%i==0){
                v[j] = false;
            }
        }
    }
    
    int m = 1e9+7;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long count = 1;
        for(int i=2; i<=n; i++){
            if(v[i]==false){
                continue;
            }
            int y = 0;
            
            for(int j=i; j<=n ; j = j*i){
                y = (y + n/j)%m;
            }
            
            count = (count%m * (y+1)%m)%m;
            
        }
        
        cout<<count<<endl;   
    }
    return 0;
}
