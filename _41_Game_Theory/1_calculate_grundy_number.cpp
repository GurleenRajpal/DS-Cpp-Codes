//  Calculate Grundy Number
// Send Feedback
// Calculate the Grundy Number for the given 'n' in the game.
// The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, .
// 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player 
// to move wins. Which player wins the game?
// Input Format:

// First line of input contains an integer T, representing the number of test cases.
// Next T lines contain an integer n.

// Constraints:

// 1 <= T <= 10^4
// 1 <= N <= 10^6

// Output Format:

// Print the Grundy Number(n) for each test case in a new line.

// Sample Input 1:

// 1
// 10

// Sample Output 1:

// 0

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <unordered_set>
using namespace std;

int getMex(unordered_set<int> s){
    int mex = 0;
    while(s.find(mex)!=s.end()){
        mex++;
    }
    return mex;
}

int grundy(int x, int* dp){
    if(x==0){
        return 0;
    }
    
    if(dp[x]!=-1){
        return dp[x];
    }
    
    unordered_set<int> s;
    s.insert(grundy(x/2, dp));
    s.insert(grundy(x/3, dp));
    s.insert(grundy(x/6, dp));
    
    return dp[x] = getMex(s);
    
}

int calculateGrundyNumber(int n, std::vector<int> &grundyNumbers) {
  // If the Grundy number has already been calculated, return it
  if (grundyNumbers[n] != -1) {
    return grundyNumbers[n];
  }
  // If n is 0, the Grundy number is 0
  if (n == 0) {
    grundyNumbers[n] = 0;
    return 0;
  }
  // Create a set to store the possible Grundy numbers for this heap size
  std::unordered_set<int> possibleGrundyNumbers;
  // Loop through all possible moves for this heap size
  for (int i : {2, 3, 6}) {
    // If the move is valid (n is divisible by i), calculate the Grundy number
    // of the resulting heap
    // if (n % i == 0) {
      possibleGrundyNumbers.insert(calculateGrundyNumber(n / i, grundyNumbers));
    
  }
  // The Grundy number for this heap size is the smallest non-negative integer
  // not in the set of possible Grundy numbers
  int grundyNumber = 0;
  while (possibleGrundyNumbers.count(grundyNumber)) {
    grundyNumber++;
  }
  grundyNumbers[n] = grundyNumber;
  return grundyNumber;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    int* dp = new int[1000010];
    for(int i=0; i<=1000009; i++){
        dp[i] = -1;
    }
    dp[0] = 0;
    // for(int i=1; i<=100000; i++){
    //     dp[i] = mexN(dp[i/2], dp[i/3],dp[i/6]);
    // }
    vector<int> grundyNumbers(1000010, -1);

    while(t--){
        int x;
        cin>>x;
        // if(x>100000){
        //     cout<<grundy(x, dp)<<endl;
        // }
        // else{
        //     cout<<dp[x]<<endl;
        // }
        //final
        // cout<<grundy(x, dp)<<endl;
        cout << calculateGrundyNumber(x, grundyNumbers) << endl;
    }
    
    
    return 0;
}
