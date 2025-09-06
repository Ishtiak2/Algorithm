#include <bits/stdc++.h>
using namespace std;

/*
🔧 Example Use Case
Searching all names with prefix "br" from a contact list → Trie
Checking if the word "abab" appears in a 1-million-character string → KMP
*/

// Function to build the LPS array
vector<int> buildLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // length of the previous longest prefix suffix

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // backtrack
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP search function
vector<int> KMP(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = buildLPS(pattern);
    vector<int> matchIndices; // store the starting indices of matches

    int i = 0, j = 0; // i for text, j for pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            matchIndices.push_back(i - j);
            j = lps[j - 1]; // look for next possible match
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return matchIndices;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    vector<int> result = KMP(text, pattern);

    if (result.empty()) {
        cout << "No match found\n";
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : result)
            cout << idx << " ";
        cout << "\n";
    }

    return 0;
}
