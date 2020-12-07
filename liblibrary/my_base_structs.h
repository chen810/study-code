//
// Created by WOOO on 2020/12/7.
//
#include <vector>
#include <string>

#ifndef MY_BASE_STRUCTS_H
#define MY_BASE_STRUCTS_H
using namespace std;

// 链表节点
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

// 二叉树节点,存在key值,此处忽略val_co作正常二叉树节点使用
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


// 数组构建链表,可选是否排序
ListNode *makeListNodeChain(vector<int>, bool = true);
// 链表打印
void printListNodeChain(ListNode *, const string & = "->");



// 向搜索二叉树中加入节点
TreeNode *addToSearchTree(TreeNode *root, int val);

// 向搜索二叉树中加入搜索二叉树
TreeNode *addToSearchTreeByTree(TreeNode *root, TreeNode *subNode);

// 从搜索二叉树中移除节点
TreeNode *removeFromSearchTree(TreeNode *root, int val);

// 在搜索二叉树中搜索节点
bool checkInSearchTree(TreeNode *root, int val);
// 哈希表的搜索二叉树实现



// 哈希map
class MyHashMap {
    TreeNode *data;
public:
    /** Initialize your data structure here. */
    MyHashMap();

    /** value will always be non-negative. */
    void put(int key, int value);

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key);

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key);
};

#endif //MY_BASE_STRUCTS_H