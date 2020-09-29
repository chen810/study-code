//
// Created by WOOO on 2020/9/28.
//

#ifndef STUDY_CODE_MYHASHSET_H
#define STUDY_CODE_MYHASHSET_H
#include <vector>
#include <iostream>
#include "MyTree.h"
using namespace std;

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
