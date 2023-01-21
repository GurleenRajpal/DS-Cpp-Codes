// Code : All connected components
// Send Feedback
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. You need to take input in main and create a function which should return all the connected components. And 
// then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order 
// of different components doesn't matter.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order 
// of different components doesn't matter.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Sample Input 1:
// 4 2
// 0 1
// 2 3
// Sample Output 1:
// 0 1 
// 2 3 
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// 0 1 3 
// 2

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void print(int** edges, int n, bool* visited, int si){
    vector<int> v;
    v.push_back(si);
    visited[si] = true;
    queue<int> pendingNodes;
    
    pendingNodes.push(si);
    
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        
        for(int i=0;i<n;i++){
            if(i==front)continue;
            if(edges[front][i]!=0 && !visited[i]){
                v.push_back(i);
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
        
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            print(edges, n, visited, i);
        }
    }
    return;
    
}

int main() {
    // Write your code here
    int n, e;
    cin>>n>>e;
    
    int** edges = new int*[n];
    
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s]= 1;
        edges[s][f] = 1;
    }
    
    bool* visited = new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    if(n==0) return 0;
    
    print(edges, n, visited, 0);
    
    return 0;
    
}
