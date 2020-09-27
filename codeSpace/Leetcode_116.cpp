// ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
/**
 * ����һ��������������������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ�
 * �������������£�
 * struct Node {
 *  int val;
 *  Node *left;
 *  Node *right;
 *  Node *next;
 * }
 * �������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ�
 * ����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL
 * ��ʼ״̬�£�����?next ָ�붼������Ϊ NULL
 * */

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

// ͨ����һ���nextָ�������ұߵ���������չ
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr){  // ����ָ��Ϊ��ֱ�ӷ��ؿ�ָ��
            return nullptr;
        }
        Node *ori = root;   // ��¼����˵Ľڵ��ַ
        while(ori->left!=nullptr){  // ���а������,ֱ����һ��û�нڵ�
            Node *temp = ori;   // ��¼��ǰ�����ʼ�ڵ�ĸ��ڵ�
            while(temp!=nullptr){   // ���б������ڵ��Լ���next
                temp->left->next = temp->right; // left.next = right
                if(temp->next!=nullptr){    // ����ұ߻��нڵ����������
                    temp->right->next = temp->next->left;   // right.next = ���ڵ�.next.left
                }
                temp = temp->next;  // Ų�����ڵ����ڲ���һ�����ڵ�
            }
            ori = ori->left;    // Ų������һ��
        }
        return root;    // ���ظ��ڵ�
    }
};