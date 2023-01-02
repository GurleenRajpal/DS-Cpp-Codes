//Two ways to print the tree
//Tree - 
//       1
//      2 3
// Print 1
// 1
// 2
// 3
// Print 2
// 1 : 2 3 
// 2 : 
// 3 : 

#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data){
            this->data = data;
        }
};
void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
    return;
}
void printTree2(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree2(root->children[i]);
    }
}
int main() {
    // Write C++ code here
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);    
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    
    printTree(root);
    printTree2(root);
    return 0;
}
