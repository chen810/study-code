// 297. �����������л��뷴���л�
/**
 * ���л��ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ���
 * �������Խ�ת��������ݴ洢��һ���ļ������ڴ���
 * ͬʱҲ����ͨ�����紫�䵽��һ���������������ȡ�෴��ʽ�ع��õ�ԭ����
 * �����һ���㷨��ʵ�ֶ����������л��뷴���л�
 * ���ﲻ�޶�������� / �����л��㷨ִ���߼�
 * ��ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊԭʼ�����ṹ
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
        if(index>=data.size()||data[index]=="None"){
            index++;
            return nullptr;
        }
        TreeNode* temp = new TreeNode(stoi(data[index++]));
        temp->left = deserializeDFS(data,index);
        temp->right = deserializeDFS(data,index);
        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));