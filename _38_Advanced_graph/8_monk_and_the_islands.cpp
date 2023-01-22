// Monk and the Islands
// Send Feedback
// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
// Input format:
// First line contains T. T testcases follow.
// First line of each test case contains two space-separated integers N, M.
// Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
// Output format:
// Print the answer to each test case in a new line.
// Constraints:
// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 10000
// 1 ≤ M ≤ 100000
// 1 ≤ X, Y ≤ N
// Sample Input
// 2
// 3 2
// 1 2
// 2 3
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2
// Sample Output
// 2
// 2

#include<bits/stdc++.h>
using namespace std;

long long f(vector<int> edges[1000000], int n, int si, bool visited[10001], int* distance){
    long long count = 0;
    queue<int> q;
    q.push(si);
    visited[si] = true;
    distance[si] = 0;
    while(!q.empty()){
        long long first = q.front();
        q.pop();
        visited[first] = true;
        for(long long i=0; i<edges[first].size(); i++){
            long long k = edges[first][i];
            // if(k==n-1){
            //     visited[n-1] = true;
            //     count++;
            //     break;
            // }
            if(k==i) continue;
            if(visited[k]) continue;
            distance[k] = distance[first]+1;
            q.push(k);
            visited[k] = true;
            
        }
        // if(visited[n-1]) break;
        // count++;
    }
    return distance[n-1];
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    vector<int> edges[1000010];
    bool visited[10010];
    while(t--){
        int n, m;
        cin>>n>>m;
        int* distance = new int[n+1];
        for(int i=0; i<=n; i++){
            distance[i] = 0;
        }
        for(int i=0; i<=n; i++){
            edges[i].clear();
            visited[i] = false;
        }
        while(m--){
            int a, b;
            cin>>a>>b;
            edges[a-1].push_back(b-1);
        	edges[b-1].push_back(a-1);
        }
        long long ans = f(edges, n, 0, visited, distance);
        cout<<ans<<endl;
        
    }
    return 0;
}
