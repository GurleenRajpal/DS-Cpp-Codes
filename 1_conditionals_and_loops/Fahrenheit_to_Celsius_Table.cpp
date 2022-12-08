//  Fahrenheit to Celsius Table
// Send Feedback
// Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) and Step Size (W), you need to convert all Fahrenheit values from Start to End at the gap of W, into their corresponding Celsius values and print the table.
// Input Format :

// 3 integers - S, E and W respectively 

// Output Format :

// Fahrenheit to Celsius conversion table. One line for every Fahrenheit and corresponding Celsius value in integer form. The Fahrenheit value and its corresponding Celsius value should be separate by single space.

// Constraints :

// 0 <= S <= 90
// S <= E <=  900
// 0 <= W <= 80 

// Sample Input 1:

// 0 
// 100 
// 20

// Sample Output 1:

// 0   -17
// 20  -6
// 40  4
// 60  15
// 80  26
// 100 37

// Sample Input 2:

// 20
// 119
// 13

// Sample Output 2:

// 20  -6
// 33  0 
// 46  7
// 59  15
// 72  22
// 85  29
// 98  36
// 111 43
#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int s,e,w;
    cin>>s>>e>>w;
    int c;
    while(s<=e){
        cout<<s<<" ";
        c = ((s-32)*5)/9;
        cout<<c<<endl;
        s+=w;
    }
    return 0;
}




