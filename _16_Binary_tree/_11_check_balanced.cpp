//  Check Balanced
// Send Feedback
// Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
// Balanced Binary Tree:

// A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
// 1. The left and right subtrees must be balanced.
// 2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    

// Input format:

// The first line of input contains data of the nodes of the tree in level order form. 
// The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. 
// Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

// Output format

// The first and only line of output contains true or false.

// Constraints

// Time Limit: 1 second

// Sample Input 1 :

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output 1 :

// false

// Sample Input 2 :

// 1 2 3 -1 -1 -1 -1

// Sample Output 2 :

// true

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}


bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
   if(root==NULL){
       return true;
   }
   
   bool leftBal = isBalanced(root->left);
   bool rightBal = isBalanced(root->right);
    
   int heightDiff = abs(height(root->left)-height(root->right));
    
   bool op3 = (heightDiff<=1);
    
  return leftBal&&rightBal&&op3;
	
    
}
