// All Prime Numbers
// Send Feedback
// Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).

// Print the prime numbers in different lines.
// Input Format :
// Integer N

// Output Format :
// Prime numbers in different lines

// Constraints :
// 1 <= N <= 100

// Sample Input 1:
// 9

// Sample Output 1:
// 2
// 3
// 5
// 7

// Sample Input 2:
// 20

// Sample Output 2:
// 2
// 3
// 5
// 7
// 11
// 13
// 17
// 19

#include <iostream>
using namespace std;

int main()
{

    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;
    bool divided = false;
    for (int i = 2; i <= n; i++)
    {
        int j = i;
        divided = false;
        for (int k = 2; k < j; k++)
        {
            if (j % k == 0)
            {
                divided = true;
                break;
            }
        }
        if (!divided)
        {
            cout << j << endl;
        }
    }
}
