// Red Scrabble
// Send Feedback
// Raymond “Red” Reddington is an international criminal hunted by the police forces of many countries. 
// Recently, a joint Task Force, with the sole purpose of capturing Reddington, is launched, led by Agent Donald Ressler.
// Red has managed to elude all the forces because he is always one step ahead. Before Ressler can catch him,
// Red manages to capture Ressler for interrogation.
// Red is a huge fan of the game scrabble, and has created many modified versions of the game. He will let 
// Ressler go, if he is able to solve one such version of the game.
// The premise is quite simple. Ressler is given a string S which contains only digits. He needs to count the 
// number of substrings of S, which are palindromes. There are some additional rules to be followed. Red explains them as follows -
// Ressler needs to count the number of substrings of S, which are palindromes without leading zeros and can be divided by 3 without a remainder.
// A string is a palindrome without leading zeros if it reads the same backward as forward and doesn't start with the symbol '0'.
// Ressler should consider string "0" as a palindrome without leading zeros.
// You need to help Agent Ressler.
// Input Format:
// The first and only line of input contains string S.
// Constraints:
// 1 <= |S| <= 10^5
// 0 <= S[i] <= 9
// Output Format:
// Print the answer obtained.
// Sample Input 1:
// 10686
// Sample Output 1:
// 3
// Explanation:
// The three palindromic substrings are: 0, 6, 6.

#include <bits/stdc++.h>
using namespace std;

int f(string s) {
  int n = s.length();
  long long count = 0;

  for (int i = 0; i < n; i++) {
    int l = i;
    int r = i;
    int sum = 0;
    int oldSum = 0;
    if(s[i]=='0'){
      count++;
      l--;
      r++;
      while (l >= 0 && r < n && s[l] == s[r]) {
        if(s[l]==0 && s[r]==0){
          l--;
          r++;
          continue;
        }
        sum += (int)s[l] + (int)s[r] - 48 - 48;
        if (sum % 3 == 0 && oldSum!=sum) {
          // cout << sum << endl;
          count++;
        }
        l--;
        r++;
        oldSum = sum;
      }

      l = i;
      r = i+1;
      while (l >= 0 && r < n && s[l] == s[r]) {
        if(s[l]==0 && s[r]==0){
          l--;
          r++;
          continue;
        }
        sum += (int)s[l] + (int)s[r] - 48 - 48;
        if (sum % 3 == 0 && oldSum!=sum) {
          // cout << sum << endl;
          count++;
        }
        l--;
        r++;
        oldSum = sum;
      }


      continue;
    }


    l = i;
    r = i;
    sum = 0;
    oldSum = 0;
    while (l >= 0 && r < n && s[l] == s[r]) {
      if(l==r) sum+=(int) s[l]-48;
      else sum+=(int)s[l]+(int)s[r]-48-48;
      if (sum % 3 == 0 && sum != 0 && oldSum != sum) {
        // cout << sum << endl;
        count++;
      }
      l--;
      r++;
      oldSum = sum;

    }
   

    l = i;
    r = i + 1;
    sum = 0;
    oldSum = 0;
    while (l >= 0 && r < n && s[l] == s[r]) {
     sum+=(int)s[l]+(int)s[r]-48-48;
     if (sum % 3 == 0 && sum != 0 && oldSum != sum) {
       count++;
      //  cout << sum << endl;
     }
     l--;
     r++;
     oldSum = sum;
    }
    
  }
  return count;
}

int main() {

  // write your code here
  
    string s;
    cin >> s;
    cout << f(s) << endl;
  
  return 0;
}
