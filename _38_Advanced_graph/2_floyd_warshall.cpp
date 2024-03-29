// Floyd-Warshall Algorithm
// Send Feedback
// You are given an undirected weighted graph G with n vertices. And Q queries, 
// each query consists of two integers a and b and you have print the distance of shortest path between a and b.
// Note: If there is no path between a and b print 10^9
// Input Format:
// First line of Input will contain T(number of test cases), each test case follows as.
// Line1: contains two space-separated integers N and M denoting the number of vertex and edge in graph.
// Next M line contain three space-separated integers a, b, c denoting the edge between a and b with weight c.
// Next line will contain Q (number of queries)
// Next Q lines will contain two space-separated integers a and b.
// Output Format:
// For each query of each test case print the answer in a newline.
// Constraints:
// 1 <= T <= 50
// 1 <= N <= 100
// 1 <= M <= 10^4
// 1 <= Q <= 10^4
// 1 <= wt <= 10^5 (for each edge)
// Note: Graph may contain multiple edges.
// Sample Input:
// 1
// 3 6
// 3 1 4
// 1 3 17
// 2 3 2
// 1 3 7
// 3 2 11
// 2 3 15
// 3
// 1 1 
// 2 2 
// 2 3 
// Sample output:
// 0
// 0
// 2

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n, e;
        cin>>n>>e;
        int** mat = new int*[n+1];
        for(int i=0; i<=n; i++){
            mat[i] = new int[n+1];
            for(int j=0; j<=n; j++){
                if(i==j) mat[i][j] = 0;
                else mat[i][j] = 1e9;
            }
        }
        
        for(int i=0; i<e; i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(c<mat[a][b]){
                mat[a][b] = c;
                mat[b][a] = c;
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; ++){
                    if((mat[i][j]>mat[i][k]+mat[k][j]) && mat[i][k]!=1e9 && mat[j][k]!=1e9){
                        mat[i][j] =  mat[i][k]+mat[k][j];
                        mat[j][i] = mat[i][j];
                    }
                }
            }
        }
        
        int q;
        cin>>q;
        for(int i=0; i<q; i++){
            int a, b;
            cin>>a>>b;
            cout<<mat[a][b]<<endl;
        }
        
        
    }
    return 0;
}
