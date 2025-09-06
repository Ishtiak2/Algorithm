#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int countPrefix;
    bool endOfWord; // Marks if this node is the end of a word
    unordered_map<char, Node*> children; // Optimized storage

    Node() {
        countPrefix = 0;
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) 
                node->children[c] = new Node();
            
            node = node->children[c];
            node->countPrefix++;
        }
        node->endOfWord = true;
    }

    int prefixCount(string prefix) {
        if (prefix.empty()) return 0; // Handle empty query case

        Node* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end())
                return 0; // Prefix doesn't exist
            node = node->children[c];
        }
        return node->countPrefix;
    }

    bool search(string word) {
        Node* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end())
                return false;
            node = node->children[c];
        }
        return node->endOfWord; // Return true only if it's a complete word
    }
};

int main() {
    Trie trie;
    
    // Insert words
    trie.insert("doggo");
    trie.insert("dogesh");
    trie.insert("cat");
    trie.insert("catline");
    trie.insert("catch");

    // Prefix count queries
    cout << "dog: " << trie.prefixCount("dog") << endl;  // Output: 2
    cout << "cat: " << trie.prefixCount("cat") << endl;  // Output: 3
    cout << "do: " << trie.prefixCount("do") << endl;    // Output: 2
    cout << "c: " << trie.prefixCount("c") << endl;      // Output: 3
    cout << "dogo: " << trie.prefixCount("dogo") << endl;// Output: 1
    cout << "empty query: " << trie.prefixCount("") << endl; // Output: 0
    cout << "not found: " << trie.prefixCount("xyz") << endl; // Output: 0

    // Word search queries
    cout << "Search 'doggo': " << trie.search("doggo") << endl; // Output: 1 (true)
    cout << "Search 'dog': " << trie.search("dog") << endl;   // Output: 0 (false)

    return 0;
}
