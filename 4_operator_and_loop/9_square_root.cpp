// Square Root (Integral)
// Send Feedback
// Given a number N, find its square root. You need to find and print only the integral part of square root of N.
// For eg. if number given is 18, answer is 4.
// Input format :
// Integer N
// Output Format :
// Square root of N (integer part only)
// Constraints :
// 0 <= N <= 10^8
// Sample Input 1 :
// 10
// Sample Output 1 :
// 3

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    cin>>n;
    int i = 0;
    while(i*i<n){
        i++;
    }
    if(n==0){
        cout<<0<<endl;
    }
    else if(i*i==n){
        cout<<i<<endl;
    }
    else{
    	cout<<--i<<endl;
    }
    return 0;
}
