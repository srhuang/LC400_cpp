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
        if(l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2-> val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
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
    cout << "Answers: " << endl;
    ListNode* cur = ans;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}