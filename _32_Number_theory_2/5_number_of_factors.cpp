// Number Of Factors
// Send Feedback
// A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers 
// a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
// Input Format:
// First line of input will contain T(number of test cases), each test case follows as.
// Each test cases consists of a single line containing integers a, b, and n as described above.
// Output Format:
// Output for each test case one line containing the number of n-factorful integers in [a, b].
// Constraints:
// 1 <= T <= 10000
// 1 ≤ a ≤ b ≤ 10^6
// 0 <= b - a <= 100
// 0 ≤ n ≤ 10
// Sample Input
// 4
// 1 3 1
// 1 10 2
// 1 10 3
// 1 100 3
// Sample Output
// 2 
// 2
// 0
// 8


#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int z = 1e6+1;
    vector<bool> v(z, true);
    v[0] = false;
    v[1] = false;
    
    for(int i=2; i*i<z; i++){
        if(v[i]==false){
            continue;
        }
        for(int j=i*i; j<z; j+=i){
            v[j] = false;
        }
    }
    
    vector<int> factors(z, 0);
    
    for(int i=2; i<z; i++){
        if(v[i]==false){
            continue;
        }
        if(v[i]==true){
            factors[i] = 1;
            for(int j=2*i; j<z; j+=i){
                factors[j]+=1;
            }
            continue;
        }
    }
    
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        int count = 0;
        for(int i=a; i<=b; i++){
            if(factors[i]==n){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
