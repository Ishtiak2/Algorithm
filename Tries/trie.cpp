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

    ~Node(){
        for(auto child : children) delete child;
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

    int check(string word){
        Node* node = root;
        
        for(int i = 0; i < word.length(); i++) {
            
            int index = word[i] - 'a';
            
            node = node -> children[index];

            if(node -> countPrefix == 1){
                return i+1;
            }
        }

        return word.length();
    }

    ~Trie() { delete root;}
};

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int count = 0;

        int n;
        cin >> n;

        vector<string> name(n);
        Trie trie;

        for(int i = 0; i < n; i++)
        {
            cin >> name[i] ;
            trie.insert(name[i]);
        }

        for(auto s : name){
            count += trie.check(s);
            //cout << trie.check(s) << endl;
        }

        cout << count << endl;
    }

    return 0;
}
