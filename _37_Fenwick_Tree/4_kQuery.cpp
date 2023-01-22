// KQUERY
// Send Feedback
// Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. 
//   A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k),
// you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
// Input Format
// Line 1: Contains an integer N denoting the number of elements in the array
// Line 2: N space-separated integers denoting the elements of the array.
// Line 3: Number of queries Q
// Next Q line contain two space-separated integers i, j, k descrbing the current query
// Constraints:
// 1 <= N <= 10^5
// 1 <= Q <= 10^5
// 1 <= arr[i] <= 10^9
// 1 <= i <= j <= N
// 1 <= k <= 10^9
// Output Format:
// For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.


#include<bits/stdc++.h>
using namespace std;

struct event{
    long long value;
    int left;
    int right;
    int index;
};

bool compare(event e1, event e2){
    if(e1.value==e2.value){
        return e1.left>e2.left;
    }
    return e1.value>e2.value;
}


void update(int value, int n, int* bit){
    for(; value<=n; value+=(value&(-value))){
        bit[value]++;
    }
}

int query(int value, int* bit){
    int k = 0;
    for(;value>0; value-=(value&(-value))){
        k+=bit[value];
    }
    return k;
}

int main(){
    
    // write your code here
    
    
    int n;
    cin>>n;
    long long* arr = new long long[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int q;
    cin>>q;
    
    event* ev = new event[n+q+1];
    ev[0].value = 0;
    ev[0].left = 0;
    ev[0].right = 0;
    ev[0].index = 0;
    
    
    for(int i=1; i<=n; i++){
        ev[i].value = arr[i-1];
        ev[i].left = 0;
        ev[i].right = i;
        ev[i].index = 0;
    }
    
    for(int i=n+1; i<=n+q; i++){
        cin>>ev[i].left>>ev[i].right>>ev[i].value;
        ev[i].index = i-n;
    }
    
    sort(ev+1, ev+n+q+1, compare);
    
    
    int* bit = new int[n+1]();
    for(int i=0; i<=n; i++){
        bit[i] = 0;
    }
    int* ans = new int[q+1];
    int ansI = 0;
    
    for(int i=1; i<n+q+1; i++){
        if(ev[i].index==0){
            update(ev[i].right, n, bit);
        }
        else{
            ans[ev[i].index] = query(ev[i].right,bit) - query(ev[i].left-1, bit);
        }
    }
    
    for(int i=1; i<=q; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
