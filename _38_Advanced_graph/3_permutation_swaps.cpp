// Permutation Swaps
// Send Feedback
// Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.
// He also believes that there are M good pairs of integers (ai, bi). Kevin can perform following operation with his permutation:
// Swap Px and Py only if (x, y) is a good pair.
// Help him and tell if Kevin can obtain permutation Q using such operations.
// Input format:
// The first line of input will contain an integer T, denoting the number of test cases.

// Each test case starts with two space-separated integers N and M. The next line contains 
// N space-separated integers Pi. The next line contains N space-separated integers Qi. 
// Each of the next M lines contains two space-separated integers ai and bi.
// Output format:
// For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
// Constraints:
// 1 ≤ T ≤ 10
// 2 ≤ N ≤ 100000
// 1 ≤ M ≤ 100000
// 1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
// 1 ≤ ai < bi ≤ N
// Time Limit: 1 second
// Sample Input 1:
// 2
// 4 1
// 1 3 2 4
// 1 4 2 3
// 3 4
// 4 1
// 1 3 2 4
// 1 4 2 3
// 2 4
// Sample Output 1:
// NO 
// YES

//Solved using connected components
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


void dfs(vector<int>* edges, int x, bool* visited, unordered_set<int>* output){
    visited[x] = true;
    output->insert(x+1);
    for(int i=0; i<edges[x].size(); i++){
    	if(!visited[edges[x][i]]){
            dfs(edges, edges[x][i], visited, output);
        }
    }
}
unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n){
    unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>();
    // unordered_set<int>* output = new unordered_set<int>();
    
    bool* visited = new bool[n];
    
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
   
    for(int i=0; i<n; i++){
        
        if(!visited[i]){
            unordered_set<int>* output = new unordered_set<int>();
            dfs(edges, i, visited, output);
        	components->insert(output);
        }
        
    }
    return components;
    
}
int main(){
    
    // write your code here
    
    int t;
    cin>>t;
    
    while(t--){
        int n, m;
        cin>>n>>m;
        
        int* p = new int[n];
        for(int i=0; i<n; i++){
            cin>>p[i];
        }
        int* q = new int[n];
        for(int i=0; i<n; i++){
            cin>>q[i];
        }
        
        vector<int>* edges = new vector<int>[n];
        
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }
        
        
        unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
        
        
        unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
        bool result = true;
        
        while(it1!=components->end()){
            unordered_set<int>* com = *it1;
            unordered_set<int>::iterator it2 = com->begin();
            set<int> s1, s2;
            while(it2!=com->end()){
                //cout<<*it2<<" ";
                
                s1.insert(p[*it2-1]);
                s2.insert(q[*it2-1]);
                it2++;
            }
            if(s1!=s2){
                result = false;
                break;
            }
            it1++;
            // cout<<endl;
        }
        
        if(result){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}
