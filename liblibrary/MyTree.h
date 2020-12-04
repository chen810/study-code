//
// Created by WOOO on 2020/9/29.
//

#ifndef STUDY_CODE_MYTREE_H
#define STUDY_CODE_MYTREE_H

// 二叉树节点,存在key值
struct TreeNode {
    int val;
    int val_co;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v, int k, TreeNode *l, TreeNode *r) : val(v), val_co(k), left(l), right(r) {};

    explicit TreeNode(int v) : TreeNode(v, -1, nullptr, nullptr) {};

    explicit TreeNode(int v, int k) : TreeNode(v, k, nullptr, nullptr) {};

    explicit TreeNode(int v, int k, TreeNode *l) : TreeNode(v, k, l, nullptr) {};
};


// 向搜索二叉树中加入节点
TreeNode *addToSearchTree(TreeNode *root, int val);

// 向搜索二叉树中加入搜索二叉树
TreeNode *addToSearchTreeByTree(TreeNode *root, TreeNode *subNode);

// 从搜索二叉树中移除节点
TreeNode *removeFromSearchTree(TreeNode *root, int val);

// 在搜索二叉树中搜索节点
bool checkInSearchTree(TreeNode *root, int val);
// 哈希表的搜索二叉树实现
#endif //STUDY_CODE_MYTREE_H
