// Maximum Sum In Subarray
// Send Feedback
// You are given a sequence A[1], A[2], ..., A[N].
// A query is defined as follows:
// Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
// Given M queries, write a program that outputs the results of these queries.
// Input Format:
// The first line of input contains an integer N.
// In the second line contains N space separated integers.
// The third line contains the integer M.
// Next M lines contains 2 integers x and y.
// Output Format:
// For each query, print the answer in a new line.
// Constraints:
// 1 <= N <= 10^5
// 1 < = Q <= 10^5
// -10^4 <= arr[i] <= 10^4
// Sample Input 1:
// 3 
// -1 2 3 
// 1
// 1 2
// Sample Output 1:
// 2

#include<bits/stdc++.h>
using namespace std;

class values{
    public:
    	int sum;
    	int max_sum;
    	int best_prefix_sum;
    	int best_suffix_sum;
};

void buildTree(int* arr, values* tree, int start, int end, int treeNode){
    
    if(start==end){
        tree[treeNode].sum = arr[start];
        tree[treeNode].max_sum = arr[start];
        tree[treeNode].best_prefix_sum = arr[start];
        tree[treeNode].best_suffix_sum = arr[start];
        return;
    }
    
    
    int mid = (start+end)/2;
    
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid+1, end, 2 * treeNode + 1);
    
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    
    tree[treeNode].best_prefix_sum = max(tree[2 * treeNode].best_prefix_sum, 
                                	tree[2*treeNode].sum+tree[2*treeNode+1].best_prefix_sum);
    
    tree[treeNode].best_suffix_sum = max(tree[2*treeNode+1].best_suffix_sum,
                                    tree[2*treeNode].best_suffix_sum+ tree[2*treeNode+1].sum);
    
    
    tree[treeNode].max_sum = max(tree[2*treeNode].max_sum,
                            max(tree[2*treeNode+1].max_sum,
                            max(tree[2*treeNode].sum+tree[2*treeNode+1].best_prefix_sum,
                            max(tree[2*treeNode+1].sum+tree[2*treeNode].best_suffix_sum,
                            tree[2*treeNode].best_suffix_sum+tree[2*treeNode+1].best_prefix_sum
                               ))));
    
    
}


values query(values* tree, int start, int end, int treeNode, int left, int right){
	if(start>right || end<left){
        values ans;
        ans.sum = -1e5;
        ans.max_sum = -1e5;
        ans.best_suffix_sum = -1e5;
        ans.best_prefix_sum = -1e5;
        return ans;
    }
    
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    
    values q1 = query(tree, start, mid, 2 * treeNode, left, right);
    values q2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    values ans;
    
    ans.sum = q1.sum+q2.sum;
    ans.best_prefix_sum = max(q1.best_prefix_sum, q1.sum+q2.best_prefix_sum);
    ans.best_suffix_sum = max(q2.best_suffix_sum, q2.sum+q1.best_suffix_sum);
    
    ans.max_sum = max(q1.max_sum,
            	max(q2.max_sum,
                max(q1.sum+q2.best_prefix_sum,
                max(q2.sum+q1.best_suffix_sum,
                q1.best_suffix_sum+q2.best_prefix_sum
                   ))));
    
    return ans;
    
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    int* arr = new int[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    values* tree = new values[4*n];
    
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<query(tree, 0, n-1, 1, a-1, b-1).max_sum<<endl;
    }
    
    
    return 0;
}
