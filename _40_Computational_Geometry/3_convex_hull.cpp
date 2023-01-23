//  Convex Hull
// Send Feedback
// Given a set of points in the plane, the Convex Hull of the set is the smallest convex polygon that contains all the points of it.
// Find out the convex hull for the given set of points.
// Input Format:

// First line of input contains integer N, representing number of points.
// Second line contains N space separated integers, which are the X coordinates.
// Third line contains N space separated integers, which are the Y coordinates.

// Constraints:

// 1 <= N <= 10^5
// 1 <= X[i] <= 10^4
// 1 <= Y[i] <= 10^4
// Also input is given in such a way that the number of points on the hull doesn't exceed 50

// Output Format:

// Print the X coordinate and the Y coordinate of all the points seperated by space. Order doesn't matter.

// Sample Input:

// 5
// 2 1 7 9 7 
// 2 5 5 2 4 

// Sample Output:

// 1 5
// 2 2
// 9 2
// 7 5


#include<bits/stdc++.h>
using namespace std;

bool toChange(pair<long long, long long> p, pair<long long, long long> q, pair<long long, long long> r){
    //pq, qr
    long long pqx = q.first - p.first;
    long long pqy = q.second - p.second;
    long long qrx = r.first - q.first;
    long long qry = r.second - q.second;

    long long val = pqx * qry - pqy * qrx;
    return val<0;
}


void convex(pair<long long, long long>* arr, long long n){
    long long p = 0;
    for(long long i=1; i<n; i++){
        if(arr[i].first<arr[p].first){
            p = i;
        }
    }   
    //start from left most
    long long q, r;
    vector<pair<long long, long long>> v;
    long long start = p;
    do{
        v.push_back(arr[p]);
        q = (p+1)%n;

        for(long long i=0; i<n; i++){
            if(toChange(arr[p], arr[q], arr[i])){
                q = i;
            }
        }

        p = q;

    }while(p!=start);

    for(long i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return;
}


int main(){
    
    // write your code here

    long long n;
    cin>>n;
    long long* x = new long long[n];
    for(long long i=0; i<n; i++){
        cin>>x[i];
    }
    long long* y = new long long[n];
    for(long long i=0; i<n; i++){
        cin>>y[i];
    }

    pair<long long, long long>* p = new pair<long long, long long>[n];
    for(long long i=0; i<n; i++){
        p[i].first = x[i];
        p[i].second = y[i];
    }

    convex(p, n);

    return 0;
}
