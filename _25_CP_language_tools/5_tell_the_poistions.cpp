// Tell the positions
// Send Feedback
// In a class there are ‘n’ number of students. They have three different subjects: Data Structures, 
// Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided 
// to you. You have to tell the position of each student in the class. Print the names of each student according 
// to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same 
// marks, the one with less roll number will have higher rank. The input is provided in order of roll number.
// Input Format:
// First line will have a single integer ‘n’, denoting the number of students in the class.
// Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.
// Output Format:
// Print ‘n’ lines having two values: First, the position of student in the class and second his name.
// Constraints:
// 1 <= n <= 10^5
// 0 <= m1, m2, m3 <= 100
// Sample Input:
// 3
// Mohit 94 85 97
// Shubham 93 91 94
// Rishabh 95 81 99
// Sample Output:
// 1 Shubham
// 2 Mohit
// 3 Rishabh


#include<bits/stdc++.h>
#include <queue>
#include<iostream>
using namespace std;
class Student{
    public:
    	string name;
    	int marks;
    	int rollNo;
};
// struct compareMarks{
//     bool operator()(Student const& s1, Student const&s2){
//         if(s1.marks<s2.marks){
//             return true;
//         }
//         else if(s1.marks>s2.marks){
//             return false;
//         }
//         else{
//             if(s1.rollNo>s2.rollNo){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
//     }
// };

bool operator<(Student const& s1, Student const&s2){
    if(s1.marks<s2.marks){
        return true;
    }
    else if(s1.marks>s2.marks){
        return false;
    }
    else{
        if(s1.rollNo>s2.rollNo){
            return true;
        }
        else{
            return false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    Student* s = new Student[n];
    priority_queue<int, vector<Student>> pq;
    for(int i=0;i<n;i++){
        string nameS;
        int m1, m2, m3;
        int rollNoS;
        cin>>nameS;
        cin>>m1>>m2>>m3;
        
        s[i].name = nameS;
        s[i].marks = m1 + m2 + m3;
        s[i].rollNo = i;
        
        pq.push(s[i]);
    }
    
    int i = 1;
    while(!pq.empty()){
        cout<<i<<" "<<pq.top().name<<endl;
        pq.pop();
        i++;
    }
	return 0;
}
