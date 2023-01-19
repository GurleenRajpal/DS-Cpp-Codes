//  Code: BST to Sorted LL
// Send Feedback
// Given a BST, convert it into a sorted linked list. You have to return the head of LL.
// Input format:

// The first and only line of input contains data of the nodes of the tree in level order form. 
// The data of the nodes of the tree is separated by space. If any node does not have left or right child, 
// take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, 
// therefore, it will not be a part of the data of any node.   

// Output Format:

// The first and only line of output prints the elements of sorted linked list.

// Constraints:

// Time Limit: 1 second

// Sample Input 1:

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

// Sample Output 1:

// 2 5 6 7 8 10


/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
class Base{
    public:
    	Node<int>* head;
    	Node<int>* tail;
    	Base(){
            head = NULL;
            tail = NULL;
        }
};

Base helper(BinaryTreeNode<int>* root){
    
    Base combined;
    if(root==NULL){
        return combined;
    }
    
    Base leftList = helper(root->left);
    Base rightList = helper(root->right);
    
    Node<int>* newNode = new Node<int>(root->data);
    
    if(leftList.tail){
        leftList.tail->next = newNode;
    }
    
    if(rightList.head){
        newNode->next = rightList.head;
    }
    
    if(leftList.head!=NULL){
        combined.head = leftList.head;
    }
    else{
        combined.head = newNode;
    }
    
    if(rightList.tail!=NULL){
        combined.tail = rightList.tail;
    }
    else{
        combined.tail = newNode;
    }
    
    return combined;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    // Base list = helper(root);
    // return list.head;
    if(root==NULL){
        return NULL;
    }
    Node<int>* leftList = constructLinkedList(root->left);
    Node<int>* rightList = constructLinkedList(root->right);
    Node<int>* newNode = new Node<int>(root->data);
    Node<int>* head=NULL, *temp = NULL;
    
    if(leftList){
        head = leftList;
        temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        temp = temp->next;
    }
    else{
        head = newNode;
        temp = newNode;
    }
    if(rightList){
        temp->next = rightList;
    }
    return head;
}

#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
