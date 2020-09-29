//
// Created by WOOO on 2020/9/29.
//

#include "MyHashMap.h"
MyHashMap::MyHashMap(){
    data = nullptr;
}
void MyHashMap::put(int key, int value){
    if(data== nullptr){
        data = new TreeNode(key,value);
        return;
    }
    auto p = data;
    while(p!= nullptr){
        if(p->val > key){
            if(p->left==nullptr){
                p->left = new TreeNode(key,value);
                break;
            }
            p = p->left;
        }else if(p->val < key){
            if(p->right==nullptr){
                p->right = new TreeNode(key,value);
                break;
            }
            p = p->right;
        }else{
            p->val_co = value;
            break;
        }
    }
}

int MyHashMap::get(int key){
    auto p = data;
    while(p!= nullptr){
        if(p->val > key){
            p = p->left;
        }else if(p->val < key){
            p = p->right;
        }else{
            return p->val_co;
        }
    }
    return -1;
}

void MyHashMap::remove(int key){
    data = removeFromSearchTree(data,key);
}
