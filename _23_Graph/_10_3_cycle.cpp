// 3 Cycle
// Send Feedback
// Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 
// 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
// Input Format :
// The first line of input contains two space separated integers, that denotes the value of N and M.
// Each of the following M lines contain two integers, that denote the vertices which have an undirected edge 
// between them. Let us denote the two vertices with the symbol u and v. 
// Output Format :
// Print the count the number of 3-cycles in the given graph
// Constraints :
// 0 <= N <= 100
// 0 <= M <= (N*(N-1))/2
// 0 <= u <= N - 1
// 0 <= v <= N - 1
// Time Limit: 1 sec
// Sample Input 1:
// 3 3
// 0 1
// 1 2
// 2 0
// Sample Output 1:
// 1

#include <iostream>
#include <queue>
using namespace std;

void helper(int **edges, int n, int si, bool* visited, int& count){
    int total = 1;
    visited[si] = true;
    queue<int> pendingNodes;
    pendingNodes.push(si);
    
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        
        for(int i=0;i<n;i++){
            if(i==front)continue;
            if(edges[front][i]==1 && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
                total++;
            }
        }
    }
    
    if(total == 3) count=count+1;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            helper(edges, n, i, visited, count);
        }
    }
    
    return;
    
}

int main() {
    // Write your code here
    // do dfs for connected components , if number is 3 increase count by 1
    
    int n, e;
    cin>>n>>e;
    
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    int cycleCount = 0;
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(edges[i][j]!=1) continue;
            for(int k=0;k<n;k++){
                if(k==i || k==j) continue;
                if(edges[k][j]!=1) continue;
                if(edges[k][j]==1 && edges[i][k]==1) cycleCount++;
            }
        }
    }
    
    cout<<cycleCount/6;
    
    return 0;
    
}
