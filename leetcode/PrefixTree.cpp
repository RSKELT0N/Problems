#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    TrieNode *children[26];

    TrieNode() {
        this->isEnd = 0;
    }
};

class Trie {
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insertWord(string word) {
        TrieNode *node = root;
        for (char cur : word) {
            int index = cur - 97;
            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for (char cur : word) {
            int index = cur - 97;
            if (node->children[index] != NULL) {
                node = node->children[index];
                continue;
            }
            return 0;
        }
        if (node->isEnd == true) {
            return 1;
        }
        return 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char cur : prefix) {
            int index = cur - 97;
            if (node->children[index] != NULL) {
                node = node->children[index];
                continue;
            }
            return 0;
        }
        return 1;
    }
};

int main() {
    return 0;
}
