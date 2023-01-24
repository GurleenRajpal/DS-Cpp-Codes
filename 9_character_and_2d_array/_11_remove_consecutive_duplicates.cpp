// Remove Consecutive Duplicates
// Send Feedback
// For a given string(str), remove all the consecutive duplicate characters.

// Example:
// Input String: "aaaa"
// Expected Output: "a"

// Input String: "aabbbcc"
// Expected Output: "abc"

//  Input Format:
// The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.

// Output Format:
// The only line of output prints the updated string.

// Note:
// You are not required to print anything. It has already been taken care of.

// Constraints:
// 0 <= N <= 10^6
// Where N is the length of the input string.

// Time Limit: 1 second

// Sample Input 1:
// aabccbaa

// Sample Output 1:
// abcba

void removeConsecutiveDuplicates(char input[])
{
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[j] == input[i])
        {
            continue;
        }
        else
        {
            j++;
            input[j] = input[i];
        }
    }
    input[++j] = '\0';
}

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}
