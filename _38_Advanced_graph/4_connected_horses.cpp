// Connected Horses
// Send Feedback
// You all must be familiar with the chess-board having 8 x 8 squares of alternate black and white cells. Well, 
// here we have for you a similar N x M size board with similar arrangement of black and white cells.
// A few of these cells have Horses placed over them. Each horse is unique. Now these horses are not the usual 
// horses which could jump to any of the 8 positions they usually jump in. They can move only if there is another 
// horse on one of the 8-positions that it can go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
// A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the
// state of the board, calculate answer. Since this answer may be quite large, calculate in modulo 10^9+7.
// Input Format:
// First line contains T which is the number of test cases.
// T test cases follow first line of each containing three integers N, M and Q where N,M is the size of the board and Q is the number of horses on it.
// Q lines follow each containing the 2 integers, X and Y which are the coordinates of the Horses.
// Output format:
// For each test case, output the number of photographs taken by a photographer in new line.
// Constraints:
//  1<=T<=10
//  1<=N,M<=1000
//  1<=Q<=N*M
// Sample Input:
// 2
// 4 4 4
// 1 1
// 1 2
// 3 1
// 3 2
// 4 4 4
// 1 1
// 1 2
// 3 1
// 4 4
// Sample Output:
// 4
// 2

// we find connected components, and then
// we multiply  the factorial of the total number of components 



#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

bool isSafe(int x1, int y1, int n, int m){
    if(x1<0 || y1<0 || x1>=n+1 || y1>=m+1){
        return false;
    }
    return true;
}
long long factorial[100001];
void fact(){
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i=2; i<=100000; i++){
        factorial[i] = (i%MOD*(factorial[i-1])%MOD)%MOD;
    }
}


long long dfs(int** mat, int i, int j, int n, int m){
    long long k = 1;
    mat[i][j] = 0;
    for(int dx = -2; dx<=2 ; dx++){
        for(int dy=-2; dy<=2; dy++){
            if(dx==dy)continue;
            if(dx==0 || dy==0) continue;
            if(dx==-dy) continue;
            //if(dy==-dx) continue;
        	int x1 = i + dx;
            int y1 = j + dy;
            if(isSafe(x1, y1, n, m) && mat[x1][y1]==1){
                // cout<<x1<<" "<<y1<<endl;
                // mat[x1][y1] = 0;
                k += dfs(mat, x1, y1, n, m);
                // mat[x1][y1] = 0;
            }
        }
    }
    return k;
}

long long f(int** mat, int n, int m){
    long long ans = 1;
    for(int i=0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(mat[i][j]==1){
                long long count = dfs(mat, i, j, n, m);
                // cout<<i<<" "<<j<<" "<<count<<endl;
            	ans = (ans%MOD * factorial[count]%MOD );
                // if(ans<0){
                //     ans += MOD;
                // }
                ans = ans%MOD;
            }
        }
    }
    
    return ans%MOD;
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    fact();
    while(t--){
        int n, m, q;
        cin>>n>>m>>q;
        
        int** mat = new int*[n+1];
        for(int i=0; i<=n; i++){
            mat[i] = new int[m+1];
            for(int j=0; j<=m; j++){
             	mat[i][j] = 0;   
            }
        }
        
        while(q--){
            int a, b;
            cin>>a>>b;
            mat[a][b] = 1;
            // cout<<a<<" "<<b<<endl;
        }
        
        long long ans = f(mat, n, m);
        cout<<ans<<endl;
        
    }
    return 0;
}
