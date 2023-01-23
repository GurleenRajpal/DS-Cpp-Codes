// Charlie and Pilots
// Send Feedback
// Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. 
// There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of 
// two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him 
// two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for 
// the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will 
// compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to 
// make the optimal (i.e. the cheapest) arrangement of pilots in crews.
// Input Format:
// First line will contain T(number of test case), each test case as follow.
// The first line of each test case contains integer N, N is even, the number of pilots working for the Charlie's company.
// The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest 
// pilot are given the first. Each of those N lines contains two integers separated by a space character, a salary as a captain (X) and a salary as an assistant (Y).
// Constraints
// 1 <= T <= 20
// 2 ≤ N ≤ 1000
// 1 ≤ Y < X ≤ 100000
// Output Format:
// For each test case print the minimal amount of money Charlie needs to give for the pilots' salaries. in newline. 
// Sample Input
// 1
// 4 
// 5000 3000 
// 6000 2000 
// 8000 1000 
// 9000 6000 
// Sample Output
// 19000 
// Explanation
// Out of various possible, optimal arrangements will be:
// Plane Crew 1 will have Pilot1 as an assistant and Pilot2 as a Captain
// Plane Crew2 will have Pilot3 as an assistant and Pilot4 as a Captain
// Amount of money required= 3000+6000+1000+9000 =19000.   

#include<bits/stdc++.h>
using namespace std;

int f(int* c, int* a, int n, int x, int** dp){
    if(n<=0){
        return 0;
    }
    
    if(x==0){
        return dp[n][x] = a[0]+f(c+1, a+1, n-1, x+1, dp);
    }
    if(x==n){
        return dp[n][x] = c[0]+f(c+1, a+1, n-1, x-1, dp);
    }
    
    if(dp[n][x]!=-1)return dp[n][x];
    
    int val1 = a[0]+f(c+1, a+1, n-1, x+1, dp);
    int val2 = c[0]+f(c+1, a+1, n-1, x-1, dp);
    
    return dp[n][x] = min(val1, val2);
    
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int* a = new int[n];
        int* c = new int[n];
        
        int* visited = new int[n];
        
        for(int i=0; i<n; i++){
            cin>>c[i]>>a[i];
        }
        
        int** dp = new int*[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = new int[n+1];
            for(int j=0; j<=n; j++){
                dp[i][j] = -1;
            }
            //dp[i] = -1;
        }
        
        int ans = f(c, a, n, 0, dp);
        
        cout<<ans<<endl;
        
    }
    return 0;
}
