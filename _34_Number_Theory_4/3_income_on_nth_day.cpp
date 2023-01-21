// Income On Nth Day
// Send Feedback
// Daulat Ram is an affluent business man. After demonetization, IT raid was held at 
// his accommodation in which all his money was seized. He is very eager to gain his money back, 
// he started investing in certain ventures and earned out of them. On the first day, his income was 
// Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
// The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
// Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
// Input Format:
// The first line of input consists of a single integer T denoting the number of test cases.
// Each of the next T lines consists of three integers F0, F1 and N respectively.
// Output Format:
// For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
// Constraints:
// 1 ≤ T ≤ 10^5
// 0 ≤ F0, F1, N ≤ 10^9
// Sample Input :
// 2
// 0 1 2
// 1 2 4
// Sample Output:
// 1
// 107
// Explanation
// In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

// F0=1

// F1=2

// F2=1 + 2 + 1×2 = 5

// F3=2 + 5 + 2×5 = 17

// F4=5 + 17 + 5×17 = 107


#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int mod = 1e9+7-1;//mod is m
long long mpow(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
long long ex(long long a, long long n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        long long smallAns = ex(a, n/2);
        return (smallAns%MOD * smallAns%MOD)%MOD;
    }
    else{
        long long smallAns = ex(a, n-1);
        return (a%MOD * smallAns%MOD)%MOD;
    }
}

// void multiply(long long A[2][2], long long M[2][2]){
//     long long fv = ((A[0][0]%MOD*M[0][0]%MOD)%MOD + (A[0][1]%MOD * M[1][0]%MOD)%MOD)%MOD;
//     long long sv = ((A[0][0]%MOD*M[0][1]%MOD)%MOD + (A[0][1]%MOD * M[1][1]%MOD)%MOD)%MOD;
//     long long tv = ((A[1][0]%MOD*M[0][0]%MOD)%MOD + (A[1][1]%MOD * M[1][0]%MOD)%MOD)%MOD;
//     long long lv = ((A[1][0]%MOD*M[0][1]%MOD)%MOD + (A[1][1]%MOD * M[1][1]%MOD)%MOD)%MOD;
//     A[0][0] = fv;
//     A[0][1] = sv;
//     A[1][0] = tv;
//     A[1][1] = lv;
// }

// void power(long long A[2][2], long long n){
//     if(n==0 || n==1){
//         return;
//     }
//     power(A, n/2);
//     multiply(A, A);
//     if(n%2!=0){
//         long long M[2][2] = {{1,1}, {1,0}};
//         multiply(A, M);
//     }
// }

// long long fib(long long n){
//     if(n==0) return 0;
//     long long A[2][2] = {{1,1}, {1,0}};
//     power(A, n-1);
//     return A[0][0];
// }
void multiply(long long a[2][2], long long m[2][2]){
    long long fv = (a[0][0]%mod * m[0][0]%mod)%mod + (a[0][1]%mod * m[1][0]%mod)%mod;
    long long sv = (a[0][0]%mod * m[0][1]%mod)%mod + (a[0][1]%mod * m[1][1]%mod)%mod;
    long long tv = (a[1][0]%mod * m[0][0]%mod)%mod + (a[1][1]%mod * m[1][0]%mod)%mod;
    long long av = (a[1][0]%mod * m[0][1]%mod)%mod + (a[1][1]%mod * m[1][1]%mod)%mod;
    a[0][0] = fv;
    a[0][1] = sv;
    a[1][0] = tv;
    a[1][1] = av;

}

void power(long long A[2][2], long long n){
    if(n==0 || n==1){
        return;
    }
    power(A, n/2);

    multiply(A, A);

    if(n%2!=0){
        long long M[2][2] = {{1,1}, {1,0}};
        multiply(A, M);
    }
}

long long fib(long long n){
    long long A[2][2] = {{1,1}, {1,0}};

    if(n==0){
        return 0;
    }

    power(A, n-1);

    return A[0][0]%mod;
}

int main(){
    
    // write your code here
    
    int t;
    cin>>t;
    
    while(t--){
        long long a, b, n;
        cin>>a>>b>>n;
        if(n==0){
            cout<<a<<endl;
            continue;
        }
    	if(n==1){
            cout<<b<<endl;
            continue;
        }
        
        long long fiba = fib(n-1)%(mod);
        long long fibb = (fib(n))%(mod);
        
        long long val = (ex(a+1, fiba)%MOD * ex(b+1, fibb)%MOD)%MOD-1;
        // if(val<0)val+=MOD;
        cout<<val<<endl;
    }
    
    return 0;
}
