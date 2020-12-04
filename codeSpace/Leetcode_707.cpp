// 设计链表
/*
 * 设计链表的实现。您可以选择使用单链表或双链表
 * 单链表中的节点应该具有两个属性：val 和 next
 * val 是当前节点的值，next 是指向下一个节点的指针/引用
 * 如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点
 * 假设链表中的所有节点都是 0-index 的
 * 在链表类中实现这些功能：
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为val的节点
 * 如果 index 等于链表的长度，则该节点将附加到链表的末尾
 * 如果 index 大于链表长度，则不会插入节点
 * 如果index小于0，则在头部插入节点
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点
 * */

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int v) : val(v), next(nullptr) {}
};

// 单链表
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
        if (index < 0 || index >= capacity) {
            return -1;
        }
        ListNode *p = head;
        while (index + 1 > 0) {
            p = p->next;
            index--;
        }
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(capacity, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0) {
            index = 0;
        }
        if (index > capacity) {
            return;
        }
        ListNode *p = head;
        while (index > 0) {
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
        if (index < 0 || index >= capacity) {
            return;
        }
        ListNode *p = head;
        while (index > 0) {
            p = p->next;
            index--;
        }
        capacity--;
        ListNode *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
};


// 双向链表
struct ListNodeT {
    int val;
    ListNodeT *next;
    ListNodeT *prev;

    ListNodeT(int v) : val(v), next(nullptr), prev(nullptr) {}
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
        if (index < 0 || index >= capacity) {
            return -1;
        }
        if (index + index < capacity) {
            ListNodeT *p = head;
            while (index + 1 > 0) {
                p = p->next;
                index--;
            }
            return p->val;
        } else {
            ListNodeT *p = tail;
            while (capacity - index > 0) {
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
        if (index < 0) {
            index = 0;
        }
        if (index > capacity) {
            return;
        }
        capacity++;
        ListNodeT *temp = new ListNodeT(val);
        if (index + index < capacity) {
            ListNodeT *p = head;
            while (index > 0) {
                p = p->next;
                index--;
            }
            temp->next = p->next;
            p->next = temp;
            temp->next->prev = temp;
            temp->prev = p;
        } else {
            ListNodeT *p = tail;
            while (capacity - index - 1 > 0) {
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
        if (index < 0 || index >= capacity) {
            return;
        }
        if (index + index < capacity) {
            ListNodeT *p = head;
            while (index > 0) {
                p = p->next;
                index--;
            }
            ListNodeT *temp = p->next;
            p->next = temp->next;
            p->next->prev = p;
            delete temp;
        } else {
            ListNodeT *p = tail;
            while (capacity - index - 1 > 0) {
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