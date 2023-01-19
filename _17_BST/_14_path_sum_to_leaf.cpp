//  Path Sum Root to Leaf
// Send Feedback
// For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths
// where the sum of all the node data along the path is equal to K.

//  Input Format:

// The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

// The second line of input contains an integer value K.

// Output Format:

// Lines equal to the total number of paths will be printed. All the node data in every path 
// will be printed in a linear fashion taken in the order they appear from top to down bottom 
// in the tree. A single space will separate them all.

// Constriants:

// 1 <= N <= 10^5
// 0 <= K <= 10^8
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 second

// Sample Input 1:

// 2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
// 13

//  Sample Output 1:

// 2 3 4 4 
// 2 3 8

// Sample Input 2:

// 5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
// 13

//  Sample Output 2:

// 5 6 2
// 5 7 1

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
#include<string>
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, string s){
    if(root==NULL){
        return;
    }
    if(!root->right && !root->left && root->data==k){
        s+=to_string(root->data);
        cout<<s<<endl;
        return;
    }
    rootToLeafPathsSumToK(root->right, k-root->data, s+to_string(root->data)+" ");
    rootToLeafPathsSumToK(root->left, k-root->data, s+to_string(root->data)+" ");
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    rootToLeafPathsSumToK(root, k, "");
}


