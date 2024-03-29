// Ninja and Flowers
// Send Feedback
// Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
// Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower 
// is a prime divisor of another flower they needed to be of a different colour.
// As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.
// Input Format:
// The only line of input will contain an integer N (number of flowers).
// Output Format:
// In first-line print K, the minimum number of different colour boxes that are needed to pack the flowers.
// Next line contains K space-separated integers in sorted order denoting the counts of the different coloured boxes.
// Constraints:
// 1 <= N <= 2*10^5
// Sample Input:
// 4
// Sample Output:
// 2
// 1 3

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int n;
    cin>>n;
    vector<bool> v(n+2, true);
    
    v[0] = false;
    v[1] = false;
    
    for(int i=2; i*i<=n+1; i++){
        if(v[i]==false){
            continue;
        }
        for(int j=i*i; j<=n+1; j+=i){
            if(j%i==0){
                v[j] = false;
            }
        }
        
    }
    
    int ct1=0, ct2 = 0;
    
    for(int i=2; i<=n+1; i++){
        if(v[i])ct1++;
        else ct2++;
    }
    
    cout<<2<<endl;
    if(ct2<ct1){
        cout<<ct2<<" "<<ct1<<endl;
    }
    else{
        cout<<ct1<<" "<<ct2<<endl;
    }
    
    
    return 0;
}
