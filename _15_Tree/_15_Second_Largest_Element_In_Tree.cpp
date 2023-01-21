//  Second Largest Element In Tree
// Send Feedback
// Given a generic tree, find and return the node with second largest value in given tree.
// Note: Return NULL if no node with required value is present.
// Input format :

// The first line of input contains data of the nodes of the tree in level order form. 
// The order is: data for root node, number of children to root node, data of each of child nodes 
// and so on and so forth for each node. The data of the nodes of the tree is separated by space.

// Output Format :

// The first and only line of output contains data of the node with second largest data.

// Constraints:

// Time Limit: 1 sec

// Sample Input 1 :

// 10 3 20 30 40 2 40 50 0 0 0 0 

// Sample Output 1 :

// 40

#include<queue>
#include<climits>
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 0;
    }
    TreeNode<int>* largest=root, *front, *secondLargest;
    
    queue<TreeNode<int>*> q;
    
    q.push(root);
    
    while(!q.empty()){
        front = q.front();
        q.pop();
        if(front->data>largest->data){
           //secondLargest = largest;
            largest = front;  
        }
        for(int i=0;i<front->children.size();i++){
            q.push(front->children[i]);
        }
    }
    
    int l = largest->data;
    secondLargest = NULL;
    int x = -2^10;
    
    q.push(root);
    while(!q.empty()){
        front = q.front();
        q.pop();
        if(front->data<l && front->data>x ){
           //secondLargest = largest;
            secondLargest = front;
            x = front->data;
        }
   		for(int i=0;i<front->children.size();i++){
            q.push(front->children[i]);
        }
    }
    return secondLargest;
}
