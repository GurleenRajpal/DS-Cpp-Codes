// Pyramid Number Pattern
// Send Feedback
// Print the following pattern for the given number of rows.

// Sample Input :
// 5

// Sample Output :
//     1
//    212
//   32123
//  4321234
// 543212345

#include <iostream>
using namespace std;

int main()
{

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

        while (j)
        {
            cout << j;
            j--;
        }
        j = 2;
        while (j <= i)
        {
            cout << j;
            j++;
        }
        cout << endl;

        i++;
    }
}
