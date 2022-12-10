// Triplet Sum
// Send Feedback
// You have been given a random integer array/list(ARR) and a number X. Find and return the number of triplets in the array/list which sum to X.
// Note :
// Given array/list can contain duplicate elements.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains an integer 'X'.
// Output format :
// For each test case, print the total number of triplets present in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 50
// 0 <= N <= 10^2
// 0 <= X <= 10^9
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7 
// 12
// Sample Output 1:
// 5

int tripletSum(int *input, int size, int x)
{
	//Write your code here
    int trp = 0;
    for(int i=0;i<size;i++){
        int l = input[i];
        for(int j=0; j<size; j++){
            int m = input[j];
            for(int k=0;k<size;k++){
                int n = input[k];
                if(i!=j && j!=k && i!=k){
                    if(l+m+n==x){
                        trp++;
                    }
                }
            }
        }
    }
    return trp/6;
}


#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}
