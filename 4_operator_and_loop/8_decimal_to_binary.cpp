// Decimal to Binary
// Send Feedback
// Given a decimal number (integer N), convert it into binary and print.
// The binary number should be in the form of an integer.

// Input format :
// Integer N

// Output format :
// Corresponding Binary number (long)

// Constraints :
// 0 <= N <= 10 ^ 5

// Sample Input 1 :
// 12

// Sample Output 1 :
// 1100

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    long long ans = 0;
    int n;
    cin >> n;
    long long pow = 1;

    int highest = 0;
    int i = 0;
    int rem = 0;
    while (n)
    {
        rem = n % 2;

        ans = ans + pow * rem;

        pow = pow * 10;

        n = n / 2;
    }
    cout << ans << endl;

    return 0;
}
