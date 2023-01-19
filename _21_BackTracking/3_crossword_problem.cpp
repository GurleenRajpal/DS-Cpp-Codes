// Crossword Problem
// Send Feedback
// Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, 
// you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
// For example, The following is an example for the input crossword grid and the word list.
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV
// Output for the given input should be:
// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA
// Note: We have provided such test cases that there is only one solution for the given input.
// Input format:
// The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
// The next line of input contains the word list, in which each word is separated by ';'. 
// Output format:
// Print the crossword grid, after placing the words of word list in '-' cells.  
// Constraints
// The number of words in the word list lie in the range of: [1,6]
// The length of words in the word list lie in the range: [1, 10]
// Time Limit: 1 second
// Sample Input 1:
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV
// Sample Output 1:
// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA

#include <bits/stdc++.h>
#include <string>
using namespace std;
char crossword[10][10];
bool isValidVertical(string word, int row, int col) {
  if (10 - row < word.length())
    return false;
  for (int i = row, j = 0; j < word.length(); i++, j++)
    if (crossword[i][col] != '-' && crossword[i][col] != word[j])
      return false;
  return true;
}

bool isValidHorizontal(string word, int row, int col) {
  if (10 - col < word.length())
    return false;
  for (int i = 0, j = col; i < word.length(); i++, j++)
    if (crossword[row][j] != '-' && crossword[row][j] != word[i])
      return false;
  return true;
}
void setVertical(string word, bool state[], int row, int col) {
  // cout<<"setVertical"<<endl;
  for (int i = 0, j = row; i < word.size(); ++i, j++) {
    if (crossword[j][col] != '+') {
      if (crossword[j][col] == word[i])
        state[i] = false;
      else
        state[i] = true;
      crossword[j][col] = word[i];
    }
  }
}

void resetVertical(int row, int col, bool state[], int size) {
  for (int i = 0, j = row; i < size; ++i, j++)
    if (state[i] == true)
      crossword[j][col] = '-';
}

void setHorizontal(string word, bool state[], int row, int col) {
  for (int i = 0, j = col; i < word.size(); ++i, j++) {
    if (crossword[row][j] != '+') {
      if (crossword[row][j] == word[i])
        state[i] = false;
      else
        state[i] = true;
      crossword[row][j] = word[i];
    }
  }
}

void resetHorizontal(int row, int col, bool state[], int size) {
  for (int i = 0, j = col; i < size; ++i, j++)
    if (state[i] == true)
      crossword[row][j] = '-';
}

bool solve(string input[], int index, int size) {
  if (index == size) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        cout << crossword[i][j];
      }
      cout << endl;
    }
    return true;
  }
  // cout<<"Here"<<endl;
  string s = input[index];
  for (int row = 0; row < 10; row++) {
    for (int col = 0; col < 10; col++) {
      if (crossword[row][col] == '-' || crossword[row][col] == s[0]) {
        vector<bool> helper;
        if (isValidVertical(s, row, col)) {
          int len = s.length();
          bool state[len];
          for (int i = 0; i < len; i++) {
            state[i] = false;
          }
          setVertical(s, state, row, col);
          if (solve(input, index + 1, size)) {
            return true;
          }
          resetVertical(row, col, state, len);
        }
        if (isValidHorizontal(s, row, col)) {
          int len = s.length();
          bool state[len];
          for (int i = 0; i < len; i++) {
            state[i] = false;
          }
          setHorizontal(s, state, row, col);
          if (solve(input, index + 1, size)) {
            return true;
          }
          resetHorizontal(row, col, state, len);
        }
      }
    }
  }

  return false;
}

int main() {

  // write your code here
  int n = 10;
  // char crossword[10][10];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> crossword[i][j];
    }
  }

  string s;
  cin >> s;

  string inputString[10];
  int i = 0;
  int size = 0;
  string word = "";
  while (s.length() != i) {
    if (s[i] == ';') {
      inputString[size] = word;
      word = "";
      size++;
    } else {
      word += s[i];
    }
    i++;
  }
  inputString[size] = word;
  size++;
  int index = 0;
  // for(int i=0;i<size;i++){
  //     cout<<inputString[i]<<endl;
  // }
  if (solve(inputString, index, size)) {
    return 0;
  }

  return 0;
}
