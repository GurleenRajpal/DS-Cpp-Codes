// 2 vs 3
// Send Feedback
// The fight for the best number in the globe is going to finally come to an end.The top two contenders 
// for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates 
// from all across the globe came to witness the breath taking finals.
// The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
// Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
// Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

// Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
// The problem proved to be a really tough one for both of them.Hours passed by but neither of them could 
// solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
// Input format:
// The first line contains N denoting the length of the binary string .
// The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
// This is followed up by Q lines where each line contains a query.
// Output format:
// For each query of Type 0 print the value modulo 3.
// Constraints:
// 1<= N <=10^5
// 1<= Q <= 10^5
// 0 <= l <= r < N
// Sample Input
// 5
// 10010
// 6
// 0 2 4
// 0 2 3
// 1 1
// 0 0 4
// 1 1
// 0 0 3
// Sample Output
// 2
// 1
// 2
// 1

#include<bits/stdc++.h>
using namespace std;

int power[100001];
void buildPower(){
    power[0] = 1;
    for(int i=1; i<100001; i++){
        power[i] = (power[i-1]*2)%3;
    }
}

void buildTree(int* arr, int* tree, int start, int end, int treeNode){
    if(start==end){
        tree[treeNode] = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    int right = tree[2*treeNode+1];
    int left = tree[2*treeNode];
    
    tree[treeNode] = (power[end-mid]*left+right)%3;
    
}

int query(int* arr, int* tree, int start, int end, int left, int right, int treeNode){
    if(left>end || right<start){
        return 0;
    }
    
    if(start>=left && end<=right){
        return (tree[treeNode]*power[right-end])%3;
    }
    
    int mid = (start+end)/2;
    
    int ans1 = query(arr, tree, start, mid, left, right, 2*treeNode);
    int ans2 = query(arr, tree, mid+1, end, left, right, 2*treeNode+1);
    
    return (ans1+ans2)%3;
}

void update(int* arr,int* tree, int start, int end, int treeNode, int idx){
    if(start==end){
        arr[start] = 1;
        tree[treeNode] = 1;
        return;
    }
    int mid = (start+end)/2;
    if(idx>mid){
        update(arr, tree, mid+1, end, 2*treeNode+1, idx);
    }
    else{
        update(arr, tree, start, mid, 2*treeNode, idx);
    }
    
    int left = tree[2*treeNode];
    int right = tree[2*treeNode+1];
    
    
    tree[treeNode] = (left*power[end-mid]+right)%3;
    
    return;
    
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    string s;
    cin>>s;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = s[i] - '0';
    }
    int* tree = new int[4*n]();
    
    buildPower();
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    while(q--){
        int a,b,c;
        cin>>a;
        if(a==0){
            cin>>b>>c;
            cout<<query(arr, tree,0, n-1, b, c, 1)<<endl;
        }
        else{
            cin>>b;
            update(arr, tree, 0, n-1, 1, b);
        }
    }
    return 0;
}
