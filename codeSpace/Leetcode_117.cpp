// ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II
/**
 * ����һ��������
 * struct Node {
 * int val;
 * Node *left;
 * Node *right;
 * Node *next;
 * }
 * �������ÿ�� next ָ��,�����ָ��ָ������һ���Ҳ�ڵ�
 * ����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL
 * ��ʼ״̬�£�����?next ָ�붼������Ϊ NULL
 * */
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        Node* next_index = root;    // ��������
        Node fake_node;
        while(next_index!=nullptr){
            Node* index = next_index;   // �����ָ��
            Node* opt = &fake_node;    // �ӽڵ�������ʼ��Ϊ����ڵ�
            while(index!=nullptr){  // ѭ������next����
                if(index->left!=nullptr&&index->right!=nullptr){    // ���������ӵĽڵ������ҽڵ�
                    index->left->next = index->right;
                    opt->next = index->left;
                    opt = index->right;
                }else if(index->left!=nullptr||index->right!=nullptr){  // ���������ӵĽڵ�ֻ��һ���ڵ�
                    opt ->next = index->left==nullptr?index->right:index->left;
                    opt = opt->next;
                }
                index = index->next;
            }
            next_index = fake_node.next;
            fake_node.next = nullptr;
        }
        return root;
    }
};