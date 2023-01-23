//  Collinear Points
// Send Feedback
// You are given a set of 3 points in a 2-D plane. You have to find out whether they are collinear or not.
// Input Format:

// First line of input will contain T, representing the number of test cases.
// Each test case contains three lines containing two space separated integers x and y, respectively, denoting the points in 2-D plane.

// Constraints:

// 1 <= T <= 10^5
// -10^6 <= x, y <= 10^6

// Ouput Format:

// For each test case output "YES" if they are collinear and "NO" if they are not.

// Sample Input:

// 2
// 1 3
// 1 4
// 1 5
// -1 0
//  0 1
//  1 0

// Sample Output:

// YES 
// NO


#include<bits/stdc++.h>
using namespace std;
bool toChange(pair<long long, long long> p, pair<long long, long long> q, pair<long long, long long> r){
    //pq, qr
    long long pqx = q.first - p.first;
    long long pqy = q.second - p.second;
    long long qrx = r.first - q.first;
    long long qry = r.second - q.second;

    long long val = pqx * qry - pqy * qrx;
    return val==0;
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        pair<long long, long long> p, q, r;
        cin>>p.first>>p.second>>q.first>>q.second>>r.first>>r.second;
        if(toChange(p, q, r)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
