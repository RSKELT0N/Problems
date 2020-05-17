/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* newOrder;
    queue<int> odd;
    queue<int> even;
    void add(ListNode* newOrder) {
        if(odd.empty() && even.empty())
            return;
        if(!odd.empty()) {
            newOrder->val = odd.front();
            odd.pop();
        } else {
            newOrder->val = even.front();
            even.pop();
        }
        if(!odd.empty() || !even.empty()) {
        ListNode* node = new ListNode();
        newOrder->next = node;
        add(node);
        }
        
    }
    ListNode* oddEvenList(ListNode* head) {
        ListNode* newOrder = head;
        for(int i = 0; !(head==NULL); i++) {
            if(i & 1)
                even.push(head->val);
            else odd.push(head->val);
            head = head->next;
        }
        add(newOrder);
        return newOrder;  
        }
};
