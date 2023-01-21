//  Min and Max of Binary Tree
// Send Feedback
// For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
// Return the output as an object of Pair class, which is already created.
// Note:

// All the node data will be unique and hence there will always exist a minimum and maximum node data.

// Input Format:

// The first and the only line of input will contain the node data, all separated by a single space. 
// Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

// Output Format:

// The only line of output prints two integers denoting the minimum and the maximum data values respectively. 
// A single line will separate them both.

// Constraints:

// 2 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec

// Sample Input 1:

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

// Sample Output 1:

// 1 14

// Sample Input 2:

// 10 20 60 -1 -1 3 50 -1 -1 -1 -1 

// Sample Output 2:

// 3 60

#include<queue>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    pair<int, int>p;
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    p.first = min1;
    p.second = max1;
    if(root==NULL){
        return  p;
    }
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* front;
    
    while(!q.empty()){
        front = q.front();
        
        if(front->data>max1){
            max1 = front->data;
        }
        if(front->data<min1){
            min1 = front->data;
        }
        
        q.pop();
        
        if(front->left){
            q.push(front->left);
        }
        
        if(front->right){
            q.push(front->right);
        }
        
    }
    p.first = min1;
    p.second = max1;
    
    return p;
    
}
