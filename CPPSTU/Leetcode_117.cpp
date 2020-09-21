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
        while(next_index!=nullptr){
            Node* index = next_index;   // 父层的指针
            Node* opt = nullptr;    // 子节点层的起点
            while(index!=nullptr&&index->left==nullptr&&index->right==nullptr){
                index = index->next;
            }   // 找到第一个包含下一层节点所在父节点
            if(index!=nullptr){
                opt = index->left==nullptr?index->right:index->left;    // 取出节点靠前的一个
                next_index = opt;   // 下一层节点起始位置定位在此节点
                if(index->left!=nullptr&&index->right!=nullptr){    // 若左右节点均有则进行连接
                    index->left->next = index->right;   // 连接
                    opt = index->right; // 向后移动
                }
                index = index->next;    // 向后移动
            }else{
                next_index = nullptr;   // 若未找到下一层节点则置空下一层的起始节点
            }
            while(index!=nullptr){  // 循环链接next参数
                if(index->left!=nullptr&&index->right!=nullptr){    // 若即将链接的节点有左右节点
                    index->left->next = index->right;
                    opt->next = index->left;
                    opt = index->right;
                    index = index->next;
                }else if(index->left!=nullptr||index->right!=nullptr){  // 若即将链接的节点只有一个节点
                    opt ->next = index->left==nullptr?index->right:index->left;
                    opt = opt->next;
                    index = index->next;
                }else{  // 若即将链接的节点没有节点
                    index = index->next;
                }
            }
        }
        return root;
    }
};