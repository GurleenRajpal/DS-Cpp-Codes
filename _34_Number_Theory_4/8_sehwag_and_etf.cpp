// Sehwag and ETF
// Send Feedback
// Sehwag has been solving a lot of mathematical problems recently. 
//   He was learning ETF (Euler Totient Function) and found the topic quite interesting. 
//   So, he tried solving a question on ETF. He will be given two numbers L and R. He has to 
//   find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
// Input Format:
// The first line contains an integer T, representing the number of test cases.
// The next T lines will contain three integers L, R and K.
// Constraints:
// 1 <= T <= 10
// 1 <= L <= R <= 10^12
// 0 <= R - L <= 10^5
// 1 <= K <= 10^6
// Output Format:
// Print the answer in a new line after rounding off the first 6 digits after the decimal place.
// Sample Input 1:
// 3
// 1 4 2
// 2 5 2
// 3 10 4
// Sample Output 1:
// 0.500000
// 0.750000
// 0.375000

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define MAX 1100001


bool primes[MAX];
vector<long long> prime_num;

void computePrimes(bool primes[]){
    
    for(long long i=0; i<MAX; i++){
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    primes[2] = true;
    // prime_num.push_back(2);
    for(long long i=2; i<MAX; i++){
        if(primes[i]){
            for(long long j=i*i; j<MAX; j+=i){
                primes[j] = false;
            }
            prime_num.push_back(i);
        }
    }
}

int main()
{
	bool primes[MAX];
    computePrimes(primes);
    
   // cout<<"here"<<endl;
    // int ans = 0;
    // return 0;
    int t;
    cin>>t;
    while(t--){
        long long l, r, k;
        cin>>l>>r>>k;
//         unordered_map<long long, vector<long long>> mp;
//         for(long long i = 0; prime_num[i]<=r && i<prime_num.size() ; i++){
//             long long curr = prime_num[i];
//             // cout<<curr<<endl;
//                 // cout<<curr<<" curr\n";
//             long long firstPosition = (r/curr)*curr;
//             while(firstPosition>=l){
//                 mp[firstPosition].push_back(curr);
//                 firstPosition-= curr;
//             }
            
//         }
        vector<int> segmented_etf(r-l+1);
        vector<int> numbers(r-l+1);
        
        for(int i = 0; i <= r-l; i++) {
            // numbers[i] is actually l+i, because it is shifted by 'L'
            segmented_etf[i] = l+i;
            numbers[i] = l+i;
        }
        for(long long i = 0; prime_num[i]<=r && i<prime_num.size() ; i++){
            // current prime
            long long curr = prime_num[i];
            long long firstPosition = (r/curr)*curr;
            if(firstPosition > r) {
                // To get the first index within [L,R] segmented sieve range
                firstPosition -= curr;
            }
            while(firstPosition>=l){
                // firstPosition is actually index "firstPosition - l" in segmented sieve range
                // Multiplying current etf with (1 - 1/p)
                segmented_etf[firstPosition - l] /= curr;
                segmented_etf[firstPosition - l] *= curr-1;
                // Reducing all the powers of "p" from the current number
                while(numbers[firstPosition - l] % curr == 0) {
                    numbers[firstPosition - l] /= curr;
                }
                firstPosition -= curr;
            }
        }
        
        for(int i = 0; i <= r-l; i++) {
            // Technically all the numbers[i] should become 1, as all prime powers have been reduced.
            // But for some numbers, one prime number can still remain
            // So numbers[i] is actually the only prime number left
            // So we include it in the answer of ETF.
            if(numbers[i] > 1) {
                segmented_etf[i] /= numbers[i];
                segmented_etf[i] *= numbers[i]-1;
            }
        }
                
        
        
        
        long long ans = 0;
        long long phi = 0;
        // unordered_map<int, vector<int>>::iterator it;
        for(int i = 0; i <= r-l; i++) {
            // Just calculating the total ETFs divisible by k
            if(segmented_etf[i] % k == 0) {
                ans++;
            }
        }
        double res = (double)ans/(r-l+1);
        printf("%.6f\n", res);
        
    }
    
    // Write your code here
    

}
