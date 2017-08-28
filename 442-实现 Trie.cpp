#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

/**
* Your Trie object will be instantiated and called as such:
* Trie trie;
* trie.insert("lintcode");
* trie.search("lint"); will return false
* trie.startsWith("lint"); will return true
*/
class TrieNode {
public:
    // Initialize your data structure here.
    char c;
    TrieNode * next[26];
    bool isEnd;

    TrieNode() {
        c = ' ';
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        isEnd = false;
    }

    TrieNode(char c) {
        this->c = c;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/implement-trie//-442-实现 Trie
     */
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curNode = root;
        for (int i = 0; i < word.size(); i++) {
            if (curNode->next[word[i] - 'a'] != nullptr) {
                curNode = curNode->next[word[i] - 'a'];
            }
            else {
                TrieNode* node = new TrieNode(word[i]);
                curNode->next[word[i] - 'a'] = node;
                curNode = node;
            }
        }
        curNode->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curNode = root;
        for (int i = 0; i < word.size(); i++) {
            if (curNode->next[word[i] - 'a'] == nullptr) {
                return false;
            }
            else {
                curNode = curNode->next[word[i] - 'a'];
            }
        }
        return curNode->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curNode = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curNode->next[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            else {
                curNode = curNode->next[prefix[i] - 'a'];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

int main()
{
    Trie t;
    t.insert("lintcode");
    cout << t.search("code") << endl;
    cout << t.startsWith("lint") << endl;
    cout << t.startsWith("linterror") << endl;
    t.insert("linterror");
    cout << t.search("lintcode") << endl;
    cout << t.startsWith("linterror") << endl;

    return 0;
}