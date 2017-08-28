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

class WordDictionary {
private:
    TrieNode* root;

public:
    /**
     * http://www.lintcode.com/zh-cn/problem/add-and-search-word/-473-单词的添加与查找
     * Your WordDictionary object will be instantiated and called as such:
     * WordDictionary wordDictionary;
     * wordDictionary.addWord("word");
     * wordDictionary.search("pattern");
     */

    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return search(word, root);
    }

    bool search(string word, TrieNode* root) {
        if (word.size() == 0 && root != NULL) {
            return root->isEnd;
        }
        else if (word[0] != '.' && root != NULL) {
            return search(word.substr(1, word.size() - 1), root->next[word[0] - 'a']);
        }
        else if (word[0] == '.' && root != NULL) {
            bool result = false;
            for (int i = 0; i < 26; i++) {
                if (root->next[i] != nullptr) {
                    result = result | search(word.substr(1, word.size() - 1), root->next[i]);
                }
            }
            return result;
        }
        else if (root == NULL) {
            return false;
        }
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }
};

int main()
{
    WordDictionary s;
    s.addWord("a");
    s.addWord("a");
    cout << s.search(".") << endl;
    cout << s.search("a") << endl;
    cout << s.search("aa") << endl;
    cout << s.search("a") << endl;
    cout << s.search(".a") << endl;
    cout << s.search("a.") << endl;


    return 0;
}