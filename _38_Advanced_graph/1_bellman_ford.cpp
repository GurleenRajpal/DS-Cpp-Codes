// Bellman-Ford Algorithm
// Send Feedback
// you are given a weighted directed graph G with n vertices and m edges, and two 
// specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// Line1: contain two space-separated integers N and M denoting the number of vertex and number of edges in graph respectively.
// Line2: contain two space-separated integers src, des.
// Next M line will contain three space-separated integers a, b, wt representing the edge from a to b with weight wt.
// Output Format:
// For each test case print the distance of des from src in new line.
// Note: In case of no path is found print (10 ^ 9) in that case.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 200
// 1 <= M <= min(800, N*(N-1))
// 1 <= a,b <= N
// -10^5 <= wt <= 10^5
// Sample Input:
// 1
// 3 6
// 3 1
// 3 1 -2
// 1 3 244
// 2 3 -2
// 2 1 201
// 3 2 220
// 1 2 223
// Sample output:
// -2

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    
    int t;
    cin>>t;
    
    while(t--){
        int n, e;
        cin>>n>>e;
        
        int a, b;
        cin>>a>>b;
        
        vector< pair< pair<int, int>, int> > edges;
        
        for(int i=0; i<e; i++){
            int v1, v2, wt;
            cin>>v1>>v2>>wt;
            edges.push_back(make_pair(make_pair(v1, v2), wt));
        }
        
        
        int* weight = new int[n+1];
        
        for(int i=1; i<=n; i++){
            weight[i] = 1e9;
        }
        
        weight[a] = 0;
        
        for(int i=0; i<n-1; i++){
            for(int j=0; j<edges.size(); j++){
                //if(weight[edges[i].first.second]>weight[edges[i].first.first]+edges[i].second){
                if(weight[edges[j].first.first]!=1e9){
                    weight[edges[j].first.second]=min(weight[edges[j].first.second], weight[edges[j].first.first]+edges[j].second);
                }
                //}
            }
        }
        cout<<weight[b]<<endl;
        
        
    }
    
    return 0;
}
