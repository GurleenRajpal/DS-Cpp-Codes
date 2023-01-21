// Print the following pattern for the given number of rows.

// Pattern for N = 5
// E
// DE
// CDE
// BCDE
// ABCDE

#include <iostream>
using namespace std;

int main()
{

    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */

    int n;
    cin >> n;

    char c = 'A';

    int i = 1;
    int j = 1;
    int k = 1;
    while (i <= n)
    {

        c = (char)('A' + n - i);
        j = 1;
        while (j <= i)
        {
            cout << c;
            c = (char)(c + 1);
            j++;
        }
        cout << endl;
        i++;
    }
}
