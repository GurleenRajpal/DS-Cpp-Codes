// AIRPORTS
// Send Feedback
// The government of a certain developing nation wants to improve transportation in one of its 
// most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
// Of course, one option is to build an airport in each of these places, but it may turn out to 
//   be cheaper to build fewer airports and have roads link them to all of the other locations. Since 
//   these are long distance roads connecting major locations in the country 
//   (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one 
//   direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one 
//   road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
// A location is considered to have access to an airport either if it contains an airport or if it 
//   is possible to travel by road to another location from there that has an airport. You are given the cost of 
//   building an airport and a list of possible roads between pairs of locations and their corresponding costs. 
//   The government now needs your help to decide on the cheapest way of ensuring that every location has access 
//   to an airport. The aim is to make airport access as easy as possible, and with minimum cost.
// Input Format:
// The first line of input contains the integer T (the number of test cases), each test case follow as.
// Line1: Three space-separated integers N, M and cost number of locations, number of possible roads and cost of airport respectively
// The following M lines each contain three integers X, Y and C, separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
// Output Format:
// For each test case print the cost in a newline.
// Constraints:
// 1 <= T <= 20
// 1 <= N, M <= 10^5
// 1 <= cost <= 10^9
// 1 <= weight(of each road) <= 10^9
// Sample Input
// 2
// 4 4 100
// 1 2 10
// 4 3 12
// 4 1 41
// 2 3 23
// 5 3 1000
// 1 2 20
// 4 5 40
// 3 2 30
// Sample Output
// 145
// 2090

#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
        long long f, s, w;
};


bool comp(edge a, edge b){
    return a.w<b.w;
}


long long getParent(long long v, long long* parent){
    if(parent[v]==v){
        return v;
    }
    return parent[v] = getParent(parent[v], parent);
}

void makeUnion(long long a, long long b, long long* parent){
    parent[getParent(a, parent)] = getParent(b, parent);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        long long n, m, cost;
        cin>>n>>m>>cost;

        edge* edges = new edge[m];
        for(int i=0; i<m; i++){
            int a, b, c;
            cin>>a>>b>>c;
            edges[i].f = a;
            edges[i].s = b;
            edges[i].w = c;
        }
        
        sort(edges, edges+m, comp);
        
        long long* parent = new long long[n+1];
        for(long long i=0; i<=n; i++){
            parent[i] = i;
        }
        long long total = 0;
        long long j = 0;
        for(long long i=0;j<n-1 &&  i<m && edges[i].w<cost; i++){
            long long firstV = edges[i].f;
            long long secV = edges[i].s;
            long long weight = edges[i].w;
            if(getParent(firstV, parent )!=getParent(secV, parent)){
                total += weight;
                makeUnion(firstV, secV, parent);
                j++;
            }
        }
        long long rem  = 0;
         for(long long i=1; i<=n; i++){
            if(parent[i] == i){
                rem++;
            }
        }
        total += cost*rem;
        cout<<total<<endl;
    }
    return 0;
}
