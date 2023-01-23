//  PARTY - Problem
// Send Feedback
// You just received another bill which you cannot pay because you lack the money.
// Unfortunately, this is not the first time to happen, and now you decide to investigate the cause 
// of your constant monetary shortness. The reason is quite obvious: the lion's share of your money 
//   routinely disappears at the entrance of party localities.
// You make up your mind to solve the problem where it arises, namely at the parties themselves. 
// You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
// You inquire beforehand about the entrance fee to each party and estimate how much fun you might have 
// there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
// Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that 
// your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
// Input Format:

// First line of input will contain an integer N (number of parties).
// Next line of input will contain N space-separated integers denoting the entry fee of Ith party.
// Next line will contain N space-separated integers denoting the amount of fun Ith party provide.
// Last line of input will contain an integer W party budget.

// Output Format:

// For each test case your program must output the sum of the entrance fees and the sum of all 
// fun values of an optimal solution. Both numbers must be separated by a single space. 
// Note: In case of multiple cost provides the maximum fun output the minimum total cost.

// Sample Input:

// 5
// 1 7 9 7 2 
// 5 5 2 4 7 
// 12

// Sample Output:

// 10 17

#include<bits/stdc++.h>
using namespace std;

pair<int, int> f(int* wn, int* vn, int n, int x, pair<int, int>** dp){
    if(n<0){
        return make_pair(0, 0);
    }
    if(n==0){
        if(wn[0]<=x){
            int v1, v2;
            v1 = wn[0];
            v2 = vn[0];
            return make_pair(v1, v2);
        }
        else{
            return make_pair(0, 0);
        }
    }
    
    if(dp[n][x]!=make_pair(-1, -1)) return dp[n][x];
    
    pair<int, int> pick = make_pair(0, 0);
    if(x>=wn[n]){
        pick = f(wn, vn, n-1, x-wn[n], dp);
        pick.first += wn[n];
    	pick.second += vn[n];
    }
    
    pair<int, int> notPick = f(wn, vn, n-1, x, dp);
    
    pair<int, int> ans;
    if(notPick.second>pick.second){
        ans = notPick;
    }
    else{
        ans = pick;
    }
    
    return dp[n][x] = ans;
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int* b = new int[n];
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    int x;
    cin>>x;
    
    pair<int, int>** dp = new pair<int, int>*[n];
    for(int i=0; i<n; i++){
        dp[i] = new pair<int, int>[x+1];
        for(int j=0; j<=x; j++){
            dp[i][j] = make_pair(-1, -1);
        }
    }
    
    
    pair<int, int> v = f(a, b, n-1, x, dp);
    cout<<v.first<<" "<<v.second<<endl;
    return 0;
}
