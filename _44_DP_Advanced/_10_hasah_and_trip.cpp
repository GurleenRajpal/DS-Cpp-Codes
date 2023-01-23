//  Hasan and Trip
// Send Feedback
// Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
// There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, 
// i-th city is in (Xi, Yi).
// Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be 
// N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
// Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't 
// like traveling too much, so his happiness will decrease by total distance traveled by him.
// Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
// Input format:

// First line will contain T(number of test case).
// First line of each test case will contain an integer N 
// Next N lines of that test case will contain three space-separated integers Xi, Yi, Fi (coordinates and happiness)

// Output format:

// For each test Output one number rounded to 6 digits after floating point, the maximum possible happiness in newline, Hasan can get. 
// Note: If answer is 2 print 2.000000

// Constraints:

// 1 <= T <= 50
// 1 <= N <= 500
// 0 <= Xi, Yi, Fi <= 100,000

// Sample Input

// 1
// 3
// 0 0 1
// 3 1 1
// 6 0 9

// Sample Output

// 4.675445

#include<bits/stdc++.h>
using namespace std;
double f(double** a, int si, int ei, double* dp){
    if(si>ei){
        return -1e9;
    }
    if(si==ei){
        for(int i=0; i<si; i++){
            double x = a[i][0]-a[si][0];
        	double y = a[i][1]-a[si][1];
        	double z = x*x+y*y;
        	double w = sqrt(z);
        	dp[si] = max(dp[si],dp[i]+a[si][2]-w);
        }
        return dp[si];
    }
    
    if(dp[si]!=-2e9) return dp[si];
    
    for(int i=0; i<si; i++){
        double pick = 0;
    	double x = a[i][0]-a[si][0];
    	double y = a[i][1]-a[si][1];
    	double z = x*x+y*y;
    	double w = sqrt(z);
    
    
    	pick = a[si][2] - w + f(a, si+1, ei, dp);
    // dp[si] = max(pick, dp[si]);
    	double notPick = f(a, si+1, ei, dp);
        
        dp[si] = max(pick, max(notPick, dp[si]));
    }
	
    
    return dp[si];
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double** a = new double*[n];
        for(int i=0; i<n; i++){
            a[i] = new double[3];
            for(int j=0; j<=2; j++){
                cin>>a[i][j];
            }
        }
        double* dp = new double[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = -2e9;
        }
        dp[0] = 0;
    	//double count = dp[0] + f(a, 1, n-1, dp);
        for(int i=0; i<n; i++){
            dp[i]+=a[i][2];
            for(int j=i+1;j<n; j++){
                double distance = 0;
                double x = a[i][0] - a[j][0];
                double y = a[i][1] - a[j][1];
                double z = x*x+y*y;
                z = sqrt(z);
                dp[j] = max(dp[j], dp[i] - z);
            }
        }
        printf("%.6f",dp[n-1]);
        cout<<endl;
    }
    return 0;
}
