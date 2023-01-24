// Second Largest
// Send Feedback
// Take input a stream of n integer elements, find the second largest element present.
// The given elements can contain duplicate elements as well. If only 0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).

// Input format :
// Line 1 : Total number of elements (n)
// Line 2 : N elements (separated by space)

// Sample Input 1:
//  4
//  3 9 0 9

// Sample Output 1:
//  3

#include <iostream>
using namespace std;
#include <climits>

int main()
{

    int n;
    cin >> n;
    int min = INT_MIN;
    if (n == 0)
    {
        cout << min << endl;
        return 0;
    }
    if (n == 1)
    {
        cin >> n;
        cout << min << endl;
        return 0;
    }
    int max_no1 = INT_MIN;
    int max_no2 = INT_MIN;
    int t;
    cin >> t;
    max_no1 = t;
    cin >> t;
    max_no2 = t;
    if (max_no1 == max_no2)
    {
        max_no2 = INT_MIN;
    }
    if (max_no1 < max_no2)
    {
        int temp = max_no1;
        max_no1 = max_no2;
        max_no2 = temp;
    }
    while (n - 2)
    {
        cin >> t;
        if (t > max_no1 && t > max_no2)
        {
            if (max_no1 > max_no2)
            {
                max_no2 = max_no1;
                max_no1 = t;
            }
            else if (max_no2 > max_no1)
            {
                max_no1 = max_no2;
                max_no2 = t;
            }
            else
            {
                max_no2 = INT_MIN;
            }
        }
        if (t > max_no2 && t < max_no1)
        {
            max_no2 = t;
        }
        n--;
    }
    cout << max_no2 << endl;

    return 0;
}
