// Terms of AP
// Send Feedback
// Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.

// Input format :
// Integer x

// Output format :
// Terms of series (separated by space)

// Constraints :
// 1 <= x <= 1,000

// Sample Input 1 :
// 10

// Sample Output 1 :
// 5 11 14 17 23 26 29 35 38 41

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int i = 1;
    int count = 0;
    while (count != n)
    {
        int x = 3 * i + 2;
        if (x % 4 != 0)
        {
            cout << x << " ";
            count++;
        }
        i++;
    }
    cout << endl;
    return 0;
}
