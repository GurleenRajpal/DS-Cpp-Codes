//  Maximum XOR Subarray
// Send Feedback
// Given an array of N integers, find the subarray whose XOR is maximum.
// Input Format:

// First line of input contains an integer N, representing number of elements in array.
// Next line contains N space-separated integers.

// Constraints:

// 1 <= N <= 10^6
// 1 <= A[i] <=10^5 

// Output Format:

// Print XOR of the subarray whose XOR of all elements in subarray is maximum over all subarrays.

// Sample Input 1:

// 4
// 1 2 3 4

// Sample Output 1:

// 7


#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        trieNode* left = NULL;
        trieNode* right = NULL;
};


void insert(trieNode* root, int val){
   
        trieNode* curr = root;
        for(int j=31; j>=0; j--){
            int b = (val>>j)&1;
            if(b==0){
                if(!curr->left){
                    curr->left = new trieNode();
                }
                curr = curr->left;
            }
            else{
                if(!curr->right){
                    curr->right = new trieNode();
                }
                curr = curr->right;
            }
        }
    
}

int findMax(trieNode* root,int val){
    
    
        trieNode* temp = root;
        if(temp==NULL){
            cout<<"here"<<endl;
            return 0;
        }
        
        int sum = 0;
        int curr = val;
        for(int j=31; j>=0; j--){
            int b = (curr>>j)&1;
            if(b==0){
                if(temp->right){
                    temp = temp->right;
                    sum += pow(2, j);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->left){
                    temp = temp->left;
                    sum+=pow(2, j);
                }
                else{
                    temp = temp->right;
                }
            }
        }
        return sum;
}

int main(){
    
    // write your code here
    int n;
    cin>>n;
    int* arr = new int[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = 0;
    int xor_till_i = 0;

    trieNode* root = new trieNode();
    insert(root, xor_till_i);
    for(int i=0; i<n; i++){
        xor_till_i = arr[i]^xor_till_i;
        ans = max(ans,findMax(root, xor_till_i));
        insert( root, xor_till_i);
    }
    
    cout<<ans<<endl;
    return 0;
}
