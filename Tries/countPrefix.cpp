#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    
    int countPrefix;
    Node* children[26];
    
    Node(){
        countPrefix = 0;
        for(int i=0; i<26;i++){
            children[i]= nullptr;
        }
    }
};

class Trie{
    Node* root;
    public:
    
    Trie() {
        root=new Node();
        }
    
    void insert(string word){
        Node* node = root;
        
        for(char c: word){
            int index = c - 'a';
            
            if(node->children[index] == nullptr)
                node->children[index] = new Node();
            node = node ->children[index];
            node->countPrefix++;   
        }
    }
    
    int prefixCount(string prefix){
        Node* node = root;
        
        for(char c : prefix){
            int index = c-'a';
            
            if(node->children[index]==nullptr)
                return 0;
            node = node -> children[index];    
        }
        
        return node -> countPrefix;
    }
};

int main()
{
    Trie trie;
    trie.insert("doggo");
    trie.insert("dogesh");
    trie.insert("cat");
    trie.insert("catline");
    trie.insert("catch");
    
    cout <<"dog: " <<trie.prefixCount("dog")<<endl;
    cout <<"cat: " <<trie.prefixCount("cat")<< endl;
    
    return 0;
}