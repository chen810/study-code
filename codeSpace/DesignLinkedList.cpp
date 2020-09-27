// 707. �������
/**
 * ��������ʵ�֡�������ѡ��ʹ�õ������˫����
 * �������еĽڵ�Ӧ�þ����������ԣ�val �� next
 * val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/����
 * ���Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ�
 * ���������е����нڵ㶼�� 0-index ��
 * ����������ʵ����Щ���ܣ�
 * get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1
 * addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ�
 * addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ��
 * addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪval�Ľڵ�
 * ��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ
 * ��� index ���������ȣ��򲻻����ڵ�
 * ���indexС��0������ͷ������ڵ�
 * deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ�
 * */

#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v):val(v),next(nullptr){}
};

// ������
class MySinglyLinkedList {
    ListNode *head;
    int capacity;
public:
    /** Initialize your data structure here. */
    MySinglyLinkedList() {
        head = new ListNode(-1);
        capacity = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0||index>=capacity){
            return -1;
        }
        ListNode *p = head;
        while(index+1>0){
            p = p->next;
            index--;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(capacity,val);
    }
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<0){
            index = 0;
        }
        if(index>capacity){
            return;
        }
        ListNode *p = head;
        while(index>0){
            p = p->next;
            index--;
        }
        capacity++;
        ListNode *temp = new ListNode(val);
        temp->next = p->next;
        p->next = temp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=capacity){
            return;
        }
        ListNode *p = head;
        while(index>0){
            p = p->next;
            index--;
        }
        capacity--;
        ListNode *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
};


// ˫������
struct ListNodeT{
    int val;
    ListNodeT *next;
    ListNodeT *prev;
    ListNodeT(int v):val(v),next(nullptr),prev(nullptr){}
};
class MyTwoWayLinkedList {
    ListNodeT *head;
    ListNodeT *tail;
    int capacity;
public:
    /** Initialize your data structure here. */
    MyTwoWayLinkedList() {
        head = new ListNodeT(0);
        tail = new ListNodeT(0);
        head->next = tail;
        tail->prev = head;
        capacity = 0;
    }
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0||index>=capacity){
            return -1;
        }
        if(index+index<capacity){
            ListNodeT *p = head;
            while(index+1>0){
                p = p->next;
                index--;
            }
            return p->val;
        }else{
            ListNodeT *p = tail;
            while(capacity-index>0){
                p = p->prev;
                index++;
            }
            return p->val;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        capacity++;
        ListNodeT *temp = new ListNodeT(val);
        temp->next = head->next;
        head->next = temp;
        temp->next->prev = temp;
        temp->prev = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        capacity++;
        ListNodeT *temp = new ListNodeT(val);
        temp->prev = tail->prev;
        tail->prev = temp;
        temp->prev->next = temp;
        temp->next = tail;
        
    }
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<0){
            index = 0;
        }
        if(index>capacity){
            return;
        }
        capacity++;
        ListNodeT *temp = new ListNodeT(val);
        if(index+index<capacity){
            ListNodeT *p = head;
            while(index>0){
                p = p->next;
                index--;
            }
            temp->next = p->next;
            p->next = temp;
            temp->next->prev = temp;
            temp->prev = p;
        }else{
            ListNodeT *p = tail;
            while(capacity-index-1>0){
                p = p->prev;
                index++;
            }
            temp->prev = p->prev;
            p->prev = temp;
            temp->prev->next = temp;
            temp->next = p;
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=capacity){
            return;
        }
        if(index+index<capacity){
            ListNodeT *p = head;
            while(index>0){
                p = p->next;
                index--;
            }
            ListNodeT *temp = p->next;
            p->next = temp->next;
            p->next->prev = p;
            delete temp;
        }else{
            ListNodeT *p = tail;
            while(capacity-index-1>0){
                p = p->prev;
                index++;
            }
            ListNodeT *temp = p->prev;
            p->prev = temp->prev;
            p->prev->next = p;
            delete temp;
        }
        capacity--;
    }
};