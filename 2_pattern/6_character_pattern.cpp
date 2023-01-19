// Print the following pattern for the given N number of rows.

// Pattern for N = 4
// A
// BC
// CDE
// DEFG

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
    char c = 'A';
    while (i <= n)
    {
        j = 0;
        while (j < i)
        {
            cout << char(c + j);
            j++;
        }
        c++;
        cout << endl;
        i++;
    }
}
