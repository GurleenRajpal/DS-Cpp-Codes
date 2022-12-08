//  Total Salary
// Send Feedback
// Write a program to calculate the total salary of a person. The user has to enter the basic salary (an integer) and the grade (an uppercase character), and depending upon which the total salary is calculated as -

//     totalSalary = basic + hra + da + allow – pf

// where :

// hra   = 20% of basic
// da    = 50% of basic
// allow = 1700 if grade = ‘A’
// allow = 1500 if grade = ‘B’
// allow = 1300 if grade = ‘C' or any other character
// pf    = 11% of basic.

// Round off the total salary and then print the integral part only.
// Note: Try finding out a function on the internet to do so
// Input format :

// Basic salary & Grade (separated by space)

// Output Format :

// Total Salary

// Constraints :

// 0 <= Basic Salary <= 7,500,000

// Sample Input 1 :

// 10000 A

// Sample Output 1 :

// 17600


#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    cin>>n;
    char a;
    cin>>a;
    
    float hra = n*0.2;
    float da = n*0.5;
    
    int allow = 1300;
    if(a=='A'){
        allow = 1700;
    }
    else if(a=='B'){
        allow = 1500;
    }
    else{
        allow = 1300;
    }
    
    float pf = 0.11*n;
    
    float sal = 0.0;
    sal = n + hra + da+ allow - pf;
    
    int sal2 = (int)sal;
    // cout<<sal2<<" "<<sal<<endl;
    if((sal-sal2)>=0.5){
        sal2+=1;
    }
    
    
    cout<<sal2;
    return 0;
}

