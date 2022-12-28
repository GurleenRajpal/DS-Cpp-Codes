// Geometric Sum
// Send Feedback
// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
// using recursion.
// Input format :
// Integer k
// Output format :
// Geometric sum (upto 5 decimal places)
// Constraints :
// 0 <= k <= 1000
// Sample Input 1 :
// 3
// Sample Output 1 :
// 1.87500

#include<cstring>
double geometricSum(int k) {
    // Write your code here
	if(k==0){
        return 1;
    }
    
    double n = 1/pow(2,k);

    return n+geometricSum(k-1);
    
}

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
