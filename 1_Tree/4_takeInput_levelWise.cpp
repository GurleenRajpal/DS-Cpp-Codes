// In this part we take the input level wise

// Code - 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<int>*> children;
        TreeNode(T data){
            this->data = data;
        }
};

void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
    
    return;
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;
    
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        cout<<"Enter the number of children for "<<front->data<<" : ";
        int numChild;
        cin>>numChild;
        for(int i=0; i<numChild; i++){
            int childData;
            cout<<"Enter child number "<<i<<" for "<<front->data<<" : ";
            cin>>childData;
            
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            
            pendingNodes.push(child);
        }
    }
    
    return root;
}

int main() {
    // Write C++ code here

    TreeNode<int>*root = takeInputLevelWise();
    printTree(root);
    
    return 0;
}

// Output - 

// Enter root data : 1
// Enter the number of children for 1 : 3
// Enter child number 0 for 1 : 2
// Enter child number 1 for 1 : 3
// Enter child number 2 for 1 : 4
// Enter the number of children for 2 : 2
// Enter child number 0 for 2 : 5
// Enter child number 1 for 2 : 6
// Enter the number of children for 3 : 1
// Enter child number 0 for 3 : 7
// Enter the number of children for 4 : 1
// Enter child number 0 for 4 : 8
// Enter the number of children for 5 : 0
// Enter the number of children for 6 : 0
// Enter the number of children for 7 : 0
// Enter the number of children for 8 : 0
// 1 : 2 3 4 
// 2 : 5 6 
// 5 : 
// 6 : 
// 3 : 7 
// 7 : 
// 4 : 8 
// 8 : 
