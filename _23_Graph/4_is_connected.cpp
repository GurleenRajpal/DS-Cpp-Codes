// Code : Is Connected ?
// Send Feedback
// Given an undirected graph G(V,E), check if the graph G is connected graph or not.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// Sample Output 1:
// true
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// false 
// Sample Output 2 Explanation
// The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 

#include <iostream>
#include <queue>
using namespace std;

bool isConnected(int **edges, int n, bool* visited){
    int sv = 0;
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<n;i++){
            if(i==front) continue;
            if(edges[front][i]==1 && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
            }
        } 
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false) return false;
    }
    return true;
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
    
    for(int i=0; i<e; i++){
        int f, s;
        cin>>f>>s;
        
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    bool* visited = new bool[n];
    
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    if(isConnected(edges,n,visited)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}
