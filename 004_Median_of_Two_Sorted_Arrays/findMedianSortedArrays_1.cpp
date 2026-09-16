#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make sure nums1 is less than nums2
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int k = (n1 + n2 + 1) / 2;

        // binary search for m1
        int left = 0;
        int right = n1;
        while (left <= right)
        {
            int m1 = (left + right) / 2;
            int m2 = k - m1;

            int n1_maxLeft = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int n1_minRight = (m1 == n1) ? INT_MAX : nums1[m1];
            int n2_maxLeft = (m2 == 0) ? INT_MIN : nums2[m2 - 1];
            int n2_minRight = (m2 == n2) ? INT_MAX : nums2[m2];

            // check the condition
            if (n1_maxLeft <= n2_minRight && n2_maxLeft <= n1_minRight ) {
                if ((n1 + n2) % 2 == 0) { //even
                    return 
                    (max(n1_maxLeft, n2_maxLeft) + min(n1_minRight, n2_minRight)) / 2.0;
                } else { // odd
                    return max(n1_maxLeft, n2_maxLeft);
                }
            } else if (n1_maxLeft > n2_minRight) {
                right = m1 - 1;
            } else {
                left = m1 + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    // input data
    int ary1[] = {1, 2};
    int ary2[] = {3, 4};
    int m = sizeof(ary1) / sizeof(ary1[0]);
    int n = sizeof(ary2) / sizeof(ary2[0]);
    vector<int> nums1(ary1, ary1 + m);
    vector<int> nums2(ary2, ary2 + n);

    // solution
    Solution s;
    double ans = s. findMedianSortedArrays(nums1, nums2);

    // print
    cout << "Answer: " << ans << endl;

}
