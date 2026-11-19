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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        dummy.next = head;

        // iterative
        ListNode* pre = &dummy;
        while ((head != nullptr) && (head->next != nullptr)) {
            ListNode* first = head;
            ListNode* second = head->next;
            // swap
            first->next = second->next;
            second->next = first;
            pre->next = second;
            // for next step
            pre = first;
            head = first->next;
        }
        return dummy.next;
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
    vector<int> nums = {1,2,3,4};
    ListNode* l = arrayToList(nums);

    // solution
    Solution s;
    ListNode* ans = s.swapPairs(l);

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