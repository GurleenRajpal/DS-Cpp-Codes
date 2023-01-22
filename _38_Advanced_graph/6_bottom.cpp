// BOTTOM
// Send Feedback
// We will use the following (standard) definitions from graph theory. Let V be a non-empty and 
//   finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian
//   product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.
// Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such 
// that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 
// to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).
// Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w 
// in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of 
// all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// First line will contain two space-separated integers N and M denoting the number of vertex and edges respectively.
// Next M line will contain two space separated integers a, b denoting an edge from a to b.
// Output Format:
// For each test case output the bottom of the specified graph on a single line. 
// Constraints:
// 1 <= T <= 50
// 1 <= N, M <= 10^5
// Sample Input:
// 1
// 3 6
// 3 1
// 2 3
// 3 2
// 1 2
// 1 3
// 2 1
// Sample Output:
// 1 2 3 

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void dfs(vector<int>* edges, int index, bool* visited, stack<int>& s,int n){
    visited[index] = true;
    for(int i=0; i<edges[index].size();i++){
        if(!visited[edges[index][i]]){
            dfs(edges, edges[index][i], visited, s, n);
        }
    }
    s.push(index);
}

void dfs2(vector<int>* edges, unordered_set<int>* component, int first,  bool* visited){
    component->insert(first);
    visited[first] = true;
    for(int i=0; i<edges[first].size(); i++){
        if(!visited[edges[first][i]]){
            dfs2(edges, component, edges[first][i], visited);
        }
    }
    
    
}


unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n){
    stack<int> s;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            dfs(edges, i, visited, s, n);
        }
    }
    
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    while(!s.empty()){
        int first = s.top();
        s.pop();
        if(visited[first])continue;
        unordered_set<int>* component = new unordered_set<int>();
        dfs2(edgesT, component, first, visited);
        output->insert(component);
    }
    
    return output;
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        int n, m;
        cin>>n>>m;
        
        vector<int>* edges = new vector<int>[n];
        vector<int>* edgesT = new vector<int>[n];
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            edges[a-1].push_back(b-1);
            edgesT[b-1].push_back(a-1);
        }
        
        
        unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
        vector<int> bottom;
        unordered_map<int, int> mp;
        int index = 1;
        unordered_set<unordered_set<int>*>::iterator it = components->begin();
        while(it!=components->end()){
            unordered_set<int>* comp = *it;
            unordered_set<int>::iterator it2 = comp->begin();
            while(it2!=comp->end()){
                // cout<<*it2+1<<" ";
                mp[*it2] = index;
                it2++;
            }
            it++;
            index++;
            // cout<<endl;
        }
        // cout<<endl;
        
        // cout<<mp[1]<<" "<<mp[2]<<" "<<mp[3]<<endl;
        it = components->begin();
        while(it!=components->end()){
            int flag = 0;
            unordered_set<int>* comp = *it;
            unordered_set<int>::iterator it2 = comp->begin();
           	while(it2!=comp->end()){
                int x = *it2;
                for(int k=0; k<edges[x].size(); k++){
                    if(mp[edges[x][k]]!=mp[x]){
                        flag = 1;
                    }
                }
                if(flag){
                    break;
                }
                it2++;
            }
            if(flag==0){
                it2 = comp->begin();
                while(it2!=comp->end()){
                    bottom.push_back(*it2+1);
                    it2++;
                }
            }
            it++;
        }
        sort(bottom.begin(), bottom.end());
        for(int i=0; i<bottom.size(); i++){
            cout<<bottom[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
