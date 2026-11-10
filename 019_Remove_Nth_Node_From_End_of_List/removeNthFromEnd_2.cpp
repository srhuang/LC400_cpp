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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // using dummy for the case removing the head of the list
        ListNode dummy(0);
        dummy.next = head;

        // two pointers
        ListNode* first = &dummy;
        ListNode* second = &dummy;

        // the gap between first pointer and second pointer is n.
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // mode the first pointer to the end and keep the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;

        return dummy.next;
    }
};

ListNode* arrayToList(vector<int>& nums) {
    int sz = nums.size();
    if (nums.size() == 0) {
        return nullptr;
    }
    // first element
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;

    // the rest elements
    for (int i = 1; i < sz; i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

int main(int argc, char* argv[]) {
    // input
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = arrayToList(nums);

    // solution
    Solution s;
    ListNode* ans = s.removeNthFromEnd(head, 2);

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