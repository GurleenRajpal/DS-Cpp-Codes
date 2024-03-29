// Binary to decimal
// Send Feedback
// Given a binary number as an integer N, convert it into decimal and print.
// Input format :
// An integer N in the Binary Format

// Output format :
// Corresponding Decimal number (as integer)

// Constraints :
// 0 <= N <= 10^9

// Sample Input 1 :
// 1100

// Sample Output 1 :
// 12

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int ans = 0;
    int pow = 1;
    int k;

    while (n)
    {
        k = n % 10;
        ans = ans + k * pow;
        pow = pow * 2;
        n = n / 10;
    }
    cout << ans << endl;

    return 0;
}
