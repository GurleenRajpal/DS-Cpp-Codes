// Counting Even/Odd
// Send Feedback
// Tanmay and Rohit are best buddies. One day Tanmay gives Rohit a problem to test his intelligence 
// and skills. He gives him an array of N natural numbers and asks him to solve the following queries:-
// Query 0:
// 0 x y
// This operation modifies the element present at index x to y.
// Query 1:
// 1 l r 
// This operation counts the number of even numbers in range l to r inclusive.
// Query 2:
// 2 l r 
// This operation counts the number of odd numbers in range l to r inclusive.
// Input Format:
// First line of the input contains the number N. 
// Next line contains N natural numbers. 
// Next line contains an integer Q followed by Q queries.
// 0 x y - modify the number at index x to y. 
// 1 x y - count the number of even numbers in range l to r inclusive.
// 2 x y - count the number of odd numbers in range l to r inclusive.
// Constraints:
// 1<=N,Q<=10^5
// 1<=l<=r<=N 
// 0<=Ai<=10^9
// 1<=x<=N
// 0<=y<=10^9
// Output Format:
//  For each query, print the answer in a new line.
// Note: Indexing starts from 1
// Sample Input 1:
// 6
// 1 2 3 4 5 6
// 4
// 1 2 5
// 2 1 4
// 0 5 4
// 1 1 6
// Sample Output 1:
// 2
// 2
// 4

#include<bits/stdc++.h>
using namespace std;
//pair.first = no of even elements
//pair.second = no of odd elements
void buildTree(int* a,pair<int, int>* tree, int start, int end, int treeNode){
    if(start==end){
        if(a[start]%2==0){
            tree[treeNode].first = 1;
            tree[treeNode].second = 0;
        }
        else{
            tree[treeNode].first = 0;
            tree[treeNode].second = 1;
        }
        return;
    }
    
    int mid = (start+end)/2;
    
    buildTree(a, tree, start, mid, 2*treeNode);
    buildTree(a, tree, mid+1, end, 2*treeNode+1);
    
    tree[treeNode].first = tree[2*treeNode].first + tree[2*treeNode+1].first;
    tree[treeNode].second = tree[2*treeNode].second + tree[2*treeNode+1].second;
    
}

void update(int* arr, pair<int, int>* tree, int start, int end, int treeNode, int idx, int value){
    if(start==end){
        arr[start] = value;
        if(value%2==0){
            tree[treeNode].first = 1;
            tree[treeNode].second = 0;
        }
        else{
          	tree[treeNode].first = 0;
            tree[treeNode].second = 1;
        }
        return;
    }
    
    int mid = (start+end)/2;
    
    if(idx>mid){//update on the right
        update(arr, tree, mid+1, end,2*treeNode+1, idx, value);
    }
    else{
        update(arr, tree, start, mid, 2*treeNode, idx, value);
    }
    
    tree[treeNode].first = tree[2*treeNode].first + tree[2*treeNode+1].first;
    tree[treeNode].second = tree[2*treeNode].second + tree[2*treeNode+1].second;
    
}

pair<int, int> query(pair<int, int>* tree, int start,int end, int treeNode, int left, int right){
    if(left>end || right<start){
        pair<int, int>p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    
    pair<int, int> ans1 = query(tree, start,mid, 2*treeNode, left, right);
    pair<int, int> ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    pair<int, int> ans;
    ans.first = ans1.first+ans2.first;
    ans.second = ans1.second+ans2.second;
    
    return ans;
}

int main(){
    
    // write your code here
    
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    pair<int, int>* tree = new pair<int, int>[4*n];
    
    buildTree(a, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    while(q--){
        int x, l, r;
        cin>>x>>l>>r;
        if(x==0){
            //update arr, tree, arr start, arr end, treeNode, index, value
            update(a, tree, 0, n-1, 1, l-1, r);
        }
        else if(x==1){
            // queryforeven first
            //query tree, arr start, arr end, treeNode, leftindex, right Index
            cout<<query(tree, 0, n-1, 1, l-1, r-1).first<<endl;
        }
        else if(x==2){
            cout<<query(tree, 0, n-1, 1, l-1, r-1).second<<endl;
        }
    }
    return 0;
}
