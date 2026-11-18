#include <iostream>

using namespace std;

// Linked List
struct ListNode {
    // variables
    int val;
    ListNode* next;

    // constructors
    ListNode() {val = 0; next = nullptr;}
    ListNode(int x) {val = x; next = nullptr;}
    ListNode(int x, ListNode* node) {val = x; next = node;}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority queue
        auto cmp = [] (ListNode* l, ListNode* r) {return (l->val > r->val);};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // push the lists
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        ListNode head;
        ListNode* cur = &head;
        while (!pq.empty()) {
            // pop
            cur->next = pq.top();
            pq.pop();
            // update current pointer
            cur = cur->next;
            // move forward
            if (cur->next) {
                pq.push(cur->next);
            }
        }
        return head.next;
    }
};

ListNode* arrayToList(vector<int>& nums) {
    int sz = nums.size();
    if (0 == sz) {
        return nullptr;
    }

    // first
    ListNode* head = new ListNode(nums[0]);

    // the rest
    ListNode* cur = head;
    for (int i = 1; i < sz; i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

int main(int argc, char* argv[]) {
    // input
    vector<int> nums_1 = {1,4,5};
    vector<int> nums_2 = {1,3,4};
    vector<int> nums_3 = {2,6};
    ListNode* l1 = arrayToList(nums_1);
    ListNode* l2 = arrayToList(nums_2);
    ListNode* l3 = arrayToList(nums_3);
    vector<ListNode*> data = {l1, l2, l3};

    // solution
    Solution s;
    ListNode* ans = s.mergeKLists(data);

    // output
    cout << "Answer: " << endl;
    ListNode* cur = ans;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}