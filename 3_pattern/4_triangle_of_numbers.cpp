// Code : Triangle of Numbers
// Send Feedback
// Print the following pattern for the given number of rows.

// Sample Input 1:
// 5
// Sample Output 1:
//        1
//       232
//      34543
//     4567654
//    567898765

#include <iostream>
using namespace std;

int main()
{
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;
    int i = 1;
    int j = 1;

    while (i <= n)
    {
        int spaces = n - i;
        while (spaces)
        {
            cout << " ";
            spaces--;
        }

        j = i;
        int k = i;
        while (j)
        {
            cout << k;
            k++;
            j--;
        }

        j = i - 1;
        k--;
        k--;
        while (j)
        {
            cout << k;
            k--;
            j--;
        }

        cout << endl;
        i++;
    }

    return 0;
}
