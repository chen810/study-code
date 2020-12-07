//
// Created by WOOO on 2020/12/7.
//

#include "my_base_structs.h"
// 向搜索二叉树中加入节点
TreeNode *addToSearchTree(TreeNode *root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (root->val > val) {
        root->left = addToSearchTree(root->left, val);
    } else {
        root->right = addToSearchTree(root->right, val);
    }
    return root;
}

// 向搜索二叉树中加入搜索二叉树
TreeNode *addToSearchTreeByTree(TreeNode *root, TreeNode *subNode) {
    if (root == nullptr) {
        return subNode;
    }
    if (root->val > subNode->val) {
        root->left = addToSearchTreeByTree(root->left, subNode);
    } else {
        root->right = addToSearchTreeByTree(root->right, subNode);
    }
    return root;
}

// 从搜索二叉树中移除节点
TreeNode *removeFromSearchTree(TreeNode *root, int val) {
    if (root == nullptr) { return nullptr; }
    if (root->val > val) {
        root->left = removeFromSearchTree(root->left, val);
    } else if (root->val < val) {
        root->right = removeFromSearchTree(root->right, val);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            root = root->right;
        } else if (root->right == nullptr) {
            root = root->left;
        } else {
            root = addToSearchTreeByTree(root->left, root->right);
        }
    }
    return root;
}

// 在搜索二叉树中搜索节点
bool checkInSearchTree(TreeNode *root, int val) {
    if (root == nullptr) {
        return false;
    }
    if (root->val > val) {
        return checkInSearchTree(root->left, val);
    } else if (root->val < val) {
        return checkInSearchTree(root->right, val);
    }
    return true;
}

MyHashMap::MyHashMap() {
    data = nullptr;
}
void MyHashMap::put(int key, int value) {
    if (data == nullptr) {
        data = new TreeNode(key, value);
        return;
    }
    auto p = data;
    while (p != nullptr) {
        if (p->val > key) {
            if (p->left == nullptr) {
                p->left = new TreeNode(key, value);
                break;
            }
            p = p->left;
        } else if (p->val < key) {
            if (p->right == nullptr) {
                p->right = new TreeNode(key, value);
                break;
            }
            p = p->right;
        } else {
            p->val_co = value;
            break;
        }
    }
}

int MyHashMap::get(int key) {
    auto p = data;
    while (p != nullptr) {
        if (p->val > key) {
            p = p->left;
        } else if (p->val < key) {
            p = p->right;
        } else {
            return p->val_co;
        }
    }
    return -1;
}

void MyHashMap::remove(int key) {
    data = removeFromSearchTree(data, key);
}