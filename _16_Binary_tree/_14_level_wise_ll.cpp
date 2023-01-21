//  Level wise linkedlist
// Send Feedback
// Given a binary tree, write code to create a separate linked list for each level. 
// You need to return the array which contains head of each level linked list.
// Input format :

// The first line of input contains data of the nodes of the tree in level order form. 
// The data of the nodes of the tree is separated by space. If any node does not have left or right child, 
// take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, 
// therefore, it will not be a part of the data of any node.

// Output format :

// Each level linked list is printed in new line (elements are separated by space).

// Constraints:

// Time Limit: 1 second

// Sample Input 1:

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

// Sample Output 1:

// 5 
// 6 10 
// 2 3 
// 9

/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};
***********************************************************/
#include<queue>
#include<vector>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return {};
    }
    vector<Node<int>*> v;
    queue<BinaryTreeNode<int>* >q, sq;
    BinaryTreeNode<int>* front;
    q.push(root);
    sq.push(root);
    
    while(!q.empty()){
        
        sq = q;
        Node<int>* head=NULL, *tail=NULL;
        while(!sq.empty()){
            front = sq.front();
            sq.pop();
            q.pop();
            Node<int>* newNode = new Node<int>(front->data);
            if(head==NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            
            if(front->left){
                q.push(front->left);
            }
            
            if(front->right){
                q.push(front->right);
            }
            
        }
        v.push_back(head);
    }
    //reverse(v.begin(), v.end());
    
    return v;
}


