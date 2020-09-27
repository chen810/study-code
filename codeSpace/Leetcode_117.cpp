// 填充每个节点的下一个右侧节点指针 II
/**
 * 给定一个二叉树
 * struct Node {
 * int val;
 * Node *left;
 * Node *right;
 * Node *next;
 * }
 * 填充它的每个 next 指针,让这个指针指向其下一个右侧节点
 * 如果找不到下一个右侧节点，则将 next 指针设置为 NULL
 * 初始状态下，所有 next 指针都被设置为 NULL
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
        Node* next_index = root;    // 父层的起点
        Node fake_node;
        while(next_index!=nullptr){
            Node* index = next_index;   // 父层的指针
            Node* opt = &fake_node;    // 子节点层的起点初始化为虚拟节点
            while(index!=nullptr){  // 循环链接next参数
                if(index->left!=nullptr&&index->right!=nullptr){    // 若即将链接的节点有左右节点
                    index->left->next = index->right;
                    opt->next = index->left;
                    opt = index->right;
                }else if(index->left!=nullptr||index->right!=nullptr){  // 若即将链接的节点只有一个节点
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