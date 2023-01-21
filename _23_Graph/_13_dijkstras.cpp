// Code : Dijkstra's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) 
// using Dijkstra's Algorithm.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and 
//   vertex ej with weight wi (separated by space)
// Output Format :
// For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its 
// distance needs to be separated by a single space.
// Note : Order of vertices in output doesn't matter.
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5

#include <iostream>
#include <climits>
using namespace std;


void dj(int** edges, int n, bool* visited, int* weight){
    int w = 0;
    int minW = 1e8;
    int node = 0;
    for(int i=0; i<n; i++){
        
        int x = 1e8;
        int index = 0;
        if(i!=0){
            for(int k=0; k<n;k++){
                if(visited[k]) continue;
                if(x>weight[k]){
                    x = weight[k];
                    index = k;
                }
            }
        }
        
        visited[index] = true;
        
        
        for(int j=0 ; j<n ; j++){
            if(j!=index && !visited[j] && edges[index][j]!=0){
                w = weight[index] + edges[index][j];
                if(w<weight[j]){
                    weight[j] = w;
                }
            }
        }
        
        
    }
    
    
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
        int f,s, w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    int* weight = new int[n];
    for(int i=0;i<n;i++){
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    dj(edges, n, visited, weight);
    for(int i=0;i<n;i++){
        cout<<i<<" "<<weight[i]<<endl;
    }
    return 0;
    
}
