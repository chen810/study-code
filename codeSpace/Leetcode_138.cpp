// 复制带随机指针的链表
/*
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点
 * 要求返回这个链表的 深拷贝
 * 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表
 * 每个节点用一个 [val, random_index] 表示
 * val：一个表示 Node.val 的整数
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）
 * 如果不指向任何节点，则为  null
 * */
#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    // 此方法需要额外空间
    Node* copyRandomList1(Node* head) {
        Node *p = head;
        Node res(0);
        Node *index = &res;
        map<Node *,Node *> rem; // 存储已经创建的节点，格式为{旧节点1:新节点1,旧节点2:新节点2,···}
        while(p!=nullptr){  // 逐个搜索节点
            if(rem[p]==nullptr){    // 若节点未被创建过则创建
                rem[p] = new Node(p->val);
            }
            index->next= rem[p];    // 将复制的节点接在结果上
            index = index->next;    // 结果指针后移
            if(p->random!=nullptr){ // 随机指针为空则跳过
                if(rem[p->random]==nullptr){    // 若随机指针指向未创建则创建
                    rem[p->random] = new Node(p->random->val);
                }
                index->random = rem[p->random]; // 随机指针指向拷贝的节点上
            }
            p = p->next;    // 节点后移
        }
        return res.next;    // 去除哑结点反回
    }

    // 此方法不需要额外空间
    Node* copyRandomList2(Node* head) {
        if(head==nullptr){  // 空链表直接反回nullptr
            return nullptr;
        }
        Node *p = head; // 遍历链表
        while(p!=nullptr){  // 每个节点后加入节点自身的深拷贝
            Node *temp = new Node(p->val);  // 创建新节点
            temp->next = p->next;   // 串联
            p->next = temp;
            p = p->next->next;  // 移动到新节点后面
        }
        p = head;   // 第二次遍历链表
        while(p!=nullptr){  // 拷贝random参数
            if(p->random!=nullptr){ // 新节点.randome = 旧节点.random.next;
                p->next->random = p->random->next;
            }
            p = p->next->next;  // 走两步
        }
        Node *res = head->next; // 结果的起始节点
        p = head;   // 原节点的遍历指针
        Node *q = res;  // 新节点的遍历指针
        while(q->next!=nullptr){    // 当新节点指针指向最后一个节点结束
            p->next = p->next->next;    // 旧节点隔一个连接到下一个节点
            p = p->next;
            q->next = q->next->next;    // 新节点隔一个连接到下一个节点
            q = q->next;
        }
        q->next = nullptr;  // 收尾,新旧链表最后一个节点的next置为nullptr
        p->next = nullptr;  // 返回结果起始节点
        return res;
    }
};
