#include <string>
#include <iostream>
using namespace std;
class Trie {
    struct TrieNode{
        bool val;
        bool isEnd;
        TrieNode *next= nullptr;
        explicit TrieNode(bool x):val(x),next(nullptr),isEnd(false){}
        explicit TrieNode():TrieNode(false){}
    };
    TrieNode *TrieRoot= nullptr;
public:
    /** Initialize your data structure here. */
    Trie();
    /** Inserts a word into the trie. */
    void insert(string word);
    /** Returns if the word is in the trie. */
    bool search(const string& word);
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix);
};

Trie::Trie(){
    TrieRoot = new TrieNode;
}

void Trie::insert(string word) {
    TrieNode *p = TrieRoot;
    int le = word.size();
    for(int index = 0; index < le; ++index){
        if(p->next==nullptr){
            p->next = new TrieNode[26];
        }
        p = &p->next[word[index]-'a'];
        p->val = true;
    }
    p->isEnd = true;
}

bool Trie::search(const string& word) {
    TrieNode *p = TrieRoot;
    for(auto i:word){
        auto temp = p->next;
        if(temp!=nullptr&&temp[i-'a'].val){
            p = &temp[i-'a'];
            continue;
        }
        return false;
    }
    return p->isEnd;
}

bool Trie::startsWith(const string& prefix) {
    TrieNode *p = TrieRoot;
    for(auto i:prefix){
        auto temp = p->next;
        if(temp!=nullptr&&temp[i-'a'].val){
            p = &temp[i-'a'];
            continue;
        }
        return false;
    }
    return true;
}
int main() {
    auto p =Trie();
    p.insert("hello");
    p.insert("wenwen");
    cout << p.search("hello") << endl;
    cout << p.search("hell") << endl;
    cout << p.startsWith("he") << endl;
    cout << p.startsWith("hp") << endl;
}
