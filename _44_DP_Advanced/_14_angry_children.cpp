//  Angry Children
// Send Feedback
// Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies 
// and would like to distribute one packet to each of the K children in the village (each packet may contain
// different number of candies). To avoid a fight between the children, he would like to pick K out of N packets 
// such that the unfairness is minimized.
// Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in 
// the ith packet, then we define unfairness as

// unfairness=0;
// for(i=0;i<n;i++)
//     for(j=i;j<n;j++)
//         unfairness+=abs(xi-xj)

// abs(x) denotes absolute value of x.
// Input Format:

// First line will contain T(number of test cases), and each test case consists of two lines.
// The first line contains two space-separated integers N and K.
// The second line will contain N space-separated integers, where Ith integer denotes the candy in the Ith packet.

// Output Format:

// For each test case print a single integer which will be minimum unfairness in newline.

// Constraints

// 1 <= T <= 10
// 2<=N<=10^5
// 2<=K<=N
// 0<= number of candies in each packet <=10^6

// Sample Input

// 1
// 7 3
// 10 100 300 200 1000 20 30

// Sample Output

// 40

// Explanation

// Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. 
// We can verify that it will be minimum in this way.

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        long long* a = new long long[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a, a+n);
        long long uf = INT_MAX;
        long long sum = 0, target = 0;
        for(int i=0; i<k; i++){
            sum+=a[i];
        }
        // for(int i=0; i<k; i++){
        //     for(int j=i; j<k; j++){
        //         target += abs(a[i]-a[j]);
        //     }
        // }
        long long* s = new long long[k];
        s[0] = a[0];
        for(int i=1; i<k; i++){
            s[i] = s[i-1] + a[i];
        }
        for(int i=1; i<k; i++){
            target += i*a[i] - s[i-1];
        }
        uf = target;
        long long new_target = 0;
        for(int i=k; i<n; i++){
            new_target = target - 2 * (sum-a[i-k]) + (k-1)*a[i-k] + (k-1)*a[i];
            sum = sum - a[i-k] + a[i];
            target = new_target;
            uf = min(target, uf);
        }
        cout<<uf<<endl;
        
    }
    return 0;
}
