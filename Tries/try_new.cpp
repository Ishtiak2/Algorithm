#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int countPrefix;
    Node* children[26];
    
    Node(){
        countPrefix = 0;

        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }

    ~Node(){
            for(auto it: children){
                delete it;
            }
        }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node =root;

        for(auto c : word){
            int index = c - 'a';

            if(node->children[index] == nullptr){
                node->children[index] = new Node();
            }
            node = node -> children[index];
            node -> countPrefix++;

        }
    }

    int prefixCount(string word){
        Node* node = root;

        for(auto c : word){
            int index = c - 'a';

            if(node -> children[index] == nullptr){
                return 0;
            }
            node = node -> children[index];
        }

        return node ->countPrefix;
    }

    ~Trie(){
        delete root;
    }
};

int main()
{
    Trie trie;
    trie.insert("abcdabcd");
    trie.insert("abcdefgh");
    trie.insert("abcdfgfgffgf");

    cout<<trie.prefixCount("abcd");
    return 0;
}