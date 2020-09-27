// ���ƴ����ָ�������
/**
 * ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ�
 * Ҫ�󷵻��������� ���
 * ������һ���� n ���ڵ���ɵ���������ʾ����/����е�����
 * ÿ���ڵ���һ�� [val, random_index] ��ʾ
 * val��һ����ʾ Node.val ������
 * random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n-1��
 * �����ָ���κνڵ㣬��Ϊ  null
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
    // �˷�����Ҫ����ռ�
    Node* copyRandomList1(Node* head) {
        Node *p = head;
        Node res(0);
        Node *index = &res;
        map<Node *,Node *> rem; // �洢�Ѿ������Ľڵ㣬��ʽΪ{�ɽڵ�1:�½ڵ�1,�ɽڵ�2:�½ڵ�2,������}
        while(p!=nullptr){  // ��������ڵ�
            if(rem[p]==nullptr){    // ���ڵ�δ���������򴴽�
                rem[p] = new Node(p->val);
            }
            index->next= rem[p];    // �����ƵĽڵ���ڽ����
            index = index->next;    // ���ָ�����
            if(p->random!=nullptr){ // ���ָ��Ϊ��������
                if(rem[p->random]==nullptr){    // �����ָ��ָ��δ�����򴴽�
                    rem[p->random] = new Node(p->random->val);
                }
                index->random = rem[p->random]; // ���ָ��ָ�򿽱��Ľڵ���
            }
            p = p->next;    // �ڵ����
        }
        return res.next;    // ȥ���ƽ�㷴��
    }

    // �˷�������Ҫ����ռ�
    Node* copyRandomList2(Node* head) {
        if(head==nullptr){  // ������ֱ�ӷ���nullptr
            return nullptr;
        }
        Node *p = head; // ��������
        while(p!=nullptr){  // ÿ���ڵ�����ڵ���������
            Node *temp = new Node(p->val);  // �����½ڵ�
            temp->next = p->next;   // ����
            p->next = temp;
            p = p->next->next;  // �ƶ����½ڵ����
        }
        p = head;   // �ڶ��α�������
        while(p!=nullptr){  // ����random����
            if(p->random!=nullptr){ // �½ڵ�.randome = �ɽڵ�.random.next;
                p->next->random = p->random->next;
            }
            p = p->next->next;  // ������
        }
        Node *res = head->next; // �������ʼ�ڵ�
        p = head;   // ԭ�ڵ�ı���ָ��
        Node *q = res;  // �½ڵ�ı���ָ��
        while(q->next!=nullptr){    // ���½ڵ�ָ��ָ�����һ���ڵ����
            p->next = p->next->next;    // �ɽڵ��һ�����ӵ���һ���ڵ�
            p = p->next;
            q->next = q->next->next;    // �½ڵ��һ�����ӵ���һ���ڵ�
            q = q->next;
        }
        q->next = nullptr;  // ��β,�¾��������һ���ڵ��next��Ϊnullptr
        p->next = nullptr;  // ���ؽ����ʼ�ڵ�
        return res;
    }
};
