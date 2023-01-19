//  LCA of Binary Tree
// Send Feedback
// Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
// LCA

// LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
// Input format:

// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the
// tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used 
// as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
// The following line of input contains two integers, denoting the value of data of two nodes of given binary tree.

// Output Format:

// The first and only line of output contains the data associated with the lowest common ancestor node.

// Constraints:

// Time Limit: 1 second

// Sample Input 1:

// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 2 10

// Sample Output 1:

// 10

// Sample Input 2:

// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 2 6

// Sample Output 2:

// 5

// Sample Input 3:

// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 12 78

// Sample Output 3:

// -1


int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
   if(root==NULL){
        return -1;
    }
    if(root->data==a || root->data==b){
        return root->data;
    }
    
    int k1 = getLCA(root->left, a, b);
    int k2 = getLCA(root->right, a, b);
    
    if(k1<0 && k2<0){
        return -1;
    }
    else if(k1<0 && k2>0){
        return k2;
    }
    else if(k1>0 && k2<0){
        return k1;
    }
    else {
        return root->data;
    }
    return -1;
}
