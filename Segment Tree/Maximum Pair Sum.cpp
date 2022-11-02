// Maximum Pair Sum

// You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
// Update:
// This will be indicated in the input of a 'U' followed by space and then two integers i and x.
// U i x
// This operation sets the value of A[i] to x.
// Query:
// This will be indicated in the input of a 'Q' followed by a single space and then two integers x and y.
// Q x y
// You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
// Input Format:
// The first line of input contains an integer N, representing the length of the sequence. 
// The second line of input contains of N space separated integers, A[i]. 
// The third line of input contains an integer Q, Q ≤ 10^5, representing the number of operations. 
// Next Q lines contain the operations.
// Constraints:
// 1 ≤ i ≤ N
// 0 ≤ x ≤ 10^8
// 1 ≤ x < y ≤ N
// Output Format:
// For each query, print the maximum sum mentioned above, in a new line.
// Sample Input 1:
// 5
// 1 2 3 4 5
// 6
// Q 2 4
// Q 2 5
// U 1 6
// Q 1 5
// U 1 7
// Q 1 5
// Sample Output 1:
// 7
// 9
// 11
// 12

// Soltion - 

#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr, pair<int, int>* tree, int start, int end, int treeNode){
    
    if(start==end){
        tree[treeNode].first = arr[start];
        tree[treeNode].second = 0;
        return;
    }
    
    int mid = (start+end)/2;
    
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid+1, end, 2 * treeNode + 1);
    
    int ax[4] = {0,0,0,0};
    
    ax[0] = tree[2*treeNode].first;
    ax[1] = tree[2*treeNode].second;
    ax[2] = tree[2*treeNode+1].first;
    ax[3] = tree[2*treeNode+1].second;
    sort(ax, ax+4);
    
    
    tree[treeNode].first = ax[3];
    tree[treeNode].second = ax[2];
    
}

void update(int* arr, pair<int, int>* tree, int start, int end, int treeNode, int idx, int value){
    if(start==end){
        arr[idx] = value;
        tree[treeNode].first = value;
        tree[treeNode].second = 0;
        return;
    }
    
    int mid = (start+end)/2;
    
    if(idx>mid){
        update(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
    }
    else{
        update(arr, tree, start, mid, 2*treeNode, idx, value);
    }
    int* ax = new int[4];
    ax[0] = tree[2*treeNode].first;
    ax[1] = tree[2*treeNode].second;
    ax[2] = tree[2*treeNode+1].first;
    ax[3] = tree[2*treeNode+1].second;
    sort(ax, ax+4);
    
    
    tree[treeNode].first = ax[3];
    tree[treeNode].second = ax[2];
    
}

pair<int,int> query(int* arr, pair<int, int>* tree, int start, int end, int treeNode, int left, int right){
    if(start>right || end<left){
        return make_pair(0, 0);
    }
    
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    
    pair<int, int> p1 = query(arr, tree, start, mid, 2*treeNode,left, right);
    pair<int, int> p2 = query(arr, tree, mid+1, end, 2*treeNode+1,left, right);
    
    int* ax = new int[4];
    ax[0] = p1.first;
    ax[1] = p1.second;
    ax[2] = p2.first;
    ax[3] = p2.second;
    
    sort(ax, ax+4);
    
    return make_pair(ax[2], ax[3]);
    
}

int main(){
    
    // write your code here
    
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    pair<int, int>* tree =  new pair<int, int>[4*n];
    for(int i=0; i<4*n; i++){
        tree[i] = make_pair(0,0);
    }
    
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    while(q--){
        char c;
        int a, b;
        cin>>c>>a>>b;
        if(c=='Q'){
            pair<int, int> p = query(arr, tree, 0, n-1, 1, a-1, b-1);
            cout<<p.first+p.second<<endl;
        }
        else if(c=='U'){
            update(arr, tree, 0, n-1, 1, a-1, b);
        }
        
    }
    return 0;
}
