//  Shortest Subsequence
// Send Feedback
// Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
// Note: The input data will be such that there will always be a solution.
// Input Format :

// The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.

// Output Format :

// Length of shortest subsequence in S such that it is not a subsequence in V

// Constraints:

// 1 <= |S| <= 1000 (|x| implies the length of the string x)
// 1 <= |V| <= 1000 
// Time Limit: 1 second

// Sample Input 1:

// babab
// babba

// Sample Output 1:

// 3

// Explanation:

// "aab" is the shortest subsequence which is present in S and absent in V.


#include<vector>
int helper(string s, int si, string v,int vi, vector<vector<int>>& dp){
    if(s.length()==0){
        return 1000000000;
    }
    if(vi>=v.length()){
        return 1;
    }
    
    if(dp[s.length()][v.length()]!=-1) return dp[s.length()][v.length()];
    
    
    char a = s[si];
    int k = 0;
    
    
    for(k=vi; k<v.length(); k++){
        if(a==v[k]) break;
    }
    
    if(k==v.length()) return 1;
    
    int pick = helper(s.substr(1), si, v, vi, dp);
    int notPick = 1+helper(s.substr(1), si, v.substr(vi+k+1), vi, dp);
    
    return dp[s.length()][v.length()] = min(pick, notPick);
    
}


int solve(string s, string v) {
    // Write your code here
    int sl = s.length();
    int vl = v.length();
    
    vector<vector<int> > dp(sl+1, vector<int>(vl+1, -1));
    
    return helper(s, 0,v, 0, dp);
}
