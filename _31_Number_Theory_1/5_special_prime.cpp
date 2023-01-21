// Special Prime
// Send Feedback
// Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
// You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
// Example of special prime 19 = 7 + 11 + 1
// Neighbouring primes are prime number such that there is no other prime number between them.
// Input Format:
// An integer N.
// Output Format:
// Print the number of special primes
// Constraints:
// 1 <= N <= 2*10^5
// Sample Input:
// 27
// Sample Output:
// 2

#include<bits/stdc++.h>
using namespace std;

void sieve(vector<bool>& v, int n, vector<int>& primes){
    v[0] = false;
    v[1] = false;
    for(int i=2; i*i<n; i++){
        if(v[i]==false){
            continue;
        }
        for(int j = i*i; j<n; j++){
            v[j] = false;
        }
    }
    for(int i=2; i<n; i++){
        if(v[i])primes.push_back(i);
    }
    
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    vector<int> primes;
    vector<bool> v(n+1, true);
    //sieve(v, n+1, primes);
	v[0] = false;
    v[1] = false;
    for(int i=2; i*i<=n; i++){
        if(v[i]==false){
            continue;
        }
        for(int j = i*i; j<=n; j+=i){
            v[j] = false;
        }
    }
    for(int i=2; i<=n; i++){
        if(v[i])primes.push_back(i);
    }    
    vector<bool> x(n+1, false);

    for(int i=0; i<primes.size()-1; i++){
        int k = primes[i]+primes[i+1]+1;
        if(k>n){
            break;
        }
        if(v[k]==true){
        	x[k] = true;   
        }
    }
    primes.clear();
    v.clear();
    
    int count = 0;
    for(int i=0; i<=n; i++){
        if(x[i]) count++;
    }
    cout<<count<<endl;
    
    
    
    return 0;
}
