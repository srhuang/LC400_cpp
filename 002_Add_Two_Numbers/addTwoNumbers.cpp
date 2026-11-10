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
    ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};

ListNode* arrayToList (vector<int>& nums) {
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

int main (int argc, char* argv[]) {
    // input
    vector<int> data1 = {2, 4, 3};
    vector<int> data2 = {5, 6, 6};
    ListNode *list1 = arrayToList(data1);
    ListNode *list2 = arrayToList(data2);

    // solution
    Solution s;
    ListNode *answer = s.addTwoNumbers(list1, list2);

    // output
    cout << "Answer: " << endl;
    ListNode *cur = answer;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
