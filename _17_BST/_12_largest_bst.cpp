//  Largest BST
// Send Feedback
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. 
//    You have to return the height of largest BST.
// Input format :

// The first line of input contains data of the nodes of the tree in level order form. 
//   The data of the nodes of the tree is separated by space. If any node does not have left or right child, 
// take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist,
// therefore, it will not be a part of the data of any node.

// Output format:

// The first and only line of output contains the height of the largest BST.

// Constraints:

// Time Limit: 1 second

// Sample Input 1:

// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output 1:

// 2


#include<climits>
class isBST{
    public:
    	bool bst;
    	int max;
    	int min;
    	int height;
};

isBST combined(BinaryTreeNode<int> *root){
    if(root==NULL){
        isBST result;
        result.bst = true;
        result.max = INT_MIN;
        result.min = INT_MAX;
        result.height = 0;
        return result;
    }
    
    isBST leftResult = combined(root->left);
    isBST rightResult = combined(root->right);
    
    int minimum = min(root->data, min(leftResult.min, rightResult.min));
    
    int maximum = max(root->data, max(leftResult.max, rightResult.max));
    
    bool bstFinal = !(root->data>leftResult.min) || !(root->data<rightResult.max) || !leftResult.bst || !rightResult.bst;
    
    int finalHeight;
    if(bstFinal){
        finalHeight =  max(leftResult.height, rightResult.height);
    }
    
    else{
        finalHeight =1+ max(leftResult.height, rightResult.height);
    }
    //finalHeight = 1 + max(leftResult.height, rightResult.height);
    isBST returnResult;
    returnResult.bst = bstFinal;
    returnResult.max = maximum;
    returnResult.min = minimum;
    returnResult.height = finalHeight;
    
    return returnResult;
    
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    isBST result;
    
    result = combined(root);
    
    
    return result.height;
    
}
