//  ZigZag tree
// Send Feedback
// Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, 
// level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
// Input format:

// The first line of input contains data of the nodes of the tree in level order form. 
// The data of the nodes of the tree is separated by space. If any node does not have a left or right child, 
// take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, 
// it will not be a part of the data of any node.

// Output Format:

// The binary tree is printed level wise, as described in the task. Each level is printed in new line.

// Constraints

// Time Limit: 1 second

// Sample Input :

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output :

// 5
// 10 6
// 2 3
// 9

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
#include<queue>
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    int k = 0;
    
    queue<BinaryTreeNode<int>*> q, sq, lq;
    stack<BinaryTreeNode<int>*> s;
    BinaryTreeNode<int>* front,*b;
    
    q.push(root);
    
    while(!q.empty()){
        
        sq = q;
        lq = q;
        
        while(!lq.empty()){
            front = lq.front();
            lq.pop();

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            q.pop();
        }
        
        if(k==1){
            while(!sq.empty()){
                b = sq.front();
                sq.pop();
                s.push(b);
            }
            while(!s.empty()){
                cout<<s.top()->data<<" ";
                s.pop();
            }
            cout<<endl;
        }
        
        if(k==0){
            while(!sq.empty()){
                b = sq.front();
                sq.pop();
                cout<<b->data<<" ";
            }
            cout<<endl;
            
        }
        
        if(k==0)k=1;
        else k=0;
        
    }
    
}
