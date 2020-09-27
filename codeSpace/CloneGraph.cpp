// clone graph
/** 
 * 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）
 * 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）
 * ======深拷贝=======
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