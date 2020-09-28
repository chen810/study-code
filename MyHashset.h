//
// Created by WOOO on 2020/9/28.
//

#ifndef STUDY_CODE_MYHASHSET_H
#define STUDY_CODE_MYHASHSET_H
#include <vector>
#include <iostream>
using namespace std;
// 二叉树节点
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v,TreeNode* l,TreeNode* r):val(v),left(l),right(r){};
    explicit TreeNode(int v):TreeNode(v, nullptr, nullptr) {};
};


// 向搜索二叉树中加入节点
TreeNode* addToSearchTree(TreeNode* root, int val);
// 向搜索二叉树中加入搜索二叉树
TreeNode* addToSearchTreeByTree(TreeNode* root, TreeNode* subNode);
// 从搜索二叉树中移除节点
TreeNode* removeFromSearchTree(TreeNode* root, int val);
// 在搜索二叉树中搜索节点
bool checkInSearchTree(TreeNode* root, int val);
// 哈希表的搜索二叉树实现
class MyHashSet {
    vector<TreeNode *> *data;
public:
    /** Initialize your data structure here. */
    MyHashSet();
    // 向对应桶中加入值,存在则不做
    void add(int key);
    // 移除节点,若不存在则不操作
    void remove(int key);
    /** Returns true if this set contains the specified element */
    bool contains(int key);
};
#endif //STUDY_CODE_MYHASHSET_H
