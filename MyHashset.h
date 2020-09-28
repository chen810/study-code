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

TreeNode* addToSearchTree(TreeNode* root, int val);
TreeNode* removeFromSearchTree(TreeNode* root, int val);
bool checkInSearchTree(TreeNode* root, int val);

// 向搜索二叉树中加入节点
TreeNode* addToSearchTree(TreeNode* root, int val){
    if(root==nullptr){
        return new TreeNode(val);
    }
    if(root->val>val){
        root->left = addToSearchTree(root->left,val);
    }else{
        root->right = addToSearchTree(root->right,val);
    }
    return root;
}
// 向搜索二叉树中加入搜索二叉树
TreeNode* addToSearchTreeByTree(TreeNode* root, TreeNode* subNode){
    if(root==nullptr){
        return subNode;
    }
    if(root->val>subNode->val){
        root->left = addToSearchTreeByTree(root->left,subNode);
    }else{
        root->right = addToSearchTreeByTree(root->right,subNode);
    }
    return root;
}
// 从搜索二叉树中移除节点
TreeNode* removeFromSearchTree(TreeNode* root, int val){
    if(root==nullptr){ return nullptr; }
    if(root->val>val){
        root->left = removeFromSearchTree(root->left,val);
    }else if(root->val<val){
        root->right = removeFromSearchTree(root->right,val);
    }else{
        if(root->left== nullptr&&root->right==nullptr){
            delete root;
            root = nullptr;
        }else if(root->left == nullptr){
            root = root->right;
        }else if(root->right== nullptr){
            root = root->left;
        }else{
            root = addToSearchTreeByTree(root->left,root->right);
        }
    }
    return root;
}
// 在搜索二叉树中搜索节点
bool checkInSearchTree(TreeNode* root, int val){
    if(root==nullptr){
        return false;
    }
    if(root->val > val){
        return checkInSearchTree(root->left,val);
    }else if(root->val < val){
        return  checkInSearchTree(root->right,val);
    }
    return true;
}
// 哈希表的搜索二叉树实现
class MyHashSet {
    vector<TreeNode *> *data;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        // 设定为1000个桶,桶内部使用搜索二叉树搜索
        data = new vector<TreeNode*>(1000);
    }
    // 向对应桶中加入值,存在则不做
    void add(int key) {
        int index = key%1000;
        if(checkInSearchTree((*data)[index],key)){
            return;
        }
        (*data)[index] = addToSearchTree((*data)[index],key);
    }

    void remove(int key) {
        int index = key%1000;
        if(checkInSearchTree((*data)[index],key)){
            (*data)[index] = removeFromSearchTree((*data)[index],key);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key%1000;
        return checkInSearchTree((*data)[index],key);
    }
};

#endif //STUDY_CODE_MYHASHSET_H
