// 297. 二叉树的序列化与反序列化
/**
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作
 * 进而可以将转换后的数据存储在一个文件或者内存中
 * 同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据
 * 请设计一个算法来实现二叉树的序列化与反序列化
 * 这里不限定你的序列 / 反序列化算法执行逻辑
 * 你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构
 * */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

 // Definition for a binary tree node.
 struct TreeNode {
    int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serializeDFS(root,res);
        return res;
    }
    void serializeDFS(TreeNode* root, string &data) {
        if(root==nullptr){
            data += "None,";
        }else{
            data += to_string(root->val);
            data += ",";
            serializeDFS(root->left,data);
            serializeDFS(root->right,data);
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> valueList;
        int left=0;
        int length=0;
        while(left<data.size()){
            while(left+length<data.size()&&data[left+length]!=','){
                ++length;
            }
            valueList.push_back(data.substr(left,length));
            left += length+1;
            length = 0;
        }
        int index = 0;
        return deserializeDFS(valueList,index);
    }
    TreeNode* deserializeDFS(vector<string> &data,int &index){
        index++;
        if(index>=data.size()||data[index]=="None"){
            return nullptr;
        }
        TreeNode* temp = new TreeNode(stoi(data[index]));
        temp->left = deserializeDFS(data,index);
        temp->right = deserializeDFS(data,index);
        return temp;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));