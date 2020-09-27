// 填充每个节点的下一个右侧节点指针
/**
 * 给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点
 * 二叉树定义如下：
 * struct Node {
 *  int val;
 *  Node *left;
 *  Node *right;
 *  Node *next;
 * }
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点
 * 如果找不到下一个右侧节点，则将 next 指针设置为 NULL
 * 初始状态下，所有?next 指针都被设置为 NULL
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

// 通过上一层的next指针向向右边的树进行扩展
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr){  // 所给指针为空直接返回空指针
            return nullptr;
        }
        Node *ori = root;   // 记录最左端的节点地址
        while(ori->left!=nullptr){  // 进行按层遍历,直到下一层没有节点
            Node *temp = ori;   // 记录当前层的起始节点的父节点
            while(temp!=nullptr){   // 进行遍历父节点以及其next
                temp->left->next = temp->right; // left.next = right
                if(temp->next!=nullptr){    // 如果右边还有节点则进行连接
                    temp->right->next = temp->next->left;   // right.next = 父节点.next.left
                }
                temp = temp->next;  // 挪到父节点所在层下一个父节点
            }
            ori = ori->left;    // 挪到树下一层
        }
        return root;    // 返回根节点
    }
};