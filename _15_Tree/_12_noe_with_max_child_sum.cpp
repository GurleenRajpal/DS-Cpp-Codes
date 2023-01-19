//  Node with maximum child sum
// Send Feedback
// Given a generic tree, find and return the node for which sum of its data and data of all 
// its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
// Input format :

// The first line of input contains data of the nodes of the tree in level order form. The order is: 
// data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. 
// The data of the nodes of the tree is separated by space. 

// Output format :

// The first and only line of output contains the data of the node with maximum sum, as described in the task.

// Constraints:

// Time Limit: 1 sec

// Sample Input 1 :

// 5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

// Sample Output 1 :

// 1


#include<queue>

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    queue<TreeNode<int>*> q;
    queue<TreeNode<int>*> cq;
    
    int max = -1;
    int sum = 0;
    
    q.push(root);
    
    TreeNode<int>* front;
    TreeNode<int>* maxNode;
    TreeNode<int>* childNode;
    
    while(!q.empty()){
        front = q.front();
        q.pop();
        sum = front->data;
        
        for(int i=0;i<front->children.size();i++){
            q.push(front->children[i]);
            sum+=front->children[i]->data;
        }
        
        if(sum>max){
            maxNode = front;
            max = sum;
        }
    }
    return maxNode;
}
