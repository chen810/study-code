//
// Created by WOOO on 2020/9/28.
//

#include "MyHashset.h"

MyHashSet::MyHashSet() {
    data = new vector<TreeNode*>(1000);
}
void MyHashSet::add(int key) {
    int index = key%1000;
    if(checkInSearchTree((*data)[index],key)){
        return;
    }
    (*data)[index] = addToSearchTree((*data)[index],key);
}

void MyHashSet::remove(int key) {
    int index = key%1000;
    if(checkInSearchTree((*data)[index],key)){
        (*data)[index] = removeFromSearchTree((*data)[index],key);
    }
}

bool MyHashSet::contains(int key) {
    int index = key%1000;
    return checkInSearchTree((*data)[index],key);
}
