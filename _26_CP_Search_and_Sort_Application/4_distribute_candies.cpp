// Distribute Candies
// Send Feedback
// Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). 
// Shaky want to distribute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He wants to distribute them in a way such that:
// 1. All students get an equal number of candies.
// 2. All the candies which a student gets must be from a single box only.
// As he wants to make all of them happy so he wants to give as many candies as possible. Help Shaky 
// in finding out what is the maximum number of candies which a student can get.
// Input
// First-line contains T the number of test cases. 
// The first line of each test case contains N and K.
// Next line contains N space-separated integers, ith of which is the number of candies in the ith box.
// Output
// For each test case print the required answer in a separate line.
// Constraints
// 1<= T <= 10^5
// 1 <= N <= 10^5
// 1 <= K <= 10^9
// 0 <= A[i] <= 10^9
// Sum of N over all test cases doesn't exceed 10^6
// Sample Input:
// 2
// 3 2 
// 3 1 4
// 4 1
// 3 2 3 9
// Sample Output:
// 3
// 9


#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code
    int n;
    int k;
    int count = 0;
    int* arr;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>k;
        arr = new int[n];
        count = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        
        int temp[n];
        for(int i=0; i<n; i++){
            temp[i] = arr[i];
        }
        int sv = 0;
        int ev = arr[n-1];
        
        int mid = ev;
        int count = 0;
        int i = 0;
        int ans = -1;
        while(sv<=ev){
            mid = sv + (ev-sv)/2;
            // check for mid if all possible
            i = n-1;
            count =0;
            
            while(i>=0){
                if(arr[i]>=mid){
                    arr[i]-=mid;
                    count++;
                    if(count==k) break;
                }
                else{
                    i--;
                }
            }
            
            for(int i=0; i<n; i++){
            	arr[i] = temp[i];
        	}
            if(count>=k) {
                ans = max(mid, ans);
                sv = mid+1;
            }
            else{
                ev = mid-1;
            }
            
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
