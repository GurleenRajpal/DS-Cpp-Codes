// Weighted Job Scheduling
// Send Feedback
// You are given N jobs where every job is represented as:
// 1. Start Time
// 2. Finish Time
// 3. Profit Associated
// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
// Input Format:
// The first line of input contains an integer denoting N.
// Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
// Constraints:
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di, p ≤ 10^6
// Output Format:
// Output one integer, the maximum profit that can be achieved.
// Sample Input 1
// 4
// 3 10 20
// 1 2 50
// 6 19 100
// 2 100 200
// Sample Output 1
// 250

#include<bits/stdc++.h>
using namespace std;
struct job{
    int start;
    int end;
    int profit;
};

// bool f(job j1, job j2){
//     return (j1.profit/(j1.end-j1.start))<(j2.profit/(j2.end-j2.start));
// }
bool f(job j1, job j2){
    return j1.end<j2.end;
}

int main(){
    
    int n;
    cin>>n;
    job* a = new job[n];
    for(int i=0; i<n; i++){
        cin>>a[i].start>>a[i].end>>a[i].profit;
    }
    sort(a, a+n, f);
    // for(int i=0; i<n; i++){
    //     cout<<a[i].start<<" "<<a[i].end<<" "<<a[i].profit<<endl;
    // }
    
    int* dp = new int[n];
    dp[0] = a[0].profit;
    
    for(int i=1; i<n; i++){
        int include = -1;
        int val = a[i].profit;

        // for(int j=i-1; j>=0; j--){
        //     if(a[i].start>=a[j].end){
        //         include = j;
        //         break;
        //     }
        // }
        int right = i-1;
        int left = 0;

        while(left<=right){
            int mid = (left+right)/2;
            if(a[i].start>=a[mid].end){
                if(a[i].start>=a[mid+1].end){
                    left = mid+1;
                }
                else{
                    include = mid;
                    break;
                }
            }
            else{
                right = mid-1;
            }
        }

        if(include!=-1){
            val += dp[include];
        }
        dp[i] = max(val, dp[i-1]);
    }
    int max_profit = dp[n-1];
    
    // for(int i=0; i<n; i++){
    //     max_profit = max(max_profit, x[i]);
    // }
    
    cout<<max_profit<<endl;
    
    
    
    // write your code here
    return 0;
}
