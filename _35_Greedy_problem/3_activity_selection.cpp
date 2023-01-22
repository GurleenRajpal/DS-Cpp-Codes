// Activity Selection
// Send Feedback
// You are given n activities with their start and finish times. Select the maximum number of 
// activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Input Format
// The first line of input contains one integer denoting N.
// Next N lines contains two space separated integers denoting the start time and finish time for the ith activity. 
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di ≤ 10^9
// Output Format
// Output one integer, the maximum number of activities that can be performed
// Sample Input 1
// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9
// Sample Output 1
// 4
// Explanation:
// The four activities will be done at following time intervals:
// 1. 1 2
// 2. 3 4
// 3. 5 7
// 4. 8 9

#include<bits/stdc++.h>
using namespace std;

bool sortBySec(pair<int, int>& a, pair<int, int>& b){
    return (a.second<b.second);
}

int main(){
    
    // write your code here
    int n;
    cin>>n;
    
    pair<int, int>* a = new pair<int, int>[n];
    
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;
    }
    
    sort(a, a+n, sortBySec);
    
    // for(int i=0; i<n; i++){
    // cout<<a[i].first<<" "<<a[i].second<<endl;
    // }
    
    int current_ending_time = a[0].second;
    int count = 1;
    for(int i=1; i<n; i++){
        if(current_ending_time<=a[i].first){
            count++;
            current_ending_time = a[i].second;
        }
    }
    cout<<count<<endl;
    
    return 0;
}
