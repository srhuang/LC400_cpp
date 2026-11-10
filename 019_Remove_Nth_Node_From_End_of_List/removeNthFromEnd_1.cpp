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

        // first pass for calculating the length
        int length = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }
        
        // second pass for removing the node
        int pos = length - n;
        cur = &dummy;
        while (pos > 0) {
            cur = cur->next;
            pos--;
        }
        cur->next = cur->next->next;

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