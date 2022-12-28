// Count Zeros
// Send Feedback
// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
// Input Format :
// Integer N
// Output Format :
// Number of zeros in N
// Constraints :
// 0 <= N <= 10^9
// Sample Input 1 :
// 0
// Sample Output 1 :
// 1
// Sample Input 2 :
// 00010204
// Sample Output 2 :
// 2



int countZeros(int n) {
    // Write your code here
    
    if(n==0){
        return 1;
    }
    if(n<10){
        return 0;
    }
    
    int ans = 0;
    int k;
    if(n%10==0){
        k=1;
    }
    else{
        k=0;
    }
    
    ans=k+countZeros(n/10);
    
    return ans;
}


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}


