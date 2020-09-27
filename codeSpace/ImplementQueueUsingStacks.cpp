// ��ջʵ�ֶ���
/**
 * ʹ��ջʵ�ֶ��е����в�����
 * push(x) -- ��һ��Ԫ�ط�����е�β��
 * pop() -- �Ӷ����ײ��Ƴ�Ԫ��
 * peek() -- ���ض����ײ���Ԫ��
 * empty() -- ���ض����Ƿ�Ϊ��
 * */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> *dataIn;
    stack<int> *dataOut;
    int capacity;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        dataIn = new stack<int>;
        dataOut = new stack<int>;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        dataIn->push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(dataOut->empty()){
            while(!dataIn->empty()){
                dataOut->push(dataIn->top());
                dataIn->pop();
            }
        }
        int res = dataOut->top();
        dataOut->pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(dataOut->empty()){
            while(!dataIn->empty()){
                dataOut->push(dataIn->top());
                dataIn->pop();
            }
        }
        return dataOut->top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return dataIn->empty()&&dataOut->empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */