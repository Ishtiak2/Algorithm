#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

class Node{
    public:

    bool endOfWord;
    Node* children[26];

    Node() {
        for(int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class Trie{
    public:
    Node* root = nullptr;

    Trie() {
        root = new Node();
    }

    void insert(string word){
        Node* node = root;

        for(auto c : word){
            int index = c - 'a';
            
            if(node->children[index] == nullptr)
                node->children[index] = new Node();

            node = node -> children[index];    
        }

        node -> endOfWord = true;
    }

    bool search(string word){
        Node* node = root;

        for(auto c : word){
            int index = c - 'a';
            if(node -> children[index] == nullptr)
                return false;

            node = node->children[index];    
        }

        if(node -> endOfWord == true)
            return true;
        else
            return false;    
    }

    bool prefixCheck(string prefix){
        Node* node = root;

        for(char c : prefix){
            int index = c - 'a';
            if(node -> children[index] == nullptr) return false;

            node = node -> children[index];
        }

        return true;
    }

    void deleteWord(string word){
        
        if(!search(word)) {
            cout <<"Error!" << endl;
            return;
        }

        Node* node = root;

        for(char c : word){
            int index = c - 'a';
            node = node -> children[index];
        } 

        node ->endOfWord = false;
    }

    void print(Node* node, string prefix){
        
        if(node -> endOfWord == true){
            cout << prefix << endl;
        }

        for(int i = 0; i < 26; i++)
        {
            if(node -> children[i]){
                char c = i+ 'a';
                print(node -> children[i],prefix+c);
            }
        }
    }

    void printTrie(){
        cout <<"Trie: " << endl;
        print(root,"");
    }


};

int main()
{
    optimize();

    Trie trie;

    trie.insert("there");
    trie.insert("the");
    trie.insert("here");
    trie.insert("abc");

    if(trie.search("ther")) cout <<"YES" << endl;
    else cout <<"NO" << endl;

    if(trie.prefixCheck("he")) cout <<"YES" << endl;
    else cout <<"NO" << endl;

    trie.printTrie();

    return 0;
}