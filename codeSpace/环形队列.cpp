#include <vector>
using namespace std;

/** The circular queue class*/
class MyCircularQueue {
    int headIndex;
    int count;
    int capacity;
    int *data;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        headIndex = 0;
        count = 0;
        capacity = k;
        data = new int[k]();    /** new an array, set each value of array to zero.*/
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(count==capacity){
            return false;
        }
        count++;
        data[(headIndex+count-1)%capacity] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(count==0){
            return false;
        }
        headIndex = (headIndex+1)%capacity;
        count--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(count==0){
            return -1;
        }
        return data[headIndex];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(count==0){
            return -1;
        }
        return data[(headIndex+count-1)%capacity];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count==capacity;
    }
};