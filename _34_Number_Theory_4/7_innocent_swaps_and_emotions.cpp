// Innocent Swaps and His Emotions
// Send Feedback
// There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: 
// Happy and Sad. Each phase of his life brings either kind of emotions.
// The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? 
//   But we know that life isn't that great, one cannot be happy all the time.
// Swaps, being a very sensitive guy, doesn't like to mix his emotions on a particular day. So each day, he is in exactly one of the three phases.
// Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of 
// these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
// Input Format:
// The first line of the input contains T, denoting the number of test cases.

// The next T lines contain two space-separated integers N and K.
// Constraints:
// 1 <=T <= 10^5
// 1<= K <= N <= 10^6
// Output Format:
// For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
// Sample Input 1:
// 3
// 1 1
// 2 1
// 3 2
// Sample Output 2:
// 2
// 4
// 12
// Explanation
// In the first test case, he needs to feel joyful on Day 1. Hence, answer is 2 (He can either play video games or sleep).

// In the second test case, he can be joyful either on Day 1 or Day 2. So number of ways = 4.


#include<bits/stdc++.h>
using namespace std;

#define m 1000000007
long long fact[1000001];



void factorial(){
    fact[0] = 1;
    for(int i=1;i<1000001; i++){
        fact[i] = (fact[i-1]%m * i%m)%m;
    }
}

long long f(long long a, long long b){
    if(b==0){
        return 1;
    }
    long long temp = f(a,b/2);
    
    if(b%2==0){
        return (temp%m * temp%m)%m;
    }
    else{
        return (a%m * temp%m * temp%m)%m;
    }
    
}

// long long f(long long a, long long b)
// {
//     long long ans = 1;
//     while (b)
//     {
//         if (b & 1)
//             ans = (ans * a) % m;
//         a = (a * a) % m;
//         b >>= 1;
//     }
//     return ans;
// }


int main(){
    
    // write your code here
    factorial();
    int t;
    cin>>t;
    while(t--){
        
        int n, k;
        cin>>n>>k;
        if(k>n){
            cout<<endl;
            continue;
        }
        
        long long ans = f(2, k);
        ans = (ans * fact[n])%m;
        ans = (ans * f(fact[n-k], m-2))%m;
        ans = (ans * f(fact[k], m-2))%m;
        
        cout<<ans<<endl;
        
        
    }
    return 0;
}
