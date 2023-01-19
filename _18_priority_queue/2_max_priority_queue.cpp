//  Code : Max Priority Queue
// Send Feedback
// Implement the class for Max Priority Queue which includes following functions -
// 1. getSize -
// Return the size of priority queue i.e. number of elements present in the priority queue.
// 2. isEmpty -
// Check if priority queue is empty or not. Return true or false accordingly.
// 3. insert -
// Given an element, insert that element in the priority queue at the correct position.
// 4. getMax -
// Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
// 5. removeMax -
// Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
// Note : main function is given for your reference which we are using internally to test the class.

  
#include<vector>
class PriorityQueue {
    // Declare the data members here
	vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        if(isEmpty()){
            pq.push_back(element);
            return;
        }
        pq.push_back(element);
        
        int k = pq.size()-1;
        int index = (k-1)/2;
        
        while(index>=0 && pq[index]<element){
            int temp = pq[index];
            pq[index] = pq[k];
            pq[k] = temp;
            
            k=index;
            index = (k-1)/2;
            
        }
        return;
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0){
            return 0;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return 0;
        }
        
        int k = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        int maxIndex = parentIndex;
        
        while(leftChildIndex < pq.size()){
            maxIndex = parentIndex;
            if(pq[leftChildIndex]>pq[maxIndex]){
                maxIndex = leftChildIndex;
            }
            if(pq[rightChildIndex]>pq[maxIndex]){
                maxIndex = rightChildIndex;
            }
            
            if(maxIndex==parentIndex) break;
            
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxIndex];
            pq[maxIndex] = temp;
            
        }
        return k;    
        
        
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};

#include <iostream>
using namespace std;



int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
