//
// Created by WOOO on 2020/9/29.
//

#ifndef STUDY_CODE_MYHASHMAP_H
#define STUDY_CODE_MYHASHMAP_H
#include <vector>
#include <string>
#include "MyTree.h"

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

#endif //STUDY_CODE_MYHASHMAP_H
