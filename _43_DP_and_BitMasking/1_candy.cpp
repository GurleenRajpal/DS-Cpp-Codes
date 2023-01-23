//  Candy
// Send Feedback
// Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with 
// different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary
// wants to know the number of ways he can distribute these N candies to his N students such that every 
// student gets exactly one candy he likes.
// Input Format :

// The first line of input will contain T(number of test cases), each test case follows as.
// Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
// Next N lines: N integers describing the preferences of one student. 1 at i'th (0 <= i < N) 
// position denotes that this student likes i'th candy, 0 means he doesn't.
// Assume input to be 0-indexed based.

// Output Format :

// Return the number of ways Gary can distribute these N candies to his N students such that every 
// student gets exactly one candy he likes for each test case in a new line.

// Sample Input:

// 1
// 3
// 1 1 1
// 1 1 1
// 1 1 1

// Sample Output:

// 6

// Explanation:

// Since, all the students like all the candies, so, the candies can be distributed in the following 6 ways:


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(int** a, int n, int si, ll mask, ll*  dp){
    
    if(si>=n){
        return 1;
    }
    
    
    if(dp[mask]!=-1) return dp[mask]; 
    
    ll ans = 0;
    
    for(ll i=0; i<n; i++){
        //check if ith bit of mask is set or not
        //if set : continue
        //if not set we 
        //we compare with the arr[i] 
        //if arr[si][i] is 0, we return 0 else we continue
        if(a[si][i]==0){
            continue;
        }
        ll k = (1<<i);
        if(!(mask&k)){//not set
            ans += f(a, n, si+1, mask|k, dp);
        }
    }
    
    return dp[mask] = ans;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        int** a = new int*[n];
        for(int i=0; i<n; i++){
            a[i] = new int[n];
            for(int j=0; j<n; j++){
                cin>>a[i][j];
            }
        }
        ll* dp = new ll[(1<<n)];
        
        for(ll i=0; i<(1<<n); i++){
            dp[i] = -1;
        }
        
        ll mask = 0;
        
    	ll ans = f(a,n,0,mask, dp);
        
        cout<<ans<<endl;
        
        //delete[] dp; 
    }
    //delete[] dp;
    return 0;
}
