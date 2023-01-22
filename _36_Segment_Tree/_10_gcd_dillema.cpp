// The GCD Dillema
// Send Feedback
// Dwight is always bragging about how amazing he is at solving complicated problems with much ease. Jim 
// got tired of this and gave him an interesting problem to solve.
// Jim gave Dwight a sequence of integers a1, a2, ..., an and q queries x1, x2, ..., xq on it. For each query 
// xi Dwight has to count the number of pairs (l, r) such that 1 ≤ l ≤ r ≤ n and GCD(al, al + 1, ..., ar) = xi. 
// Dwight is feeling out of his depth here and asked you to be his Secret Assistant to the Regional Manager. Your 
// first task is to help him solve the problem. Are you up to it?
// Input Format:
// First line of input contains an integer N, representing the number of elements in the sequence.
// Second line contains N space-separated integers denoting the elements of the sequence.
// Third line of input contains an integer Q, representing the number of queries.
// Next Q line contains an integer X.
// Constraints:
// 1 < = N <= 10^4
// 1 <= arr[i] <= 10^9
// 1 <= Q <= 10^4
// 1 <= X <= 10^9 
// Output Format:
// For each query, print the answer in a new line.
// Sample Input:
// 2
// 8 12 
// 3
// 8
// 12
// 4
// Sample Output:
// 1
// 1
// 1

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int gcd(int a, int b){
    if(a<b){
        return gcd(b, a);
    }
    if(b==0) return a;
    return gcd(b, a%b);
}


void buildTree(int* arr, int* tree,int start, int end, int treeNode){
    if(start==end){
        tree[treeNode] = arr[start];
        //mp[arr[start]]++;
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    int x = gcd(tree[2*treeNode], tree[2*treeNode+1]);
    // int x = 1;
    // mp[x]++;
    tree[treeNode] = x;
    return;
    
}


int query(int* arr, int* tree, int start, int end, int left, int right, int treeNode){
    if(start>right || end<left){
        return 0;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    
    int ans1 = query(arr, tree, start, mid, left, right, 2*treeNode);
    int ans2 = query(arr, tree, mid+1, end, left, right, 2*treeNode+1);
    
    return gcd(ans1, ans2);
    
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    //sort(arr, arr+n);
    
    int* tree = new int[4*n];
    for(int i=0; i<4*n; i++){
        tree[i] = 0;
    }
    unordered_map<int, int> mp;
    buildTree(arr, tree, 0, n-1, 1);
    
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         mp[query(arr, tree, 0, n-1, i, j, 1)]++;
    //     }
    // }
    
    for(int i=0; i<n; i++)
    {
        int it = i;
        while (it < n)
        {
            int l = it + 1;//l =1 
            int r = n-1; //r = n-1
            int s = query(arr, tree, 0, n-1, i, it, 1);
            int limit = it;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (query(arr, tree, 0, n-1, i, m, 1) == s)
                {
                    l = m + 1;
                    limit = m;
                }
                else
                    r = m - 1;
            }
            mp[s] += limit - it + 1;
            it = limit + 1;
        }
    }
    
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<mp[x]<<endl;
    }
    
    return 0;
}
