// This is Sparta!
// Send Feedback
// King Leonidas of Sparta is preparing his men and country for a war against the Persian King Xerxes. He 
// has N soldiers with him and he has arranged them in a line at The Hot Gates. Let us number them from 1 to N. Leonidas 
// will fight Xerxes' army for Q days, and each day he can send only one of his men to fight.
// For each warrior, we know 2 traits: Strength and Cowardice. These are given to us in a form of integer. Each day, 
// Leonidas can choose his warrior from a range Li to Ri, and he will choose the warrior with maximum Strength value. 
// If there is more than one warrior having the same maximum Strength value, he will choose the warrior with minimum 
// Cowardice value. If there is still more than 1 warrior with the same maximum Strength value and same minimum Cowardice 
// value, he chooses the one with lower index in line.
// King Leonidas is ready to lay his life for Sparta. You, his right hand man, have to help him save Sparta by helping him choose a warrior for each day.
// Input Format:
// First line contains a single integer N, denoting the number of warriors Leonidas has. 
// Second line contains N space separated integers, representing Strength of ith warrior. 
// Third line contains N space separated integers, representing Cowardice of ith warrior
// Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
// Each of the next Q lines contains 2 integers Li and Ri.
// Constraints:
// 1 ≤ N,Q ≤ 10^5
// 1 ≤ Ai,Bi ≤ 10^9
// 1 ≤ Li ≤ Ri
// Output Format:
// For each Li and Ri, print the index of the warrior that King Leonidas should choose.
// Sample Input 1:
// 5
// 1 8 4 6 8
// 4 8 6 3 7
// 4
// 1 4
// 2 4
// 3 4
// 1 5
// Sample Output 1:
// 2
// 2
// 4
// 5

#include<bits/stdc++.h>
using namespace std;
class tree_attr{
    public:
    	int first, second, index;
};


void buildTree(pair<int, int>* arr, tree_attr* tree, int start, int end, int treeNode){
    
    if(start==end){
        tree[treeNode].first = arr[start].first;
        tree[treeNode].second = arr[start].second;
        tree[treeNode].index = start;
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    tree_attr p1 = tree[2*treeNode];
    tree_attr p2 = tree[2*treeNode+1];
    
    
    tree_attr ans;
    
    if(p1.first>p2.first){
        ans = p1;
    }
    else if(p1.first<p2.first){
        ans = p2;
    }
    else {
        if(p1.second<p2.second){
            ans = p1;
        }
        else if(p1.second>p2.second){
            ans = p2;
        }
        else{
            if(p1.index<p2.index){
                ans = p1;
            }
            else{
                ans = p2;
            }
        }
    }
    
    tree[treeNode] = ans;
    
}


tree_attr query(tree_attr* tree, int start, int end, int treeNode, int left, int right){
    
    if(start>right || end<left){
        tree_attr ans;
        ans.first = INT_MIN;
        ans.second = INT_MIN;
        ans.index = INT_MAX;
        return ans;
    }
    
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    
    
    int mid = (start+end)/2;
    
    tree_attr p1 = query(tree, start, mid, 2*treeNode, left, right);
    tree_attr p2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    tree_attr ans;
    
    if(p1.first>p2.first){
        ans = p1;
    }
    else if(p1.first<p2.first){
        ans = p2;
    }
    else {
        if(p1.second<p2.second){
            ans = p1;
        }
        else if(p1.second>p2.second){
            ans = p2;
        }
        else{
            if(p1.index<p2.index){
                ans = p1;
            }
            else{
                ans = p2;
            }
        }
    }
    return ans;
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    
    pair<int,int>* arr = new pair<int, int>[n];
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
    }
    for(int i=0; i<n; i++){
        cin>>arr[i].second;
    }
    
    tree_attr* tree = new tree_attr[4*n]();
    
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<query(tree, 0, n-1, 1,a-1, b-1).index + 1<<endl;
    }
    
    return 0;
}
