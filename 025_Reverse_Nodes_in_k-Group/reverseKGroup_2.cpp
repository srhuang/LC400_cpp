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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // iteration
        ListNode* new_head = nullptr;
        ListNode* ktail = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            // find the next head of group
            int cnt = 0;
            while ((cnt < k) && (cur != nullptr)) {
                cur = cur->next;
                cnt++;
            }
            // the group less than k
            if (cnt < k) {
                if (new_head == nullptr) new_head = head;
                if (ktail != nullptr) ktail->next = head;
            } else {
                // reverse the group
                ListNode* rev_head = reverse(head, k);
                if (new_head == nullptr) new_head = rev_head;
                if (ktail != nullptr) ktail->next = rev_head;
            }
            // for next run
            ktail = head;
            head = cur;
        }
        return new_head;
    }
private:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* new_head = nullptr;
        for (int i = 0; i < k; i++) {
            ListNode* next = cur->next;
            cur->next = new_head;
            new_head = cur;
            cur = next;
        }
        return new_head;
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
    vector<int> nums = {1,2,3,4,5};
    ListNode* l = arrayToList(nums);

    // solution
    Solution s;
    ListNode* ans = s.reverseKGroup(l, 3);

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