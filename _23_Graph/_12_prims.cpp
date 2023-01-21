// Code : Prim's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. 
//   print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// Print the MST, as described in the task.
// Constraints :
// 2 <= V, E <= 10^5
// 1 <= Wi <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 1 3
// 1 2 1
// 0 3 5


#include <iostream>
#include <climits>
using namespace std;

int main() {
    // Write your code here
    int n, e;
    cin>>n>>e;
    
    int** edges = new int*[n];
    
    
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++){
        int si, ei, w;
        cin>>si>>ei>>w;
        edges[si][ei] = w;
        edges[ei][si] = w;
    }
    
    
    bool* visited = new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    int* parent = new int[n];
    
    parent[0] = -1;
    for(int i=1;i<n;i++){
        parent[i] = INT_MIN;
    }
    
    int* weight = new int[n];
    weight[0] = 0;
    
    for(int i=1;i<n;i++){
        weight[i] = INT_MAX;
    }
    //visited[0] = true;
    
//     for(int j=0; j<e; j++){
//         edges currentEdge = input[j];
//         int si = currentEdge.v1;
//         int ei = currentEdge.v2;
//         int wi = currentEdge.wi;
		
//         if(si==0){
//             if(weight[ei]>wi){
//                 weight[ei] = wi;
//                 parent[ei] = si;
//                 visited[si] = true;
//             }
//         }
//         if(ei==0){
//             if(weight[si]>wi){
//                 weight[si] = wi;
//                 parent[si] = ei;
//                 visited[ei] = true;
//             }
//         }

//     }
    int index = 0;
    
//     for(int i=1; i<n; i++){
//         //update parent and weight
//         index = i;
//         //visited[index] = true;
//         for(int j=0; j<e; j++){
//             edges currentEdge = input[j];
//             int si = currentEdge.v1;
//             int ei = currentEdge.v2;
//             int wi = currentEdge.wi;
            
//             if(si==index && !visited[index]){
//                 if(weight[si]>wi){
//                     weight[si] = wi;
//                     parent[si] = ei;
//                     //visited[ei] = true;
//                 }
//             }
//             if(ei==index && !visited[index]){
//                 if(weight[ei]>wi){
//                     weight[ei] = wi;
//                     parent[ei] = si;
//                     //visited[si] = true;
//                 }
//             }
            
            
//         }
//         visited[index] = true;
        
//     }
    
    for(int i=0; i<n-1; i++){
        int minVertex = -1;
        for(int j=0; j<n; j++){
            if(!visited[j] && (minVertex==-1 || (weight[j]<weight[minVertex]))){
                minVertex = j;
            }
        }
        
        visited[minVertex] = true;
        
        for(int j=0; j<n; j++){
            if(edges[minVertex][j] && !visited[j] && edges[minVertex][j]<weight[j]){
                weight[j] = edges[minVertex][j];
                parent[j] = minVertex;
            }    
        }
        
    }
    
    for(int i=1;i<n;i++){
        if(i>parent[i]){
        	cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    
    return 0;
}
