//  Alyona and Spreadsheet
// Send Feedback
// During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
// Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j 
// we will denote the integer located at the i-th row and the j-th column. We say that the table is 
// sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
// Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to 
// answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will 
// the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j 
// that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
// Alyona is too small to deal with this task and asks you to help!
// Input Format:

// First line of input will contain T(number of test case), each test case is described as.
// The first line of the each test case contains two positive integers n and m the number of rows and 
//   the number of columns in the table respectively.
// Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j.

// The next line of the input contains an integer k, the number of task that teacher gave to Alyona.

// The i-th of the next k lines contains two integers li and ri

// Output Format:

// For each test case, print "Yes" to the i-th line of the output if the table consisting of rows from li to ri 
// inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".

// Constriants:

// 1 <= T <= 10
// 1 <= N, M <=  20000
// 1 <= N*M <= 20000
// 1 <= arr[i][j] <= 10^9
// 1 <= K <= 10000
// 1 <= l <= r <= N

// Sample Input :

// 1
// 3 11
// 5 1 3 4 5 1 5 5 3 3 2 
// 5 8 2 10 1 9 8 4 4 3 4 
// 15 6 9 2 7 1 3 13 7 7 5 
// 1
// 1 3

// Sample Output :

// Yes


#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        
        int** a = new int*[n];
        for(int i=0; i<n; i++){
            a[i] = new int[m];
            for(int j=0; j<m; j++){
                cin>>a[i][j];
            }
        }
        
        int** dp = new int*[n];
        for(int i=0; i<n; i++){
            dp[i] = new int[m];
            for(int j=0; j<m; j++){
                dp[i][j] = -1;
            }
        }
        
        for(int i=0; i<m; i++){
            dp[0][i] = 0;
        }
        int* result = new int[n];
        for(int i=0; i<n; i++){
            result[i] = 1e9;
        }
        
        for(int i=1; i<n; i++){
            //result[i] = dp[i][0];
            for(int j=0; j<m; j++){
                if(a[i][j]>=a[i-1][j]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = i;
                }
                //result[i] = min(result[i], dp[i][j]);
            }
            
        }
        for(int i=0; i<n; i++){
            result[i] = 1e9;
            for(int j=0; j<m; j++){
                result[i] = min(dp[i][j], result[i]);
            }
        }
        
        int k;
        cin>>k;
        
        while(k--){
            int l, r;
            cin>>l>>r;
            l = l-1;
            r = r-1;
            if(result[r]<=l){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        
    }
    return 0;
}
