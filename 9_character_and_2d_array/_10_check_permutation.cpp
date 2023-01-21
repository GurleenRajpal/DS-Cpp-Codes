// Check Permutation
// Send Feedback
// For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.
// Permutations of each other
// Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

// Example:
// str1= "sinrtg"
// str2 = "string"

// The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are a permutation of each other.

// Input Format:
// The first line of input contains a string without any leading and trailing spaces, representing the first string 'str1'.
// The second line of input contains a string without any leading and trailing spaces, representing the second string 'str2'.

// Note:
// All the characters in the input strings would be in lower case.

// Output Format:
// The only line of output prints either 'true' or 'false', denoting whether the two strings are a permutation of each other or not.
// You are not required to print anything. It has already been taken care of. Just implement the function.

// Constraints:
// 0 <= N <= 10^6
// Where N is the length of the input string.

// Time Limit: 1 second

// Sample Input 1:
// abcde
// baedc

// Sample Output 1:
// true

bool isPermutation(char input1[], char input2[])
{
    int a[26] = {0};
    int b[26] = {0};
    int i = 0;

    while (input1[i] != '\0')
    {
        a[input1[i] - 97] += 1;
        i++;
    }

    int j = 0;
    while (input2[j] != '\0')
    {
        b[input2[j] - 97] += 1;
        j++;
    }

    if (i != j)
        return false;

    int k = 25;
    while (k)
    {
        if (a[k] != b[k])
            return false;
        k--;
    }
    return true;
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
