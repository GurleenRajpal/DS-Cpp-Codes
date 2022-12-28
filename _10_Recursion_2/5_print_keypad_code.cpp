// Return Keypad Code
// Send Feedback
// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. 
// You just have to populate the output array and return the count of elements populated in the output array.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    if(num==0 || num==1){
        output[0] = "";
        return 1;
    }

    int newNo = num/10;
    int count = keypad(newNo, output);

    int k = num%10;
    
    switch(k){
        case 2:
            for(int i=0;i<count; i++){
                output[i+2*count] = output[i]+"c";
                output[i+1*count] = output[i]+"b";
                output[i] = output[i]+"a";
            }
            return 3*count;
        case 3:
            for(int i=0;i<count; i++){
                output[i+2*count] = output[i]+"f";
                output[i+1*count] = output[i]+"e";
                output[i] = output[i]+"d";
            }
            return 3*count;
        case 4:
            for(int i=0;i<count; i++){
                output[i+2*count] = output[i]+"i";
                output[i+1*count] = output[i]+"h";
                output[i] = output[i]+"g";
            }
            return 3*count;

        case 5:
            for(int i=0;i<count; i++){
                output[i+2*count] = output[i]+"l";
                output[i+1*count] = output[i]+"k";
                output[i] = output[i]+"j";
            }
            return 3*count;
        case 6:
            for(int i=0;i<count; i++){
                output[i+2*count] = output[i]+"o";
                output[i+1*count] = output[i]+"n";
                output[i] = output[i]+"m";
            }
            return 3*count;
        case 7:
            for(int i=0;i<count; i++){
                output[i+3*count] = output[i]+"s";
                output[i+2*count] = output[i]+"r";
                output[i+1*count] = output[i]+"q";
                output[i] = output[i]+"p";
            }
            return 4*count;
        case 8:
            for(int i=0;i<count; i++){
                output[i+2*count] = output[i]+"v";
                output[i+1*count] = output[i]+"u";
                output[i] = output[i]+"t";
            }
            return 3*count;
        case 9:
            for(int i=0;i<count; i++){
                output[i+3*count] = output[i]+"z";
                output[i+2*count] = output[i]+"y";
                output[i+1*count] = output[i]+"x";
                output[i] = output[i]+"w";
            }
            return 4*count;
        default:
            return 0;
    }

    
}
#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

