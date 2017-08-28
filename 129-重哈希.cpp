#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/rehashing/-129-重哈希
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int capacity = hashTable.size();
        if (capacity <= 0) {
            return vector<ListNode*>();
        }

        vector<int> hashValue;
        for (ListNode *node : hashTable) {
            while (node != NULL) {
                hashValue.push_back(node->val);
                node = node->next;
            }
        }

        hashTable.clear();
        capacity *= 2;
        hashTable.resize(capacity);

        for (int i = 0; i < hashValue.size(); i++) {
            int index = (hashValue[i] % capacity + capacity) % capacity;
            if (hashTable[index] == NULL) {
                hashTable[index] = new ListNode(hashValue[i]);
            }
            else {
                ListNode* node = hashTable[index];
                while (node->next != NULL) {
                    node = node->next;
                }
                node->next = new ListNode(hashValue[i]);
            }
        }
        return hashTable;
    }

    void display(vector<ListNode*> &nums) {
        vector<ListNode*>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            if (*i == NULL) {
                cout << "null" <<endl;
            }
            else {
                display(*i);
            }
        }
        cout << endl;
    }

    void display(ListNode *head) {
        ListNode *l = head;
        while (l->next != NULL) {
            cout << l->val << "->";
            l = l->next;
        }
        cout << l->val << "->null" << endl;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    vector<ListNode*> hashTable;
    ListNode l1(21), l2(9), l3(14);
    l1.next = &l2;
    hashTable.push_back(nullptr);
    hashTable.push_back(&l1);
    hashTable.push_back(&l3);
    hashTable.push_back(nullptr);
    s.display(hashTable);

    s.display(s.rehashing(hashTable));

    return 0;
}