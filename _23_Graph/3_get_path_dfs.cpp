//  Code : Get Path - DFS
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
// find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using DFS and print the first path that you encountered.
// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.

// Input Format :

// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
// The following line contain two integers, that denote the value of v1 and v2.

// Output Format :

// Print the path from v1 to v2 in reverse order.

// Constraints :

// 2 <= V <= 1000
// 1 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= 2^31 - 1
// 0 <= v2 <= 2^31 - 1
// Time Limit: 1 second

// Sample Input 1 :

// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3

// Sample Output 1 :

// 3 0 1

#include <iostream>
#include <vector>
using namespace std;


bool getPath(int** edges, bool* visited, int n, int si, int ei, vector<int>& v){
    if(si==ei){
        visited[si] = true;
        v.push_back(ei);
        return true;
    }
    visited[si] = true;
    for(int i=0; i<n; i++){
        if(i==si)continue;
        if(edges[i][si]==1 && !visited[i]){
            bool result = getPath(edges, visited, n, i, ei, v);
            if(result){
                v.push_back(si);
                return result;
            }
        }
    }
    
    return false;
    
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    for(int i=0; i<e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int si, ei;
    cin>>si>>ei;
    
    vector<int> v;
    
    bool result = getPath(edges, visited, n, si, ei, v);
    
    if(result){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
