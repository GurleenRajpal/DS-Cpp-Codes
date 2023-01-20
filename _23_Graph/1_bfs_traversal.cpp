//  Code : BFS Traversal
// Send Feedback
// Given an undirected and disconnected graph G(V, E), print its BFS traversal.
// Note:

// 1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
// 2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 3. E is the number of edges present in graph G.
// 4. Take graph input in the adjacency matrix.
// 5. Handle for Disconnected Graphs as well

// Input Format :

// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.

// Output Format :

// Print the BFS Traversal, as described in the task.

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

// 0 1 3 2

#include <iostream>
#include <queue>
using namespace std;

void print(int** edges,bool* visited,int sv, int n){
    queue<int> q;
    int front;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        front = q.front();
        q.pop();
        
        cout<<front<<" ";
        for(int i=0; i<n; i++){
            if(front==i) continue;
            if(edges[i][front]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
        
    }
    
}


int main() {
    // Write your code here
    int n, e;
    cin>>n>>e;
    if(n==0)return 0;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0; i<e; i++){
        int fn, sn;
        cin>>fn>>sn;
        
        edges[fn][sn] = 1;
        edges[sn][fn] = 1;
    }
    
    bool* visited = new bool[n];
    
    for(int i=0; i<n; i++){
        visited[i] =false;
    }
    
    for(int i=0; i<n ;i++){
    	if(!visited[i]){
            print(edges, visited,i, n);
        }
    }
    
}
