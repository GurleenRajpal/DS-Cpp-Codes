// Totient Function
// Send Feedback
// You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// An integer N in new line.
// Output Format:
// For each test case print the answer in new line
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 10^9
// Sample Input:
// 2
// 20
// 21
// Sample Output:
// 8 
// 12

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    vector<bool> v(100000, true);
    v[0] = false;
    v[1] = false;
    for(int i=2; i*i<100000; i++){
        if(v[i]==false){
            continue;
        }
        for(int j = i*i; j<100000; j+=i){
            if(j%i==0){
                v[j] = false;
            }
        }
    }
    
   vector<int> phi(1000001, 0);
    for(int i=0; i<1000001; i++){
        phi[i] = i;
    }
    
    
    for(int i=2; i*i<1000001; i++){
        if(phi[i]==i){
            phi[i] = i-1;
            for(int j=2*i; j<1000001; j+=i){
                phi[j] = (phi[j] * (i-1))/i;
            }
            
        }
        
    }
    
    int t;
    cin>>t;
    while(t--){
        long long a;
        cin>>a;
        // cout<<phi[a]<<endl;
		long long ans = a;
        
        for(long long i=2; i*i<=a; i++){
            if(a%i==0){
                while(a%i==0){
                    a = a/i;
                }
            	ans = (ans * (i - 1))/i;
            }
        }
        if(a>1){
            ans = (ans * (a - 1))/a;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
