#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    bool endOfWord;
    Node* children[26];

    Node(){
        endOfWord = false;

        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }

    ~Node(){
        for(auto child: children){
            delete child;
        }
    }

};

class Trie{
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;

        for(char i: word){
            int c = i - 'a';

            if(node->children[c] == nullptr){
                node->children[c] = new Node();
            }
            node = node -> children[c];
        }

        node->endOfWord = true;
    }

    bool search(string word){
        Node* node = root;

        for(auto i: word){
            int c = i - 'a';
            if(node -> children[c] == nullptr) return false;
            node = node -> children[c];
        }

        return node ->endOfWord;
    }

    bool prefix(string word){
        Node* node = root;

        for(auto i: word){
            int c = i - 'a';

            if(node -> children[c] == nullptr){
                return false;
            }
            node = node -> children[c];
        }

        return true;
    }

    ~Trie(){
        delete root;
    }
};



int main()
{
    
    Trie t;
    t.insert("abcd");
    t.insert("efgh");
    t.insert("asdddd");

    cout<<t.search("abc");
    return 0;
}