// Minimum In SubArray

// You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). 
// There are Q queries, and each query is defined in either of the following two ways:
// Query on range:
// You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). 
// Note that in this query, i and j lies in the range: [1, N].
// Update query:
// You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
// Input Format:
// The first line of input contains two integers: N and Q, representing the length of the sequence and the number of queries. 
// The second line of input contains N space-separated integers, A[i].  
// Next, Q lines contain the queries. Each line contains one character, followed by two space-separated integers. 
// For the query on range, the character will be q and for the update query, the character will be u. 

// Constraints:
// 1 ≤ i ≤ N
// 0 ≤ B ≤ 10^8
// 1 ≤ i <= j ≤ N

// Output Format:
// For each query on range, print the minimum number between the range, in a new line.
// Sample Input 1:
// 4 3
// 5 2 4 3
// q 1 3
// u 1 1
// q 3 4

// Sample Output 1:
// 2
// 3

// Solution - 

#include<bits/stdc++.h>
using namespace std;


void buildTree(int* arr, int* tree, int start, int end, int treeNode){
    if(start==end){
        tree[treeNode] = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid+1, end, 2 * treeNode + 1);
    
    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
    
}

void update(int* arr, int* tree, int start, int end, int treeNode, int idx, int value){
    if(start==end){
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }
    
    int mid = (start + end)/2;
    
    if(idx>mid){
        update(arr, tree, mid+1, end, 2 * treeNode + 1, idx, value);
    }
    else{
        update(arr, tree, start, mid, 2 * treeNode, idx, value);
    }
    
    tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
    
}


int query(int* arr, int* tree, int start, int end, int treeNode, int left, int right){
    if(start>right || end<left){
        return 1e9;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    
    int ans1 = query(arr, tree, start, mid, 2 * treeNode, left, right);
    int ans2 = query(arr, tree, mid+1, end, 2 * treeNode + 1, left, right);
    
    return min(ans1, ans2);
    
}
int main(){
    
    // write your code here
    int n, q;
    cin>>n>>q;
    
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int* tree = new int[4 * n];
    // for(int i=0; i< 4*n; i++){
    //     tree[i] = 1e9;
    // }
    buildTree(arr, tree, 0, n-1, 1);
    
    while(q--){
        char c;
        int a, b;
        cin>>c>>a>>b;
        if(c=='q'){
            cout<<query(arr, tree, 0, n-1, 1, a-1, b-1)<<endl;
        }
        else if(c=='u'){
            update(arr, tree,0, n-1, 1, a-1, b);
        }
    }
    
    
    return 0;
}
