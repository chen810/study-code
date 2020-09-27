// clone graph
/** 
 * �������� ��ͨ ͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡��
 * ͼ�е�ÿ���ڵ㶼��������ֵ val��int�� �����ھӵ��б�list[Node]��
 * ======���=======
 * */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node *,Node *> visited;
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        if(visited[node]!=nullptr){
            return visited[node];
        }
        Node *temp = new Node(node->val);
        visited[node] = temp;
        for(auto i:node->neighbors){
            temp->neighbors.emplace_back(cloneGraph(i));
        }
        return temp;
    }
};