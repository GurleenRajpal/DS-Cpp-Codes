// Fractional Knapsack
// Send Feedback
// You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select 
// the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
// Note: You are allowed to break the items in parts.
// Input Format:
// The first line of input contains two space separated integers, that denote the value of N and W.
// Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.    
// Constraints:
// 1 <= N = 2*10^5
// 1 <= W <= 10^9
// 1 <= value, weight <= 10^5
// Time Limit: 1 sec
// Output Format:
// Print the maximum total value upto six decimal places.
// Sample Input 1:
// 4 22
// 6 4
// 6 4
// 4 4
// 4 4
// Sample Output 1:
// 20.000000
// Explanation:
// The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, 
// we will add all the items in the knapsack and total value will be 20 units.

#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

bool sf(pair<int, int>& a, pair<int, int>&b){
    return (a.first*1.0/a.second)>(b.first*1.0/b.second);
}

int main(){
    
    // write your code here
    int n, w;
    cin>>n>>w;
    
    pair<int, int>* a = new pair<int, int>[n];
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;
    }
    
    sort(a, a+n, sf);
    
    // for(int i=0; i<n; i++){
    //     cout<<a[i].first<<" "<<a[i].second<<endl;
    // }
    
    int weight = 0;
    int k = 0;
    double value = 0.0;
    while(weight<=w && k<n){
        if(weight+a[k].second>w){
            break;
        }
        value += a[k].first;
        w -= a[k].second;
        k++;
    }
    cout<<fixed<<setprecision(6);
    if(k==n){
        cout<<fixed<<setprecision(6)<<value<<endl;
        return 0;
    }
    
    float fractMass = (w*1.0)/a[k].second;
    
    value += (fractMass)*a[k].first;
    
    cout<<fixed<<setprecision(6)<<value<<endl;
    
    
    return 0;
}
