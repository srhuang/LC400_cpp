#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0)
        {
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

ListNode* arrayCopy(int* array, int num){
    printf("Copy Array to linked list : ");
    printf("%d", array[0]);
    ListNode* head = new ListNode(array[0]);

    ListNode *pre = head;
    for (int i = 1; i < num; i++)
    {
        printf("->%d", array[i]);
        ListNode* current = new ListNode(array[i]);
        pre->next = current;
        pre = current;
    }
    printf("\n");
    return head;
}

int main(int argc, char* argv[])
{
    // input data
    int data1[3] = {2, 4, 3};
    int data2[3] = {5, 6, 6};
    ListNode *data1_head = NULL;
    ListNode *data2_head = NULL;
    data1_head = arrayCopy(data1, sizeof(data1)/sizeof(data1[0]));
    data2_head = arrayCopy(data2, sizeof(data2)/sizeof(data2[0]));

    // solution
    Solution s;
    ListNode *answer = s.addTwoNumbers(data1_head, data2_head);

    // print
    ListNode *temp = answer;
    while(nullptr != temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
