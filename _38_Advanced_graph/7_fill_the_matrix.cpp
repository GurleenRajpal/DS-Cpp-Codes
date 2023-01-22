// Fill the Matrix
// Send Feedback
// A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an 
// array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.
// You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are 
// filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries 
// of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
// Input Format:
// The first line of the input contains an integer T denoting the number of test cases.

// The first line of each test case contains two space separated integers N, Q.

// Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
// Constraints:
// 1 ≤ T ≤ 20
// 2 ≤ N ≤ 10^5
// 1 ≤ Q ≤ 10^5
// 1 ≤ i, j ≤ N
// 0 ≤ val ≤ 1
// Output Format:
// For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
// Sample Input 1:
// 1
// 5 4
// 1 2 0
// 2 2 0
// 5 2 1
// 2 1 1
// Sample Output 1:
// no

#include<bits/stdc++.h>
using namespace std;

bool firstCheck(int** mat, int n){
    bool res = true;
    for(int i=0; i<n; i++){
        if(mat[i][i]==1){
            res = false;
            return res;
        }
    }
    // cout<<"here"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]!=mat[j][i] && mat[i][j]!=2 && mat[j][i]!=2){
                // cout<<i<<" "<<j<<endl;
                res = false;
                return res;
            }
        }
    }
    return res;
}
 bool bipartite( vector<int> *graph, int n)
{
     if(n==0){
         return true;
     }
    unordered_set<int> st[2];
    vector<int> pending;
    pending.push_back(0);
    st[0].insert(0);
    // visited[0] = true;
    while (!pending.empty())
    {
        int curr = pending.back();
        int currSet = st[0].count(curr) > 0 ? 0 : 1;
        pending.pop_back();
        for (int i=0; i<graph[curr].size(); i++)
        {
            int neighbour = graph[curr][i];
            // visited[neighbour] = true;
            if (!st[0].count(neighbour) && !st[1].count(neighbour))
            {
                st[1 - currSet].insert(neighbour);
                pending.push_back(neighbour);
            }
            else if (st[currSet].count(neighbour) > 0)
            {
                return false;
            }
        }
    }
    return true;
}
int getParent(int a, int parent[]){
    if(parent[a]==a){
        return a;
    }
    return parent[a] = getParent(parent[a], parent);
}


void unite(int x, int y, int parent[], int rank[]){
    int p1 = getParent(x, parent);
    int p2 = getParent(y, parent);
    if(p1==p2)return;
    if(rank[p1]<rank[p2]){
        parent[p1] = p2;
    }
    else if(rank[p1]>rank[p2]){
        parent[p2] = p1;
    }
    else{
        parent[p2] = p1;
        rank[p1]++;
        
    }
}
bool isBipartite(vector<int>* edges,int n)
{
    vector<int> pending;
    int set[n];
    for(int i=0;i<n;i++)
        set[i]=-1;
    int fl=0;
    for(int i=0;i<n;i++)
    {
        if(set[i]==-1)
        {
            pending.push_back(i);
            set[i]=0;
            while(!pending.empty())
            {
                int curr=pending.back();
                pending.pop_back();
                for(int j=0;j<edges[curr].size();j++)
                {
                    int nw=edges[curr][j];
                    if(set[nw]==-1)
                    { 
                     set[nw]=1-set[curr];
                     pending.push_back(nw);
                    }
                    else if(set[curr]==set[nw])
                        return false;
                   
                }
            }
        }
    }
    return true;
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        int parent[n];
      	vector<int>* edges = new vector<int>[n];
        bool flag = true;
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int rank[n] = {0};
        
        while(q--){
            int a, b, c;
            cin>>a>>b>>c;
            a--;
            b--;
            if(a==b){
                if(c==1){
                    flag = false;
                }
            }
            if(c==0){
                unite(a, b, parent, rank);
            }
            else{
                edges[a].push_back(b);
                edges[b].push_back(a);
            }
            
        }
        if(!flag){
            cout<<"no"<<endl;
            continue;
        }
        vector<int>* newGraph = new vector<int>[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<edges[i].size(); j++){
                int p1 = getParent(i, parent);
                int p2 = getParent(edges[i][j], parent);
                if(p1==p2){
                    flag = false;
                    break;
                }
                else{
                    newGraph[p1].push_back(p2);
                    newGraph[p2].push_back(p1);
                }
            }
            if(!flag)break;
        }
        if(!flag){
            cout<<"no"<<endl;
            continue;
        }
//         bool* visited = new bool[n];
//         for(int i=0; i<n; i++){
//             visited[i] = false;
//         }
//         for(int i=0; i<n; i++){
//             if(!visited[i]){
//                 flag = bipartite(newGraph, i, n, visited);
//                 if(flag==false)break;
//             }
            
//         }
        if(bipartite(newGraph, n)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
