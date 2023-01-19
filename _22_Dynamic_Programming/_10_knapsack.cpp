// Code : Knapsack
// Send Feedback
// A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th 
// item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
// Input Format :
// The first line of the input contains an integer value N, which denotes the total number of items.

// The second line of input contains the N number of weights separated by a single space.

// The third line of input contains the N number of values separated by a single space.

// The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
// Output Format :
// Print the maximum value of V that the thief can steal.
// Constraints :
// 1 <= N <= 20
// 1<= Wi <= 100
// 1 <= Vi <= 100

// Time Limit: 1 sec
// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output 1 :
// 13
// Sample Input 2 :
// 5
// 12 7 11 8 9
// 24 13 23 15 16
// 26
// Sample Output 2 :
// 51

#include <iostream>
using namespace std;

#include<climits>
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    
    if(n<0){
        return 0;
    }
    
    
    int pick=INT_MIN;
    
    int notPick;
    
    if(weights[n-1]<=maxWeight){
    	pick = values[n-1] + knapsack(weights, values, n-1, maxWeight-weights[n-1]);
    }
    notPick = knapsack(weights, values, n-1, maxWeight);
    
    return max(pick, notPick);
    
    
}
int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}
