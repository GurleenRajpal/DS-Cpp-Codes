//  Roy and Coin Boxes
// Send Feedback
// Roy has N coin boxes numbered from 1 to N.
// Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
// He does this for M number of days.
// After M days, Roy has a query: How many coin boxes have at least X coins.
// He has Q such queries.
// Input Format:

// First line will contain T (number of test case), format of each test case follows
// First line contains two space separated integers N and M (N - number of coin boxes, M - number of days). 
// Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
// Each of next Q lines contain a single integer X.

// Output Format:

// For each query of each test case output the result in a new line.

// Constraints:

// 1 <= T <= 10
// 1 ≤ N ≤ 10000
// 1 ≤ M ≤ min(10000, N)
// 1 ≤ L ≤ R ≤ N
// 1 ≤ Q ≤ 10000
// 1 ≤ X ≤ N

// Sample Input

// 1
// 7
// 4
// 1 3
// 2 5
// 1 2
// 5 6
// 4
// 1
// 7
// 4
// 2

// Sample Output

// 6
// 0
// 0
// 4


#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int* start = new int[n+1];
        int* end = new int[n+1];
        for(int i=0; i<=n; i++){
            start[i] = 0;
            end[i] = 0;
        }
        int k = 0;
        while(k<m){
            int l, r;
            cin>>l>>r;
            start[l]++;
            end[r]++;
            k++;
        }
        
        int* ar = new int[n+1];
        ar[0] = 0;
        ar[1] = start[1];
        for(int i=2; i<=n; i++){
            ar[i] = start[i]-end[i-1]+ar[i-1];
        }
        
        int* kr = new int[n+1];
		for(int i=0; i<=n; i++){
            kr[i]=0;
        }

        for(int i=0; i<=n; i++){
            kr[ar[i]]++;
        }
        int *dp=new int [n+1];
        for(int i=0; i<n+1; i++)
        {
            dp[i]=0;
        }
        dp[n]=kr[n];
        for(int i=n-1; i>=0; i--)
        {
            dp[i]=kr[i]+dp[i+1];
        }
        // for(int i=n-1; i>=0; i++){
        //     kr[i] = kr[i]+kr[i+1];
        // }
        
        
        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            cout<<dp[x]<<endl;
        }
    }
    return 0;
}
