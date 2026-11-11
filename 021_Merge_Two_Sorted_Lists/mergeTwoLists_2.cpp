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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        // iteration
        ListNode* cur = &head;
        while(l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 == nullptr) {
            cur->next = l2;
        } else {
            cur->next = l1;
        }
        return head.next;
    }
};

ListNode* arrayToList(vector<int>& nums) {
    int sz = nums.size();
    if (0 == sz) {
        return nullptr;
    }

    // first element
    ListNode* head = new ListNode(nums[0]);

    // the rest elements
    ListNode* cur = head;
    for (int i = 1; i < sz; i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

int main(int argc, char* argv[]) {
    // input
    vector<int> nums_1 = {1, 2, 4};
    vector<int> nums_2 = {1, 3, 4};
    ListNode* l1 = arrayToList(nums_1);
    ListNode* l2 = arrayToList(nums_2);

    // solution
    Solution s;
    ListNode* ans = s.mergeTwoLists(l1, l2);

    // output
    cout << "Answer: " << endl;
    ListNode* cur = ans;
    while(cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}