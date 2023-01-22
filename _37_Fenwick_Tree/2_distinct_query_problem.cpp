// Distinct Query Problem
// Send Feedback
// Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query 
// is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number 
// of distinct elements in the subsequence ai, ai+1, ..., aj.
// Input Format:
// Line 1: n (1 ≤ n ≤ 30000).
// Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
// Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
// In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).
// Output Format:
// For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.
// Sample Input 1:
// 5
// 1 1 2 1 3
// 3
// 1 5
// 2 4
// 3 5
// Sample Output 1:
// 3
// 2
// 3 

#include<bits/stdc++.h>
using namespace std;

struct queries{
    int first, last, index;
};


bool compare(queries& q1, queries& q2){
    return q1.last<q2.last;
}

void update(int index, int value, int n, int* bit){
    for(;index<=30000; index += (index & (-index))){
        bit[index] += value;
    }
}

int value(int index, int* bit){
    int value = 0;
    for(;index>0; index -= (index & (-index))){
        value += bit[index];
    }
    return value;
}

int main(){
    
    // write your code here
    
    int n;
    cin>>n;
    int* arr = new int[n+1]();
    
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    
    int q;
    cin>>q;
    
    queries* qr = new queries[q+1];
    
    for(int i=1; i<=q; i++){
        cin>>qr[i].first>>qr[i].last;
        qr[i].index = i;
    }
    
    sort(qr+1, qr+q+1, compare);
    
    int* lastIndex = new int[1000001];
    for(int i=1; i<=1000001; i++){
        lastIndex[i] = -1;
    }
    
    int* bit = new int[30001];
    for(int i=1; i<=30000; i++){
        bit[i] = 0;
    }
    
    int* ans = new int[q+1];
    
    int total = 0;
    int k = 1;
    
    for(int i=1; i<=n; i++){
        
        if(lastIndex[arr[i]]!=-1){
    		update(lastIndex[arr[i]], -1, n, bit);    
        }
        
        else{
            total++;
        }
        
        update(i, 1, n, bit);
        lastIndex[arr[i]] = i;
        
        while(k<=q && qr[k].last==i){
            ans[qr[k].index] = total - value(qr[k].first-1, bit);
            k++;
        }
        
    }
    
    for(int i=1; i<=q; i++){
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
}
