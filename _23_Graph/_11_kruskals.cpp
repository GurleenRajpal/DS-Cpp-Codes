// Code : Kruskal's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller 
// vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// Print the MST, as described in the task.
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
// 1 2 1
// 0 1 3
// 0 3 5


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class edges{
    public:
    	int v1;
    	int v2;
    	int wi;
};

bool compare(edges const &a, edges const &b){
    return a.wi<b.wi;
}

int findParent(int* parent, int v){
    if(parent[v]==v) return v;
    
    return parent[v] = findParent(parent, parent[v]);
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    
    edges* a = new edges[e];
    
    for(int i=0; i<e; i++){
        int f, s, w;
        cin>>f>>s>>w;
        a[i].v1 = f;
        a[i].v2 = s;
        a[i].wi = w;
    }
    
    sort(a, a+e, compare);
    
    edges* output = new edges[n-1];
    
    int* parent = new int[n];
    
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    
    int count = 0;
    int index = 0;
    while(count!=n-1){
        
        edges currentEdge = a[index];
        
        int v1 = currentEdge.v1;
        int v2 = currentEdge.v2;
        
        int parent_v1 = findParent(parent, v1);
        int parent_v2 = findParent(parent, v2);
        
        if(parent_v1!=parent_v2){
            output[count] = currentEdge;
            count++;
            parent[parent_v1] = parent_v2;
        }
        
        index++; 
    }
    
    for(int i=0; i<count; i++){
        if(output[i].v1<output[i].v2){
        	cout<<output[i].v1<<" "<<output[i].v2<<" "<<output[i].wi<<endl;
        }
        else{
            cout<<output[i].v2<<" "<<output[i].v1<<" "<<output[i].wi<<endl;
        }
    }
    
    delete[] a;
    delete[] output;
    delete[] parent;
    
    return 0;
    
}
