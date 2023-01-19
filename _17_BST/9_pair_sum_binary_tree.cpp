//  Pair Sum Binary Tree
// Send Feedback
// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
// Note:

// 1. Assume the given binary tree contains all unique elements.
// 2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

// Input format :

// The first line of input contains data of the nodes of the tree in level order form. 
// The data of the nodes of the tree is separated by space. If any node does not have a 
// left or right child, take -1 in its place. Since -1 is used as an indication whether the 
// left or right nodes exist, therefore, it will not be a part of the data of any node.
// The following line of input contains an integer, that denotes the value of S.

// Output Format :

// Print each pair in a new line, as described in the task. 

// Constraints:

// Time Limit: 1 second

// Sample Input 1:

// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 15

// Sample Output 1:

// 5 10
// 6 9

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<vector>
#include<bits/stdc++.h>
void putIn(BinaryTreeNode<int> *root, vector<int>& v){
    if(root==NULL) return;
    if(root->left) putIn(root->left, v);
    v.push_back(root->data);
    if(root->right) putIn(root->right,v);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL){
        return;
    }
    vector<int>v;
    putIn(root, v);
    sort(v.begin(), v.end());
    int i = 0;
    int j = v.size()-1;
    int k = 0;
    while(i<j){
        k = v[i]+v[j];
        if(k==sum){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        if(k>sum){
            j--;
        }
        if(k<sum){
            i++;
        }
    }
    
}
